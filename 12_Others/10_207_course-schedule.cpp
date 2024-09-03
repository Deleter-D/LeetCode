/*
    Topic link: https://leetcode.cn/problems/course-schedule/
*/
#include <iostream>
#include <list>
#include <stack>
#include <vector>

bool valid = true;

void dfs(std::vector<std::list<int>> &graph, std::vector<int> &visited,
         std::stack<int> &res, int node) {
    visited[node] = 1;
    for (int node : graph[node]) {
        if (visited[node] == 0) {
            dfs(graph, visited, res, node);
            if (!valid)
                return;
        } else if (visited[node] == 1) {
            valid = false;
            return;
        }
    }
    visited[node] = 2;
}

bool canFinish(int numCourses, std::vector<std::vector<int>> &prerequisites) {
    std::vector<std::list<int>> graph(numCourses);
    for (auto vec : prerequisites) {
        graph[vec[0]].push_back(vec[1]);
    }

    std::vector<int> visited(numCourses, 0);
    std::stack<int> res;
    for (int i = 0; i < numCourses && valid; i++) {
        if (!visited[i]) {
            dfs(graph, visited, res, i);
        }
    }

    return valid;
}

int main(int argc, char *argv[]) {
    std::vector<std::vector<int>> prerequisites{{1, 0}, {0, 1}};

    bool res = canFinish(2, prerequisites);

    std::cout << (res ? "true" : "false") << std::endl;
    return 0;
}
