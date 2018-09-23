#ifndef MYSPLASHSCREEN_H
#define MYSPLASHSCREEN_H

#include <QObject>
#include <QWidget>
#include <QSplashScreen>

class MySplashScreen : public QSplashScreen
{
public:
    explicit MySplashScreen();
    
public slots:
    void closeSplash();
};

#endif // MYSPLASHSCREEN_H
