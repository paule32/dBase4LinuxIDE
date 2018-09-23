#!/bin/bash
echo "Building help documentation..."
qhelpgenerator dBaseHelp.qhp -o dBaseHelp.qhc
qcollectiongenerator dBaseHelp.qhcp -o dBaseHelp.qhc
