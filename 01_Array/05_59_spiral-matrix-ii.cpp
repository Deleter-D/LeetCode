/*
    Topic link: https://leetcode.cn/problems/spiral-matrix-ii/
*/
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> generateMatrix(int n) {
    int start_row = 0, start_col = 0;
    vector<vector<int>> res(n, vector<int>(n, 0));
    int loop = n / 2;
    int offset = 1;
    int count = 1;
    int i, j;
    while (loop--) {
        for (j = start_col; j < n - offset; j++) {
            res[start_row][j] = count++;
        }
        for (i = start_row; i < n - offset; i++) {
            res[i][j] = count++;
        }
        for (; j > start_col; j--) {
            res[i][j] = count++;
        }
        for (; i > start_row; i--) {
            res[i][j] = count++;
        }
        start_row++;
        start_col++;
        offset++;
    }

    if (n % 2) {
        int mid = n / 2;
        res[mid][mid] = count;
    }

    return res;
}

int main(int argc, char *argv[]) {
    vector<vector<int>> res = generateMatrix(5);
    for (vector<int> vec : res) {
        for (int x : vec) {
            cout << setw(4) << x;
        }
        cout << "\n";
    }
    return 0;
}
