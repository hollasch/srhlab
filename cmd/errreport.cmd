@echo off

@rem // Test return values from subroutines.

call :report pass "1 passed."   || goto :fail
call :report pass "2 passed."   || goto :fail
call :report pass "3 passed."   || goto :fail
call :report pass "4 passed."   || goto :fail
call :report fail "Failed at 5" || goto :fail
call :report pass "6 passed."   || goto :fail
call :report pass "7 passed."   || goto :fail
call :report pass "8 passed."   || goto :fail
call :report pass "9 passed."   || goto :fail
goto :eof

:report
    @echo %2
    if %1 equ fail echo halt & exit /b 1
    exit /b 0

:fail
    cmd /c exit 1
