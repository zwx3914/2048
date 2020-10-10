@echo off
windres 2048.rc -O coff -o 2048.res
g++  -o 2048 main.cpp 2048.cpp 2048.res
pause