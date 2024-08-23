/*
    Topic link: https://kamacoder.com/problempage.php?pid=1177
*/
#include <iostream>
#include <queue>
#include <vector>

void bfs(std::vector<std::vector<int>> &graph, std::vector<bool> &visited,
         int node) {
    std::queue<int> que;
    que.push(node);
    visited[node] = true;

    while (!que.empty()) {
        int cur = que.front();
        que.pop();

        for (int i = 0; i < graph.size(); i++) {
            if (!visited[i] && graph[cur][i] != 0) {
                que.push(i);
                visited[i] = true;
            }
        }
    }
}

int main(int argc, char *argv[]) {
    int n, k;
    std::cin >> n >> k;

    std::vector<std::vector<int>> grid(n, std::vector<int>(n, 0));
    int begin, end;
    for (int i = 0; i < k; i++) {
        std::cin >> begin >> end;
        grid[begin - 1][end - 1] = 1;
    }

    std::vector<bool> visited(n, false);

    bfs(grid, visited, 0);

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            std::cout << -1 << std::endl;
            return 0;
        }
    }

    std::cout << 1 << std::endl;
    return 0;
}
