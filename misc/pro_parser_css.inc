#--------------------------------------------------------------
# css file parser
#--------------------------------------------------------------
CSSFLEXSOURCES  = $${SRCDIR}/parser/css/css.lpp
CSSBISONSOURCES = $${SRCDIR}/parser/css/css.ypp

cssFlexSource.output = $${SRCDIR}/parser/css/css.lex.cc
cssFlexSource.input = CSSFLEXSOURCES
cssFlexSource.commands = flex -i -o${QMAKE_FILE_OUT} ${QMAKE_FILE_IN}
cssFlexSource.variable_out = SOURCES
cssFlexSource.name = CSS Flex Sources ${QMAKE_FILE_IN}
cssFlexSource.depends = $${SRCDIR}/parser/css/css.tab.hh
QMAKE_EXTRA_COMPILERS += cssFlexSource

cssBisonSource.output= $${SRCDIR}/parser/css/css.tab.cc
cssBisonSource.input = CSSBISONSOURCES
cssBisonSource.commands = bison -d -o ${QMAKE_FILE_OUT} ${QMAKE_FILE_IN}
cssBisonSource.variable_out = SOURCES
cssBisonSource.name = CSS Bison Sources ${QMAKE_FILE_IN}
QMAKE_EXTRA_COMPILERS += cssBisonSource

# This dummy entry is required so that qmake handles the header correctly
cssBisonHeader.commands=@true
cssBisonHeader.output= source/parser/css/css.tab.hh
cssBisonHeader.input = CSSBISONSOURCES
cssBisonHeader.variable_out = HEADERS
cssBisonHeader.name = cssBisonHeader ${QMAKE_FILE_IN}
cssBisonHeader.depends = source/parser/css/css.tab.cc
QMAKE_EXTRA_COMPILERS += cssBisonHeader

