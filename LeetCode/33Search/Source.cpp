#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int search(vector<int>& nums, int target) {
		if (nums.size() <= 0) return -1;
		if (nums.size() <= 3) {
			for (int i = 0; i < nums.size(); i++) {
				if (target == nums[i]) return i;
			}
			return -1;
		}
		int l = 0, r = nums.size() - 1;
		int first = nums[l], last = nums[r];
		int mid;
		while (r > l + 1) {
			mid = (l + r) / 2;
			if (nums[mid] > nums[mid + 1])
				break;
			if (nums[mid] > first) {
				l = mid;
			}
			else {
				r = mid;
			}
		}
		mid = (r + l) / 2;
		if (r == 0 || l==nums.size()-2) {
			return binarySearch(nums, 0, nums.size() - 1, target);
		}
		else {
			int li = binarySearch(nums, 0, mid, target);
			int ri = binarySearch(nums, mid + 1, nums.size() - 1, target);
			if (li != -1) return li;
			if (ri != -1) return ri;
			return -1;
		}
	}

	int binarySearch(vector<int>& nums, int l, int r, int target) {
		if (nums[l] > target || nums[r] < target) return -1;
		if (nums[l] == target) return l;
		if (nums[r] == target) return r;
		while (r > l + 1) {
			int mid = (r + l) / 2;
			if (nums[mid] == target) return mid;
			else if (nums[mid] > target) {
				r = mid - 1;
			}
			else {
				l = mid;
			}
		}
		if (nums[l] == target) return l;
		if (nums[r] == target) return r;
		return -1;
	}
};

void outputVector(vector<int> &vi) {
	for (auto x : vi) {
		cout << x << " ";
	}
	cout << endl;
}

void testBS(initializer_list<int> il, int t) {
	Solution s;
	vector<int> vi(il);
	cout << "Test: target= " << t << " ";  outputVector(vi);
	cout << s.binarySearch(vi, 0, vi.size() - 1, t) << endl;
}

void testS(initializer_list<int> il, int t) {
	Solution s;
	vector<int> vi(il);
	cout << "Test: target= " << t << "; ";  outputVector(vi);
	cout << s.search(vi, t) << endl;
}

int main() {
	testS({ 4,5,6,7,0,1,2 }, 6);
	testS({ 4,5,6,7,0,1,2 }, 0);
	testS({ 4,5,6,7,0,1,2 }, 3);
	testS({ 1,2,3,4,5 }, 0);
	testS({ 3, 1 }, 1);
}