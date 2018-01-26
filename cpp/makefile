ccopts=-nologo -W3 -I"%VCINSTALLDIR%/include"

all: forscope istream constants float

forscope: forscope.exe

forscope.exe: forscope.cpp
    cl $(ccopts) forscope.cpp
    del 2>nul forscope.obj

istream: istream.exe

istream.exe: istream.cpp
    cl $(ccopts) -EHsc istream.cpp
    del 2>nul istream.obj

constants: constants.exe
    cl $(ccopts) constants.cpp
    del 2>nul constants.obj

float: float.exe

float.exe: float.cpp
    cl $(ccopts) -Ox float.cpp
    del 2>nul float.obj

clean:
    del 2>nul *.obj *.exe

fresh: clean all
