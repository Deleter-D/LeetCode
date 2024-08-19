/*
    Topic link: https://kamacoder.com/problempage.php?pid=1174
*/
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

std::vector<std::vector<int>> dir{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
std::vector<std::pair<int, int>> indices;
bool isolated = true;

void bfs(std::vector<std::vector<int>> &grid,
         std::vector<std::vector<bool>> &visited, int x, int y) {
    std::queue<std::pair<int, int>> que;
    que.push({x, y});
    visited[x][y] = true;
    indices.push_back({x, y});

    while (!que.empty()) {
        auto cur = que.front();
        que.pop();

        int x_cur = cur.first;
        int y_cur = cur.second;

        for (int i = 0; i < 4; i++) {
            int x_next = x_cur + dir[i][0];
            int y_next = y_cur + dir[i][1];

            if (x_next < 0 || x_next >= grid.size() || y_next < 0 ||
                y_next >= grid[0].size())
                continue;

            if (!visited[x_next][y_next] && grid[x_next][y_next]) {
                que.push({x_next, y_next});
                visited[x_next][y_next] = true;
                indices.push_back({x_next, y_next});

                if (x_next == 0 || x_next == grid.size() - 1 || y_next == 0 ||
                    y_next == grid[0].size() - 1) {
                    isolated = false;
                }
            }
        }
    }
}

int main(int argc, char *argv[]) {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> grid(n, std::vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> grid[i][j];
        }
    }

    std::vector<std::vector<bool>> visited(n, std::vector<bool>(m, false));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && grid[i][j] == 1) {
                indices.clear();
                indices.push_back({i, j});
                isolated = true;
                visited[i][j] = true;
                if (i == 0 || i == grid.size() - 1 || j == 0 ||
                    j == grid[0].size() - 1)
                    isolated = false;

                bfs(grid, visited, i, j);

                if (isolated) {
                    for (auto idx : indices) {
                        grid[idx.first][idx.second] = 0;
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cout << grid[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
