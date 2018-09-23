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
#include "source/parser/misc.h"

QList< help_text_struct> help_text;   // help text info holder
QList< help_css_struct > help_css_content;

struct help_css_struct   help_css;
struct help_text_struct  help_current;

QString help_class_str;

// --------------------------------------------------
// wrapper procedure, to save code size and speed ...
// --------------------------------------------------
void help_setup_settings(void)
{
    help_current.text = "";
    help_current.isBold      = false;
    help_current.isItalic    = false;
    help_current.isUnderline = false;
    
    help_text.append(help_current);
}

// -------------------------------
// appends text to help widget ...
// -------------------------------
void help_append_text(char* txt)
{
    if (help_text.count() < 1)
    help_setup_settings();
    
    help_current.text = txt;
    help_text.append(help_current);
}
void help_append_char(char c)
{
    QChar ch  = c;
    QString t = ch;
    help_append_text(t.toLatin1().data());
}

// ----------------------------------------------
// set the current text object attribure bold ...
// ----------------------------------------------
void help_setBold(bool flag)
{
    if (!flag)
    { help_current.isBold = false; help_current.text = "</b>"; } else
    { help_current.isBold = true;  help_current.text = "<b>";  }
    
    help_text.append(help_current);
}

void help_append_css_class(char *txt)
{
    help_css.name = txt;
    help_css_content.append(help_css);
}

void help_append_css_text(char *hstr, char *txt)
{
    
}
