#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		vector<int> ret;
		if (s.length() == 0 || words.size() == 0) return ret;
		map<string, int> stat;
		for (auto w : words) {
			stat[w]++;
		}
		int wordLen = words[0].length();
		int totalLen = wordLen * words.size();
		for (int i = 0; i < s.length() - totalLen + 1; i++) {
			int counter;
			map<string, int> freq = stat;
			for (counter = 0; counter < words.size(); counter++) {
				string sub = s.substr(i + counter * wordLen, wordLen);
				auto iter = freq.find(sub);
				if (iter != freq.end() && iter->second > 0) {
					iter->second--;
				}
				else {
					break;
				}
			}
			if (counter >= words.size()) {
				ret.push_back(i);
			}
		}
		return ret;
	}

};

void OutputVector(vector<int> &vi) {
	for (auto x : vi) {
		cout << x << " ";
	}
	cout << endl;
}

void testSolution(string str, initializer_list<string> il) {
	Solution s;
	cout << "Test: " << str << endl;
	vector<string> words(il);
	vector<int> re = s.findSubstring(str, words);
	for (auto x : re) {
		cout << x << " ";
	}
	cout << endl;
}
int main()
{
	testSolution("barfoothefoobarman", { "foo", "bar" });
	testSolution("", { "foo", "bar" });
	testSolution("barfoothefoobarman", { "the"});
}