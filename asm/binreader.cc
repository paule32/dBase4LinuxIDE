#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>

#include "binheader.h"

using namespace std;

MyHeaderReader::MyHeaderReader(std::string n)
    : m_path(n)
{
    rd.open(n,ios_base::in | ios_base::binary);
    if (!rd.is_open())
    throw std::string("error: could no open file for reading.\n");

    code_libs   .clear();
    code_exports.clear();
    
    read_header  ();
    read_library ();
    read_exports ();
    read_image   ();
}

// header
void MyHeaderReader::read_header()
{
    uint32_t magic   = 0;
    uint32_t version = 0;
    uint16_t nsize   = 0;
    uint16_t lib_id  = 0;
  
    rd >> magic  ;
    rd >> version;
    rd >> nsize  ;

    char*   name = new char[nsize];
    rd.read(name,nsize);
    name[nsize] =  '\0';  // string terminator
    
    rd >> lib_id ;
    rd >> codebeg;
    rd >> codelen;
}

// libs
void MyHeaderReader::read_library()
{
    uint16_t length;
    uint16_t id;
    uint32_t libs;

    rd >> libs;
    
    for (uint32_t i = 0; i < libs; i++) {
        rd >> length;
        rd >> id    ;
        
        char *name = new char[length];
        rd.read(name,length);
        name[length] =  '\0';  // string terminator
        
        code_libs.emplace_back(
            static_cast<uint16_t>(length),
            static_cast<uint16_t>(id),
            std::string(name));

        delete[] name;
    }
}

// exports
void MyHeaderReader::read_exports()
{
    uint64_t funcs  = 0;
    
    uint16_t length = 0;
    uint64_t offset = 0;
    uint8_t  lib_id = 0;
    
    code_exports.clear();
    rd >> funcs;

    for (uint64_t i = 0; i < funcs; i++) {
        rd >> length;
        rd >> offset;
        rd >> lib_id;

        char *  name = new char[length];
        rd.read(name,length);
        name[length] =  '\0';  // string terminator
        
        code_exports.emplace_back(
        length,
        offset,
        lib_id, name);

        delete[] name;
    }
}

// image
void MyHeaderReader::read_image()
{
    image = new uint8_t[codelen];
    rd.seekg(codebeg,ios_base::beg);
    rd.read(reinterpret_cast<char*>(image),codelen);
}

void MyHeaderReader::call(std::string wfun)
{
    uint64_t position = 0;
    bool     found    = false;
    
    for (int i = 0; i < code_exports.size(); i++) {
        if (code_exports.at(i).name == wfun) {
            found    = true;
            position = code_exports.at(i).offset;
            break;
        }
    }
    
    if (!found)
    throw std::string("error: could not found entry point.\n");

    vmExec(image,codelen);
}

int MyCodeRunner::call(std::string fun)
{
    MyHeaderReader imgrd(lib_name);    
    imgrd.call(fun);
}
