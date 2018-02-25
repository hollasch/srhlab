ccopts=-nologo -W3 -I"%VCINSTALLDIR%/include" -EHsc

all: forscope istream constants float string variadic

forscope: forscope.exe

forscope.exe: forscope.cpp
    cl $(ccopts) forscope.cpp
    del 2>nul forscope.obj

istream: istream.exe

istream.exe: istream.cpp
    cl $(ccopts) -EHsc istream.cpp
    del 2>nul istream.obj

constants: constants.exe

constants.exe: constants.cpp
    cl $(ccopts) constants.cpp
    del 2>nul constants.obj

float: float.exe

float.exe: float.cpp
    cl $(ccopts) -Ox float.cpp
    del 2>nul float.obj

string: string.exe

string.exe: string.cpp
    cl $(ccopts) string.cpp
    del 2>nul string.obj

variadic: variadic.exe

variadic.exe: variadic.cpp
    cl $(ccopts) variadic.cpp
    del 2>nul variadic.obj

clean:
    del 2>nul *.obj *.exe

fresh: clean all
