/*
    Topic link: https://leetcode.cn/problems/spiral-matrix/
*/
#include <iostream>
#include <vector>

std::vector<int> spiralOrder(std::vector<std::vector<int>> &matrix) {
    int row = matrix.size(), col = matrix[0].size();
    int stop = 1;
    int startRow = 0, startCol = 0;

    std::vector<int> res;
    int left = 0, right = col - 1;
    int top = 0, bottom = row - 1;
    while (left <= right && top <= bottom) {
        for (int j = left; j <= right; j++) {
            res.push_back(matrix[top][j]);
        }
        for (int i = top + 1; i <= bottom; i++) {
            res.push_back(matrix[i][right]);
        }
        if (left < right && top < bottom) {
            for (int j = right - 1; j > left; j--) {
                res.push_back(matrix[bottom][j]);
            }
            for (int i = bottom; i > top; i--) {
                res.push_back(matrix[i][left]);
            }
        }
        left++;
        right--;
        top++;
        bottom--;
    }

    return res;
}

int main(int argc, char *argv[]) {
    std::vector<std::vector<int>> matrix{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    auto res = spiralOrder(matrix);

    for (int i : res) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}
