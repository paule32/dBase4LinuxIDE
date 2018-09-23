#include "source/includes/dbase/procmakefile.h"
#include "source/includes/console/console.h"

MyMakefileProcess::MyMakefileProcess(Console * _crt, QString _prog, QStringList _args)
    : crt (_crt)
    , prog(_prog)
    , args(_args)
{
}

void MyMakefileProcess::processOutput()
{
    QByteArray out = readAllStandardOutput();
    QByteArray err = readAllStandardError ();

    crt->putData(out);
    crt->putData(err);
}
