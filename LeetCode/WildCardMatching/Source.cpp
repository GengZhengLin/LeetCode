#include <iostream>
#include <string>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
	bool isMatch(string s, string p) {
		vector<int> newStatus, curStatus;
		string pClean;
		bool prevStar = false;
		for (auto c : p) {
			if (prevStar && c == '*') {
				continue;
			}
			else {
				pClean.push_back(c);
				if (c == '*')
					prevStar = true;
				else
					prevStar = false;
			}
		}
		curStatus.push_back(0);
		if (pClean[0] == '*') {
			curStatus.push_back(1);
		}

		for (int i = 0; i < s.length(); i++) {
			char c = s[i];
			newStatus.clear();
			for (auto j : curStatus) {
				if (j >= pClean.length())
					continue;
				if (pClean[j] == '*') {
					newStatus.push_back(j);
					newStatus.push_back(j + 1);
				}
				else if (pClean[j] == '?' || pClean[j] == c) {
					newStatus.push_back(j + 1);
					if (pClean[j + 1] == '*') {
						newStatus.push_back(j + 2);
					}
				}
			}
			if (newStatus.empty())
				return false;
			curStatus = newStatus;

		}
		for (auto i : curStatus) {
			if (i == pClean.length())
				return true;
		}
		return false;
	}
};

void test(string s, string p) {
	Solution so;
	cout << "isMatch(" + s + ", " + p + ") -> " << so.isMatch(s, p) << endl;
}

int main() {
	test("aa", "a");
	test("aa", "aa");
	test("aaa", "*");
	test("aa", "a*");
	test("ab", "?*");
	test("aab", "c*a*b");
	test("aababa", "a*?b*a");
	test("", "*");
	test("ababa", "*ba");
	test("babaaababaabababbbbbbaabaabbabababbaababbaaabbbaaab", "***bba**a*bbba**aab**b");
	

}