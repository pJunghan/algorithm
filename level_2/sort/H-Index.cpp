#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.rbegin(), citations.rend());
    for (int i = 0; i < citations.size(); i++) {
        if (citations[i] < i+1) {
            answer++;
        }
        else return answer;
    }
    return answer;  
}

int main() {

    vector<int> citations;
    string line;
    int num;

    getline(cin, line);      
    stringstream ss(line);

    while (ss >> num) {
        citations.push_back(num);   
    }

    solution(citations);
   
    return 0;
}