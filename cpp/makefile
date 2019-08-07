build=build
ccopts=-nologo -std:c++latest -W3 -I"%VCINSTALLDIR%/include" -Fo$(build)\obj\ -EHsc

all: mkBuild \
	constants expr-vars float float-close floatEpsilonDiffTest forscope initialization istream \
	rgbclamp pair sharedPtr string unordered_set variadic

mkBuild:
    -mkdir 2>nul $(build)\obj

clean:
    -rmdir 2>nul /s /q  $(build)

fresh: clean all


constants:            mkBuild $(build)\constants.exe
expr-vars:            mkBuild $(build)\expr-vars.exe
float-close:          mkBuild $(build)\float-close.exe
float:                mkBuild $(build)\float.exe
floatEpsilonDiffTest: mkBuild $(build)\floatEpsilonDiffTest.exe
forscope:             mkBuild $(build)\forscope.exe
initialization:       mkBuild $(build)\initialization.exe
istream:              mkBuild $(build)\istream.exe
rgbclamp:             mkBuild $(build)\rgbclamp.exe
pair:                 mkBuild $(build)\pair.exe
sharedPtr:            mkBuild $(build)\sharedPtr.exe
string:               mkBuild $(build)\string.exe
unordered_set:        mkBuild $(build)\unordered_set.exe
variadic:             mkBuild $(build)\variadic.exe


$(build)\constants.exe: constants.cpp
    cl $(ccopts) -Fe$@ constants.cpp

$(build)\expr-vars.exe: expr-vars.cpp
    cl $(ccopts) -Fe$@ expr-vars.cpp

$(build)\float.exe: float.cpp
    cl $(ccopts) -Ox -wd4723 -Fe$@ float.cpp

$(build)\floatEpsilonDiffTest.exe: floatEpsilonDiffTest.cpp
    cl $(ccopts) -Ox -Fe$@ floatEpsilonDiffTest.cpp

$(build)\float-close.exe: float-close.cpp
    cl $(ccopts) -Ox -wd4723 -Fe$@ float-close.cpp

$(build)\forscope.exe: forscope.cpp
    cl $(ccopts) -Fe$@ forscope.cpp

$(build)\initialization.exe: initialization.cpp
    cl $(ccopts) -EHsc -Fe$@ initialization.cpp

$(build)\istream.exe: istream.cpp
    cl $(ccopts) -EHsc -Fe$@ istream.cpp

$(build)\pair.exe: pair.cpp
    cl $(ccopts) -Fe$@ pair.cpp

$(build)\rgbclamp.exe: rgbclamp.cpp
    cl $(ccopts) -Fe$@ rgbclamp.cpp

$(build)\sharedPtr.exe: sharedPtr.cpp
    cl $(ccopts) -Fe$@ sharedPtr.cpp

$(build)\string.exe: string.cpp
    cl $(ccopts) -Fe$@ string.cpp

$(build)\unordered_set.exe: unordered_set.cpp
    cl $(ccopts) -Fe$@ unordered_set.cpp

$(build)\variadic.exe: variadic.cpp
    cl $(ccopts) -Fe$@ variadic.cpp
