#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <unordered_map>
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
	string minWindow(string s, string t) {
		unordered_map<char, int> stats;
		for (auto c : t) {
			if (stats.find(c) == stats.end()) {
				stats[c] = 1;
			}
			else {
				stats[c] += 1;
			}
		}

		unordered_map<char, FixedQueue> queues;
		for (auto p : stats) {
			queues.insert(std::pair<char, FixedQueue>(p.first, FixedQueue(p.second)));
		}

		int mini = -1;
		int numOfFull = 0;
		int numOfChar = queues.size();
		int minLength = s.length() + 1;
		int minStart = -1;
		for (int i = 0; i < s.length(); i++) {
			char c = s[i];
			if (queues.find(c) == queues.end()) {
				continue;
			}
			if (mini == -1) mini = i;
			if (queues[c].size == queues[c].N - 1) {
				numOfFull++;
			}
			int tmp = queues[c].push(i);
			if (tmp == mini) {
				int m = s.length();
				for (auto p : queues) {
					if (p.second.size > 0 && p.second.back() < m) {
						m = p.second.back();
					}
				}
				mini = m;
			}
			if (numOfFull >= numOfChar) {
				if (i - mini + 1 < minLength) {
					minLength = i - mini + 1;
					minStart = mini;
				}
			}
		}
		if (minStart == -1) {
			return "";
		}
		else {
			return s.substr(minStart, minLength);
		}
	}
};

void printFixedQueue(FixedQueue &q) {
	for (int i = 0; i < q.size; i++) {
		cout << q[i] << " ";
	}
	cout << endl;
}

void testFixedQueue() {
	FixedQueue q(3);
	
	q.push(1);
	printFixedQueue(q);
	cout << "back " << q.back() << endl;
	q.push(2);
	printFixedQueue(q);
	cout << "back " << q.back() << endl;
	q.push(3);
	printFixedQueue(q);
	cout << "back " << q.back() << endl;
	q.push(4);
	printFixedQueue(q);
	cout << "back " << q.back() << endl;
	q.push(5);
	printFixedQueue(q);
	cout << "back " << q.back() << endl;
	q.push(6);
	printFixedQueue(q);
	cout << "back " << q.back() << endl;
	q.push(7);
	printFixedQueue(q);
	cout << "back " << q.back() << endl;
}

void test(string s, string t) {
	cout << "s=" << s << ", t=" << t << endl;
	Solution sol;
	cout << "result:" << sol.minWindow(s, t) << endl;
}

int main() {
	// testFixedQueue();
	
	test("ADOBECODEBANC", "ABC");
	test("bba", "ba");
	test("of_characters_and_as", "aas");
	test("aaabbaaba", "abbb");
	
}