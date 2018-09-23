#--------------------------------------------------------------
# html file parser
#--------------------------------------------------------------
HTMLFLEXSOURCES  = $${SRCDIR}/parser/html/html.lpp
HTMLBISONSOURCES = $${SRCDIR}/parser/html/html.ypp

htmlFlexSource.output = $${SRCDIR}/parser/html/html.lex.cc
htmlFlexSource.input = HTMLFLEXSOURCES
htmlFlexSource.commands = flex -i -o${QMAKE_FILE_OUT} ${QMAKE_FILE_IN}
htmlFlexSource.variable_out = SOURCES
htmlFlexSource.name = HTML Flex Sources ${QMAKE_FILE_IN}
htmlFlexSource.depends = $${SRCDIR}/parser/html/html.tab.hh
QMAKE_EXTRA_COMPILERS += htmlFlexSource

htmlBisonSource.output= $${SRCDIR}/parser/html/html.tab.cc
htmlBisonSource.input = HTMLBISONSOURCES
htmlBisonSource.commands = bison -d -o ${QMAKE_FILE_OUT} ${QMAKE_FILE_IN}
htmlBisonSource.variable_out = SOURCES
htmlBisonSource.name = HTML Bison Sources ${QMAKE_FILE_IN}
QMAKE_EXTRA_COMPILERS += htmlBisonSource

# This dummy entry is required so that qmake handles the header correctly
htmlBisonHeader.commands=@true
htmlBisonHeader.output= $${SRCDIR}/parser/html/html.tab.hh
htmlBisonHeader.input = HTMLBISONSOURCES
htmlBisonHeader.variable_out = HEADERS
htmlBisonHeader.name = htmlBisonHeader ${QMAKE_FILE_IN}
htmlBisonHeader.depends = $${SRCDIR}/parser/html/html.tab.cc
QMAKE_EXTRA_COMPILERS += htmlBisonHeader

