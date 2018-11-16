# Visual Studio `nmake` Makefile for WinTitle
#
# A quick and dirty start

all: wintitle

fresh: clobber all

wintitle: wintitle.exe

wintitle.exe: wintitle.cpp
	cl -nologo -O2 -Ox -W4 -GF -GS -EHsc -Fe: wintitle.exe -Fo: wintitle.obj wintitle.cpp
