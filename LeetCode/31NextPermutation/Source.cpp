#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void outputVector(vector<int> &vi);
class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		if (nums.size() <= 1) return;
		int i = nums.size() - 2, j = nums.size() - 1;
		for (; i >= 0 && nums[i] >= nums[j]; i--, j--);
		if (i < 0) {
			// reverse
			for (int l = 0, r = nums.size() - 1; l < r; l++, r--) {
				int tmp = nums[l];
				nums[l] = nums[r];
				nums[r] = tmp;
			}
			return;
		}
		int fsNum = nums[i];
		int nearNum = nums[j];
		int nearInd = j;
		int k;
		for (k = j+1; k < nums.size(); k++) {
			if (nums[k] <= fsNum) continue;
			if (nums[k] < nearNum) {
				nearNum = nums[k];
				nearInd = k;
			}
		}
		int tmp = nums[i];
		nums[i] = nums[nearInd];
		nums[nearInd] = tmp;
		sort(nums.begin() + j, nums.end());
	}
};


void outputVector(vector<int> &vi) {
	for (auto x : vi) {
		cout << x << " ";
	}
	cout << endl;
}
void testSolution(initializer_list<int> il) {
	Solution s;
	vector<int> vi(il);
	cout << "Test:";
	outputVector(vi);
	s.nextPermutation(vi);
	outputVector(vi);
}

int main() {
	testSolution({ 1,2,3 });
	testSolution({ 3,2,1 });
	testSolution({ 1,1,5 });
}