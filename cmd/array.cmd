@echo off & setlocal EnableDelayedExpansion

set n=7
echo n = %n%

set foo[%n%]=bar
echo foo[n] = "!foo[%n%]!"
