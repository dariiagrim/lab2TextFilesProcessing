#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <experimental/filesystem>

using namespace std;
namespace fs = std::experimental::filesystem;

int main() {
    string directoryName;

    cout << "Please, write path to directory: ";

    cin >> directoryName;

    vector<string> files;

    for (const auto& entry : fs::directory_iterator(directoryName)) {
        if (entry.path().extension().string() == ".csv")
            files.push_back(entry.path().string());
    }
    for (string file : files) {
        cout << file << endl;
    }

    return 0;
}
