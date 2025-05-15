#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(int a, int b) {
    return to_string(a) + to_string(b) > to_string(b) + to_string(a);
}

string solution(vector<int> numbers) {
    sort(numbers.begin(), numbers.end(), compare);
    // [시간복잡도 : O(N log N)]
    if (numbers[0] == 0) return "0";

    string answer = "";
    for (int num : numbers) {
        answer += to_string(num);
    }
    // [시간복잡도 : O(N)]

    return answer;
}
// [시간복잡도 : O(N log N)]
// [공간복잡도 : O(N)]
int main() {
    vector<int> numbers = { 6, 10, 2 };
    string result = solution(numbers);
    cout << "가장 큰 수: " << result << endl;

    numbers = { 3, 30, 34, 5, 9 };
    result = solution(numbers);
    cout << "가장 큰 수: " << result << endl;

    return 0;
}