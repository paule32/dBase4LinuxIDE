#ifndef UPDATE_THREAD_H
#define UPDATE_THREAD_H

#include <QThread>

class update_thread : public QThread
{
    Q_OBJECT
public:
    explicit update_thread(QObject *parent = 0, bool b = false);
    void run();

    bool Stop;
    int  steps;

signals:
    void valueChanged(int);
};

#endif // UPDATE_THREAD_H
