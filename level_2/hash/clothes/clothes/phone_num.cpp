#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;

/*
bool solution(vector<string> phone_book) {
    for (int i = 0; i < phone_book.size(); i++) {
        for (int j = 0; j < phone_book.size(); j++) {
            if (i == j) continue;
            if (phone_book[i].substr(0, phone_book[j].size()) == phone_book[j]) {
                return false;
            }
        }
    }
    return true;
}
시간 복잡도 : O(n^2 * m) -> 이중 for문 사용으로 O(n^2), substr으로 최대 m 길이의 문자열 복사해서 O(m) 곱해야 함
공간복잡도 : O(1)

*/
bool solution(vector<string> phone_book) {

    unordered_set<string> phone_set;

    for (const string& num : phone_book) phone_set.insert(num);
    for (const string& num : phone_book) {
        for (int len = 1; len < (int)num.size(); len++) {
            string prefix = num.substr(0, len);
            if (phone_set.find(prefix) != phone_set.end()) return false;
        }
    }
    return true;
}
/*
시간복잡도 : O(n * m) -> 전화번호 개수 : n, 최대 길이 : m , 각 번호마다 최대 m-1개 접두어 검사
공간복잡도 : O(n * m) -> 해시셋에 모든 전화번호 저장
*/
int main() {
    vector<string> phone_book1 = { "119", "97674223", "1195524421" };
    vector<string> phone_book2 = { "123", "456", "789" };
    vector<string> phone_book3 = { "12", "123", "1235", "567", "88" };

    cout << boolalpha;
    cout << "Test 1: " << solution(phone_book1) << endl;
    cout << "Test 2: " << solution(phone_book2) << endl;
    cout << "Test 3: " << solution(phone_book3) << endl;

    return 0;
}