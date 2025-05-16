#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// ��� ������ ���ں� ������ K �̻����� ����� ���� �ּ� Ƚ���� ��ȯ
// �ð����⵵: O(N log N)
// �������⵵: O(N)
int solution(vector<int> scoville, int K) {
    int answer = 0;

    // �ּ� ��(priority_queue with greater): O(N log N) �ð� �ҿ�
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());

    while (pq.size() > 1 && pq.top() < K) {
        int first = pq.top(); pq.pop();        // �ּҰ�: O(log N)
        int second = pq.top(); pq.pop();       // �״��� �ּҰ�: O(log N)
        pq.push(first + (second * 2));         // ��� Ǫ��: O(log N)
        answer++;                              // ���� Ƚ�� ����
    }

    // ������ ���� ������ K �̸��̸� ���� (-1 ��ȯ)
    if (!pq.empty() && pq.top() < K) return -1;

    return answer;
}

int main() {
    vector<int> scoville = { 1, 2, 3, 9, 10, 12 };
    int K = 7;

    int result = solution(scoville, K);
    cout << "��� ������ ���ں� ������ " << K << " �̻����� ����� �ּ� Ƚ��: " << result << endl;

    return 0;
}
