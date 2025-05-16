#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int time = 0;
    int total_weight = 0;
    int i = 0; 
    queue<pair<int, int>> bridge;

    while (i < truck_weights.size() || !bridge.empty()) {
        if (!bridge.empty() && time - bridge.front().second >= bridge_length) {
            total_weight -= bridge.front().first;
            bridge.pop();
        }

        if (i < truck_weights.size() &&
            total_weight + truck_weights[i] <= weight &&
            bridge.size() < bridge_length) {
            bridge.push({ truck_weights[i], time });
            total_weight += truck_weights[i];
            i++;
        }

        time++;
    }

    return time;
}

int main() {
    int bridge_length = 2;
    int weight = 10;
    vector<int> truck_weights = { 7, 4, 5, 6 };

    int result = solution(bridge_length, weight, truck_weights);

    cout << "��� Ʈ���� �ǳʴ� �� �ɸ� �ð�: " << result << "��" << endl;

    return 0;
}
