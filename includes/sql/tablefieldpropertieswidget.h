#ifndef TABLEFIELDPROPERTIESWIDGET_H
#define TABLEFIELDPROPERTIESWIDGET_H

#include <QObject>
#include <QWidget>
#include <QTableWidget>

class TableFieldPropertiesWidget : public QTableWidget
{
public:
    explicit TableFieldPropertiesWidget(QWidget * parent = 0);
    void init();
    void init(int mode);
    
private slots:
    void onComboBoxChanged(const QString &text);
};

#endif // TABLEFIELDPROPERTIESWIDGET_H
