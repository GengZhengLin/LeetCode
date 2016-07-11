#include <iostream>
#include <string>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		int N = nums.size();
		vector<int> next(N);
		for (int i = 0; i < N; i++) {
			next[i] = i + 1;
		}

		for (auto p : nums) {
			if (p <= 0)
				continue;
			if (p < N)
				next[p - 1] = next[p];
			if (p == N)
				next[p - 1] = p + 1;
		}

		int ind = 1;
		while (ind - 1 < N && next[ind - 1] != ind) {
			ind = next[ind - 1];
		}
		return ind;
	}
};

void test(vector<int> nums) {
	Solution s;
	cout << "Test:[";
	for (auto p : nums) {
		cout << p << " ";
	}
	cout << "] First Missing Positive:" << s.firstMissingPositive(nums) << endl;

}
int main() {
	test({ 1,2,0 });
	test({ 3,4,-1,1 });
	test({ 1,2,3 });
}