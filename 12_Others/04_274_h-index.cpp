/*
    Topic link: https://leetcode.cn/problems/h-index/
*/
#include <iostream>
#include <vector>

int hIndex(std::vector<int> &citations) {
    int h = citations.size();

    while (h >= 0) {
        int count = 0;
        for (int i = 0; i < citations.size(); i++) {
            if (citations[i] >= h)
                count++;
        }
        if (count >= h)
            break;
        else
            h--;
    }

    return h;
}

int main(int argc, char *argv[]) {
    std::vector<int> citations{3, 0, 6, 1, 5};

    int h = hIndex(citations);

    std::cout << h << std::endl;
    return 0;
}
