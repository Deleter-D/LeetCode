/*
    Topic link: https://kamacoder.com/problempage.php?pid=1182
*/
#include <iostream>
#include <vector>

class DisjointSet {
  public:
    DisjointSet(int n) {
        for (int i = 0; i < n; i++) {
            father.push_back(i);
        }
    }

    int find(int u) { return u == father[u] ? u : father[u] = find(father[u]); }

    bool isSameSet(int u, int v) {
        u = find(u);
        v = find(v);
        return u == v;
    }

    void join(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v)
            return;
        father[v] = u;
    }

  private:
    std::vector<int> father;
};

void getRemoveEdge(std::vector<std::vector<int>> &edges) {
    DisjointSet dset(edges.size());

    for (int i = 0; i < edges.size(); i++) {
        if (dset.isSameSet(edges[i][0], edges[i][1])) {
            std::cout << edges[i][0] << " " << edges[i][1] << std::endl;
            return;
        } else {
            dset.join(edges[i][0], edges[i][1]);
        }
    }
}

bool isTreeAfterRemoveEdge(std::vector<std::vector<int>> &edges,
                           int deletedEdge) {
    DisjointSet dset(edges.size());

    for (int i = 0; i < edges.size(); i++) {
        if (i == deletedEdge)
            continue;
        if (dset.isSameSet(edges[i][0], edges[i][1]))
            return false;
        dset.join(edges[i][0], edges[i][1]);
    }

    return true;
}

int main(int argc, char *argv[]) {
    int n;
    std::cin >> n;
    std::vector<int> inDegree(n + 1, 0);
    std::vector<std::vector<int>> edges;

    int s, t;
    for (int i = 0; i < n; i++) {
        std::cin >> s >> t;
        inDegree[t]++;
        edges.push_back({s, t});
    }

    std::vector<int> vec;
    for (int i = n - 1; i >= 0; i--) {
        if (inDegree[edges[i][1]] == 2)
            vec.push_back(i);
    }

    if (vec.size() > 0) {
        if (isTreeAfterRemoveEdge(edges, vec[0])) {
            std::cout << edges[vec[0]][0] << " " << edges[vec[0]][1]
                      << std::endl;
        } else {
            std::cout << edges[vec[1]][0] << " " << edges[vec[1]][1]
                      << std::endl;
        }
        return 0;
    }

    getRemoveEdge(edges);
    return 0;
}
