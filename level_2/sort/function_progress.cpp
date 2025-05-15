#include <iostream>
#include <vector>
#include <string>

using namespace std;


vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer; 
    vector<int> days;
    // [�������⵵ : O(2N)]

    for (int i = 0; i < progresses.size(); i++) {
        int remain = 100 - progresses[i];
        int day = (remain + speeds[i] - 1) / speeds[i];
        days.push_back(day);
    }
    // [�ð����⵵ : O(N)]
    int current = days[0];
    int count = 1;

    for (int i = 1; i < days.size(); i++) {
        if (days[i] <= current) {
            count++;
        }
        else {
            answer.push_back(count);
            current = days[i];
            count = 1;
        }
    }
    // [�ð����⵵ : O(N)]
    answer.push_back(count);
    return answer;
}
// �ð����⵵ : O(N)
// �������⵵ : O(N)

int main() {
    vector<int> progresses = { 93, 30, 55 };
    vector<int> speeds = { 1, 30, 5 };

    vector<int> result = solution(progresses, speeds);

    cout << "��� ���� ���: ";
    for (int n : result) {
        cout << n << " ";
    }
    cout << endl;

    return 0;
}
