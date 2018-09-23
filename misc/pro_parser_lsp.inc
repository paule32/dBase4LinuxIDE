#--------------------------------------------------------------
# Lisp compiler ...
LispFLEXSOURCES  = $${SRCDIR}/parser/lisp/lisp.lpp
LispBISONSOURCES = $${SRCDIR}/parser/lisp/lisp.ypp

LispFlexSource.output = $${SRCDIR}/parser/lisp/lisp.lex.cc
LispFlexSource.input = LispFLEXSOURCES
LispFlexSource.commands = flex -i -o${QMAKE_FILE_OUT} ${QMAKE_FILE_IN}
LispFlexSource.variable_out = SOURCES
LispFlexSource.name = Lisp Flex Sources ${QMAKE_FILE_IN}
LispFlexSource.depends = $${SRCDIR}/parser/lisp/lisp.tab.hh
QMAKE_EXTRA_COMPILERS += LispFlexSource

LispBisonSource.output= $${SRCDIR}/parser/lisp/lisp.tab.cc
LispBisonSource.input = LispBISONSOURCES
LispBisonSource.commands = bison -d -o ${QMAKE_FILE_OUT} ${QMAKE_FILE_IN}
LispBisonSource.variable_out = SOURCES
LispBisonSource.name = Lisp Bison Sources ${QMAKE_FILE_IN}
QMAKE_EXTRA_COMPILERS += LispBisonSource

# This dummy entry is required so that qmake handles the header correctly
LispBisonHeader.commands=@true
LispBisonHeader.output= $${SRCDIR}/parser/lisp/lisp.tab.hh
LispBisonHeader.input = LispBISONSOURCES
LispBisonHeader.variable_out = HEADERS
LispBisonHeader.name = LispBisonHeader ${QMAKE_FILE_IN}
LispBisonHeader.depends = $${SRCDIR}/parser/lisp/lisp.tab.cc
QMAKE_EXTRA_COMPILERS += LispBisonHeader

