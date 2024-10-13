/*
    Topic link: https://leetcode.cn/problems/surrounded-regions/
*/
#include <iostream>
#include <vector>

const std::vector<std::pair<int, int>> directions{
    {1, 0}, {-1, 0}, {0, 1}, {0, -1}};

std::vector<std::pair<int, int>> subgraph;
bool isIsolation = true;

void dfs(std::vector<std::vector<char>> &board,
         std::vector<std::vector<bool>> &used, int x, int y) {
    if (board[x][y] == 'X' || used[x][y]) {
        return;
    }

    used[x][y] = true;
    subgraph.push_back({x, y});
    if (x == 0 || x == board.size() - 1 || y == 0 || y == board[0].size() - 1) {
        isIsolation = false;
    }

    for (int i = 0; i < 4; i++) {
        int next_x = x + directions[i].first;
        int next_y = y + directions[i].second;

        if (next_x < 0 || next_x >= board.size() || next_y < 0 ||
            next_y >= board[0].size()) {
            continue;
        }

        dfs(board, used, next_x, next_y);
    }
}

void solve(std::vector<std::vector<char>> &board) {
    std::vector<std::vector<bool>> used(
        board.size(), std::vector<bool>(board[0].size(), false));

    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            if (!used[i][j]) {
                dfs(board, used, i, j);
            }
            if (isIsolation) {
                for (auto coordinate : subgraph) {
                    board[coordinate.first][coordinate.second] = 'X';
                }
            }
            isIsolation = true;
            subgraph.clear();
        }
    }
}

int main(int argc, char const *argv[]) {
    std::vector<std::vector<char>> board{{'X', 'X', 'X', 'X'},
                                         {'X', 'O', 'O', 'X'},
                                         {'X', 'X', 'O', 'X'},
                                         {'X', 'O', 'X', 'X'}};

    solve(board);

    for (auto &vec : board) {
        for (auto &i : vec) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
