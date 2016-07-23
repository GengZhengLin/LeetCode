#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
	bool isPalindrome(string &s, int start, int len) {
		if (len == 1)
			return true;
		int end = start + len - 1;
		for (int i = start, j = end; j > i; i++, j--) {
			if (s[i] != s[j])
				return false;
		}
		return true;
	}

	int minCut(string s) {
		int N = s.length();
		if (N <= 1)
			return 0;
		if (isPalindrome(s, 0, N))
			return 0;
		vector<vector<int>> palindromTable(N);
		for (int i = 0; i < N; i++) {
			palindromTable[i].resize(N - i);
		}

		for (int i = 1; i < N; i++) {
			int len = i + 1;
			for (int j = 0; j < N - i; j++) {
				int start = j, end = j + len - 1;
				int minPartition = len;
				if (isPalindrome(s, start, len)) {
					minPartition = 0;
				}
				else {
					for (int k = 1; k < len; k++) {
						int partition = palindromTable[k - 1][start] + palindromTable[len - k - 1][start + k] + 1;
						if (partition < minPartition)
							minPartition = partition;
					}
				}
				palindromTable[i][j] = minPartition;
			}
		}

		return palindromTable[N - 1][0];
	}
};

void test(string s) {
	cout << "string:" << s;
	Solution sol;
	cout << ", minCut:" << sol.minCut(s) << endl;
}
int main() {
	test("aab");
	test("aabaac");
	test("ababa");
}