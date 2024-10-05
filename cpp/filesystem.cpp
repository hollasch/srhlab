//======================================================================================================================
// file-system
//
// Illustration of the std::filesystem class.
//======================================================================================================================

#include <filesystem>
#include <iostream>
#include <string>

namespace fs = std::filesystem;
using std::cout;
using std::string;

inline const string& toString(const bool b) {
    static const string trueString{ "true" };
    static const string falseString{ "false" };
    return b ? trueString : falseString;
}

int main () {
    // Show path properties.

    //fs::path pathToShow{"../../srhlab/cpp/build/debug/filesystem.exe"};
    fs::path pathToShow{"C:/Windows/system.ini"};

    cout << "fs::path(" << pathToShow << "):\n"
         << "    exists() = " << toString(fs::exists(pathToShow)) << "\n"
         << "    is_regular_file() = " << toString(fs::is_regular_file(pathToShow)) << "\n"
         << "    is_directory() = " << toString(fs::is_directory(pathToShow)) << "\n"
         << "    root_name() = " << pathToShow.root_name() << "\n"
         << "    root_path() = " << pathToShow.root_path() << "\n"
         << "    relative_path() = " << pathToShow.relative_path() << "\n"
         << "    parent_path() = " << pathToShow.parent_path() << "\n"
         << "    filename() = " << pathToShow.filename() << "\n"
         << "    stem() = " << pathToShow.stem() << "\n"
         << "    extension() = " << pathToShow.extension() << "\n";

    cout << "\nfs::path(" << pathToShow << ") parts:\n";

    for (const auto& part : pathToShow) {
        cout << "    path part: " << part << '\n';
    }

    // Illustrate path construction.

    cout << "\nPath Building:\n";
    fs::path builtPath{"//foo/bar"};
    cout << "    = " << builtPath << "\n";
    builtPath /= "baz";
    cout << "    /= \"baz\": " << builtPath << '\n';
    builtPath /= "qux";
    cout << "    /= \"qux\": " << builtPath << '\n';
    builtPath += "/frob";
    cout << "    += \"/frob\": " << builtPath << '\n';
    builtPath += "natz";
    cout << "    += \"natz\": " << builtPath << '\n';
    builtPath += "_dorf";
    cout << "    += \"_dorf\": " << builtPath << '\n';
    builtPath += ".json";
    cout << "    += \".json\": " << builtPath << '\n';

    // Display the size of a file.

    fs::path sizeTarget{"filesystem.cpp"};
    //if (fs::exists(sizeTarget) && fs::is_regular_file(sizeTarget))
    {
        std::error_code err;
        auto size = fs::file_size(sizeTarget, err);
        if (size != static_cast<uintmax_t>(-1)) {
            cout << "\n" << sizeTarget << " size is " << size << " bytes\n";
        } else {
            cout << "\n" << sizeTarget << " size error: " << err.message() << '\n';
        }
    }

    // Display contents of a directory.

    const string markDir{"[DIR] "};
    const string markFile{"[FILE]"};
    const string markUnknown{"[?]   "};

    // Display the directory contents.

    fs::path dirToShowNR{"."};
    if (!fs::exists(dirToShowNR) || !fs::is_directory(dirToShowNR)) {
        cout << "\nError: " << dirToShowNR << " is not a valid directory\n";
    } else {
        cout << "\nDirectory " << dirToShowNR << " contains (non-recursive):\n";
        for (const auto& entry : fs::directory_iterator{ dirToShowNR }) {
            const string* dirMarker{ nullptr };

            if (fs::is_directory(entry.status())) {
                dirMarker = &markDir;
            } else if (fs::is_regular_file(entry.status())) {
                dirMarker = &markFile;
            } else {
                dirMarker = &markUnknown;
            }

            cout << "    " << *dirMarker << " " << entry.path() << '\n';
        }
    }

    // Traverse a path using the recursive directory iterator.
    fs::path dirToShow{"build/filesystem.dir"};
    if (!fs::exists(dirToShowNR) || !fs::is_directory(dirToShowNR)) {
        cout << "\nError: " << dirToShowNR << " is not a valid directory\n";
    } else {
        cout << "\nDirectory " << dirToShow << " contains (recursive):\n";
        for (const auto& entry : fs::recursive_directory_iterator{dirToShow}) {
            const string* dirMarker{nullptr};

            if (fs::is_directory(entry.status())) {
                dirMarker = &markDir;
            } else if (fs::is_regular_file(entry.status())) {
                dirMarker = &markFile;
            } else {
                dirMarker = &markUnknown;
            }

            cout << "    " << *dirMarker << " " << entry.path() << '\n';
        }
    }

    return 0;
}
