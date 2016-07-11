#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
	
};
class Solution {
public:
	vector<Interval> merge(vector<Interval>& intervals) {
		vector<Interval> re;
		if (intervals.empty())
			return re;
		sort(intervals.begin(), intervals.end(), [](Interval a, Interval b) {
			return a.start < b.start;
		});
		int N = intervals.size();
		Interval curi(intervals[0].start, intervals[0].end);
		for (int i = 1; i < N; i++) {
			if (intervals[i].start <= curi.end) {
				if (intervals[i].end > curi.end) {
					curi.end = intervals[i].end;
				}
			}
			else {
				re.push_back(curi);
				curi = intervals[i];
			}
		}
		re.push_back(curi);
		return re;
	}
};

void printInterval(Interval &i) {
	cout << "[" << i.start << ", " << i.end << "]";
}

void printIntervals(vector<Interval> &vi) {
	for (auto &i : vi) {
		printInterval(i); cout << " ";
	}
	cout << endl;
}

void test(vector<Interval> intervals) {
	Solution s;
	cout << "Intervals:";
	printIntervals(intervals);
	cout << "merge:";
	printIntervals(s.merge(intervals));
}

int main() {
	test({ { 1,3 }, { 2,6 }, { 8,10 }, { 15,18 } });
}