/*
    Topic link: https://leetcode.cn/problems/rotate-image/
*/
#include <iostream>
#include <utility>
#include <vector>

void rotate(std::vector<std::vector<int>> &matrix) {
    int n = matrix.size();

    for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < n; j++) {
            std::swap(matrix[i][j], matrix[n - i - 1][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            std::swap(matrix[i][j], matrix[j][i]);
        }
    }
}

int main(int argc, char *argv[]) {
    std::vector<std::vector<int>> matrix{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    rotate(matrix);

    for (auto vec : matrix) {
        for (int i : vec) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
