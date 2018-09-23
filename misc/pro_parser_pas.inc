#--------------------------------------------------------------
# delphi compiler ...
DELPHIFLEXSOURCES  = $${SRCDIR}/parser/delphi/delphi.lpp
DELPHIBISONSOURCES = $${SRCDIR}/parser/delphi/delphi.ypp

delphiFlexSource.output = $${SRCDIR}/parser/delphi/delphi.lex.cc
delphiFlexSource.input = DELPHIFLEXSOURCES
delphiFlexSource.commands = flex -i -o${QMAKE_FILE_OUT} ${QMAKE_FILE_IN}
delphiFlexSource.variable_out = SOURCES
delphiFlexSource.name = Delphi Flex Sources ${QMAKE_FILE_IN}
delphiFlexSource.depends = $${SRCDIR}/parser/delphi/delphi.tab.hh
QMAKE_EXTRA_COMPILERS += delphiFlexSource

delphiBisonSource.output= $${SRCDIR}/parser/delphi/delphi.tab.cc
delphiBisonSource.input = DELPHIBISONSOURCES
delphiBisonSource.commands = bison -d -o ${QMAKE_FILE_OUT} ${QMAKE_FILE_IN}
delphiBisonSource.variable_out = SOURCES
delphiBisonSource.name = delphi Bison Sources ${QMAKE_FILE_IN}
QMAKE_EXTRA_COMPILERS += delphiBisonSource

# This dummy entry is required so that qmake handles the header correctly
delphiBisonHeader.commands=@true
delphiBisonHeader.output= $${SRCDIR}/parser/delphi/delphi.tab.hh
delphiBisonHeader.input = DELPHIBISONSOURCES
delphiBisonHeader.variable_out = HEADERS
delphiBisonHeader.name = delphiBisonHeader ${QMAKE_FILE_IN}
delphiBisonHeader.depends = $${SRCDIR}/parser/delphi/delphi.tab.cc
QMAKE_EXTRA_COMPILERS += delphiBisonHeader

