#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	int longestValidParentheses(string s) {
		vector<int> mLenAtI(s.length());
		vector<int> pStack;
		int maxLen = 0;
		for (int i = 0; i < s.length(); i++) {
			switch (s[i])
			{
			case '(':
				pStack.push_back(i);
				mLenAtI[i] = 0;
				break;
			case ')':
				if (pStack.empty()) {
					mLenAtI[i] = 0;
				}
				else {
					int pI = pStack.back(); pStack.pop_back();
					int len = i - pI + 1;
					if (pI > 0) {
						len += mLenAtI[pI - 1];
					}
					mLenAtI[i] = len;
					if (maxLen < len) {
						maxLen = len;
					}
				}
				break;
			default:
				break;
			}
		}
		return maxLen;
	}
};

void testSolution(string str) {
	Solution s;
	cout << "Test: " << str << endl;
	cout << s.longestValidParentheses(str) << endl;
}

int main() {
	testSolution(")()())");
	testSolution("");
	testSolution("()");
	testSolution("))())))()())");
	testSolution("(((()(((()()(");
}