#--------------------------------------------------------------
# dBase compiler ...
DBASEFLEXSOURCES  = $${SRCDIR}/parser/dbase/dbase.lpp
DBASEBISONSOURCES = $${SRCDIR}/parser/dbase/dbase.ypp

dbaseFlexSource.output = $${SRCDIR}/parser/dbase/dbase.lex.cc
dbaseFlexSource.input = DBASEFLEXSOURCES
dbaseFlexSource.commands = flex -i -o ${QMAKE_FILE_OUT} ${QMAKE_FILE_IN}
dbaseFlexSource.variable_out = SOURCES
dbaseFlexSource.name = dbase Flex Sources ${QMAKE_FILE_IN}
dbaseFlexSource.depends = $${SRCDIR}/parser/dbase/dbase.tab.hh
QMAKE_EXTRA_COMPILERS += dbaseFlexSource

dbaseBisonSource.output= $${SRCDIR}/parser/dbase/dbase.tab.cc
dbaseBisonSource.input = DBASEBISONSOURCES
dbaseBisonSource.commands = bison -d -o ${QMAKE_FILE_OUT} ${QMAKE_FILE_IN}
dbaseBisonSource.variable_out = SOURCES
dbaseBisonSource.name = dbase Bison Sources ${QMAKE_FILE_IN}
QMAKE_EXTRA_COMPILERS += dbaseBisonSource

# This dummy entry is required so that qmake handles the header correctly
dbaseBisonHeader.commands=@true
dbaseBisonHeader.output= $${SRCDIR}/parser/dbase/dbase.tab.hh
dbaseBisonHeader.input = DBASEBISONSOURCES
dbaseBisonHeader.variable_out = HEADERS
dbaseBisonHeader.name = dbaseBisonHeader ${QMAKE_FILE_IN}
dbaseBisonHeader.depends = $${SRCDIR}/parser/dbase/dbase.tab.cc
QMAKE_EXTRA_COMPILERS += dbaseBisonHeader

