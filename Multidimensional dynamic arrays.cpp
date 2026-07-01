#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;    


//3

void addColumn(vector<vector<int>>& matrix, int position, int value) {
    for (int i = 0; i < matrix.size(); ++i) {
        matrix[i].insert(matrix[i].begin() + position, value);
    }
}




int main() {
    //1
    vector<string> students(5);

    for (int i = 0; i < 5; ++i) {
        getline(cin, students[i]);
    }

    sort(students.begin(), students.end());

    for (const auto& student : students) {
        cout << student << endl;
    }

    //2

    srand(time(0));

    int rows = 5;
    int cols = 4;
    vector<vector<int>> matrix(rows, vector<int>(cols));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = rand() % 6;
        }
    }

    vector<vector<int>> result;

    for (int i = 0; i < rows; ++i) {
        bool has_zero = false;

        for (int j = 0; j < cols; ++j) {
            if (matrix[i][j] == 0) {
                has_zero = true;
                break;
            }
        }

        if (!has_zero) {
            result.push_back(matrix[i]);
        }
    }

    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[i].size(); ++j) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }



    //3

    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int pos = 1;
    int newValue = 99;

    addColumn(matrix, pos, newValue);

    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }


    return 0;
}
