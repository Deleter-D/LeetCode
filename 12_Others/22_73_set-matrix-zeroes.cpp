/*
    Topic link: https://leetcode.cn/problems/set-matrix-zeroes/
*/
#include <iostream>
#include <vector>

void setZeroes(std::vector<std::vector<int>> &matrix) {
    int m = matrix.size(), n = matrix[0].size();
    bool firstRow = false, firstCol = false;

    for (int i = 0; i < m; i++) {
        if (matrix[i][0] == 0) {
            firstCol = true;
        }
    }
    for (int j = 0; j < n; j++) {
        if (matrix[0][j] == 0) {
            firstRow = true;
        }
    }

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = matrix[0][j] = 0;
            }
        }
    }

    for (int i = 1; i < m; i++) {
        if (matrix[i][0] == 0) {
            for (int j = 1; j < n; j++) {
                matrix[i][j] = 0;
            }
        }
    }

    for (int j = 1; j < n; j++) {
        if (matrix[0][j] == 0) {
            for (int i = 1; i < m; i++) {
                matrix[i][j] = 0;
            }
        }
    }

    if (firstCol) {
        for (int i = 0; i < m; i++) {
            matrix[i][0] = 0;
        }
    }

    if (firstRow) {
        for (int j = 0; j < n; j++) {
            matrix[0][j] = 0;
        }
    }
}

int main(int argc, char *argv[]) {
    std::vector<std::vector<int>> matrix{{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};

    setZeroes(matrix);

    for (auto vec : matrix) {
        for (int i : vec) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
