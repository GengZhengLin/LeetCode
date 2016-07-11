#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int jump(vector<int>& nums) {
		int N = nums.size();
		if (N <= 1)
			return 0;
		int last_ind = 0, next_ind = 0;
		int reach = nums[0];
		if (reach >= N - 1) {
			return 1;
		}
		int steps = 1;
		for (int i = 1; i < N; i++) {

			if (i > last_ind + nums[last_ind]) {
				steps++;
				last_ind = next_ind;
			}
			if (i + nums[i] > reach) {
				reach = i + nums[i];
				next_ind = i;
			}
			if (reach >= N - 1 && i != N-1) {
				return steps + 1;
			}
		}
		return steps;
	}
};


void test(vector<int> nums) {
	Solution s;
	cout << "test:[";
	for (auto p : nums) {
		cout << p << " ";
	}
	cout << "] steps:" << s.jump(nums) << endl;
}
int main() {
	test({ 2, 3, 1, 1, 4 });
	test({1,1,1,1});
	test({ 1,2,1,1,1 });
	test({ 1,1,1,1,1 });
}