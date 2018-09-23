#ifndef DELEGATE_H
#define DELEGATE_H
#pragma once

#include <QObject>
#include <QWidget>
#include <QCheckBox>
#include <QModelIndex>
#include <QStyleOptionViewItem>
#include <QItemDelegate>

class MyDelegate : public QItemDelegate
{
public:
    MyDelegate(QObject *parent = 0) { }

    QWidget *createEditor(
        QWidget *parent,
        const QStyleOptionViewItem & option,
        const QModelIndex &index) const;
};

#endif
