// --------------------------------------------------------------------------------
// MIT License
//
// Copyright (c) 2018 Jens Kallup
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
// --------------------------------------------------------------------------------
#include "source/includes/dbase/mainwindow.h"
#include "source/includes/dbase/mainclass.h"
#include "source/includes/asm/codeeditor.h"
#include "source/includes/settings_dialog.h"
#include "source/includes/console/console.h"
#include "source/includes/wizard/newprojectassistent.h"

#include "source/includes/dbase/parseprojectfile.h"

#include "source/includes/asm/assembleredit.h"
#include "source/includes/asm/highlighter.h"

#include "source/includes/help/mywebbrowser.h"

#include "source/parser/basic/basic.h"

#include "ui_settings_dialog.h"

#include "source/includes/asm/nasm.h"

#include <QWidget>
#include <QIcon>
#include <QTabWidget>
#include <QAbstractButton>
#include <QComboBox>
#include <QCommandLinkButton>
#include <QPlainTextEdit>
#include <QTreeWidget>
#include <QListWidget>
#include <QListWidgetItem>
#include <QStandardItem>
#include <QByteArray>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

#include "source/includes/setup/delegate.h"
#include "source/includes/setup/downloader.h"

#include "source/includes/help/helpbrowser.h"

extern  QString pro_target_path;

QVector<forthStruct> forthScreenList(100);
int forthListBefore  = 0;

compileToIndex::type compileToLang = compileToIndex::cUnknown;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    helpCtx = 0;
    
    installEventFilter(this);
    //editor = ui->editorWidget;
    
    connect(ui->actionMake_executable,
            &QAction::triggered,
            this,
            &MainWindow::on_actionMake_executable_triggered);
    connect(ui->cmdButtonMakeExe,
            &QCommandLinkButton::clicked,
            this,
            &MainWindow::on_actionMake_executable_triggered);
           
    // compile to ... 
    connect(ui->startCompilerButton,
            &QAbstractButton::clicked,
            this,
            &MainWindow::on_startCompilerButtonClicked);
    
    connect(ui->filterComboBox,
    static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
    [=](int index){
        on_filterComboBoxIndexChanged(index);
    });
    
    connect(ui->listScreenWidget,
            &QListWidget::itemDoubleClicked,
            this,
            &MainWindow::on_listScreensWidgetItemDblClicked);

    /*
    connect(ui->cmdLinkButtonNewProject,
            &QCommandLinkButton::clicked,
            this,
            &MainWindow::on_new_project);
    */
    
    connect(ui->actionMenuNew,
            &QAction::triggered,
            this,
            &MainWindow::on_MenuNew);

    connect(ui->addFilesToSetup,
            &QAbstractButton::clicked,
            this,
            &MainWindow::on_addFilesToSetup);
    connect(ui->addLanguageToSetup,
            &QAbstractButton::clicked,
            this,
            &MainWindow::on_addLanguageToSetup);
            
    connect(ui->helpToolButton,
            &QToolButton::clicked,
            this,
            &MainWindow::on_helpOpen);

    connect(ui->actionOpen_File,
            &QAction::triggered,
            this,
            &MainWindow::on_FileOpen);

    connect(ui->actionSpeichern,
            &QAction::triggered,
            this,
            &MainWindow::on_SaveFile);

    connect(ui->actionSpeichern_unter,
            &QAction::triggered,
            this,
            &MainWindow::on_SaveFileAs);

    connect(ui->actionAbout_Qt,
            &QAction::triggered,
            this,
            &MainWindow::on_AboutQt
            );

    connect(ui->actionEinstellungen,
            &QAction::triggered,
            this,
            &MainWindow::on_actionEinstellungen
            );

    ui->projectTreeWidget->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->projectTreeWidget,
            &QTreeWidget::customContextMenuRequested,
            this,
            &MainWindow::on_projectWidgetClicked);
    connect(ui->projectTreeWidget,
            &QTreeWidget::itemDoubleClicked,
            this,
            &MainWindow::on_projectWidgetDoubleClicked);
            
    // open project ...
    connect(ui->commandLinkButton_3,
            &QCommandLinkButton::clicked,
            this,
            &MainWindow::on_commandLinkButton_3_clicked);
            
    connect(ui->toolButton_Project,
            &QWidget::customContextMenuRequested,
            this,
            &MainWindow::ShowContextMenuProject);


    connect(ui->pushButton_8,
            &QPushButton::clicked,
            this,
            &MainWindow::on_addSQLwindow_clicked);
    
    
    connect(ui->toolButton_Welcome,
            &QToolButton::clicked,
            this,
            &MainWindow::on_toolButton_8_clicked
            );
            
    connect(ui->toolButton_Home,
            &QToolButton::clicked,
            this,
            &MainWindow::on_toolButton_Home_clicked
            );
            
    connect(ui->toolButton_Connect,
            &QToolButton::clicked,
            this,
            &MainWindow::on_toolButton_Connect_clicked
            );
            
    connect(ui->openTableButton,
            &QToolButton::clicked,
            this,
            &MainWindow::on_toolButton_clicked);
            
    connect(ui->connectBDE,
            &QToolButton::clicked,
            this,
            &MainWindow::on_toolButton_9_clicked);

    connect(ui->tblOpenPath,
            &QToolButton::clicked,
            this,
            &MainWindow::on_OpenTablePath);
            
    connect(ui->x86RadioButton,
            &QRadioButton::clicked,
            this,
            &MainWindow::on_x86click);

    ui->ErrorOutputWidget->setColumnWidth(0,24);
    ui->ErrorOutputWidget->setColumnWidth(1,450);
    ui->ErrorOutputWidget->setColumnWidth(2,140);
    ui->ErrorOutputWidget->setColumnWidth(3,64);
    
    ui->ErrorOutputWidget->setRowHeight(0,22);
       
    // customized ...
    ui->tableWidget_Create  -> init();
    ui->tblFieldTableWidget -> init();
    ui->columnView          -> init();
    
    ui->lineNumberPanelColorButton -> init(ui->previewTextEdit,"lineNumberPanelColor");
    ui->lineNumberFontColorButton  -> init(ui->previewTextEdit,"lineNumberFontColor");
    ui->fontColorButton            -> init(ui->previewTextEdit,"fontColor");
    ui->currentLineColorButton     -> init(ui->previewTextEdit,"currentLineColor");
    ui->backgroundColorButton      -> init(ui->previewTextEdit,"backgroundColor");
    ui->debugLineColorButton       -> init(ui->previewTextEdit,"debugLineColor");
    //
    ui->keywordsColorButton  -> init(ui->previewTextEdit,"fg_keywordsColor");  ui->keywordsColorButton_2  -> init(ui->previewTextEdit,"bg_keywordsColor");
    ui->registersColorButton -> init(ui->previewTextEdit,"fg_registersColor"); ui->registersColorButton_2 -> init(ui->previewTextEdit,"bg_registersColor");
    ui->numbersColorButton   -> init(ui->previewTextEdit,"fg_numbersColor");   ui->numbersColorButton_2   -> init(ui->previewTextEdit,"bg_numbersColor");
    ui->memoryColorButton    -> init(ui->previewTextEdit,"fg_memoryColor");    ui->memoryColorButton_2    -> init(ui->previewTextEdit,"bg_memoryColor");
    ui->labelsColorButton    -> init(ui->previewTextEdit,"fg_labelsColor");    ui->labelsColorButton_2    -> init(ui->previewTextEdit,"bg_labelsColor");
    ui->commentsColorButton  -> init(ui->previewTextEdit,"fg_commentsColor");  ui->commentsColorButton_2  -> init(ui->previewTextEdit,"bg_commentsColor");
    ui->systemColorButton    -> init(ui->previewTextEdit,"fg_systemColor");    ui->systemColorButton_2    -> init(ui->previewTextEdit,"bg_systemColor");
    ui->iomacroColorButton   -> init(ui->previewTextEdit,"fg_iomacroColor");   ui->iomacroColorButton_2   -> init(ui->previewTextEdit,"bg_iomacroColor");
    ui->quotationColorButton -> init(ui->previewTextEdit,"fg_quotationColor"); ui->quotationColorButton_2 -> init(ui->previewTextEdit,"bg_quotationColor");
    //
    ui->panelCheckBox        -> init(ui->lineNumberPanelColorButton, ui->previewTextEdit,"lineNumberPanelColor");
    ui->lineFontCheckBox     -> init(ui->lineNumberFontColorButton,  ui->previewTextEdit,"lineNumberFontColor");
    ui->fontColorCheckBox    -> init(ui->fontColorButton,            ui->previewTextEdit,"fontColor");
    ui->currentLineCheckBox  -> init(ui->currentLineColorButton,     ui->previewTextEdit,"currentLineColor");
    ui->backgroundCheckBox   -> init(ui->backgroundColorButton,      ui->previewTextEdit,"backgroundColor");
    ui->debugLineCheckBox    -> init(ui->debugLineColorButton,       ui->previewTextEdit,"debugLineColor");
    
    CodeEditor * ce = new CodeEditor(ui->AsmEditor);
    ce->setParent(ui->AsmEditor);
    ce->setGeometry(0,0,296,270);
    ce->setVisible(true);
    
    if (assembler == nullptr)
        assembler  = new NASM(true);
    highlighter = new AsmHighlighter(assembler, ce->document());
    highlighter->init(dynamic_cast<MainWindow*>(this));
    
    
    ui->DesignerTabWidget->setVisible(false);
    
    QSettings settings("dBase4Linux","dbase");
    QString startText = settings.value("starttext", QString()).toString();
    if (startText.isEmpty()) {
        settings.setValue("starttext", assembler->getStartText());
        startText = assembler->getStartText();
    }
    
    if (settings.value("x86build", true) == true)
    ui->x86RadioButton->setChecked(true); else
    ui->x64RadioButton->setChecked(true);


    // editor tab
    ui->editorLayoutWidget->setVisible(false);
    ui->editorLayoutWidget->setEnabled(false);

    ui->openFilesList->hide();    
    
    ui->tabWidget->setCurrentIndex(0);
	showMaximized();


/*
    update = new update_dbase(dynamic_cast<QDialog*>(this));
    update->show();
    update->exec();*/
}


MainWindow::~MainWindow() {
    delete highlighter;
    delete assembler;
    delete ui;
    delete tableModel;
}

void MainWindow::resizeEvent(QResizeEvent* event) {
//    ui->editPage->resize(width(), height());
    QMainWindow::resizeEvent(event);
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    QMessageBox::StandardButton  btn;
    QMessageBox::StandardButtons btns=(
    QMessageBox::Yes |
    QMessageBox::Cancel); btn=
    QMessageBox::question(this,tr("Attention"),tr("You would like to Exit the application?"),btns);

    if (btn == QMessageBox::Yes)    { event->accept(); close(); } else
    if (btn == QMessageBox::Cancel) { event->ignore(); }

    if (ui->EditorWidget->document()->isModified()) {
        ui->EditorWidget->document()->setModified(true);
        on_FileOpen(1);
    }
}

bool MainWindow::eventFilter(QObject *target, QEvent *event)
{
    event->accept();
    
    if (event->type() == QEvent::KeyPress)
    {   QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
        switch (keyEvent->key())
        {
        case Qt::Key_F1:
            {   addHelp("./help/index.html");
                return true;
            }
            break;

        case Qt::Key_F9:
            on_actionMake_executable_triggered();
            break;
            
        case Qt::Key_Escape:
            { //  delHelpPanel();
              //  addEditPanel();
              //  return true;
            }
            close();
            return true;
            break;
        }
    }
    return QMainWindow::eventFilter(target,event);
}

void MainWindow::on_dockHelpOpen()
{ //  delEditPanel();
    //addHelpPanel();
}

void MainWindow::on_dockEditOpen()
{
}

void MainWindow::addHelp(QString page)
{
    //if   ( helpBrowser != nullptr)
    //delete helpBrowser ;

    helpBrowser = new HelpBrowser(page,ui->helpTextBrowser);
}

void MainWindow::on_AboutQt() {
    QApplication::aboutQt();
}

void MainWindow::on_SaveFile()
{
    if (ui->delphiWidget->isActiveWindow()) {
        ui->EditorWidget->document()->setModified(false);
        fname = ui->delphiEditorWidget->documentTitle();
    }   else
    if (ui->EditorWidget->document()->isModified()) {
        ui->EditorWidget->document()->setModified(false);
        fname = ui->EditorWidget->documentTitle();
    }
    
    if (fname.length() < 1) {
        fname = QFileDialog::getSaveFileName(
        this,
        tr("Save File"),
        QString(QDir::homePath() + fname),
        "Pascal    *.pas (*.pas);;"
        "Forms     *.frm (*.frm);;"
        "Programs  *.prg (*.prg);;"
        "All Files *.* (*.*)");
    }
    
    if (fname.length() > 1) {
        QFile f(fname); f.open(
        QIODevice::WriteOnly  |
        QIODevice::Truncate   |
        QIODevice::Text);
        
        QString src;
        
        if (fname.lastIndexOf(".pas") > -1)
        src = ui->delphiEditorWidget->document()->toPlainText(); else
        src = ui->EditorWidget      ->document()->toPlainText();
        
        QTextStream out(&f);
        out.setCodec("UTF-8");
        out.setGenerateByteOrderMark(false);
        out << src;
        
        f.close();
    }
}

void MainWindow::on_SaveFileAs()
{
    //if (editor->document()->isModified())
    fname = QFileDialog::getSaveFileName(
        this,
        tr("Save File As ..."),
        QString(QDir::homePath()),
        "Pascal    *.pas (*.pas);;"
        "Forms     *.frm (*.frm);;"
        "Programs  *.prg (*.prg);;"
        "All Files *.* (*.*)");
    
    qDebug() << "before: " << fname;
    
    if (fname.length() > 1) {
        QFile f(fname); f.open(
        QIODevice::WriteOnly  |
        QIODevice::Truncate   |
        QIODevice::Text);

        if (!f.isOpen())
        throw new dBaseError("file can not be saved");
        
        QString src;
        
        if (fname.lastIndexOf(".pas") > -1)
        src = ui->delphiEditorWidget->document()->toPlainText(); else
        src = ui->EditorWidget      ->document()->toPlainText();

        QTextStream out(&f);
        out.setCodec("UTF-8");
        out.setGenerateByteOrderMark(false);
        out << src;
        
        if (fname.lastIndexOf(".pas") > -1)
        ui->delphiEditorWidget->setDocumentTitle(fname); else
        ui->EditorWidget      ->setDocumentTitle(fname);

        qDebug() << "after: " << fname;
        qDebug() << "bytes: " << src.size();
        
        f.close();
    }
}


void MainWindow::on_FileOpen(int state)
{
    QString fname;

    if (ui->delphiWidget->isActiveWindow()) {
        ui->delphiEditorWidget->document()->setModified(false);
        fname = ui->delphiEditorWidget->documentTitle();
    }   else
    if (ui->EditorWidget->document()->isModified()) {
        ui->EditorWidget->document()->setModified(false );
        fname = ui->EditorWidget->documentTitle();
    }
    
    if (fname.length() < 1) {
        fname = QFileDialog::getSaveFileName(
            this,
            tr("Save File"),
            QString(QDir::homePath() + fname),
                "Pascal    *.pas (*.pas);;"
            "Forms     *.frm (*.frm);;"
            "Programs  *.prg (*.prg);;"
            "All Files *.* (*.*)");
    }
    
    QFile f(fname); f.open(
    QIODevice::WriteOnly  |
    QIODevice::Truncate   |
    QIODevice::Text);

    QString src;

    if (fname.lastIndexOf(".pas") > -1)
    src = ui->delphiEditorWidget->document()->toPlainText(); else
    src = ui->EditorWidget      ->document()->toPlainText();

    QTextStream out(&f);
    out.setCodec("UTF-8");
    out.setGenerateByteOrderMark(false);
    out << src;

    f.close();

    if (state == 1)  return ;
    
    QString dname = QDir::homePath();
    fname = QFileDialog::getOpenFileName(
        this,
        tr("Open File"),
        dname,
        "Pascal    *.pas (*.pas);;"
        "Forms     *.frm (*.frm);;"
        "Programs  *.prg (*.prg);;"
        "All Files *.* (*.*)");

    if (fname.size() < 1)
    return;

    if (fname.lastIndexOf(".pas") > -1)
    ui->delphiEditorWidget->setDocumentTitle(fname); else
    ui->EditorWidget      ->setDocumentTitle(fname);

    f.setFileName(fname);
    f.open(QIODevice::ReadOnly | QIODevice::Text); QByteArray barr=
    f.readAll();
    f.close();

    if (fname.lastIndexOf(".pas") > -1) {
        ui->delphiEditorWidget->clear();
        ui->delphiEditorWidget->insertPlainText(barr.data());
        ui->delphiEditorWidget->document()->setModified(false);
    } else {
        ui->EditorWidget->clear();
        ui->EditorWidget->insertPlainText(barr.data());
        ui->EditorWidget->document()->setModified(false);
    }
}

void MainWindow::on_actionBeenden_triggered()
{
    if (editor->document()->isModified())
    on_FileOpen(1);
    close();
}

void MainWindow::on_MainWindow_clicked()
{
    on_dockEditOpen();
}

void MainWindow::on_actionEinstellungen()
{
//    Settings *se = new SettingsDialog(this);
//    se->show();
  

//    delete  se;
}

void MainWindow::on_toolButton_triggered(QAction *arg1)
{
    qDebug() << "Home";
}

void MainWindow::on_toolButton_2_triggered(QAction *arg1)
{
    qDebug() << "Edit";
}

void MainWindow::on_toolButton_3_triggered(QAction *arg1)
{
    qDebug() << "Design";
}

void MainWindow::on_toolButton_5_triggered(QAction *arg1)
{
    qDebug() << "Help";
}

void MainWindow::on_toolButton_6_triggered(QAction *arg1)
{
    qDebug() << "Run";
}

void MainWindow::on_toolButton_4_triggered(QAction *arg1)
{
    qDebug() << "Build";
}

void MainWindow::on_LayoutView_itemActivated(QTreeWidgetItem *item, int column)
{
    qDebug() << item->text(0) << column;
}

void MainWindow::on_LayoutView_itemClicked(QTreeWidgetItem *item, int column)
{
    qDebug() << item->text(0) << column;
}




void MainWindow::ShowContextMenuProject()
{
    QPoint globalPos = mapFromGlobal(QCursor::pos());
    QMenu myPopUp;

    QAction *sess1 = new QAction("Last Session ...");
    QFont font;
    
    font.setBold(true);
    sess1->setFont(font);
    myPopUp.addAction(sess1);
    
    myPopUp.addSeparator();
    myPopUp.addAction("Session 2 - ProjectA");
    myPopUp.addAction("Session 3 - ProjectB");
    myPopUp.addAction("Session 4 - ProjectC");
    myPopUp.setObjectName("myPopUp");
    myPopUp.setStyleSheet(
R"(

#myPopUp {
font-size: 12pt;
font-weight: bold;
color: #333;
border: 2px solid #555;
border-radius: 11px;
padding: 5px;
background: qradialgradient(cx: 0.3, cy: -0.4,
fx: 0.3, fy: -0.4,
radius: 1.35, stop: 0 #fff, stop: 1 #888);
min-width: 80px;
}
QMenu:hover:#myPopUp {
background: qradialgradient(cx: 0.3, cy: -0.4,
fx: 0.3, fy: -0.4,
radius: 1.35, stop: 0 #fff, stop: 1 #bbb);
}
QMenu:pressed:#myPopUp {
background: qradialgradient(cx: 0.4, cy: -0.1,
fx: 0.4, fy: -0.1,
radius: 1.35, stop: 0 #fff, stop: 1 #ddd);
}
)");
      
    QAction* selectedItem = myPopUp.exec(globalPos);
    if (selectedItem == nullptr)
    return;    
}

void MainWindow::on_toolButton_Project_pressed()
{
    ShowContextMenuProject();
}

void MainWindow::on_pushButton_7_clicked()
{
    QDesktopServices::openUrl(QUrl(
    "https://www.paypal.com/cgi-bin/webscr/?"
    "hosted_button_id=FBESEMEXP8HSL&"
    "cmd=_s-xclick"
    ));
}

void MainWindow::on_toolButton_8_clicked()
{
    ui->welcomeLabel->setVisible(false);
    ui->introPage->setVisible(false);
    ui->welcomeWidget->setVisible(false);
    
    ui->welcomeLabel->setVisible(false);
    
    ui->EditorTab->setVisible(false);
    
    ui->DesignerTabWidget->setVisible(true);
    ui->DesignerTabWidget->setMinimumHeight(200);
    
    //ui->tabWidget->setVisible(true);
    ui->welcomeWidget->setVisible(true);
    ui->welcomeWidget->setFocus();
}

void MainWindow::on_tabWidget_tabBarClicked(int index)
{
    if (index == 0) {
        ui->welcomeLabel->setVisible(true);
        ui->introPage->setVisible(true);
        ui->DesignerTabWidget->setVisible(false);
    }
}

void MainWindow::on_toolButton_Home_clicked()
{
    on_tabWidget_tabBarClicked(0);
}

void MainWindow::on_toolButton_clicked()
{
    QString filename =
    QFileDialog::getOpenFileName(
    this,
    tr("Open Database File"),
    QString(QDir::homePath()),
    "Tables *.dbf (*.dbf);;SQL *.sql (*.sql);;All Files *.* (*.*)");
    
    if (filename.trimmed().length() < 1)
    throw dBaseError("open filename segfault.");
    
    if (!filename.toLower().endsWith(".dbf"))
    throw dBaseError("Database file name not supported");

    
}

void MainWindow::on_toolButton_Project_clicked()
{
qDebug() << "sdsdsd";
}

void MainWindow::on_columnView_customContextMenuRequested(const QPoint &pos)
{
    QPoint globalPos = mapFromGlobal(QCursor::pos());
    QMenu myPopUp;

    QAction *sess1 = new QAction("Last Session ...");
    QFont font;
    
    font.setBold(true);
    sess1->setFont(font);
    myPopUp.addAction(sess1);
    
    myPopUp.addSeparator();
    myPopUp.addAction("Session 2 - ProjectA");
    
    QAction* selectedItem = myPopUp.exec(globalPos);
    if (selectedItem == nullptr)
    return;    
}

void MainWindow::on_toolButton_Connect_clicked()
{
    auto *lp = new LocalConnectDataBase(this);
    lp->exec();
    delete lp;
}

void MainWindow::on_toolButton_9_clicked()
{
    qDebug() << "sss";
}

void MainWindow::on_addSQLwindow_clicked()
{
    DesignerSQLwindow * win2 = new
    DesignerSQLwindow(QRect(50,50,100,100),
    ui->SQLgraphicsView->getScene());
}

void MainWindow::on_tabWidget_currentChanged(int index)
{
    
}

void MainWindow::on_toolButton_Welcome_triggered(QAction *arg1)
{
    
}

void MainWindow::on_OpenTablePath()
{
    QString dir = QFileDialog::getExistingDirectory(
    this, tr("Open Directory"),
    "/home",
    QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    
    ui->folderWithTables->addItem(dir);
}

// source/parser/delphi.ypp:
extern int delphimain(QString);
void MainWindow::on_actionMake_executable_triggered()
{
    QString pptr;
    
    if (ui->delphiWidget->isActiveWindow())
    pptr = ui->delphiEditorWidget->documentTitle(); else
    
    if (ui->EditorWidget->isActiveWindow())
    pptr = ui->EditorWidget->documentTitle();
    
    if (pptr.isEmpty()) {
        on_SaveFile();
    }

    if (ui->delphiWidget->isActiveWindow()) {
        if (ui->delphiEditorWidget->document()->isModified()) {
            ui->delphiEditorWidget->document()->setModified(false);
            QFile f(fname);
            if (!f.open(QIODevice::WriteOnly)) {
                QMessageBox::warning(this,
                "System Error !!!",
                "Could not save your text to storage.\n"
                "Please check your permisson's.");
                return;
            }
            
            QTextStream out(&f);
            out.setCodec("UTF-8");
            out << ui->delphiEditorWidget->document()->toPlainText();
            
            f.close();
        }
    
        int  res = 0;
        if ((res = delphimain(fname)) < 1) {
            QMessageBox::information(
            this,
            "Information",
            "Parser Success, no errors.");
        }
    }
}

void MainWindow::on_commandLinkButton_4_clicked()
{
    on_actionMake_executable_triggered();
}

void MainWindow::on_new_project()
{
    parseProjectFile pro(this);
}

void MainWindow::on_helpOpen()
{
    //MyHelpBrowser * whelp = new
    //MyHelpBrowser(ui->javascriptWidget);
}

void MainWindow::on_x86click()
{
    QSettings settings("dBase4Linux","dbase");
    settings.setValue("x86build",true);
}

extern int promain(MainWindow *w, QString file);
void MainWindow::on_commandLinkButton_3_clicked()
{
    QFileDialog dia(this);
    dia.setFileMode(QFileDialog::AnyFile);
    dia.setNameFilter("Project Files (*.pro)");
    
    QString filename =
    QFileDialog::getOpenFileName(
    this,
    tr("Open Project File"),
    QString(QDir::homePath()),
    "Project Files *.pro (*.pro);;All Files *.* (*.*)");
    
    if (filename.trimmed().length() < 1) {
        QMessageBox::warning(this,
        "Open File Error !!!",
        QString("Could not open file: '%1'")
        .arg(filename));
        return;
    }
    promain(this,filename);
}

void MainWindow::on_projectWidgetClicked()
{
    QPoint globalPos = mapFromGlobal(QCursor::pos());
    QMenu  myPopUp;

    myPopUp.addAction("Copy");
    myPopUp.addSeparator();
    myPopUp.addAction("Close");
      
    QAction* selectedItem = myPopUp.exec(globalPos);
    if (selectedItem == nullptr) {
        QMessageBox::critical(this,
        "Memory Allocation Error",
        "could not get item");
        return;
    }
    
    if (selectedItem->text() == QString("Copy" )) { on_copyAct(); } else
    if (selectedItem->text() == QString("Close")) { on_closeAct(); }
}

void MainWindow::on_copyAct()
{
    QMessageBox::information(this,
    "Inform",
    "CopyAct");
}

void MainWindow::on_closeAct()
{
    QMessageBox::information(this,
    "Inform",
    "closeAct");
}

void MainWindow::on_projectWidgetDoubleClicked()
{
    QTreeWidgetItem * item = ui->projectTreeWidget->currentItem();
    if (item == nullptr)
    return;

    if (item->text(0).contains("[master]"))         return;
    if (item->text(0).contains("Unit's"))           return;
    if (item->text(0).contains("Designer Form's"))  return;

    QString file_name = pro_target_path;
    file_name.append(
    QString("/%1").arg(item->text(0))); qDebug() << file_name;
    
    QFileInfo f1(file_name);
    if (!f1.exists()) {
        QMessageBox::warning(this,
        "System Error !!!",
        "The requested file could not be open.\n"
        "May be, your project .pro file is currupted.\n"
        "Or the file does not exists.\n"
        "Please check your permissions, too.");
        return;
    }
    
    QFile f2(file_name);
    if (!f2.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this,
        "System Error !!!",
        "Could not open requested file in step 2.\n"
        "Please check your permission's.");
        return;
    }
    
    QByteArray ba =
    f2.readAll();
    f2.close();

    ui->delphiEditorWidget->document()->clear();
    ui->delphiEditorWidget->insertPlainText(ba.data());
    ui->delphiEditorWidget->setDocumentTitle(file_name);
    
    ui->tabWidget->setCurrentIndex(1);
}

void MainWindow::on_MenuNew()
{
    auto *pa = new NewProjectAssistent2(this);
    pa->exec();
}

void MainWindow::on_filterComboBoxIndexChanged(int index)
{
    switch (index) {
    case 0: {
        ui->openFilesList->hide();
        ui->projectTreeWidget->show();
    }
    break;
    case 1: {
        ui->projectTreeWidget->hide();
        ui->openFilesList->show();
    }
    break;
    default:
    break;
    }
    
    QMessageBox::information(this, "Eine Information","blub");
}

void MainWindow::on_startCompilerButtonClicked()
{

    int compile_to_index = ui->compileToComboBox->currentIndex();
        
    switch (compile_to_index) {
        case 0:  { compileToLang = compileToIndex::cForth;   } break;
        case 1:  { compileToLang = compileToIndex::cBASIC;   } break;
        default: { compileToLang = compileToIndex::cUnknown; } break;
    }
    
    // ---------------
    // BASIC -> ...
    // ---------------
    if (ui->delphiWidget->currentIndex() == 2) {
        QString filename;
        if (ui->basicEditorWidget->documentTitle().trimmed().size() < 1)
        filename = "unnamed.bas"; else
        filename = ui->basicEditorWidget->documentTitle();
        ui->basicEditorWidget->setDocumentTitle(filename);
        
        basicmain(this,filename);
    }
}

void MainWindow::on_listScreensWidgetItemDblClicked(QListWidgetItem *ic)
{
    Q_UNUSED(ic)
    int row = ic->listWidget()->currentRow();
    
    forthScreenList.at(forthListBefore).saved_text =
    ui->basicEditorWidget->document()->toPlainText();
      
    ui->basicEditorWidget->setPlainText(
    forthScreenList.at(row).saved_text);
    
    forthListBefore =  row;
    ui->basicEditorWidget->setFocus();
}

void MainWindow::on_addFilesToSetup()
{
    static int row_count = 0;

    auto *item0 = new QTableWidgetItem("item2");
    item0->setCheckState(Qt::Checked);

    ++row_count;

    ui->setupFilesWidget->setRowCount(row_count);
    ui->setupFilesWidget->setItem    (row_count-1,0,item0);
}

void MainWindow::on_addLanguageToSetup()
{
    QList<QStandardItem *> items;

    static int item_row = 0;
    static int item_col = 0;

    if (item_row >= 5)
    return;

    //items.append(new QStandardItem("Column 1 Text"));
    //items.append(new QStandardItem("Column 2 Text"));

    static QStandardItemModel * model = nullptr;
    if (model == nullptr) {
        model = new QStandardItemModel(5,5,this);
        ui->projectLangItemsForSetup->setModel(model);
        ui->projectLangItemsForSetup->setIconSize(QSize(45,45));

        ui->projectLangItemsForSetup->horizontalHeader()->hide();
        ui->projectLangItemsForSetup->verticalHeader  ()->hide();

        ui->projectLangItemsForSetup->setShowGrid(false);
        ui->projectLangItemsForSetup->setEditTriggers(QAbstractItemView::NoEditTriggers);

        ui->projectLangItemsForSetup->setStyleSheet(
        "QTableView::item{background-color:white;}"
        "QTableView::item::selected{background-color:white;}");

        struct world__flags {
            QString land;
            QString pic;
        };
        QVector<world__flags> wflags = {
            { tr("English"), "gb" },
            { tr("France") , "fr" },
            { tr("German") , "de" },
            { tr("Italy")  , "it" },
            { tr("Spain")  , "es" }
        };

        QString surl = ":/images/flagen";
        QString wurl;

        for (auto f: wflags)
        {
            wurl = surl;
            wurl.append(QString("/%1.png").arg(f.pic));

            QStandardItem * item = new QStandardItem(QIcon(wurl),f.pic);
            item->setData(Qt::Unchecked, Qt::CheckStateRole);
            item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
            model->setItem(item_row, item_col, item);

            ++item_col;
        }


        /*
        int i = 0;
        for (i = 0; i < wflags.count(); ++i)
        {
            if (item_col >=  5)  {
                item_col  = -1;
                item_row +=  1;
            }

            wurl = surl;
            wurl.append(QString("/%1.png").arg(wflags.at(i).pic));

            auto * downFlag = new MyDownloader(QUrl(wurl));
            pmap.loadFromData(downloadedData,"png");

            ++item_col;

            QStandardItem *item = new QStandardItem(QIcon(pmap),wflags.at(i).pic);
            item->setData(Qt::Unchecked, Qt::CheckStateRole);
            item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
            model->setItem(item_row, i, item);

            QMessageBox::information(this,"1111","222");
        }*/
    }
}



