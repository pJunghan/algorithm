#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 모든 음식의 스코빌 지수를 K 이상으로 만들기 위한 최소 횟수를 반환
// 시간복잡도: O(N log N)
// 공간복잡도: O(N)
int solution(vector<int> scoville, int K) {
    int answer = 0;

    // 최소 힙(priority_queue with greater): O(N log N) 시간 소요
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());

    while (pq.size() > 1 && pq.top() < K) {
        int first = pq.top(); pq.pop();        // 최소값: O(log N)
        int second = pq.top(); pq.pop();       // 그다음 최소값: O(log N)
        pq.push(first + (second * 2));         // 섞어서 푸시: O(log N)
        answer++;                              // 섞은 횟수 증가
    }

    // 마지막 남은 음식이 K 미만이면 실패 (-1 반환)
    if (!pq.empty() && pq.top() < K) return -1;

    return answer;
}

int main() {
    vector<int> scoville = { 1, 2, 3, 9, 10, 12 };
    int K = 7;

    int result = solution(scoville, K);
    cout << "모든 음식의 스코빌 지수를 " << K << " 이상으로 만드는 최소 횟수: " << result << endl;

    return 0;
}
