/*
    Topic link: https://kamacoder.com/problempage.php?pid=1178
*/
#include <iostream>
#include <vector>

std::vector<std::vector<int>> dir{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int main(int argc, char *argv[]) {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> grid(n, std::vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> grid[i][j];
        }
    }

    int res = 0;
    std::vector<std::vector<bool>> visited(n, std::vector<bool>(m, false));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1) {
                for (int k = 0; k < 4; k++) {
                    int x_next = i + dir[k][0];
                    int y_next = j + dir[k][1];

                    if (x_next < 0 || x_next >= n || y_next < 0 ||
                        y_next >= m || grid[x_next][y_next] == 0)
                        res++;
                }
            }
        }
    }

    std::cout << res << std::endl;
    return 0;
}
