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
�ð� ���⵵ : O(n^2 * m) -> ���� for�� ������� O(n^2), substr���� �ִ� m ������ ���ڿ� �����ؼ� O(m) ���ؾ� ��
�������⵵ : O(1)

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
�ð����⵵ : O(n * m) -> ��ȭ��ȣ ���� : n, �ִ� ���� : m , �� ��ȣ���� �ִ� m-1�� ���ξ� �˻�
�������⵵ : O(n * m) -> �ؽü¿� ��� ��ȭ��ȣ ����
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