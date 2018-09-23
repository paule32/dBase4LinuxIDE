#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDesktopServices>
#include <QStandardItemModel>
#include <QStatusBar>
#include <QSettings>

#include <QStandardItem>
#include <QStandardItemModel>

#include "source/includes/pch.h"
#include "source/includes/designer/scene.h"
#include "source/includes/designer/designergraphicsview.h"
#include "source/includes/designer/designeritem.h"
#include "source/includes/designer/components_draglist.h"
#include "source/includes/designer/events_and_methods.h"
#include "source/includes/editors/dbase/editorgutter.h"
#include "source/includes/help/helpdocker.h"
#include "source/includes/help/helpbrowser.h"
#include "source/includes/click.h"
#include "source/includes/keypress.h"
#include "source/includes/settings_dialog.h"
#include "source/includes/sql/newtabledefinitionplaceholder.h"
#include "source/includes/dbase/dbaseexception.h"
#include "source/includes/dbase/dbaselevel7.h"
#include "source/includes/BDE/localconnectdatabase.h"
#include "source/includes/sql/tablefieldpropertieswidget.h"
#include "source/includes/sql/sqlgraphicsdesigner.h"
#include "source/includes/asm/assembleredit.h"
#include "source/includes/asm/highlighter.h"

#include ".uic/ui_mainwindow.h"

#include "source/includes/asm/nasm.h"

extern int guiExceptionError;   // exception while GUI is open?

namespace Ui {
class MainWindow;
}

class AsmHighlighter;

class MainWindow : public QMainWindow
{
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
    Ui::MainWindow * getUserInterface() { return ui; }
    
    bool eventFilter(QObject *target, QEvent *event);
    void resizeEvent(QResizeEvent * event);
    void closeEvent(QCloseEvent   * event);

    void on_FileOpen(int state = 0);
    void on_SaveFile();
    void on_SaveFileAs();
    void on_AboutQt();
    void on_helpOpen();
    void on_OpenTablePath();

    void on_new_project();
    void on_actionEinstellungen();
public:
    //void keyPressEvent(QKeyEvent  * event);
    
    void addHelp(QString hlp);
    class HelpBrowser * helpBrowser;
    class MyEditor    * editor;
    
    QString fname;

    class components_draglist *components_drag;
    class events_and_methods  *eventsAmethods;

    class update_dbase *update;

    Ui::MainWindow *ui;

public slots:
    void on_actionBeenden_triggered();
    void on_dockHelpOpen();
    void on_dockEditOpen();
    void on_actionMake_executable_triggered();
    void on_x86click();
    void on_listScreensWidgetItemDblClicked(QListWidgetItem *);
    
    void ShowContextMenuProject();

private slots:
    void on_MainWindow_clicked();
    void on_toolButton_triggered(QAction *arg1);
    void on_toolButton_2_triggered(QAction *arg1);
    void on_toolButton_3_triggered(QAction *arg1);
    void on_toolButton_5_triggered(QAction *arg1);
    void on_toolButton_6_triggered(QAction *arg1);
    void on_toolButton_4_triggered(QAction *arg1);
    void on_LayoutView_itemActivated(QTreeWidgetItem *item, int column);
    void on_LayoutView_itemClicked(QTreeWidgetItem *item, int column);
    void on_toolButton_Project_pressed();
    void on_pushButton_7_clicked();
    void on_toolButton_8_clicked();
    void on_tabWidget_tabBarClicked(int index);
    void on_toolButton_Home_clicked();
    void on_toolButton_clicked();
    void on_toolButton_Project_clicked();
    void on_columnView_customContextMenuRequested(const QPoint &pos);
    void on_toolButton_Connect_clicked();
    void on_addSQLwindow_clicked();
    void on_toolButton_9_clicked();
    void on_tabWidget_currentChanged(int index);
    void on_toolButton_Welcome_triggered(QAction *arg1);
    void on_projectWidgetClicked();
    void on_projectWidgetDoubleClicked();
    void on_commandLinkButton_4_clicked();
    void on_commandLinkButton_3_clicked();
    void on_filterComboBoxIndexChanged(int index);
    void on_startCompilerButtonClicked();
    void on_MenuNew();
    void on_copyAct();
    void on_closeAct();
    void on_addFilesToSetup();
    void on_addLanguageToSetup();
    
private:
    QSplitter  * hsplit;
    QStandardItemModel * tableModel;

public:
    AssemblerEdit  * assembler;
    AsmHighlighter * highlighter;
    
    QWidget        * helpWindow;

    int helpCtx;
};

struct compileToIndex {
    enum type {
        cUnknown = 0,
        cForth,
        cBASIC,
        cDelphi,
        cGNUC,
        cDBase
    };
};

#endif
