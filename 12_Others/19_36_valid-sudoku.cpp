/*
    Topic link: https://leetcode.cn/problems/valid-sudoku/
*/
#include <iostream>
#include <unordered_set>
#include <vector>

bool isValidRow(std::vector<char> &row) {
    std::unordered_set<char> uset;
    for (char c : row) {
        if (c != '.') {
            if (uset.find(c) != uset.end())
                return false;
            else
                uset.insert(c);
        }
    }

    return true;
}

bool isValidCol(std::vector<std::vector<char>> &board, int col) {
    std::unordered_set<char> uset;
    for (int i = 0; i < board.size(); i++) {
        if (board[i][col] != '.') {
            if (uset.find(board[i][col]) != uset.end())
                return false;
            else
                uset.insert(board[i][col]);
        }
    }

    return true;
}

bool isValidMatrix(std::vector<std::vector<char>> &board, int row, int col) {
    std::unordered_set<char> uset;
    for (int i = row; i < row + 3; i++) {
        for (int j = col; j < col + 3; j++) {
            if (board[i][j] != '.') {
                if (uset.find(board[i][j]) != uset.end())
                    return false;
                else
                    uset.insert(board[i][j]);
            }
        }
    }

    return true;
}

bool isValidSudoku(std::vector<std::vector<char>> &board) {
    bool res = true;
    for (int i = 0; i < board.size(); i++) {
        res = res && isValidRow(board[i]);
    }

    for (int j = 0; j < board[0].size(); j++) {
        res = res && isValidCol(board, j);
    }

    for (int i = 0; i < board.size(); i += 3) {
        for (int j = 0; j < board[0].size(); j += 3) {
            res = res && isValidMatrix(board, i, j);
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    std::vector<std::vector<char>> board{
        {'8', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    bool res = isValidSudoku(board);

    std::cout << (res ? "true" : "false") << std::endl;
    return 0;
}
