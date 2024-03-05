/*
    Topic link: https://leetcode.cn/problems/ransom-note/
*/
#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

bool canConstruct(string ransomNote, string magazine) {
    multiset<char> record(magazine.cbegin(), magazine.cend());
    for (char c : ransomNote) {
        auto iter = record.find(c);
        if (iter != record.cend()) {
            record.erase(iter);
        } else {
            return false;
        }
    }

    return true;
}

bool canConstruct2(string ransomNote, string magazine) {
    vector<int> record(26, 0);
    if (ransomNote.size() > magazine.size())
        return false;

    for (char c : magazine) {
        record[c - 'a']++;
    }
    for (char c : ransomNote) {
        record[c - 'a']--;
        if (record[c - 'a'] < 0)
            return false;
    }

    return true;
}

int main(int argc, char *argv[]) {
    string ransomNote("aa");
    string magazine("aab");

    cout << canConstruct(ransomNote, magazine) << endl;
    cout << canConstruct2(ransomNote, magazine) << endl;
    return 0;
}
