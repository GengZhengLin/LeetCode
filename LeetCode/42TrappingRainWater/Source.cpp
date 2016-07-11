#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int trap(vector<int>& height) {
		int N = height.size();
		if (N == 0) return 0;
		vector<int> ml(N);
		vector<int> mr(N);
		ml[0] = height[0];
		for (int i = 1; i < N; i++) {
			ml[i] = max(ml[i - 1], height[i]);
		}
		mr[N - 1] = height[N - 1];
		for (int i = N - 2; i >= 0; i--) {
			mr[i] = max(mr[i + 1], height[i]);
		}
		int sum = 0;
		for (int i = 0; i < N; i++) {
			int tm = min(ml[i], mr[i]);
			if (tm > height[i])
				sum += (tm - height[i]);
		}
		return sum;
	}
};


void test(vector<int> height) {
	Solution s;
	cout << "test:[";
	for (auto p : height) {
		cout << p << " ";
	}
	cout << "], rain:" << s.trap(height) << endl;
}

int main() {
	test({ 0,1,0,2,1,0,1,3,2,1,2,1 });
}