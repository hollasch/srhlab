@echo off & setlocal EnableDelayedExpansion

set foo[7]=bar
set n=7

echo n = %n%
echo foo[n] = "!foo[%n%]!"
