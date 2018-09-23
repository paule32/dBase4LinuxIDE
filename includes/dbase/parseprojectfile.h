#ifndef PARSEPROJECTFILE_H
#define PARSEPROJECTFILE_H

#include <QString>
#include "source/includes/dbase/mainwindow.h"

class parseProjectFile
{
public:
    parseProjectFile(MainWindow *w);
private:
    MainWindow *win = nullptr;
};

#endif // PARSEPROJECTFILE_H
