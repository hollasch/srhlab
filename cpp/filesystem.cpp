//======================================================================================================================
// file-system
//
// Illustration of the std::filesystem class.
//======================================================================================================================

#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;
using std::cout;

int main () {
    //fs::path pathToShow("../../srhlab/cpp/build/debug/filesystem.exe");
    fs::path pathToShow("C:/Windows/system.ini");
    cout << "fs::path(" << pathToShow << "):\n";

    cout << "    exists() = " << fs::exists(pathToShow) << "\n"
         << "    root_name() = " << pathToShow.root_name() << "\n"
         << "    root_path() = " << pathToShow.root_path() << "\n"
         << "    relative_path() = " << pathToShow.relative_path() << "\n"
         << "    parent_path() = " << pathToShow.parent_path() << "\n"
         << "    filename() = " << pathToShow.filename() << "\n"
         << "    stem() = " << pathToShow.stem() << "\n"
         << "    extension() = " << pathToShow.extension() << "\n";

    return 0;
}
