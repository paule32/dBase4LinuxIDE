#include "source/includes/setup/delegate.h"

QWidget *
MyDelegate::createEditor(
    QWidget *parent, const
    QStyleOptionViewItem &option, const
    QModelIndex &index) const
{
    QCheckBox *editor = new QCheckBox(parent);

    editor->installEventFilter(const_cast<MyDelegate*>(this));
    return editor;
}
