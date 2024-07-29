/*
    Topic link: https://leetcode.cn/problems/queue-reconstruction-by-height/
*/
#include <algorithm>
#include <iostream>
#include <vector>

std::vector<std::vector<int>>
reconstructQueue(std::vector<std::vector<int>> &people) {
    std::sort(people.begin(), people.end(),
              [](std::vector<int> a, std::vector<int> b) {
                  if (a[0] == b[0])
                      return a[1] < b[1];
                  else
                      return a[0] > b[0];
              });

    std::vector<std::vector<int>> res;

    for (int i = 0; i < people.size(); i++) {
        int pos = people[i][1];
        res.insert(res.begin() + pos, people[i]);
    }

    return res;
}

int main(int argc, char *argv[]) {
    std::vector<std::vector<int>> people{{7, 0}, {4, 4}, {7, 1},
                                         {5, 0}, {6, 1}, {5, 2}};

    auto res = reconstructQueue(people);

    for (auto vec : res) {
        std::cout << "[" << vec[0] << ", " << vec[1] << "]" << " ";
    }
    std::cout << std::endl;
    return 0;
}
