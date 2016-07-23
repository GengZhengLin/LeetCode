#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		unordered_map<int, int> map;
		int maxLen = 1;
		for (auto &x : nums) {
			if (map.count(x) != 0)
				continue;
			bool leftIn = map.find(x - 1) != map.end();
			bool rightIn = map.find(x + 1) != map.end();
			int len = 1;
			int leftIdx = x, rightIdx = x;
			int leftLen = 0, rightLen = 0;
			if (leftIn) {
				leftLen = map[x - 1];
				leftIdx = x - leftLen;
			}
			if (rightIn) {
				rightLen = map[x + 1];
				rightIdx = x + rightLen;
			}
			len = len + leftLen + rightLen;
			map[x]
			map[leftIdx] = len;
			map[rightIdx] = len;
			if (len > maxLen) {
				maxLen = len;
			}
			cout << "num:" << x << ", len:" << len << endl;
		}

		return maxLen;
	}
};

void test(vector<int> nums) {
	cout << "nums:";
	for (auto x : nums) {
		cout << x << " ";
	}
	Solution s;
	cout << ", longestConsequtive:" << s.longestConsecutive(nums) << endl;
}
int main() {
	test({ 100, 4, 200, 1, 3, 2 });
	test({ 1,3,5,7 });
	test({ 7,4,6,1,3,2 });
	test({ 1,2,0,1 });
	test({ 4,0,-4,-2,2,5,2,0,-8,-8,-8,-8,-1,7,4,5,5,-4,6,6,-3 });
}