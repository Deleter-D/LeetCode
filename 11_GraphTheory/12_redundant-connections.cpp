/*
    Topic link: https://kamacoder.com/problempage.php?pid=1181
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
    int n;
    std::cin >> n;

    DisjointSet dset(n);

    int u, v;
    std::cin >> u >> v;
    dset.join(u, v);
    for (int i = 1; i < n; i++) {
        std::cin >> u >> v;
        if (dset.isSameSet(u, v)) {
            std::cout << u << " " << v << std::endl;
        } else {
            dset.join(u, v);
        }
    }

    return 0;
}
