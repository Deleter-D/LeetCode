/*
    Topic link: https://leetcode.cn/problems/insert-delete-getrandom-o1/
*/
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <random>
#include <unordered_set>

class RandomizedSet {
  public:
    RandomizedSet() {}

    bool insert(int val) {
        auto res = uset.insert(val);
        return res.second;
    }

    bool remove(int val) {
        auto iter = uset.find(val);
        if (iter == uset.end())
            return false;
        else {
            uset.erase(iter);
            return true;
        }
    }

    int getRandom() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<size_t> dis(0, uset.size() - 1);

        size_t idx = dis(gen);
        auto iter = uset.begin();
        std::advance(iter, idx);

        return *iter;
    }

  private:
    std::unordered_set<int> uset;
};

int main(int argc, char *argv[]) {
    RandomizedSet rset;

    std::cout << (rset.insert(1) ? "true" : "false") << std::endl;
    std::cout << (rset.remove(2) ? "true" : "false") << std::endl;
    std::cout << (rset.insert(2) ? "true" : "false") << std::endl;
    std::cout << rset.getRandom() << std::endl;
    std::cout << (rset.remove(1) ? "true" : "false") << std::endl;
    std::cout << (rset.insert(2) ? "true" : "false") << std::endl;
    std::cout << rset.getRandom() << std::endl;
    return 0;
}
