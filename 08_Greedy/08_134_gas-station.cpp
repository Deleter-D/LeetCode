/*
    Topic link: https://leetcode.cn/problems/gas-station/
*/
#include <climits>
#include <iostream>
#include <vector>

int canCompleteCircuit(std::vector<int> &gas, std::vector<int> &cost) {
    int curGas = 0;
    int minGas = INT_MAX;
    for (int i = 0; i < gas.size(); i++) {
        int rest = gas[i] - cost[i];
        curGas += rest;
        if (curGas < minGas)
            minGas = curGas;
    }
    if (curGas < 0)
        return -1;
    if (minGas >= 0)
        return 0;

    for (int i = gas.size() - 1; i >= 0; i--) {
        int rest = gas[i] - cost[i];
        minGas += rest;
        if (minGas >= 0)
            return i;
    }
    return -1;
}

int main(int argc, char *argv[]) {
    std::vector<int> gas{1, 2, 3, 4, 5};
    std::vector<int> cost{3, 4, 5, 1, 2};

    int res = canCompleteCircuit(gas, cost);

    std::cout << res << std::endl;
    return 0;
}
