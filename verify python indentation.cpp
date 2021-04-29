#include "bits/stdc++.h"

using namespace std;

int getIndentSize(string s) {
    int indentSize = 0;
    for (char c: s) {
        if (c == ' ') indentSize += 1;
        else break;
    }
    return indentSize;
}

bool colCheck(string s, bool flag) {
    if (s.empty()) return flag;
    return s[s.length() - 1] == ':';
}

void verifyPythonIndentation(vector<string> &code) {
    bool flag = false;
    stack<int> indentLevel;
    indentLevel.push(0);
    for (string s : code) {
        int newIndentSize = getIndentSize(s);
        if (flag) {
            if (newIndentSize > indentLevel.top()) {
                indentLevel.push(newIndentSize);
            } else {
                cout << "InValid";
                return;
            }
        } else {
            if (newIndentSize > indentLevel.top()) {
                cout << "InValid";
                return;
            } else if (newIndentSize < indentLevel.top()) {
                while (indentLevel.top() > newIndentSize) {
                    indentLevel.pop();
                }
                if (indentLevel.top() == newIndentSize) {
                    cout << "valid";
                    return;
                } else {
                    cout << "InValid";
                    return;
                }
            }
        }
        flag = colCheck(s, flag);
    }
    cout << "Valid";
}

int main() {
    vector<string> code = {"num = 29",
                           "",
                           "flag = False",
                           "",
                           "if num > 1:",
                           "    for i in range(2, num):",
                           "        if (num % i) == 0:",
                           "            flag = True",
                           "            break",
                           "",
                           "if flag:",
                           "    print(num, \"is not a prime number\")",
                           "else:",
                           "    print(num, \"is a prime number\")"
    };
    verifyPythonIndentation(code);
    return 0;
}
