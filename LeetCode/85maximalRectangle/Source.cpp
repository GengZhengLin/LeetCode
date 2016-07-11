#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;


class Solution {
public:
	int maximalRectangle(vector<vector<char>>& matrix) {
		vector<vector<char>> m;
		int n1 = matrix.size();
		if (n1 == 0)
			return 0;
		int n2 = matrix[0].size();
		if (n2 == 0)
			return 0;
		int rows = n1, cols = n2;
		if (n1 > n2) {
			m.resize(n2);
			for (int i = 0; i < n2; i++) {
				m[i].resize(n1);
			}
			for (int i = 0; i < n2; i++) {
				for (int j = 0; j < n1; j++) {
					m[i][j] = matrix[j][i];
				}
			}
			rows = n2; cols = n1;
		}
		else {
			m = matrix;
		}

		vector<vector<int>> table;
		table.resize(rows + 1);
		for (int i = 0; i <= rows; i++) {
			table[i].resize(cols);
		}
		for (int i = 0; i < cols; i++) {
			for (int j = 0; j < rows; j++) {
				table[j + 1][i] = table[j][i] + m[j][i] - '0';
			}
		}

		int maxArea = 0;
		for (int i = 0; i < rows; i++) {
			for (int j = i; j < rows; j++) {
				vector<int> v(cols);
				for (int k = 0; k < cols; k++) {
					if (table[j + 1][k] - table[i][k] == j - i + 1) {
						v[k] = 1;
					}
					else {
						v[k] = 0;
					}
				}
				bool isOne = false;
				int lastOneInd = -1;
				int maxLen = 0;
				for (int k = 0; k < cols; k++) {
					if (!isOne && v[k] == 1) {
						isOne = true;
						lastOneInd = k;
					}
					else if (isOne && v[k] == 0) {
						isOne = false;
						int len = k - lastOneInd;
						if (len > maxLen)
							maxLen = len;
					}
				}
				if (isOne) {
					int len = cols - lastOneInd;
					if (len > maxLen)
						maxLen = len;
				}
				int area = maxLen * (j - i + 1);
				if (area > maxArea) {
					maxArea = area;
				}
			}
		}
		return maxArea;
	}
};

void printTable(vector<vector<char>> &table) {
	int rows = table.size();
	int cols = table[0].size();
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << table[i][j] << " ";
		}
		cout << endl;
	}
}

void test(vector<vector<char>> data) {
	Solution s;
	cout << "data:" << endl;
	printTable(data);
	cout << "maxArea:" << s.maximalRectangle(data) << endl << endl;

}
int main() {
	test({
		{'0', '1'},
		{'1', '0'},
		{'1', '0'}
	});
}