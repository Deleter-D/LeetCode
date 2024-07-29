/*
    Topic link: https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/
*/
#include <iostream>
#include <ostream>
#include <vector>

int maxProfit(std::vector<int> &prices) {
    int res = 0;

    for (int i = 1; i < prices.size(); i++) {
        if (prices[i] - prices[i - 1] > 0)
            res += prices[i] - prices[i - 1];
    }

    return res;
}

int main(int argc, char *argv[]) {
    std::vector<int> nums{7, 1, 5, 3, 6, 4};

    int res = maxProfit(nums);

    std::cout << res << std::endl;
    return 0;
}
