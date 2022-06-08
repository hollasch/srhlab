@echo off & setlocal

@echo ERRORLEVEL %ERRORLEVEL% (expect 0)
call :setcode || echo :setcode returned non-zero exit code.
@echo ERRORLEVEL %ERRORLEVEL% (expect 37)

@echo This process exits with a 0 process exit code.
goto :eof

:setcode
    exit /b 37
    @echo This command does not execute.
