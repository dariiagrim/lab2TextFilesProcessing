#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <experimental/filesystem>
#include <fstream>

using namespace std;
namespace fs = experimental::filesystem;

vector<string> split(const string &, char);

vector<int> getSortedIndexes(vector<int> &);

int main() {
    string directoryName;

    cout << "Please, write path to directory: ";
    cin >> directoryName;

    vector<string> files;
    for (const auto &entry : fs::directory_iterator(directoryName)) {
        if (entry.path().extension().string() == ".csv")
            files.push_back(entry.path().string());
    }

    vector<string> countries;
    vector<vector<string> > datas;
    for (const string &fileName : files) {
        ifstream file;
        file.open(fileName);

        int n;
        file >> n;

        for (int i = 0; i < n; i++) {
            string s;
            getline(file >> ws, s);
            vector<string> data = split(s, ',');
            countries.push_back(data[0]);
            datas.push_back(data);
        }

        file.close();
    }

    vector<vector<int> > countryPoints(countries.size(), vector<int>());

    for (int i = 0; i < datas.size(); i++) {
        for (int j = 1; j < datas[i].size(); j++) {
            countryPoints[j - 1].push_back(atoi(datas[i][j].c_str()));
        }
    }

    map<string, int> points;

    for (int i = 0; i < countryPoints.size(); i++) {
        vector<int> indexes = getSortedIndexes(countryPoints[i]);
        points[countries[indexes[0]]] += 12;
        points[countries[indexes[1]]] += 10;
        for (int j = 2; j < 10; j++)
            points[countries[indexes[j]]] += 10 - j;
    }

    vector<int> finalPoints;
    for (int i = 0; i < countries.size(); i++) {
        finalPoints.push_back(points[countries[i]]);
    }

    vector<int> indexes = getSortedIndexes(finalPoints);

    for (int i = 0; i < 10; i++) {
        cout << countries[indexes[i]] << ": " << finalPoints[i] << endl;
    }

    return 0;
}

vector<string> split(const string &a, char delimeter) {
    vector<string> splitedString;
    string b;
    for (char symbol : a) {
        if (symbol != delimeter)
            b.push_back(symbol);
        else {
            splitedString.push_back(b);
            b = "";
        }
    }
    splitedString.push_back(b);
    return splitedString;
}

vector<int> getSortedIndexes(vector<int> &points) {
    vector<int> indexes;
    for (int i = 0; i < points.size(); i++)
        indexes.push_back(i);
    for (int i = 0; i < points.size() - 1; i++)
        for (int j = i + 1; j < points.size(); j++)
            if (points[i] < points[j]) {
                swap(points[i], points[j]);
                swap(indexes[i], indexes[j]);
            }
    return indexes;
}
