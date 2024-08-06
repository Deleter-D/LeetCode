/*
    Topic link: https://kamacoder.com/problempage.php?pid=1046
*/
#include <iostream>
#include <vector>

int maxValue(std::vector<int> &weight, std::vector<int> &value, int pack) {
    int category = weight.size();
    std::vector<std::vector<int>> dp(category, std::vector<int>(pack + 1, 0));

    for (int i = 0; i < category; i++) {
        dp[i][0] = 0;
    }
    for (int j = weight[0]; j <= pack; j++) {
        dp[0][j] = value[0];
    }

    for (int i = 1; i < category; i++) {
        for (int j = 1; j <= pack; j++) {
            if (j < weight[i])
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] =
                    std::max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
        }
    }

    return dp[weight.size() - 1][pack];
}

int main() {
    int category, pack;
    std::cin >> category;
    std::cin >> pack;

    std::vector<int> weight(category);
    std::vector<int> value(category);

    for (int i = 0; i < category; i++) {
        std::cin >> weight[i];
    }
    for (int i = 0; i < category; i++) {
        std::cin >> value[i];
    }

    int res = maxValue(weight, value, pack);

    std::cout << res << std::endl;
}
