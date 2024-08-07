/*
    Topic link: https://kamacoder.com/problempage.php?pid=1052
*/
#include <iostream>
#include <vector>

int maxValue(std::vector<int> &weight, std::vector<int> &value, int pack) {
    std::vector<int> dp(pack + 1, 0);

    for (int i = 0; i < weight.size(); i++) {
        for (int j = 1; j <= pack; j++) {
            if (j - weight[i] >= 0)
                dp[j] = std::max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }

    return dp[pack];
}

int main() {
    int category, pack;
    std::cin >> category;
    std::cin >> pack;

    std::vector<int> weight(category);
    std::vector<int> value(category);
    for (int i = 0; i < category; i++) {
        std::cin >> weight[i];
        std::cin >> value[i];
    }

    int res = maxValue(weight, value, pack);

    std::cout << res << std::endl;
}
