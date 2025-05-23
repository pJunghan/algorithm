#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool is_valid(const string& s) {
    stack<char> stk;
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            stk.push(c);
        }
        else {
            if (stk.empty()) return false;
            char top = stk.top();
            if ((c == ')' && top != '(') ||
                (c == ']' && top != '[') ||
                (c == '}' && top != '{')) {
                return false;
            }
            stk.pop();
        }
    }
    return stk.empty();
}

int solution(string s) {
    int answer = 0;
    int n = s.length();
    for (int i = 0; i < n; i++) { // O(n)
        string rotated = s.substr(i) + s.substr(0, i);
        if (is_valid(rotated)) answer++;//O(n)
    }
    return answer;
}

int main() {
    vector<string> test_cases = {
        "[](){}",
        "}]()[{",
        "[)(]",
        "}}}",
    };

    for (const string& s : test_cases) {
        cout << "Input: " << s << "\n";
        cout << "Valid Rotations: " << solution(s) << "\n\n";
    }

    return 0;
}

//시간 복잡도	O(n^2)
//공간 복잡도	O(n)