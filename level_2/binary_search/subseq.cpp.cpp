#include<iostream>
#include<vector>

using namespace std;

int find_legnth(v) {
	vector<int> temp;

	for (int i = 0; i < v.size(); i++) {
		auto it = lower_bound(temp.begin(), temp.end(), num);
		if (it == temp.end()) temp.push_back(num);
		else *it = num;
	}
	return temp.size();
}


int main() {
	int N;
	cin >> N;
	vector<int> v(N);
	for (int i = 0; i < N; i++) cin >> v[i];

	cout << find_length(v);
	
	return 0;
}