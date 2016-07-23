#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
	pair<int,int> maxProfit1Transaction(vector<int>& prices, int l, int r, int &profit) {
		int N = r - l + 1;
		int maxP = 0;
		if (N <= 1)
			return pair<int, int>(l, l);
		int minPrice = prices[l];
		int minPriceInd = l;
		int maxPriceL = l;
		int maxPriceR = l;
		for (int i = l + 1; i <= r; i++) {
			if (prices[i] < minPrice) {
				minPrice = prices[i];
				minPriceInd = i;
			}
			if (prices[i] - minPrice > maxP) {
				maxP = prices[i] - minPrice;
				maxPriceL = minPriceInd;
				maxPriceR = i;
			}
		}
		profit = maxP;
		return pair<int, int>(maxPriceL, maxPriceR);
	}

	int maxProfit(vector<int>& prices) {
		int N = prices.size();
		int l = 0, r = N - 1;
		int maxP = 0;
		do {
			int p = 0;
			pair<int, int> interval = maxProfit1Transaction(prices, l, r, p);
			int lp = 0, rp = 0;
			if (interval.first < interval.second) {
				maxProfit1Transaction(prices, 0, interval.first, lp);
				maxProfit1Transaction(prices, interval.second + 1, N - 1, rp);
				p = p + max(lp, rp);
			}

			if (p > maxP) {
				maxP = p;
			}
			cout << "interval:[" << interval.first << ", " << interval.second << "], p:" << p << endl;
			l = interval.first + 1;
			r = interval.second;
		} while (l < r);

		return maxP;
	}
};

void test1Transaction(vector<int> prices) {
	cout << "prices:";
	for (auto x : prices) {
		cout << x << " ";
	}
	Solution s; int profit;
	pair<int, int> p = s.maxProfit1Transaction(prices, 0, prices.size() - 1, profit);
	cout << ", Interval:[" << p.first << ", " << p.second << "], Profit:" << profit << endl;
}

void test(vector<int> prices) {
	cout << "prices:";
	for (auto x : prices) {
		cout << x << " ";
	}
	Solution s; 
	cout << ", Profit:" << s.maxProfit(prices) << endl;
}
int main() {
	//test1Transaction({ 7,6,4,3,1 });
	//test1Transaction({ 7,1,5,3,6,4 });
	//test1Transaction({ 2,4,1 });
	test({ 7,6,4,3,1 });
	test({ 7,1,5,3,6,4 });
	test({ 1,3,2,5 });
	test({ 1,2,3,4 });
	test({ 2,4,1 });
	test({ 2,1,2,0,1 });
}