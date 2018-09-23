#ifndef MENUSQLBUILDER_H
#define MENUSQLBUILDER_H

#include <QObject>
#include <QWidget>
#include <QMenu>
#include <QMenuBar>

class MenuSqlBuilder : public QMenuBar
{
public:
    explicit MenuSqlBuilder(QWidget *parent = 0);
};

#endif // MENUSQLBUILDER_H
