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
#ifndef ASM32_H_
#define ASM32_H_

#ifndef BUILD_CLI
# include "source/includes/asm/asmjit/asmjit.h"
# include "source/includes/asm/asmtk/asmtk.h"
#else
# include "asmjit/asmjit.h"
# include "asmtk/asmtk.h"
#endif

#define ASM32_MAGIC    0x19790208
#define ASM32_VERSION  0x01

struct dso_export_header {
    uint32_t offset;
    char   * name;
};

struct dso_library_header {
    uint32_t id;
    char   * name;
    struct   dso_export_header  * func;
    struct   dso_library_header * next;
};

struct dso_header {
    uint32_t magic;
    uint32_t version;
    struct   dso_library_header * libs;
};

extern struct dso_header asm32_header;
#endif
