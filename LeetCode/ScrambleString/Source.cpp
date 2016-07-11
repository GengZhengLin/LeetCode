#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
	bool isScramble(string s1, string s2) {
		if (s1.length() != s2.length())
			return false;
		table1.resize(26);
		table2.resize(26);
		int l = s1.length();
		for (int i = 0; i < 26; i++) {
			table1[i].resize(l+1);
			table2[i].resize(l+1);
		}
		for (int i = 0; i < l; i++) {
			for (int j = 0; j < 26; j++) {
				if (s1[i] == 'a' + j) {
					table1[j][i+1] = table1[j][i] + 1;
				}
				else {
					table1[j][i+1] = table1[j][i];
				}
				if (s2[i] == 'a' + j) {
					table2[j][i+1] = table2[j][i] + 1;
				}
				else {
					table2[j][i+1] = table2[j][i];
				}
			}
		}
		if (!hasEqualChars(0, 0, l))
			return false;
		return stringCmp(s1, 0, s2, 0, l);

	}

	vector<vector<int>> table1, table2;
	bool stringCmp(string &s1, int i1, string &s2, int i2, int l) {
		if (l == 1)
			return s1[i1] == s2[i2];
		for (int i = 1; i <= l - 1; i++) {
			if (hasEqualChars(i1, i2, i)) {
				if (stringCmp(s1, i1, s2, i2, i) && stringCmp(s1, i1 + i, s2, i2 + i, l - i))
					return true;
			}
			if (hasEqualChars(i1, i2 + l - i, i)) {
				if (stringCmp(s1, i1, s2, i2 + l - i, i) && stringCmp(s1, i1 + i, s2, i2, l - i))
					return true;
			}
		}
		return false;
	}

	bool hasEqualChars(int i1, int i2, int l) {
		for (int i = 0; i < 26; i++) {
			int t1 = table1[i][i1 + l] - table1[i][i1];
			int t2 = table2[i][i2 + l] - table2[i][i2];
			if (t1 != t2)
				return false;
		}
		return true;
	}
};

void test(string s1, string s2) {
	Solution s;
	cout << "test string:" << s1 << ", " << s2 << " isScramble: " << s.isScramble(s1, s2) << endl;;
}
int main() {
	test("great", "great");
	test("great", "rgeat");
	test("great", "rgtae");
	test("abb", "bab");
	test("aabb", "abab");
}