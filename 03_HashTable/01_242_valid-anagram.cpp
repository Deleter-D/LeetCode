/*
    Topic link: https://leetcode.cn/problems/valid-anagram/
*/
#include <iostream>
#include <map>
using namespace std;

bool isAnagram(string s, string t) {
    map<char, int> s_counter, t_counter;
    for (char c : s) { // 统计s字符串出现字母的数量
        s_counter[c]++;
    }
    for (char c : t) { // 统计t字符串出现字母的数量
        t_counter[c]++;
    }

    if (s_counter.size() < t_counter.size()) // 为了遍历出现字母更多的map而交换
        swap(s_counter, t_counter);

    for (auto begin = s_counter.cbegin(); begin != s_counter.cend(); begin++) {
        if (t_counter[begin->first] != begin->second)
            return false;
    }

    return true;
}

int main(int argc, char *argv[]) {
    string s("a");
    string t("ab");
    cout << isAnagram(s, t) << endl;
    return 0;
}
