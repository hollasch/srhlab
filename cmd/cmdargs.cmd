echo off
setlocal EnableDelayedExpansion

rem Usage: x [-f1] [-f2] [name1] [name2]

set f1=0
set f2=0
set n1=
set n2=

for %%a in (%*) do (
    if /i %%a equ -f1 (
        set f1=1
    ) else if /i %%a equ -f2 (
        set f2=1
    ) else if x!n1! equ x (
        set n1=%%a
    ) else (
        set n2=%%a
    )
)

echo f1=%f1%
echo f2=%f2%
echo n1=%n1%
echo n2=%n2%
