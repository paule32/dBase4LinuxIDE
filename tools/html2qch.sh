#!/bin/bash
echo "Building help documentation..."
/opt//qt5/5.5/gcc_64/bin/qhelpgenerator help/dBaseHelp.qhp -o help/dBaseHelp.qch
/opt/qt5/5.5/gcc_64/bin/qcollectiongenerator help/dBaseHelp.qhcp -o help/dBaseHelp.qhc

