setlocal

set foo=label_bar

goto %foo%

echo Didn't work. :(
exit /b 1

:label_bar
echo It worked! :)
exit /b 0
