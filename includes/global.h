#ifndef GLOBAL_H
#define GLOBAL_H

extern void yyerror(char*);
extern int  yyline;

enum dBase4LinuxOutputType {
    cvt_assembler = 0,
    cvt_cpp,
    cvt_html,
    cvt_css,
    cvt_javascript,
    cvt_math
};

extern dBase4LinuxOutputType filecvt_type;
#endif // GLOBAL_H

