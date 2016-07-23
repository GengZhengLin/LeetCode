#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
	int candy(vector<int>& ratings) {
		if (ratings.size() == 0)
			return 0;
		if (ratings.size() == 1)
			return 1;
		enum Status {
			ASCEND,
			EQUAL,
			DESCEND
		}status;
		if (ratings[1] > ratings[0])
			status = ASCEND;
		else if (ratings[1] == ratings[0])
			status = EQUAL;
		else
			status = DESCEND;
		int lastIdx = 0;
		int N = ratings.size();
		vector<int> candies(N);
		for (int i = 1; i < N; i++) {
			int prevLastIdxCandies = 0;
			bool changeStatus = false;
			if (status == ASCEND) {
				if (i == N - 1 || ratings[i + 1] <= ratings[i]) {
					prevLastIdxCandies = candies[lastIdx];
					candies[lastIdx] = 1;
					for (int j = lastIdx+1; j <= i; j++) {
						candies[j] = candies[j - 1] + 1;
					}
					changeStatus = true;
				}
			}
			else if (status == DESCEND){
				if (i == N - 1 || ratings[i + 1] >= ratings[i]) {
					candies[i] = 1;
					prevLastIdxCandies = candies[lastIdx];
					for (int j = i - 1; j >= lastIdx; j--) {
						candies[j] = candies[j + 1] + 1;
					}
					changeStatus = true;
				}
			}
			else if (status == EQUAL) {
				if (i == N - 1 || ratings[i + 1] != ratings[i]) {
					prevLastIdxCandies = candies[lastIdx];
					for (int j = lastIdx; j <= i; j++) {
						candies[j] = 1;
					}
					changeStatus = true;
				}
			}
			if (changeStatus) {
				if (candies[lastIdx] < prevLastIdxCandies) {
					candies[lastIdx] = prevLastIdxCandies;
				}

				lastIdx = i;
				if (i != N - 1) {
					if (ratings[i + 1] > ratings[i])
						status = ASCEND;
					else if (ratings[i + 1] == ratings[i])
						status = EQUAL;
					else
						status = DESCEND;
				}
			}
		}
		int sum = 0;
		for (int i = 0; i < N; i++) {
			sum += candies[i];
		}

		//cout << "candies:";
		//for (auto &x : candies) {
		//	cout << x << " ";
		//}
		//cout << endl;
		return sum;
	}
};

void test(vector<int> ratings) {
	cout << "ratings:";
	for (auto &x : ratings) {
		cout << x << " ";
	}
	cout << endl;
	Solution s;
	int candies = s.candy(ratings);
	cout << "candies:" << candies << endl;
}
int main() {
	test({ 3,3,3,2,2,1,1,4,5,2,5,4,3,2,1,0,2 });
	test({ 1,2,2 });
}