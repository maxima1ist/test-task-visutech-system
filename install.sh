#!/bin/bash

set -e

g++ -w -std=c++17 src/main.cpp src/Logger.h src/Logger.cpp src/Exception.h src/Exception.cpp src/ConstantStrings.h src/ConstantStrings.cpp -o TestTask.out

echo Installation completed successfully, use the file \"TestTask.out\" to execute.