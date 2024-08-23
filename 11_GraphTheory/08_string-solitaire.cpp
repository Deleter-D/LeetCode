/*
    Topic link: https://kamacoder.com/problempage.php?pid=1183
*/
#include <iostream>
#include <ostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>

int main(int argc, char *argv[]) {
    int n;
    std::cin >> n;

    std::string beginStr, endStr;
    std::cin >> beginStr >> endStr;

    std::string tmp;
    std::unordered_set<std::string> strList(n);
    for (int i = 0; i < n; i++) {
        std::cin >> tmp;
        strList.insert(tmp);
    }

    std::unordered_map<std::string, int> visitMap;

    std::queue<std::string> que;
    que.push(beginStr);

    visitMap.insert(std::pair<std::string, int>(beginStr, 1));

    while (!que.empty()) {
        std::string word = que.front();
        que.pop();
        int path = visitMap[word];

        for (int i = 0; i < word.size(); i++) {
            std::string newWord = word;

            for (int j = 0; j < 26; j++) {
                newWord[i] = j + 'a';
                if (newWord == endStr) {
                    std::cout << path + 1 << std::endl;
                    return 0;
                }
                if (strList.find(newWord) != strList.end() &&
                    visitMap.find(newWord) == visitMap.end()) {
                    visitMap.insert(
                        std::pair<std::string, int>(newWord, path + 1));
                    que.push(newWord);
                }
            }
        }
    }

    std::cout << 0 << std::endl;

    return 0;
}
