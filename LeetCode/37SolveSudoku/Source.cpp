#include <iostream>
#include <vector>
#include <unordered_map>
#include <bitset>
using namespace std;

class Solution {
public:
	unordered_map<int, bitset<9>> undecided_cells;
	vector<vector<char>> mboard_;
	void solveSudoku(vector<vector<char>>& board) {
		mboard_ = board;
		// Init
		for (int y = 0; y < 9; y++) {
			for (int x = 0; x < 9; x++) {
				if (mboard_[y][x] == '.') {
					InitCell(y, x);
				}
			}
		}
		// OutputUndecided();
		SetCell();
		board = mboard_;
	}

	bool SetCell() {
		if (undecided_cells.size() == 0)
			return true;
		// Find cell with smallest count
		int minC = 10, minK = 0;
		for (auto o : undecided_cells) {
			int count = 9 - o.second.count();
			if (count < minC) {
				minC = count;
				minK = o.first;
			}
		}

		if (minC == 0) {
			return false;
		}

		int y = minK / 10, x = minK % 10;
		for (int i = 0; i < 9; i++) {
			if (!undecided_cells[minK][i]) {
				// cout << "set " << y << " " << x << " with " << i  << " minC=" << minC << endl;
				SetCellValue(y, x, i);
				if (SetCell()) {
					return true;
				}
				UnsetCellValue(y, x);
				// cout << "!Unset " << y << " " << x << " with " << i << " minC=" << minC << endl;
			}
		}
		return false;
	}

	void SetCellValue(int y, int x, int v) {
		mboard_[y][x] = v + '1';
		undecided_cells.erase(GetHash(y, x));
		// update row
		for (int i = 0; i < 9; i++) {
			if (mboard_[y][i] == '.') {
				undecided_cells[GetHash(y, i)].set(v);
			}
		}

		// update col
		for (int i = 0; i < 9; i++) {
			if (mboard_[i][x] == '.') {
				undecided_cells[GetHash(i, x)].set(v);
			}
		}

		// update unit
		int bx = x / 3, by = y / 3;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (mboard_[by * 3 + i][bx * 3 + j] == '.') {
					undecided_cells[GetHash(by * 3 + i, bx * 3 + j)].set(v);
				}
			}
		}
	}

	void UnsetCellValue(int y, int x) {
		mboard_[y][x] = '.';
		InitCell(y, x);
		for (int i = 0; i < 9; i++) {
			if (mboard_[y][i] == '.') {
				InitCell(y, i);
			}
		}

		// update col
		for (int i = 0; i < 9; i++) {
			if (mboard_[i][x] == '.') {
				InitCell(i, x);
			}
		}

		// update unit
		int bx = x / 3, by = y / 3;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (mboard_[by * 3 + i][bx * 3 + j] == '.') {
					InitCell(by * 3 + i, bx * 3 + j);
				}
			}
		}
	}

	inline int GetHash(int y, int x) {
		return y * 10 + x;
	}

	void InitCell(int y, int x) {
		if (mboard_[y][x] != '.')
			return;
		bitset<9> pos;
		// init for row
		for (int i = 0; i < 9; i++) {
			if (mboard_[y][i] != '.') {
				pos.set(mboard_[y][i] - '1');
			}
		}

		for (int i = 0; i < 9; i++) {
			if (mboard_[i][x] != '.') {
				pos.set(mboard_[i][x] - '1');
			}
		}

		int bx = x / 3, by = y / 3;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				char tmp = mboard_[by * 3 + i][bx * 3 + j];
				if (tmp != '.') {
					pos.set(tmp - '1');
				}
			}
		}

		undecided_cells[GetHash(y, x)] = pos;
	}

	void OutputUndecided() {
		for (auto o : undecided_cells) {
			cout << o.first << " " << o.second << endl;
		}
	}
};

void OutputSudoku(vector<vector<char>> &board) {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << board[i][j] << " ";
			if (j % 3 == 2) {
				cout << " ";
			}
		}
		cout << endl;
		if (i % 3 == 2) {
			cout << endl;
		}
	}
}

int main() {
	vector<vector<char>> data{
		{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
		{'6', '.', '.', '1', '9', '5', '.', '.', '.'},
		{'.', '9', '8', '.', '.', '.', '.', '6', '.'},
		{'8', '.', '.', '.', '6', '.', '.', '.', '3'},
		{'4', '.', '.', '8', '.', '3', '.', '.', '1'},
		{'7', '.', '.', '.', '2', '.', '.', '.', '6'},
		{'.', '6', '.', '.', '.', '.', '2', '8', '.'},
		{'.', '.', '.', '4', '1', '9', '.', '.', '5'},
		{'.', '.', '.', '.', '8', '.', '.', '7', '9'}
	};
	Solution s;
	s.solveSudoku(data);
	OutputSudoku(data);
}