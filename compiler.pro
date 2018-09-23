#------------------------------------------------------------------------
# dBase4Linux 1.0
# RDP - Rapid Database Programming
#
# (c) 2015-2018 Jens Kallup
# MIT License
#
# Copyright (c) 2018 Jens Kallup
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.
#------------------------------------------------------------------------
TEMPLATE = app
TARGET   = dbase

CONFIG  += release
CONFIG  += c++14

QT += core gui widgets help network script

PWD=$$system(pwd)

TOPDIR=$$PWD
SRCDIR=$${TOPDIR}/source
HDRDIR=$${SRCDIR}/includes
LIBDIR=$${SRCDIR}/libs

GENFOLDER=$${TOPDIR}/build/

TEMPLATE_DEPTH = 516

UI_DIR =$${TOPDIR}/.uic
MOC_DIR=$${TOPDIR}/.moc
OBJECTS_DIR=$${TOPDIR}/.obj
RCC_DIR=$${TOPDIR}/.res

DEFINES += BUILDTIME=\\\"$$system(date '+%H:%M:%S')\\\"
DEFINES += BUILDDATE=\\\"$$system(date '+%Y-%m-%d')\\\"

DEFINES += NO_GUI=0
#----------------------------------------------------------------------
# if you would not use pch - pre-compiled-header, just remove -H block
#----------------------------------------------------------------------
QMAKE_CXXFLAGS += \
	-ggdb \
	-Wno-unused-parameter \
	-Wno-unused-variable \
	-Wno-unused-local-typedefs \
    -Wno-unused-but-set-variable \
    -Woverloaded-virtual \
    -Wno-write-strings \
	-Wno-switch \
    -Wno-extra \
    -Wno-reorder \
    -Wno-multichar \
    -Wno-sign-compare \
    -Wunused-function \
    -Woverloaded-virtual -fpermissive \
    -ftemplate-depth=$${TEMPLATE_DEPTH} \
    -frtti -fexceptions \
    -I$${TOPDIR}. -I$${SRCDIR} -I$${SRCDIR}/includes \
    -D__BYTE_ORDER=__LITTLE_ENDIAN \
    -DQT_DEPRECATED \
    -DQT_DISABLE_DEPRECATED_BEFORE -D_GLIBCXX_USE_CXX11_ABI=0

#------------------------------------------------------
# to keep clean here, I out source a little bit ...
#------------------------------------------------------
include ( $${SRCDIR}/misc/pro_parser_bas.inc )
include ( $${SRCDIR}/misc/pro_parser_css.inc )
include ( $${SRCDIR}/misc/pro_parser_dbl.inc )
include ( $${SRCDIR}/misc/pro_parser_htm.inc )
include ( $${SRCDIR}/misc/pro_parser_lsp.inc )
include ( $${SRCDIR}/misc/pro_parser_pas.inc )
include ( $${SRCDIR}/misc/pro_parser_pro.inc )

INCLUDEPATH += \
    /usr/local/include/c++/6.3.0 \
    /usr/local/include \
    /usr/include \
    $${TOPDIR}/.uic \
    $${SRCDIR}/ \
    $${SRCDIR}/includes \
    $${SRCDIR}/includes/asm/asmjit \
    $${SRCDIR}/includes/asm/asmtk

SOURCES += \
    $${SRCDIR}/BDE/dbaselevel7.cc \
    $${SRCDIR}/BDE/localconnectdatabase.cc \
    \
    $${SRCDIR}/console/console.cc \
    \
    $${SRCDIR}/setup/downloader.cc \
    $${SRCDIR}/setup/delegate.cc \
    \
    $${SRCDIR}/asm/asm32.cc \
    $${SRCDIR}/asm/stub32.cc \
    $${SRCDIR}/asm/binheader.h \
    $${SRCDIR}/asm/binreader.cc \
    $${SRCDIR}/asm/binreader.h \
    $${SRCDIR}/asm/binwriter.h \
    $${SRCDIR}/asm/binwriter.cc \
    $${SRCDIR}/asm/vmexec.c \
    \
    $${SRCDIR}/dbase/antifreeze.cc \
    $${SRCDIR}/dbase/assistant.cc \
    $${SRCDIR}/dbase/click.cc \
    $${SRCDIR}/dbase/connecttobde.cc \
    $${SRCDIR}/dbase/dbaseexception.cc \
    $${SRCDIR}/dbase/dbasemainmenu.cc \
    $${SRCDIR}/dbase/dragdroplistwidget.cc \
    $${SRCDIR}/dbase/keypress.cc \
    $${SRCDIR}/dbase/main.cc \
    $${SRCDIR}/dbase/mainclass.cc \
    $${SRCDIR}/dbase/mainwindow.cc \
    $${SRCDIR}/dbase/menusqlbuilder.cc \
    $${SRCDIR}/dbase/newtabledefinitionplaceholder.cc \
    $${SRCDIR}/dbase/procmakefile.cc \
    $${SRCDIR}/dbase/parseprojectfile.cc \
    $${SRCDIR}/dbase/selectcolorbutton.cc \
    $${SRCDIR}/dbase/selectcheckbox.cc \
    $${SRCDIR}/dbase/settings_dialog.cc \
    $${SRCDIR}/dbase/tablefieldpropertieswidget.cc \
    \
    $${SRCDIR}/designer/components_draglist.cpp \
    $${SRCDIR}/designer/cornergrabber.cc \
    $${SRCDIR}/designer/dbaseparser.cc \
    $${SRCDIR}/designer/designergraphicsview.cc \
    $${SRCDIR}/designer/designeritem.cc \
    $${SRCDIR}/designer/designerwindow.cc \
    $${SRCDIR}/designer/events_and_methods.cc \
    $${SRCDIR}/designer/hauptdesignerwindow.cc \
    $${SRCDIR}/designer/scene.cc \
    $${SRCDIR}/designer/sqlgraphicsdesigner.cc \
    \
    $${SRCDIR}/editors/asm/codeeditor.cc \
    $${SRCDIR}/editors/asm/common.cc \
    $${SRCDIR}/editors/asm/highlighter.cc \
    $${SRCDIR}/editors/asm/nasm.cc \
    \
    $${SRCDIR}/editors/dbase/editorgutter.cc \
    \
    $${SRCDIR}/help/helpbrowser.cc \
    $${SRCDIR}/help/helpdocker.cc \
    $${SRCDIR}/help/mywebbrowser.cc \
    \
    $${SRCDIR}/parser/misc.cc \
    $${SRCDIR}/parser/thread.cc \
    \
    $${SRCDIR}/splash/mysplashscreen.cc \
    $${SRCDIR}/splash/infoscreen.cc \
    \
    $${SRCDIR}/ssl/qsslclient.cc \
    $${SRCDIR}/ssl/qsslserver.cc \
    \
    $${SRCDIR}/update/update_dbase.cc \
    $${SRCDIR}/update/update_thread.cc \
    $${SRCDIR}/parser/pro/projectitem.cc \
    \
    $${SRCDIR}/editors/asm/assembleredit.cc \
    $${SRCDIR}/wizard/newprojectassistent.cc \
    \
    $${SRCDIR}/editors/files/openfilelist.cc

HEADERS += \
    \
    $${SRCDIR}/includes/console/console.h \
    $${SRCDIR}/parser/common.h \
    \
    $${SRCDIR}/includes/editors/files/openfilelist.h \
    \
	$${SRCDIR}/includes/antifreeze.h \
	$${SRCDIR}/includes/assistant.h \
	\
	$${SRCDIR}/includes/asm/decode/asm32.h \
	\
    $${SRCDIR}/includes/setup/downloader.h \
    $${SRCDIR}/includes/setup/delegate.h \
    \
    $${SRCDIR}/includes/asm/nasm.h \
    $${SRCDIR}/includes/asm/codeeditor.h \
    $${SRCDIR}/includes/asm/common.h \
    $${SRCDIR}/includes/asm/highlighter.h \
    \
    $${SRCDIR}/includes/BDE/connecttobde.h \
    $${SRCDIR}/includes/BDE/localconnectdatabase.h \
    \
    $${SRCDIR}/includes/dbase/dbaseaddnumber.h \
    $${SRCDIR}/includes/dbase/dbaseassign.h \
    $${SRCDIR}/includes/dbase/dbasecomando.h \
    $${SRCDIR}/includes/dbase/dbasedownvisitor.h \
    $${SRCDIR}/includes/dbase/dbaseexception.h \
    $${SRCDIR}/includes/dbase/dbaselevel7.h \
    $${SRCDIR}/includes/dbase/dbasemainmenu.h \
    $${SRCDIR}/includes/dbase/dbasemulnumber.h \
    $${SRCDIR}/includes/dbase/dbaseparameter.h \
    $${SRCDIR}/includes/dbase/dbasevisitor.h \
    $${SRCDIR}/includes/dbase/mainclass.h \
    $${SRCDIR}/includes/dbase/mainwindow.h \
    $${SRCDIR}/includes/dbase/parseprojectfile.h \
    $${SRCDIR}/includes/dbase/procmakefile.h \
    $${SRCDIR}/includes/dbase/selectcolorbutton.h \
    $${SRCDIR}/includes/dbase/selectcheckbox.h \
    \
    $${SRCDIR}/includes/designer/components_draglist.h \
    $${SRCDIR}/includes/designer/designergraphicsview.h \
    $${SRCDIR}/includes/designer/designeritem.h \
    $${SRCDIR}/includes/designer/designerpushbutton.h \
    $${SRCDIR}/includes/designer/designerwidgetcontainer.h \
    $${SRCDIR}/includes/designer/designerwindow.h \
    $${SRCDIR}/includes/designer/dragdroplistwidget.h \
    $${SRCDIR}/includes/designer/events_and_methods.h \
    $${SRCDIR}/includes/designer/hauptdesignerwindow.h \
    $${SRCDIR}/includes/designer/scene.h \
    \
    $${SRCDIR}/includes/editors/dbase/editorgutter.h \
    \
    $${SRCDIR}/includes/help/helpbrowser.h \
    $${SRCDIR}/includes/help/helpdocker.h \
    $${SRCDIR}/includes/help/mywebbrowser.h \
    \
    $${SRCDIR}/includes/quazip/crypt.h \
    $${SRCDIR}/includes/quazip/ioapi.h \
    $${SRCDIR}/includes/quazip/JlCompress.h \
    $${SRCDIR}/includes/quazip/quaadler32.h \
    $${SRCDIR}/includes/quazip/quacrc32.h \
    $${SRCDIR}/includes/quazip/quagzipfile.h \
    $${SRCDIR}/includes/quazip/quaziodevice.h \
    $${SRCDIR}/includes/quazip/quazip.h \
    $${SRCDIR}/includes/quazip/quazip_global.h \
    $${SRCDIR}/includes/quazip/quazipdir.h \
    $${SRCDIR}/includes/quazip/quazipfile.h \
    $${SRCDIR}/includes/quazip/quazipfileinfo.h \
    $${SRCDIR}/includes/quazip/quazipnewinfo.h \
    $${SRCDIR}/includes/quazip/unzip.h \
    $${SRCDIR}/includes/quazip/zip.h \
    \
    $${SRCDIR}/includes/splash/infoscreen.h \
    $${SRCDIR}/includes/splash/mysplashscreen.h \
    \
    $${SRCDIR}/includes/sql/menusqlbuilder.h \
    $${SRCDIR}/includes/sql/newtabledefinitionplaceholder.h \
    $${SRCDIR}/includes/sql/sqlgraphicsdesigner.h \
    \
    $${SRCDIR}/includes/ssl/qsslclient.h \
    $${SRCDIR}/includes/ssl/qsslserver.h \
    \
    $${SRCDIR}/includes/update/update_dbase.h \
    $${SRCDIR}/includes/update/update_thread.h \
    \
    $${SRCDIR}/parser/misc.h \
    $${SRCDIR}/parser/pro/projectitem.h \
    $${SRCDIR}/includes/asm/assembleredit.h \
    $${SRCDIR}/asm/binheader.h \
    $${SRCDIR}/includes/wizard/newprojectassistent.h
    
OBJECTS +=

FORMS   += \
    $${SRCDIR}/forms/mainwindow.ui \
    $${SRCDIR}/forms/settings_dialog.ui \
    $${SRCDIR}/forms/update_dbase.ui \
    $${SRCDIR}/forms/designerwindow.ui \
    $${SRCDIR}/forms/localconnectdatabase.ui \
    $${SRCDIR}/forms/infoscreen.ui \
    $${SRCDIR}/forms/newprojectassistent.ui

RESOURCES += \
    $${SRCDIR}/resource/icons.qrc \
    $${SRCDIR}/resource/lang.qrc \
    $${SRCDIR}/resource/data.qrc

TRANSLATIONS += \
    $${SRCDIR}/resource/lang/language_deu.ts \
    $${SRCDIR}/resource/lang/language_eng.ts

DISTFILES += \
    $${SRCDIR}/parser/common.h \
    \
    $${SRCDIR}/parser/basic/basic.lpp \
    $${SRCDIR}/parser/basic/basic.ypp \
    \
    $${SRCDIR}/parser/dbase/dbase.lpp \
    $${SRCDIR}/parser/dbase/dbase.ypp \
    \
    $${SRCDIR}/parser/lisp/lisp.lpp \
    $${SRCDIR}/parser/lisp/lisp.ypp \
    \
    $${SRCDIR}/parser/css/css.lpp \
    $${SRCDIR}/parser/css/css.ypp \
    \
    $${SRCDIR}/parser/delphi/delphi.lpp \
    $${SRCDIR}/parser/delphi/delphi.ypp \
    \
    $${SRCDIR}/parser/html/html.lpp \
    $${SRCDIR}/parser/html/html.ypp \
    \
    $${SRCDIR}/parser/pro/pro.lpp \
    $${SRCDIR}/parser/pro/pro.ypp \
    $${SRCDIR}/parser/pro/projectitem.cc \
    $${SRCDIR}/parser/pro/projectitem.h \
    \
    LICENSE \
    README.md \
    \
    examples/Delphi/src.pas \
    \
    examples/dBase/Form1.frm \
    examples/dBase/example1.prg \
    examples/dBase/test1.prg \
    examples/dBase/test4.prg \
    \
    help/html2qch.sh \
    help/dBaseHelp.qch \
    help/dBaseHelp.qhc \
    help/dBaseHelp.qhp \
    help/doc/dbase/class.html \
    help/doc/dbase/endclass.html \
    help/doc/dbase/index.html \
    help/doc/dbase/of.html \
    help/append.html \
    help/index.html \
    help/printline.html \
    help/test.html \
    help/dBaseHelp.qhcp

LIBS += -L. -lasmjit -lasmtk -lssl -lcrypto -lquazip -lz -lm -ll
