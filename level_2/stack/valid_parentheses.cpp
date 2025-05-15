#include<string>
#include<iostream>
#include<stack>
using namespace std;

//문제 잘못 이해해서 틀림
//bool solution(string s)
//{
//    bool answer = true;
//    stack<char> parentheses;
//    for (char s_parentheses : s) parentheses.push(s_parentheses);
//
//    while (1) {
//        char check = parentheses.top();
//        if (parentheses.top() != check) {
//            answer = false;
//            break;
//        }
//        else {
//            cout << parentheses.top() << endl;
//            parentheses.pop();
//        }
//        if (parentheses.empty()) break;
//    }
//    return answer;
//}

int main() {
    string s1 = "()()";
    string s2 = "(())()";
    string s3 = "(()(";

    cout << boolalpha; // true/false 출력
    cout << "s1: " << solution(s1) << endl; // true
    cout << "s2: " << solution(s2) << endl; // true
    cout << "s3: " << solution(s3) << endl; // false

    return 0;
}