/*
    Topic link:
   https://leetcode.cn/problems/substring-with-concatenation-of-all-words/
*/
#include <cstring>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

std::vector<int> findSubstring(std::string s, std::vector<std::string> &words) {
    std::vector<int> res;

    int m = words.size(), n = words[0].size(), ls = s.size();

    for (int i = 0; i < n && i + m * n <= ls; i++) { // 遍历每个起始位置
        // 当前窗口内单词出现次数与words中单词出现次数的差值
        std::unordered_map<std::string, int> diff;

        // 统计从起始位置i开始的m个单词
        for (int j = 0; j < m; j++) {
            diff[s.substr(i + j * n, n)]++;
        }
        // 遍历words中的单词，在diff中减去相应单词出现的次数
        for (std::string &word : words) {
            if (--diff[word] == 0) {
                diff.erase(word);
            }
        }
        // 此时已经将窗口内单词出现次数与words中单词出现次数的差值统计完毕

        // 内层窗口，滑动检查每个长度为ls的组合
        for (int start = i; start < ls - m * n + 1; start += n) {
            if (start != i) {
                // 窗口右侧进入的长度为n的单词
                std::string word = s.substr(start + (m - 1) * n, n);
                // 添加进diff中
                if (++diff[word] == 0) {
                    diff.erase(word);
                }
                // 窗口左侧离开的长度为n的单词
                word = s.substr(start - n, n);
                // 从diff中删去
                if (--diff[word] == 0) {
                    diff.erase(word);
                }
            }
            // 若diff为空说明当前窗口内单词的出现次数恰好与words中相同
            if (diff.empty()) {
                res.push_back(start);
            }
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    std::string s("wordgoodgoodgoodbestword");
    std::vector<std::string> words{"word", "good", "best", "good"};

    auto res = findSubstring(s, words);

    for (auto i : res) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}
