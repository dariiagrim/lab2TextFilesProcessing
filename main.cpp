#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

int main() {
    string directoryName;

    cout << "Please, write path to directory: ";

    cin >> directoryName;

    vector<string> files;

    for (const auto& entry : fs::directory_iterator(directoryName)) {
        cout << entry.path().string() << endl;
    }

    return 0;
}
