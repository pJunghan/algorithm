#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    unordered_map<string, int> count;

    for (int i = 0; i < clothes.size(); i++) {
        string type = clothes[i][1];
        count[type]++;
    }

    int answer = 1;
    for (auto num : count) answer *= (num.second + 1);

    return answer - 1;
}
/*
�ð����⵵ :�ּ�:O(N), �־�:O(N+K) clothes ���� n, unordered_map ���� -> ��� O(1), ��ü ���� O(N), count ũ�� K�� ���� O(K)
�������⵵ :O(K)
*/

int main() {
    vector<vector<string>> clothes1 = {
        {"yellow_hat", "headgear"},
        {"blue_sunglasses", "eyewear"},
        {"green_turban", "headgear"}
    };

    vector<vector<string>> clothes2 = {
        {"crow_mask", "face"},
        {"blue_sunglasses", "face"},
        {"smoky_makeup", "face"}
    };

    cout << "���� 1 ���: " << solution(clothes1) << endl; // ���: 5
    cout << "���� 2 ���: " << solution(clothes2) << endl; // ���: 3

    return 0;
}
