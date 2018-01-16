@setlocal & echo off

:argloop
    if "%~1" equ "" goto :done
    echo Arg: "%~1"
    shift
    goto :argloop

:done
exit /b 0
