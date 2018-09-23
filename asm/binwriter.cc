#include "binheader.h"

using namespace std;

std::vector<dso_header_libs>   code_libs;
std::vector<dso_export_header> code_exports;

void testfunc(void)
{
    printf("Eine Runtimesfiler\n");
}

MyHeaderWriter::MyHeaderWriter(
    std::string n,
    uint64_t length,
    void   * buffer)
{
    lib_name = n;
    out_name = std::string("./" + n);

    code_libs   .clear();
    code_exports.clear();
    
    code_position    = 0;

    wr.open(n, ios_base::out | ios_base::binary);
    if (!wr.is_open())
    throw std::string("error: could no open file for writing.\n");

    codelen = length;
    
    init_header ();
    init_libs   ();
    init_exports();
    init_image  (buffer);
}

MyHeaderWriter::~MyHeaderWriter() { }

void MyHeaderWriter::write_data()
{    
    write_header ();
    write_libs   ();
    write_exports();
    write_image  ();
}

uint64_t MyHeaderWriter::init_header()
{
    uint64_t hdr_length =
    (2 * sizeof(uint64_t)) +
    (2 * sizeof(uint32_t)) +
    (2 * sizeof(uint16_t)) + lib_name.size();
    
    header_image_length  =  hdr_length;
    header_image = new char[hdr_length];
    memset(header_image, 0, hdr_length);
    
    code_position += hdr_length;
    return hdr_length;
}

uint64_t MyHeaderWriter::init_libs()
{
    uint64_t str_length = 0;
    
    code_libs.emplace_back(0x8, 0x1, "crtA.ovl"); str_length += 8;
    code_libs.emplace_back(0x8, 0x2, "crtB.ovl"); str_length += 8;
    
    uint64_t lib_length =((
    (2 * sizeof(uint16_t)) * code_libs.size()) +
    (1 * str_length));
    
    lib_image_length =   lib_length;
    lib_image = new char[lib_length];
    memset(lib_image, 0, lib_length);
    
    code_position += lib_length;
    return lib_length;
}

uint64_t MyHeaderWriter::init_exports()
{
    uint64_t str_length = 0;
    
    // basic exports
    auto ptr_printf   = reinterpret_cast<uint64_t>(&printf);
    auto ptr_testfunc = reinterpret_cast<uint64_t>(&testfunc);
    //
    code_exports.emplace_back(0x4, static_cast<uint64_t>(0x00), 0x4, "main"); str_length += 4;
    code_exports.emplace_back(0x8, ptr_testfunc , 0x1, "testfunc");           str_length += 8;
    code_exports.emplace_back(0x6, ptr_printf   , 0x2, "printf");             str_length += 6;
    
    uint64_t exp_length =
    ((
    (1 * sizeof(uint16_t))  +
    (1 * sizeof(uint64_t))  +
    (1 * sizeof(uint8_t ))) * code_exports.size()) +
    //
    (1 * str_length);
    
    export_image_length =   exp_length;
    export_image = new char[exp_length];
    memset(export_image, 0, exp_length);
    
    code_position += exp_length;
    return exp_length;
}

uint64_t MyHeaderWriter::init_image(void * buffer)
{
    code_image_length = codelen;
    code_image = new char[codelen];
    memcpy(code_image, reinterpret_cast<char*>(buffer), codelen);

    code_position += 12;    
    return code_image_length;
}

void MyHeaderWriter::write_header()
{
    struct dso_header header(
    lib_name,
    lib_name.size(), 1);
    
    wr << header.magic;
    wr << header.version;
    wr << static_cast<uint16_t>(lib_name.size());
    wr.write(lib_name.c_str()  ,lib_name.size());
    wr << header.id;
    
    wr << code_position ;
    wr << codelen;
}

void MyHeaderWriter::write_libs()
{
    wr << static_cast<uint32_t>(code_libs.size());        
    for (int i = 0; i < code_libs.size(); i++)
    {
        wr << static_cast<uint16_t>(code_libs.at(i).name.size());
        wr << static_cast<uint16_t>(code_libs.at(i).id);
        
        wr.write(
        code_libs.at(i).name.c_str(),
        code_libs.at(i).name.size());
    }
}

void MyHeaderWriter::write_exports()
{
    uint64_t elen = code_exports.size();
    uint16_t nlen = 0;
    
    wr << elen;
    for (int i = 0; i < elen; i++) {
        nlen = code_exports.at(i).name.size();
        wr << nlen;
        
        if (code_exports.at(i).name == "main")
        exports_position = wr.tellp();
        
        wr << code_exports.at(i).offset;
        wr << code_exports.at(i).lib_id;
        
        char *name = new char[nlen];
        memcpy(name,code_exports.at(i).name.c_str(),nlen);
        wr.write(name,nlen);
        
        delete name;
    }
}

void MyHeaderWriter::write_image()
{
    uint64_t oldpos = wr.tellp();
    wr.seekp(code_position,ios_base::beg);
    
    wr << oldpos ;
    wr << codelen;
    
    // main entry
    wr.seekp(exports_position,ios_base::beg);
    wr << static_cast<uint64_t>(oldpos);
    
    wr.seekp(oldpos, ios_base::beg);
    wr.write(reinterpret_cast<const char*>(code_image),codelen);
}
