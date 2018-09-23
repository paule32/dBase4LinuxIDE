#ifndef DBASELEVEL7_H
#define DBASELEVEL7_H

#include <QString>
#include <QDataStream>

typedef unsigned char       uint8_t; //!<  8-Bit unsigned char  \sa BYTE
typedef unsigned short     uint16_t; //!< 16-Bit unsigned short \sa WORD

typedef unsigned char          BYTE; //!<  8-Bit \sa uint8_t  \sa uint8_t
typedef unsigned short         WORD; //!< 16-Bit \sa uint16_t \sa uint16_t
typedef unsigned int          DWORD; //!< 32-Bit \sa uint32_t \sa uint32_t
typedef uint64_t          ULONGLONG; //!< 64-Bit \sa uint64_t \sa uint64_t

// -------------------------------------------------------------
// dbf file format: Header byte 0:
// -------------------------------------------------------------
// 0x01   not used
// 0x02   FoxBASE
// 0x03   FoxBASE+/Dbase III plus, no memo
// 0x04   dBase 7
// 0x05   dBase 5, no memo
// 0x30   Visual FoxPro
// 0x31   Visual FoxPro, autoincrement enabled
// 0x32   Visual FoxPro with field type Varchar or Varbinary
// 0x43   dBASE IV SQL table files, no memo
// 0x63   dBASE IV SQL system files, no memo
// 0x83   FoxBASE+/dBASE III PLUS, with memo
// 0x8B   dBASE IV with memo
// 0xCB   dBASE IV SQL table files, with memo
// 0xF5   FoxPro 2.x (or earlier) with memo
// 0xE5   HiPer-Six format with SMT memo file (Clipper)
// 0xFB   FoxBASE
// -------------------------------------------------------------

// prop_type_desc:
# define prop_type_desc_Required            0x01
# define prop_type_desc_Min                 0x02
# define prop_type_desc_Max                 0x03
# define prop_type_desc_Default             0x04
# define prop_type_desc_DatabaseConstraint  0x01

// field_type:
# define field_type_no_type                 0x00
# define field_type_char                    0x01
# define field_type_numeric                 0x02
# define field_type_memo                    0x03
# define field_type_logical                 0x04
# define field_type_date                    0x05
# define field_type_float                   0x06
# define field_type_ole                     0x08
# define field_type_binary                  0x09
# define field_type_long                    0x11
# define field_type_timestamp               0x12
# define field_type_double                  0x13
# define field_type_autoincrement           0x14

// array_element:
# define array_element_isaconstraint        0x00
# define array_element_isnotaconstraint     0x02

// field_type
# define field_desc_type_bool                    0x01 // B
# define field_desc_type_char                    0x02 // C
# define field_desc_type_date                    0x03 // D
# define field_desc_type_numeric                 0x04 // N
# define field_desc_type_logical                 0x05 // L
# define field_desc_type_memo                    0x06 // M
# define field_desc_type_timestamp               0x07 // @
# define field_desc_type_long                    0x08 // I
# define field_desc_type_autoincrement           0x09 // +
# define field_desc_type_float                   0x10 // F
# define field_desc_type_double                  0x11 // O
# define field_desc_type_ole                     0x12 // G

// field_std_type
# define field_std_type_null                     0x00 // no type
# define field_std_type_char                     0x01 // char
# define field_std_type_numeric                  0x02 // numeric
# define field_std_type_memo                     0x03 // memo
# define field_std_type_logical                  0x04 // logical
# define field_std_type_date                     0x05 // date
# define field_std_type_float                    0x06 // float
# define field_std_type_ole                      0x08 // ole
# define field_std_type_binary                   0x09 // binary
# define field_std_type_long                     0x11 // long
# define field_std_type_timestamp                0x12 // timestamp
# define field_std_type_double                   0x13 // double
# define field_std_type_autoincrement            0x14 // autoincrement

struct FieldDescriptorArray {
    char     field_name [32];           //  0 - 32   32 byte ASCII
    char     field_type;                // 32         1 byte
    uint8_t  field_length;              // 33         1 byte
    uint8_t  field_decimal_count;       // 34         1 byte
    char     reserved1[2];              // 35 - 36    2 byte
    uint8_t  mdx_field_flag;            // 37         1 byte
    char     reserved2[2];              // 38 - 39    2 byte
    uint32_t next_autoincrement;        // 40 - 43    4 bytes
    char     reserved3[4];              // 44 - 47    4 bytes
};

struct TableFileHeader {
    char     version;                       //  0           1 byte
    char     last_update_date[3];           //  1 -  3      3 byte
    uint32_t number_of_records_in_table;    //  4 -  7      4 byte - 32 bit num
    uint16_t number_of_bytes_in_header;     //  8 -  9      2 byte - 16 bit num
    uint16_t number_of_bytes_in_record;     // 10 - 11      2 byte - 16 bit num
    char     reserved1[2];                  // 12 - 13      2 byte
    uint8_t  transaction_flag;              // 14           1 byte
    uint8_t  encryptet_flag;                // 15           1 byte
    char     multi_user_reserved[12];       // 16 - 27     12 byte
    uint8_t  mdx_flag;                      // 28           1 byte
    uint8_t  language_driver_id;            // 29           1 byte
    char     reserved2[2];                  // 30 - 31      2 byte
    char     language_driver_name[32];      // 32 - 63     32 byte
    char     reserved3[4];                  // 64 - 67      4 byte > 68 bytes
};

struct FieldPropertiesStructure {
    uint16_t number_of_std_prop;
    uint16_t start_of_std_custom_prop_desc_array;
    uint16_t number_of_custom_prop;
    uint16_t start_of_custom_prop_desc_array;
    uint16_t number_of_ri_prop;
    uint16_t start_of_ri_prop_desc_array;
    uint16_t start_of_data;
    uint16_t actual_size_of_struct;
    
    unsigned char std_prop_desc_array   [15];
    unsigned char custom_prop_desc_array[14];
    unsigned char ri_prop_desc_array    [22];
};

struct StandardPropertyAndConstraintDescriptorArray {
    uint16_t prop;
    uint16_t table_offset;
    uint8_t  prop_type_desc;
    uint8_t  field_std_type;
    uint8_t  array_element;    // 0x00 or 0x02
    uint32_t reserved;
    uint16_t offset_from_start;
    uint16_t width_of_database_field;
};

struct CustomPropertyDescriptorArray {
    uint16_t number;
    uint16_t table_field_offset;
    uint8_t  field_type;
    uint8_t  reserved;
    uint16_t start_offset;
    uint16_t custom_prop_name;
    uint16_t from_offset;
    uint16_t custom_prop_length;
};

class dBaseLevel7
{
public:
    explicit dBaseLevel7();
    
    bool read (QString name);
    bool write(QString name);
};

class dBaseTable
{
    QStringList fields;
    QString     TableName;
    QString     TableIndexFile;
    int         TableLevel       = 7;
    bool        TableIsExclusive = false;
public:
    explicit dBaseTable(QString name);
};

#endif // DBASELEVEL7_H
