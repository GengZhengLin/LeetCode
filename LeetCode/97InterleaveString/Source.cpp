#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
	string str1, str2, str3;
	bool isInterleave(string s1, string s2, string s3) {
		str1 = s1;
		str2 = s2;
		str3 = s3;
		if (s1.length() + s2.length() != s3.length())
			return false;
		return interleave(0, 0, 0);
	}

	bool interleave(int i1, int i2, int i3) {
		if (i1 == str1.length() && i2 == str2.length() && i3 == str3.length())
			return true;
		if (i1 < str1.length() && i2 < str2.length() && i3 < str3.length() && str1[i1] == str3[i3] && str2[i2] == str3[i3]) {
			if (interleave(i1 + 1, i2, i3 + 1)) {
				return true;
			}
			else if (interleave(i1, i2 + 1, i3 + 1)) {
				return true;
			}
			else {
				return false;
			}
		}
		else if (i1 < str1.length() && i3 < str3.length() && str1[i1] == str3[i3]) {
			return interleave(i1 + 1, i2, i3 + 1);
		}
		else if (i2 < str2.length() && i3 < str3.length() && str2[i2] == str3[i3]) {
			return interleave(i1, i2 + 1, i3 + 1);
		}
		else {
			return false;
		}
	}
};

void test(string s1, string s2, string s3) {
	Solution s;
	cout << "s1=" << s1 << ", s2=" << s2 << ", s3=" << s3 << " isInterleave:" << s.isInterleave(s1, s2, s3) << endl;
}
int main() {
	test("aabcc", "dbbca", "aadbbcbcac");
	test("aabcc", "dbbca", "aadbbbaccc");
}