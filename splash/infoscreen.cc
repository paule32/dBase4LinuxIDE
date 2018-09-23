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
#include <QMessageBox>
#include <QAction>

#include <QtNetwork/QAbstractSocket>
#include <QtNetwork/QSslSocket>
#include <QtNetwork/QSslError>

#include "source/includes/splash/infoscreen.h"
#include "ui_infoscreen.h"

#include "source/includes/ssl/qsslserver.h"
#include "source/includes/ssl/qsslclient.h"

#include "source/includes/quazip/quazipfile.h"

#include <QDesktopServices>
#include <QDebug>

LizenzDialog::LizenzDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LizenzDialog)
{   ui->setupUi(this);
    ui->textBrowser->setHtml(getZipContent("info.html"));
    on_pushButton_2_clicked();

    exit_code = 1;
}

LizenzDialog::~LizenzDialog() { delete ui; }

void LizenzDialog::on_buttonBox_clicked(QAbstractButton *button)
{
    qDebug() << "button: " << button->text();
    if (button->text() == QString("&Cancel")) {
        exit_code = 1;
    }
    if (!ui->checkBox->isChecked()) {
        exit_code = 1;
    }
    else {
        if (button->text() == "&OK")
        exit_code = 0; else
        exit_code = 1;
    }

    close();
}

void LizenzDialog::on_pushButton_clicked()
{
    QDesktopServices::openUrl(QUrl(
    "https://www.paypal.com/cgi-bin/webscr/?"
    "hosted_button_id=FBESEMEXP8HSL&"
    "cmd=_s-xclick"
    ));

//    QSslServer *server = new
//    QSslServer; server->start_listen(8179);

//    QSslClient *client = new
//    QSslClient; client->connectToServer(8179);
}

QString LizenzDialog::getZipContent(QString hfile)
{
    QByteArray inhalt;

    QuaZip zip(":/ssl/ssl/info.zip");
    zip.open(QuaZip::mdUnzip);
    zip.setCurrentFile(hfile);

    QuaZipFile file(&zip);
    file.open(QIODevice::ReadOnly); inhalt =
    file.readAll();
    file.close();

    return QString(inhalt.data());
}

void LizenzDialog::on_pushButton_2_clicked()
{
    static int flag = 0;

    if (!flag) {
        ui->pushButton_2->setText("GNU - Manifest");
        ui->textBrowser_2->setHtml(getZipContent("gpl.html"));
        flag = 1;
    }   else
    if (flag == 1) {
        ui->pushButton_2 ->setText("Manifest - Ausblenden");
        ui->textBrowser_2->setHtml(getZipContent("manifest.html"));
        flag = 2;
    }   else
    if (flag == 2) {
        ui->pushButton_2 ->setText("Free Software");
        ui->textBrowser_2->setHtml(getZipContent("freesoftware.html"));
        flag = 3;
    }   else {
        ui->pushButton_2 ->setText("GPL - Bitte lesen !");
        ui->textBrowser_2->setHtml("<b>Hello</b>");
        ui->textBrowser_2->update();
        flag = 0;
    }
}
