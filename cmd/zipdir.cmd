setlocal

set srcDirectory=%1
set dstZip=%srcDirectory%.zip

if -%srcDirectory%- equ -- (
    @echo USAGE: %0 ^<src-directory^>.
    exit /b 1
)

@echo Creating zip archive for directory %srcDirectory%.

dir >nul 2>&1 %srcDirectory%
if %errorlevel% GTR 0 (
    @echo ERROR: Source directory '%srcDirectory%' is invalid. 1>&2
    exit /b 1
)

powershell.exe -nologo -noprofile -command ^
    "& { Add-Type -A 'System.IO.Compression.FileSystem'; [IO.Compression.ZipFile]::CreateFromDirectory('%srcDirectory%', '%srcDirectory%.zip'); }"

REM -- To extract from zip use:
REM    "& { Add-Type -A 'System.IO.Compression.FileSystem'; [IO.Compression.ZipFile]::ExtractToDirectory('foo.zip', 'bar'); }"
