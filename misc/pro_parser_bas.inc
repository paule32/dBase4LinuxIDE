#--------------------------------------------------------------
# basic compiler ...
BASICFLEXSOURCES  = $${SRCDIR}/parser/basic/basic.lpp
BASICBISONSOURCES = $${SRCDIR}/parser/basic/basic.ypp

BASICFlexSource.output = $${SRCDIR}/parser/basic/basic.lex.cc
BASICFlexSource.input = BASICFLEXSOURCES
BASICFlexSource.commands = flex -i -o${QMAKE_FILE_OUT} ${QMAKE_FILE_IN}
BASICFlexSource.variable_out = SOURCES
BASICFlexSource.name = BASIC Flex Sources ${QMAKE_FILE_IN}
BASICFlexSource.depends = $${SRCDIR}/parser/basic/basic.tab.hh
QMAKE_EXTRA_COMPILERS += BASICFlexSource

BASICBisonSource.output= $${SRCDIR}/parser/basic/basic.tab.cc
BASICBisonSource.input = BASICBISONSOURCES
BASICBisonSource.commands = bison -d -o ${QMAKE_FILE_OUT} ${QMAKE_FILE_IN}
BASICBisonSource.variable_out = SOURCES
BASICBisonSource.name = BASIC Bison Sources ${QMAKE_FILE_IN}
QMAKE_EXTRA_COMPILERS += BASICBisonSource

# This dummy entry is required so that qmake handles the header correctly
BASICBisonHeader.commands=@true
BASICBisonHeader.output= $${SRCDIR}/parser/basic/basic.tab.hh
BASICBisonHeader.input = BASICBISONSOURCES
BASICBisonHeader.variable_out = HEADERS
BASICBisonHeader.name = BASICBisonHeader ${QMAKE_FILE_IN}
BASICBisonHeader.depends = $${SRCDIR}/parser/basic/basic.tab.cc
QMAKE_EXTRA_COMPILERS += BASICBisonHeader

