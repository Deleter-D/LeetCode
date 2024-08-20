/*
    Topic link: https://kamacoder.com/problempage.php?pid=1175
*/
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

std::vector<std::vector<int>> dir{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void bfs(std::vector<std::vector<int>> &grid,
         std::vector<std::vector<bool>> &visited, int x, int y) {
    std::queue<std::pair<int, int>> que;
    que.push({x, y});
    visited[x][y] = true;

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

            if (visited[x_next][y_next] ||
                grid[x_next][y_next] < grid[x_cur][y_cur])
                continue;

            que.push({x_next, y_next});
            visited[x_next][y_next] = true;
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

    std::vector<std::vector<bool>> topLeftVisited(n,
                                                  std::vector<bool>(m, false));
    std::vector<std::vector<bool>> bottomRightVisited(
        n, std::vector<bool>(m, false));
    for (int i = 0; i < n; i++) {
        bfs(grid, topLeftVisited, i, 0);         // left
        bfs(grid, bottomRightVisited, i, m - 1); // right
    }

    for (int j = 0; j < m; j++) {
        bfs(grid, topLeftVisited, 0, j); // top
        bfs(grid, bottomRightVisited, n - 1, j);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (topLeftVisited[i][j] && bottomRightVisited[i][j])
                std::cout << i << " " << j << std::endl;
        }
    }
    return 0;
}
