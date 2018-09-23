#--------------------------------------------------------------
# project file parser
PROFLEXSOURCES  = $${SRCDIR}/parser/pro/pro.lpp
PROBISONSOURCES = $${SRCDIR}/parser/pro/pro.ypp

proFlexSource.output = $${SRCDIR}/parser/pro/pro.lex.cc
proFlexSource.input = PROFLEXSOURCES
proFlexSource.commands = flex -i -o${QMAKE_FILE_OUT} ${QMAKE_FILE_IN}
proFlexSource.variable_out = SOURCES
proFlexSource.name = Flex Sources ${QMAKE_FILE_IN}
proFlexSource.depends = $${SRCDIR}/parser/pro/pro.tab.hh
QMAKE_EXTRA_COMPILERS += proFlexSource

proBisonSource.output= $${SRCDIR}/parser/pro/pro.tab.cc
proBisonSource.input = PROBISONSOURCES
proBisonSource.commands = bison -d -o ${QMAKE_FILE_OUT} ${QMAKE_FILE_IN}
proBisonSource.variable_out = SOURCES
proBisonSource.name = Bison Sources ${QMAKE_FILE_IN}
QMAKE_EXTRA_COMPILERS += proBisonSource

# This dummy entry is required so that qmake handles the header correctly
proBisonHeader.commands=@true
proBisonHeader.output= $${SRCDIR}/parser/pro/pro.tab.hh
proBisonHeader.input = PROBISONSOURCES
proBisonHeader.variable_out = HEADERS
proBisonHeader.name = proBisonHeader ${QMAKE_FILE_IN}
proBisonHeader.depends = $${SRCDIR}/parser/pro/pro.tab.cc
QMAKE_EXTRA_COMPILERS += proBisonHeader
