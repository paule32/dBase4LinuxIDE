// --------------------------------------------------------------------------------
// MIT License
//
// Copyright (c) 2018 Jens Kallup
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
// --------------------------------------------------------------------------------
#include <QDataStream>
#include <QDateTime>
#include <QString>
#include <QDir>
#include <QDebug>

#include "source/includes/dbase/dbaseexception.h"
#include "source/includes/dbase/dbaselevel7.h"

// macro, to save code size
static const QString msg = "can't write header for dbf file.";
static int   c0123 = 0;

// ---------------------------------------
// dbf header file ...
// ---------------------------------------
QDataStream & operator << (QDataStream &stream, const struct TableFileHeader &stcl)
{
    qDebug() << "write header";
    
    //stream << stcl.version;
    //stream << stcl.last_update_date;
    
    stream.writeRawData( (char*)& stcl.version,1);
    stream.writeRawData( (char*)& stcl.last_update_date,3);
    stream.writeRawData( (char*)& stcl.number_of_records_in_table, 4);
    stream.writeRawData( (char*)& stcl.number_of_bytes_in_header,  2);
    stream.writeRawData( (char*)& stcl.number_of_bytes_in_record,  2);
    stream.writeRawData( (char*)& stcl.reserved1,                  2);
    stream.writeRawData( (char*)& stcl.transaction_flag,           1);
    stream.writeRawData( (char*)& stcl.encryptet_flag,             1);
    stream.writeRawData( (char*)& stcl.multi_user_reserved,        12);
    stream.writeRawData( (char*)& stcl.mdx_flag,                   1);
    stream.writeRawData( (char*)& stcl.language_driver_id,         1);
    stream.writeRawData( (char*)& stcl.reserved2,                  2);
    stream.writeRawData( (char*)& stcl.language_driver_name,       32);
    stream.writeRawData( (char*)& stcl.reserved3,                  4);
    
    return stream;
}

// record ...
QDataStream & operator << (QDataStream &stream, const struct FieldDescriptorArray &stcl)
{
    char termiChar = 0x00;
    
    stream.writeRawData( (char*)& stcl.field_name,           32);
    stream.writeRawData( (char*)& stcl.field_type,            1);
    stream.writeRawData( (char*)& stcl.field_length,          1);
    stream.writeRawData( (char*)& stcl.reserved1,             2);
    stream.writeRawData( (char*)& stcl.mdx_field_flag,        1);
    stream.writeRawData( (char*)& stcl.reserved2,             2);
    stream.writeRawData( (char*)& stcl.next_autoincrement,    4);
    stream.writeRawData( (char*)& stcl.reserved3,             4);
    stream.writeRawData( (char*)& termiChar,                  1);
    
    return stream;
}

dBaseLevel7::dBaseLevel7()
{
    write(QDir::homePath() + "/test.dbf");
}

bool dBaseLevel7::write(QString name)
{
    TableFileHeader header;
    FieldDescriptorArray record[2];
    
    QDate date;
    date = QDate::currentDate();  

    char *bufferField = new char[32];
    memset(bufferField, 0x00,32);
    memset(record[0].field_name,0x00,32);
    sprintf(bufferField,"%s","feldA");
    strcpy (record[0].field_name, bufferField);
    
    memset(bufferField, 0x00,32);
    memset(record[1].field_name,0x00,32);
    
    sprintf(bufferField,"%s","feldB");
    strcpy (record[1].field_name, bufferField);
    
    delete bufferField;
    
    record[0].field_type     = 'C';        record[1].field_type     = 'L';
    record[0].field_length   =  15;        record[1].field_length   = 0x01;
    record[0].mdx_field_flag = 0x00;       record[1].mdx_field_flag = 0x00;
    record[0].field_decimal_count = 0x00;  record[1].field_decimal_count = 0x00;
    record[0].next_autoincrement  = 0x00;  record[1].next_autoincrement  = 0x00;
    
    memset(record[0].reserved1,0x00,2);    memset(record[1].reserved1,0x00,2);
    memset(record[0].reserved2,0x00,2);    memset(record[1].reserved2,0x00,2);
    memset(record[0].reserved3,0x00,4);    memset(record[1].reserved3,0x00,4);
    
    header.version = 0x04;       // dbase Level 7
    header.last_update_date[0] = date.year() - 1900;
    header.last_update_date[1] = date.toString("MM").toInt();
    header.last_update_date[2] = date.toString("dd").toInt();
    
    header.number_of_records_in_table = 0; // TODO
    header.number_of_bytes_in_header  = sizeof(struct TableFileHeader)-1;
    header.number_of_bytes_in_record  = sizeof(record[0]);  // size of 1 record
       
    header.transaction_flag = 0x00;
    header.encryptet_flag   = 0x00;
    
    memset(header.multi_user_reserved,0x00,12);
    
    header.mdx_flag = 0x00;       // 0x01 MDX file exists
    header.language_driver_id = 49;
    
    char *buffer = new char[32];
    memset(buffer,0x00,32);
    memset(header.language_driver_name,0x00,32);
    
    sprintf(buffer,"%s","DBWINUS0");
    strcpy (header.language_driver_name, buffer);
    
    qDebug() << header.number_of_bytes_in_header;
   
    QFile f(name); f.open(
    QIODevice::WriteOnly |
    QIODevice::Truncate  );
    
    QDataStream out(&f);
        out << header;

        out << record[0];
        out << record[1];

    char data2 = 0x0d; out.writeRawData( (char*)& data2, 1);
    char data3 = 0x1a; out.writeRawData( (char*)& data3, 1);

    int pos = f.pos();
    char data = pos - 1;
    int  daia = 0x00000000;
    
    f.seek(8);     out.writeRawData( (char*)& data, 1); data = 0x00;
    f.seek(pos-3); out.writeRawData( (char*)& data, 1); data = 0x11;
    
    f.seek(0x0a);  out.writeRawData( (char*)& data, 1); data = 0x00;
    f.seek(0x1d);  out.writeRawData( (char*)& data, 1);
    
    f.seek(0x40);  out.writeRawData( (char*)& daia, 4);

    f.flush();
    f.close();
    
    qDebug() << "write ok";
       
    return true;
}

bool dBaseLevel7::read(QString name)
{
    return true;
}


// ----------------------------
// using Lazarus DBF-Table ...
// ----------------------------
dBaseTable::dBaseTable(QString name)
    : TableName(name)
{

}
