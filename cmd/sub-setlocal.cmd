@echo off & setlocal

REM // This script demonstrates that called subroutines are equivalent to a full call to the
REM // originating script, but starting execution at the specified label. This means that commands
REM // like `setlocal` can be used, and are scoped to the subroutine.

set X=1
echo X=%X%
call :A
echo X=%X%
call :B

REM !! This will not reflect the update in the :B routine below, since it used `setlocal`.
echo X=%X%

REM !! This command will fail to expand, since the EnableDelayedExpansion option is restricted to
REM !! the :B scope below.
echo X=!X!

goto :eof


:A
    echo A: X=%X%
    set X=2
    exit /b

:B
    setlocal EnableDelayedExpansion
    echo B: X=%X%
    echo B: X=!X!
    set X=3
    echo B: X=!X!
    exit /b
