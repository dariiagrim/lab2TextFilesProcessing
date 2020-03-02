#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <experimental/filesystem>
#include <fstream>
#include <sstream>

using namespace std;
namespace fs = std::experimental::filesystem;

vector<std::string> split(const string& s, char delimiter)
{
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);
    while (getline(tokenStream, token, delimiter))
    {
        tokens.push_back(token);
    }
    return tokens;
}

int main() {
    string directoryName;

    cout << "Please, write path to directory: ";

    cin >> directoryName;

    vector<string> files;

    for (const auto& entry : fs::directory_iterator(directoryName)) {
        if (entry.path().extension().string() == ".csv")
            files.push_back(entry.path().string());
    }

    vector<string> countries;

    for (const string& fileName : files) {
        ifstream file;
        file.open(fileName);

        int n;
        file >> n;

        for (int i = 0; i < n; i++) {
            string s;
            getline(file >> ws, s);
            vector<string> data = split(s, ',');
            countries.push_back(data[0]);
        }

        file.close();
    }

    for (auto country : countries) {
        cout << country << endl;
    }

    return 0;
}
