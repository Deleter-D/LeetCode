/*
    Topic link: https://leetcode.cn/problems/spiral-matrix-ii/
*/
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> generateMatrix(int n) {
    int start_row = 0, start_col = 0; // 记录起始行和列
    vector<vector<int>> res(n, vector<int>(n, 0));
    int loop = n / 2; // 计算所需的圈数
    int offset = 1; // 控制每次遍历的长度，即末端已经处理过的数据宽度
    int count = 1; // 用于计数和赋值
    int i, j;
    while (loop--) {
        // 向右移动
        for (j = start_col; j < n - offset; j++) {
            res[start_row][j] = count++;
        }
        // 向下移动
        for (i = start_row; i < n - offset; i++) {
            res[i][j] = count++;
        }
        // 向左移动
        for (; j > start_col; j--) {
            res[i][j] = count++;
        }
        // 向上移动
        for (; i > start_row; i--) {
            res[i][j] = count++;
        }
        start_row++; // 起始行加一
        start_col++; // 起始列加一
        offset++;    // 已经处理过的数据宽度加一
    }

    if (n % 2) { // 若n为奇数，则存在独立的中心点
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
