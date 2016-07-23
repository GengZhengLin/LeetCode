#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
	string simplifyPath(string path) {
		int state = 0;
		vector<string> paths;
		string word;
		if (path.back() != '/'){
			path = path + '/';
		}
		for (int i = 0; i < path.length(); i++) {
			char c = path[i];
			// cout << "current state:" << state << ", input:" << c;
			if (state == 0) {
				if (c == '/') {
					state = 1;
				}
			}
			else if (state == 1) {
				if (c == '/') {
					
				}
				else if (c == '.') {
					state = 3;
				}
				else {
					state = 2;
					word = string("") + c;
				}
			}
			else if (state == 2) {
				if (c == '/') {
					state = 1;
					paths.push_back(word);
					word = "";
				}
				else {
					word += c;
				}
			}
			else if (state == 3) {
				if (c == '/') {
					state = 1;
				}
				else if (c == '.') {
					state = 4;
				}
				else {
					word = string(".") + c;
					state = 2;
				}
			}
			else if (state == 4) {
				if (c == '/') {
					if (!paths.empty()) {
						paths.pop_back();
					}
					state = 1;
				}
				else if (c == '.') {
					word = "...";
					state = 2;
				}
				else {
					word = string("..") + c;
					state = 2;
				}
			}
			// cout << ", outState:" << state << ", word:\"" << word << "\"" << endl;
		}
		string result = "";
		if (paths.empty() || word != paths.back()) {
			if (word != "") {
				paths.push_back(word);
			}
		}
		if (paths.empty()) {
			return "/";
		}
		for (auto &w : paths) {
			result = result + "/" + w;
		}

		return result;
	}
};


void test(string str) {
	Solution s;
	cout << "Path:" << str << ", Simplified:" << s.simplifyPath(str) << endl;
}
int main() {
	test("/home/");
	test("/a/./b/../../c/");
	test("/../");
	test("/home//foo/");
	test("/...");
	test("/home");
	test("/..hidden");
	test("/.hidden");
	test("/home/../../..");
	test("///eHx/..");
}