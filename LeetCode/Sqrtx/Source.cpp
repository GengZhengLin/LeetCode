#include <iostream>
#include <string>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
	int mySqrt(int x) {
		if (x == 0)
			return 0;
		else if (x < 4)
			return 1;
		else if (x < 9)
			return 2;
		int x_4 = x / 4;
		int s_x_4 = mySqrt(x_4);
		int t = 2 * s_x_4 + 1;
		int t2 = t * t;
		if (t2 < 0 || x < t2)
			return (t - 1);
		t = 2 * s_x_4 + 2;
		t2 = t * t;
		if (t2 < 0 || x < t2)
			return (t - 1);
		else
			return t;
	}
};

void test(int x) {
	Solution s;
	cout << "sqrt(" << x << ")=" << s.mySqrt(x) << endl;
}

int main() {
	test(0);
	test(1);
	test(2);
	test(4);
	test(10);
	test(1000);
	test(2147395600);
}