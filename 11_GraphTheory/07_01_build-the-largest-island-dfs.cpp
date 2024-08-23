/*
    Topic link: https://kamacoder.com/problempage.php?pid=1176
*/
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

std::vector<std::vector<int>> dir{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int count = 0;

void dfs(std::vector<std::vector<int>> &grid,
         std::vector<std::vector<bool>> &visited, int x, int y, int mark) {
    if (visited[x][y] || grid[x][y] == 0)
        return;

    visited[x][y] = true;
    grid[x][y] = mark;
    count++;

    for (int i = 0; i < 4; i++) {
        int x_next = x + dir[i][0];
        int y_next = y + dir[i][1];

        if (x_next < 0 || x_next >= grid.size() || y_next < 0 ||
            y_next >= grid[0].size())
            continue;

        dfs(grid, visited, x_next, y_next, mark);
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
                dfs(grid, visited, i, j, mark);
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
