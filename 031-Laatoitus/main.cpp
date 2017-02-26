#include <iostream>
#include <set>
#include <vector>
#include <cmath>
#include <unordered_set>

using namespace std;

long counter = 0;

int width, height, rows;
long options;
unordered_set<int> validRows;
vector<vector<int>> rowOptions;

void createRows(int row, int i) {
    if ( i == width ) validRows.insert(row);
    if (i > width) return;
    createRows((row << 2), i+2);
    createRows(((row << 1) | 1), i+1);
}

void countOptions() {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < rows; ++j) {
            if ((i & j) == 0 && validRows.find(i | j) != validRows.end()) rowOptions[i].push_back(j);
        }
    }
}

void findOptions(int row, int n) {
    if (n == height - 1) {
        if (validRows.find(row) != validRows.end()) options++;
        return;
    }
    for (int i = 0; i < rowOptions[row].size(); ++i) {
        findOptions(rowOptions[row][i], n+1);
    }
}

int main() {
    cin.sync_with_stdio(false);
    cin >> width >> height;
    rows = pow(2, width);
    rowOptions = vector<vector<int>>(rows, vector<int>(rows));
    options = 0;
    createRows(0, 0);
    countOptions();
    findOptions(0, 0);
    cout << options;
}