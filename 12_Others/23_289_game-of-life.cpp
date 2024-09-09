/*
    Topic link: https://leetcode.cn/problems/game-of-life/
*/
#include <iostream>
#include <vector>

std::vector<std::vector<int>> dir{{-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
                                  {0, 1},   {1, -1}, {1, 0},  {1, 1}};

void gameOfLife(std::vector<std::vector<int>> &board) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            int count = 0;
            for (int k = 0; k < 8; k++) {
                int i_neighbor = i + dir[k][0];
                int j_neighbor = j + dir[k][1];

                if (i_neighbor < 0 || i_neighbor >= board.size() ||
                    j_neighbor < 0 || j_neighbor >= board[0].size())
                    continue;

                if (abs(board[i_neighbor][j_neighbor]) == 1) {
                    count++;
                }
            }

            if (board[i][j] == 1) {
                if (count < 2 || count > 3) {
                    board[i][j] = -1;
                }
            } else {
                if (count == 3) {
                    board[i][j] = 2;
                }
            }
        }
    }

    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            if (board[i][j] == -1) {
                board[i][j] = 0;
            } else if (board[i][j] == 2) {
                board[i][j] = 1;
            }
        }
    }
}

int main(int argc, char *argv[]) {
    std::vector<std::vector<int>> board{
        {0, 1, 0}, {0, 0, 1}, {1, 1, 1}, {0, 0, 0}};

    gameOfLife(board);

    for (auto vec : board) {
        for (int i : vec) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
