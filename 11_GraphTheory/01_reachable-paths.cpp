/*
        Topic link: https://kamacoder.com/problempage.php?pid=1170
*/
#include <iostream>
#include <vector>

std::vector<std::vector<int>> res;
std::vector<int> path;

void dfs(std::vector<std::vector<int>> &graph, int cur, int end) {
    if (cur == end) {
        res.push_back(path);
        return;
    }
    for (int i = 1; i <= end; i++) {
        if (graph[cur][i] == 1) {
            path.push_back(i);
            dfs(graph, i, end);
            path.pop_back();
        }
    }
}

int main(int argc, char *argv[]) {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> graph(n + 1, std::vector<int>(n + 1, 0));
    while (m--) {
        int beg, end;
        std::cin >> beg >> end;
        graph[beg][end] = 1;
    }

    path.push_back(1);
    dfs(graph, 1, n);

    if (res.size() == 0)
        std::cout << -1 << std::endl;
    for (auto &vec : res) {
        for (int i = 0; i < vec.size() - 1; i++) {
            std::cout << vec[i] << " ";
        }
        std::cout << vec[vec.size() - 1] << std::endl;
    }
    return 0;
}
