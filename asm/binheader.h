#ifndef BINHEADER_H
#define BINHEADER_H

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <sys/types.h>

#include <iostream>
#include <fstream>
#include <iomanip>
#include <type_traits>
#include <map>
#include <vector>

#define EXPORT __attribute__((visibility("default")))
#define IMPORT

#include "source/includes/asm/asmjit/asmjit.h"
#include "source/includes/asm/asmtk/asmtk.h"

extern "C" void vmExec(uint8_t *img, size_t len);

constexpr int ASM32_MAGIC   = 0x19790208;
constexpr int ASM32_VERSION = 0x00000132;

struct dso_export_header {
    uint16_t    length = 0;
    uint64_t    offset = 0;
    uint8_t     lib_id = 0;
    std::string name;
    
    dso_export_header(uint16_t _length, uint64_t _offset, uint8_t _id, std::string _name)
        : length(_length)
        , offset(_offset)
        , lib_id(_id)
        , name(_name)
     { }
     
     dso_export_header() { }
};

struct dso_header_libs {
    uint16_t     length = 0;
    uint16_t     id     = 0;
    std::string  name;
    
    dso_header_libs(uint16_t _length, uint16_t _id, std::string _name)
        : name(_name)
        , id(_id)
        , length(_length)
    { }
};

struct dso_header {
    const uint32_t    magic     = ASM32_MAGIC;
    const uint32_t    version   = ASM32_VERSION;
    uint16_t          name_size = 0;
    std::string       name;
    uint16_t          id = 0;
    uint64_t          code_begin = 0;
    uint64_t          code_len   = 0;
    
    dso_header() { }
    dso_header(std::string _name, uint16_t _sz, uint8_t _tp)
        : name(_name)
        , name_size(_sz)
        , id(_tp)
    { }
};

extern std::vector<dso_header_libs>   code_libs;
extern std::vector<dso_export_header> code_exports;

#include "binreader.h"
#include "binwriter.h"

class MyCodeEmitter {
    void emitTest();
    std::string lib_name;
public:
    MyCodeEmitter(std::string _name);
    
    void write();
      
    asmjit::X86Compiler  x86_compiler;
    asmjit::X86Emitter * x86_emitter ;
    
    asmjit::JitRuntime   x86_runtime;
    asmjit::CodeHolder   x86_codeholder;
};

#endif
