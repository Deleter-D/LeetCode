/*
    Topic link: https://leetcode.cn/problems/simplify-path/
*/
#include <iostream>
#include <stack>
#include <string>
#include <vector>

std::vector<std::string> split(std::string &path) {
    std::vector<std::string> res;

    for (int i = 0; i < path.size(); i++) {
        while (i > 0 && path[i] == '/' && path[i - 1] == '/') {
            path.erase(i, 1);
        }
    }
    if (path[path.size() - 1] != '/') {
        path.push_back('/');
    }

    int len = 0;
    for (int i = 1; i < path.size(); i++) {
        if (path[i] == '/') {
            res.push_back(path.substr(i - len, len));
            len = 0;
        } else {
            len++;
        }
    }

    return res;
}

std::string simplifyPath(std::string path) {
    std::vector<std::string> splits = split(path);

    std::stack<std::string> st;
    for (std::string &dir : splits) {
        if (dir == ".") {
            continue;
        } else if (dir == "..") {
            if (!st.empty()) {
                st.pop();
            }
        } else {
            st.push(dir);
        }
    }

    std::string res;
    while (!st.empty()) {
        res.insert(0, st.top());
        res.insert(0, "/");
        st.pop();
    }

    if (res == "") {
        res.push_back('/');
    }

    return res;
}

int main(int argc, char *argv[]) {
    std::string path("/.../a/../b/c/../d/./");

    auto res = simplifyPath(path);

    std::cout << res << std::endl;

    return 0;
}
