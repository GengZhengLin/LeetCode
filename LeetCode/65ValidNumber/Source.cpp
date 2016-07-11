#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	bool isNumber(string s) {
		if (s == "") return false;
		int state = 0;
		int i = 0;
		while (i < s.length()) {
			if (state == 0) {
				if (isWhite(s[i])) {
					i++;
				}
				else if (s[i] == '+' || s[i] == '-' || s[i] == '.' || isDigit(s[i])) {
					state = 1;
					bool isNumber = takeNumber(s, i);
					if (!isNumber) {
						return false;
					}
				}
				else {
					return false;
				}
			}
			else if (state == 1) {
				if (s[i] == 'e') {
					i++;
					state = 2;
				}
				else if (isWhite(s[i])) {
					i++;
					state = 4;
				}
				else {
					return false;
				}
			}
			else if (state == 2) {
				if (isDigit(s[i])) {
					i++;
					state = 3;
				}
				else if (s[i] == '+' || s[i] == '-') {
					state = 5;
					i++;
				}
				else {
					return false;
				}
			}
			else if (state == 3) {
				if (isDigit(s[i])) {
					i++;
				}
				else if (isWhite(s[i])) {
					i++;
					state = 4;
				}
				else {
					return false;
				}
			}
			else if (state == 4) {
				if (isWhite(s[i])) {
					i++;
				}
				else {
					return false;
				}
			}
			else if (state == 5) {
				if (isDigit(s[i])) {
					i++;
					state = 3;
				}
				else {
					return false;
				}
			}
		}
		if (i == s.length() && (state == 1 || state == 4 || state == 3))
			return true;
		return false;
	}

	bool isDigit(char c) {
		return c >= '0' && c <= '9';
	}
	bool isWhite(char c) {
		return c == ' ' || c == '\t' || c == '\n';
	}
	bool takeNumber(string s, int &i) {
		int state = 0;
		int start_i = i;
		for (; i < s.length(); i++) {
			if (state == 0) {
				if (s[i] == '+' || s[i] == '-') {
					state = 1;
				}
				else if (isDigit(s[i])) {
					state = 2;
				}
				else if (s[i] == '.') {
					state = 3;
				}
				else {
					break;
				}
			}
			else if (state == 1) {
				if (isDigit(s[i])) {
					state = 2;
				}
				else if (s[i] == '.') {
					state = 3;
				}
				else {
					break;
				}
			}
			else if (state == 2) {
				if (isDigit(s[i])) {
					state = 2;
				}
				else if (s[i] == '.') {
					state = 4;
				}
				else {
					break;
				}
			}
			else if (state == 3) {
				if (isDigit(s[i])) {
					state = 4;
				}
				else {
					break;
				}
			}
			else if (state == 4) {
				if (isDigit(s[i])) {
					state = 4;
				}
				else {
					break;
				}
			}
			else {
				break;
			}
		}
		if (i > start_i && (state == 2 || state == 4))
			return true;
		else
			return false;
	}
};


void test(string s) {
	Solution sol;
	cout << s << " " << sol.isNumber(s) << endl;
}
int main() {
	test("0");
	test(" 0.1");
	test("abc");
	test("1 a");
	test("2e10");
	test(".");
	test("1 ");
	test("-.");
	test("6e6.5");
	test(" 005047e+6");
}