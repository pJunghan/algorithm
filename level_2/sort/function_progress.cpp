#include <iostream>
#include <vector>
#include <string>

using namespace std;


vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer; 
    vector<int> days;
    // [공간복잡도 : O(2N)]

    for (int i = 0; i < progresses.size(); i++) {
        int remain = 100 - progresses[i];
        int day = (remain + speeds[i] - 1) / speeds[i];
        days.push_back(day);
    }
    // [시간복잡도 : O(N)]
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
    // [시간복잡도 : O(N)]
    answer.push_back(count);
    return answer;
}
// 시간복잡도 : O(N)
// 공간복잡도 : O(N)

int main() {
    vector<int> progresses = { 93, 30, 55 };
    vector<int> speeds = { 1, 30, 5 };

    vector<int> result = solution(progresses, speeds);

    cout << "기능 배포 결과: ";
    for (int n : result) {
        cout << n << " ";
    }
    cout << endl;

    return 0;
}
