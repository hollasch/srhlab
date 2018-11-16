#include <windows.h>
#include <stdio.h>

int wmain (int argc, wchar_t* argv[])
{
    char titleBuffer[2048];

    GetConsoleTitleA (titleBuffer, sizeof(titleBuffer));

    printf ("Console title is \"%s\".\n", titleBuffer);

    return 0;
}
