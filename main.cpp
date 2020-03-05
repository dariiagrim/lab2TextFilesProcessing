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
            if (datas[i][j][0] != '-')
                countryPoints[j - 1].push_back(atoi(datas[i][j].c_str()));
            else {
                if (countryPoints[j-1].size() != 0)
                    countryPoints[j - 1].push_back(*(countryPoints[j - 1].end() - 1));
                else
                    countryPoints[j - 1].push_back(0);
            }
        }
    }

    for (int i = 0; i < countryPoints.size(); i++) {
        cout << countries[i] << ": ";
        for (int j = 0; j < countryPoints[i].size(); j++)
            cout << countryPoints[i][j] << " ";
        cout << endl;
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

    ofstream out("results.csv");

    for (int i = 0; i < 10; i++) {
        out << countries[indexes[i]] << "," << finalPoints[i] << endl;
    }

    out.close();

    return 0;
}

vector<string> split(const string &a, char delimeter) {
    vector<string> splitedString;
    string b;
    bool Flag = false;
    for (int i = 0; i < a.length(); i++) {
        if (a[i] == '"' && !Flag) {
            Flag = true;
            continue;
        }
        if (!Flag) {
            if (a[i] != delimeter)
                b.push_back(a[i]);
            else {
                splitedString.push_back(b);
                b = "";
            }
        } else {
            if (a[i] != '"')
                b.push_back(a[i]);
            else {
                Flag = false;

            }
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
