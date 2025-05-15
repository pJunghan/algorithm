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
시간복잡도 :최선:O(N), 최악:O(N+K) clothes 길이 n, unordered_map 삽입 -> 평균 O(1), 전체 루프 O(N), count 크기 K의 루프 O(K)
공간복잡도 :O(K)
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

    cout << "예제 1 결과: " << solution(clothes1) << endl; // 출력: 5
    cout << "예제 2 결과: " << solution(clothes2) << endl; // 출력: 3

    return 0;
}
