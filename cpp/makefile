ccopts=-nologo -W3 -I"%VCINSTALLDIR%/include" -EHsc
outDir=out

all: mkout forscope istream constants float string variadic

mkout:
    -mkdir 2>nul $(outDir)

forscope: mkout $(outDir)\forscope.exe

$(outDir)\forscope.exe: forscope.cpp
    cl $(ccopts) forscope.cpp -Fe$@
    del 2>nul forscope.obj

istream: $(outDir)\istream.exe

$(outDir)\istream.exe: istream.cpp
    cl $(ccopts) -EHsc istream.cpp -Fe$@
    del 2>nul istream.obj

constants: $(outDir)\constants.exe

$(outDir)\constants.exe: constants.cpp
    cl $(ccopts) constants.cpp -Fe$@
    del 2>nul constants.obj

float: $(outDir)\float.exe

$(outDir)\float.exe: float.cpp
    cl $(ccopts) -Ox float.cpp -Fe$@
    del 2>nul float.obj

string: $(outDir)\string.exe

$(outDir)\string.exe: string.cpp
    cl $(ccopts) string.cpp -Fe$@
    del 2>nul string.obj

variadic: $(outDir)\variadic.exe

$(outDir)\variadic.exe: variadic.cpp
    cl $(ccopts) variadic.cpp -Fe$@
    del 2>nul variadic.obj

clean:
    del 2>nul *.obj *.exe

fresh: clean all
