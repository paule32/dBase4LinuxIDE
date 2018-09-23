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
#ifndef MISCH
#define MISCH

#include <QString>
#include <QFont>
#include <QList>

// -----------------------------------------
// structure holder for text information ...
// -----------------------------------------
struct help_css_struct {
    QString name;
    QStringList values;
};

struct help_text_struct {
    QString text;
    QFont font;
    bool isBold = false;
    bool isItalic = false;
    bool isUnderline = false;
};

extern QList< help_text_struct> help_text;   // help text info holder
extern QList< help_css_struct > help_css_content;

extern struct help_css_struct   help_css;
extern struct help_text_struct  help_current;

extern void help_setup_settings(void);
extern void help_append_text(char* txt);
extern void help_append_char(char c);
extern void help_append_css_class(char *txt);
extern void help_append_css_text (char*,char*);
extern void help_setBold(bool flag);

extern QString help_class_str;
#endif
