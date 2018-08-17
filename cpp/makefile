ccopts=-nologo -W3 -I"%VCINSTALLDIR%/include" -Fo.\out\obj\ -EHsc
outDir=out

all: mkout constants expr-vars float float-close floatEpsilonDiffTest forscope istream sharedPtr \
    string variadic

mkout:
    -mkdir 2>nul $(outDir)\obj

clean:
    -rmdir 2>nul /s /q  $(outDir)

fresh: clean all


constants:            mkout $(outDir)\constants.exe
expr-vars:            mkout $(outDir)\expr-vars.exe
float-close:          mkout $(outDir)\float-close.exe
float:                mkout $(outDir)\float.exe
floatEpsilonDiffTest: mkout $(outDir)\floatEpsilonDiffTest.exe
forscope:             mkout $(outDir)\forscope.exe
istream:              mkout $(outDir)\istream.exe
sharedPtr:            mkout $(outDir)\sharedPtr.exe
string:               mkout $(outDir)\string.exe
variadic:             mkout $(outDir)\variadic.exe


$(outDir)\constants.exe: constants.cpp
    cl $(ccopts) -Fe$@ constants.cpp

$(outDir)\expr-vars.exe: expr-vars.cpp
    cl $(ccopts) -Fe$@ expr-vars.cpp

$(outDir)\float.exe: float.cpp
    cl $(ccopts) -Ox -wd4723 -Fe$@ float.cpp

$(outDir)\floatEpsilonDiffTest.exe: floatEpsilonDiffTest.cpp
    cl $(ccopts) -Ox -Fe$@ floatEpsilonDiffTest.cpp

$(outDir)\float-close.exe: float-close.cpp
    cl $(ccopts) -Ox -wd4723 -Fe$@ float-close.cpp

$(outDir)\forscope.exe: forscope.cpp
    cl $(ccopts) -Fe$@ forscope.cpp

$(outDir)\istream.exe: istream.cpp
    cl $(ccopts) -EHsc -Fe$@ istream.cpp

$(outDir)\sharedPtr.exe: sharedPtr.cpp
    cl $(ccopts) -Fe$@ sharedPtr.cpp

$(outDir)\string.exe: string.cpp
    cl $(ccopts) -Fe$@ string.cpp

$(outDir)\variadic.exe: variadic.cpp
    cl $(ccopts) -Fe$@ variadic.cpp
