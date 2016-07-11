#include <iostream>
#include <string>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
	vector<string> fullJustify(vector<string>& words, int maxWidth) {
		int i = 0, last_i = 0;;
		int N = words.size();
		int wNum = 0;
		int total_len = 0;
		vector<string> result;
		for (i = 0; i < N; i++) {
			wNum++;
			total_len += words[i].length();
			if (wNum - 1 + total_len > maxWidth) {
				wNum--;
				total_len -= words[i].length();
				string s = "";
				if (wNum == 1) {
					s += words[i - 1];
					while (s.length() < maxWidth) s += ' ';
				}
				else if (wNum > 1){
					int spaceNum = (maxWidth - total_len) / (wNum - 1);
					int oneMore = (maxWidth - total_len) % (wNum - 1);
					for (int j = last_i; j < i; j++) {
						s += words[j];
						if (j != i - 1) {
							for (int k = 0; k < spaceNum; k++) s += ' ';
							if (j - last_i + 1 <= oneMore) {
								s += ' ';
							}
						}
					}
				}
				result.push_back(s);
				wNum = 1;
				total_len = words[i].length();
				last_i = i;
			}
		}
		string s = "";
		for (int j = last_i; j < i; j++) {
			s += words[j];
			if (j != i - 1) {
				s += ' ';
			}
		}
		while (s.length() < maxWidth)
			s += ' ';
		result.push_back(s);
		return result;
	}
};

void test(vector<string> words, int maxWidth) {
	cout << "Input:[";
	for (auto &s : words) {
		cout << s << " ";
	}
	cout << "]" << endl;
	Solution s;
	vector<string> result = s.fullJustify(words, maxWidth);
	cout << "Results:" << endl;
	for (auto &s : result) {
		cout << s << endl;
	}
}

int main() {
	test({ "This", "is", "an", "example", "of", "text", "justification." }, 16);
	test({ "What","must","be","shall","be." }, 12);
}