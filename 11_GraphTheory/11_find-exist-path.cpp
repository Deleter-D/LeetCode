/*
    Topic link: https://kamacoder.com/problempage.php?pid=1179
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

int main(int argc, char *argv[]) {
    int n, m;
    std::cin >> n >> m;

    DisjointSet dset(n);

    int u, v;
    for (int i = 0; i < m; i++) {
        std::cin >> u >> v;
        dset.join(u, v);
    }

    std::cin >> u >> v;
    bool res = dset.isSameSet(u, v);

    if (res)
        std::cout << 1 << std::endl;
    else
        std::cout << 0 << std::endl;

    return 0;
}
