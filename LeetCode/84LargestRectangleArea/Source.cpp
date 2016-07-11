#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct FixedQueue {
	FixedQueue() {};
	FixedQueue(int n) :data(n), tail(0), N(n), size(0) {}
	int push(int v) {
		int tmp = data[tail];
		data[tail] = v;
		tail = (tail + 1) % N;
		if (size < N) {
			size++;
			return -1;
		}
		return tmp;
	}
	int operator[] (int i) { int ind = (tail - 1 - i + N) % N; return data[ind]; }
	int back() {
		if (size == N)
			return data[tail];
		else
			return data[0];
	}
	int size;
	vector<int> data;
	int tail;
	int N;
};
class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {
		int N = heights.size();
		int minHeight = 0;
		int maxArea = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N - i; j++) {
				if (j == 0) {
					minHeight = heights[i];
				}
				else {
					minHeight = std::min(minHeight, heights[i + j]);
				}
				int area = (j + 1) * minHeight;
				if (area > maxArea) {
					maxArea = area;
				}
			}
		}
		return maxArea;
	}
};

void test(vector<int> heights) {
	cout << "heights:[";
	for (auto &i : heights) {
		cout << i << " ";
	}
	Solution s;
	cout << "] " << "maxArea:" << s.largestRectangleArea(heights) << endl;
}

int main() {
	test({ 2,1,5,6,2,3 });

}