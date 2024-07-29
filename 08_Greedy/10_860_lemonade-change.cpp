/*
    Topic link: https://leetcode.cn/problems/lemonade-change/
*/
#include <iostream>
#include <iterator>
#include <map>
#include <vector>

bool lemonadeChange(std::vector<int> &bills) {
    if (bills[0] != 5)
        return false;

    std::map<int, int> changes{{5, 0}, {10, 0}, {20, 0}};
    for (int i = 0; i < bills.size(); i++) {
        changes[bills[i]]++;
        if (bills[i] == 5)
            continue;
        else if (bills[i] == 10) {
            if (changes[5] > 0)
                changes[5]--;
            else
                return false;
        } else {
            if (changes[5] == 0)
                return false;

            if (changes[10] > 0) {
                changes[10]--;
                changes[5]--;
            } else {
                if (changes[5] < 3)
                    return false;
                else
                    changes[5] -= 3;
            }
        }
    }

    return true;
}

int main(int argc, char *argv[]) {
    std::vector<int> bills{5, 5, 5, 10, 20};

    bool res = lemonadeChange(bills);

    std::cout << (res ? "true" : "false") << std::endl;
    return 0;
}
