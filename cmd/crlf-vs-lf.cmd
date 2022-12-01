@echo off &goto :start
REM  30        40        50        60        70        80        90       100..
REM 110       120       130       140       150       160       170       180       190         202
REM 210       220       230       240       250       260       270       280       290         302
REM 310       320       330       340       350       360       370       380       390         402
REM 410       420       430       440       450       460       470       480       490         502
REM 510
::label
    echo Failed. This script must have LF line endings.
    cmd /c exit 1 & goto :exit

:label
    echo Succeeded. This script must have CRLF line endings.
    cmd /c exit 0 & goto :exit

:start
    goto :label

REM ================================================================================================
REM What's Happening Here?
REM
REM LF line endings almost work on Windows batch/script files. I say "almost" because of a known bug
REM where the shell will fail to find prior labels (with backward jumps) that lie on 512-byte
REM boundaries with LF line endings. You can work around this by always repeating labels two lines
REM in a row and avoid ::-style comments, or you can surrender to the eternal legacy support of
REM Windows and always use CRLF for your Windows shell scripts.
REM
REM See the "Kinda, but..." answer on
REM https://serverfault.com/questions/429594/is-it-safe-to-write-batch-files-with-unix-line-endings
REM
REM ( When using Unix line endings, the label parser will skip over some labels
REM ( because of an off-by-one error. This is due to the parser's use of 512-byte
REM ( sized chunks and the assumption that line endings is denoted by two
REM ( characters, `\r\n`, rather than one, `\n`. When a label is erroneously skipped
REM ( over, the next erroneous skip can only occur at an offset of 512 bytes. If you
REM ( duplicate a label on the next line, the duplicated label will be within the
REM ( 512 limit, and can act as a fallback.
REM (
REM ( Furthermore, as demonstrated by @jeb, the parser also misinterprets the end of
REM ( each 512-byte size chunk as a new line (as well as somehow ignoring white
REM ( space characters between a colon and the next text on these pseudo lines). A
REM ( comment such as `:: main section` can trigger the parser into somehow reading
REM ( the text `: main` as the label `:main`.
REM (
REM ( In summary, not only can the parser skip labels, it can also misinterpret
REM ( comments and other pieces of text as labels.
REM
REM ================================================================================================

:exit
    cmd /c exit %ERRORLEVEL%
