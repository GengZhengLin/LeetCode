#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
	vector<vector<string>> result;
	vector<string> board;
	vector<bool> cols;
	vector<bool> l1, l2;
	int N;
	vector<vector<string>> solveNQueens(int n) {
		board.resize(n);
		N = n;
		for (auto &s : board) {
			string tmp = "";
			for (int i = 0; i < n; i++)
				tmp += '.';
			s = tmp;
		}
		cols.resize(n);
		for (int i = 0; i < n; i++) {
			cols[i] = false;
		}
		l1.resize(2 * n);
		for (int i = 0; i < l1.size(); i++) {
			l1[i] = false;
		}
		l2.resize(2 * n);
		for (int i = 0; i < l2.size(); i++) {
			l2[i] = false;
		}
		placeInRow(0);
		return result;
	}
	void placeInRow(int row) {
		if (row == N) {
			result.push_back(board);
			return;
		}
		int placed = false;
		for (int col = 0; col < N; col++) {
			if (cols[col] || l1[row - col + N] || l2[row + col])
				continue;
			board[row][col] = 'Q';
			cols[col] = true;
			l1[row - col + N] = true;
			l2[row + col] = true;
			placeInRow(row + 1);
			board[row][col] = '.';
			cols[col] = false;
			l1[row - col + N] = false;
			l2[row + col] = false;
		}
	}

};

void test(int n) {
	cout << "n=" << n << endl;
	Solution s;
	vector<vector<string>> result = s.solveNQueens(n);
	for (auto &board : result) {
		for (auto &s : board) {
			cout << s << endl;
		}
		cout << endl;
	}
	
}
int main() {
	test(4);
}