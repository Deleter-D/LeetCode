/*
    Topic link: https://kamacoder.com/problempage.php?pid=1176
*/
#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

std::vector<std::vector<int>> dir{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int count = 0;

void bfs(std::vector<std::vector<int>> &grid,
         std::vector<std::vector<bool>> &visited, int x, int y, int mark) {
    std::queue<std::pair<int, int>> que;
    que.push({x, y});
    visited[x][y] = true;
    grid[x][y] = mark;
    count++;

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

            if (visited[x_next][y_next] || grid[x_next][y_next] == 0)
                continue;

            que.push({x_next, y_next});
            visited[x_next][y_next] = true;
            grid[x_next][y_next] = mark;
            count++;
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
    std::unordered_map<int, int> island_area;
    int mark = 2;
    bool is_whole_island = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 0)
                is_whole_island = false;
            if (!visited[i][j] && grid[i][j] == 1) {
                count = 0;
                bfs(grid, visited, i, j, mark);
                island_area[mark] = count;
                mark++;
            }
        }
    }

    if (is_whole_island) {
        std::cout << n * m << std::endl;
        return 0;
    }

    int res = 0;
    std::unordered_set<int> visited_island;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            count = 1;
            visited_island.clear();
            if (grid[i][j] == 0) {
                for (int k = 0; k < 4; k++) {
                    int i_next = i + dir[k][0];
                    int j_next = j + dir[k][1];
                    if (i_next < 0 || i_next >= n || j_next < 0 || j_next >= m)
                        continue;
                    if (visited_island.count(grid[i_next][j_next]))
                        continue;
                    count += island_area[grid[i_next][j_next]];
                    visited_island.insert(grid[i_next][j_next]);
                }
            }
            res = std::max(count, res);
        }
    }

    std::cout << res << std::endl;

    return 0;
}
