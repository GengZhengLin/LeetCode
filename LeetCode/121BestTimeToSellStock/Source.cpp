#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int N = prices.size();
		int maxP = 0;
		if (N <= 1)
			return 0;
		int minPrice = prices[0];
		for (int i = 1; i < N; i++) {
			if (prices[i] < minPrice) {
				minPrice = prices[i];
			}
			if (prices[i] - minPrice > maxP) {
				maxP = prices[i] - minPrice;
			}
		}
		return maxP;
	}
};

void test(vector<int> prices) {
	cout << "prices:";
	for (auto x : prices) {
		cout << x << " ";
	}
	Solution s;
	cout << ", maxProfit:" << s.maxProfit(prices) << endl;
}
int main() {
	test({ 7,6,4,3,1 });
	test({ 7,1,5,3,6,4 });
}