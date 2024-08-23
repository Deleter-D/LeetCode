/*
    Topic link: https://kamacoder.com/problempage.php?pid=1177
*/
#include <iostream>
#include <vector>

void dfs(std::vector<std::vector<int>> &graph, std::vector<bool> &visited,
         int node) {
    if (visited[node])
        return;

    visited[node] = true;
    for (int i = 0; i < graph.size(); i++) {
        if (graph[node][i] != 0) {
            dfs(graph, visited, i);
        }
    }
}

int main(int argc, char *argv[]) {
    int n, k;
    std::cin >> n >> k;

    std::vector<std::vector<int>> grid(n, std::vector<int>(n));
    int begin, end;
    for (int i = 0; i < k; i++) {
        std::cin >> begin >> end;
        grid[begin - 1][end - 1] = 1;
    }

    std::vector<bool> visited(n, false);

    dfs(grid, visited, 0);

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            std::cout << -1 << std::endl;
            return 0;
        }
    }

    std::cout << 1 << std::endl;
    return 0;
}
