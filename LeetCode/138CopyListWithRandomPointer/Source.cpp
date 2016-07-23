#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}

};

class Solution {
public:
	RandomListNode *copyRandomList(RandomListNode *head) {
		if (head == NULL)
			return NULL;
		unordered_map<RandomListNode *, int> ptrToIdx;
		vector<RandomListNode *> idxToPtr;
		RandomListNode *head0 = head;
		RandomListNode *head1 = new RandomListNode(head0->label);
		ptrToIdx[head0] = 0;
		idxToPtr.push_back(head1);
		RandomListNode *p0 = head0->next, *q0 = head0, *p1 = head1->next, *q1 = head1;
		int idx = 1;
		while (p0 != NULL) {
			p1 = new RandomListNode(p0->label);
			q1->next = p1;
			ptrToIdx[p0] = idx;
			idxToPtr.push_back(p1);
			idx ++;
			p0 = p0->next;
			q0 = q0->next;
			q1 = q1->next;
		}

		p0 = head0; p1 = head1;
		while (p0 != NULL) {
			if (p0->random == NULL) {
				p1->random = NULL;
			}
			else {
				p1->random = idxToPtr[ptrToIdx[p0->random]];
			}
			p0 = p0->next;
			p1 = p1->next;
		}

		return head1;
	}
};

RandomListNode * createRandomList(vector<int> randomPointers) {
	int N = randomPointers.size();
	RandomListNode *head = new RandomListNode(0);
	RandomListNode *prev = head, *p = NULL;
	vector<RandomListNode *> idxToPtr(N);
	idxToPtr[0] = head;
	for (int i = 1; i < N; i++) {
		p = new RandomListNode(i);
		idxToPtr[i] = p;
		prev->next = p;
		prev = p;
	}
	for (int i = 0; i < N; i++) {
		if (randomPointers[i] == -1) {
			idxToPtr[i]->random = NULL;
		}
		else {
			idxToPtr[i]->random = idxToPtr[randomPointers[i]];
		}
	}
	return head;
}

void printRandomList(RandomListNode *head) {
	RandomListNode *p = head;
	while (p != NULL) {
		cout << "[" << p->label << ", ";
		if (p->random == NULL)
			cout << "-1";
		else
			cout << p->random->label;
		cout << "] ";
		p = p->next;
	}
}


void test(vector<int> randomPointers) {
	RandomListNode *head0 = createRandomList(randomPointers);
	cout << "RandomList:";
	printRandomList(head0);
	cout << endl;
	Solution s;
	RandomListNode *head1 = s.copyRandomList(head0);
	cout << "CopiedList:";
	printRandomList(head1);
	cout << endl;
}

int main() {
	test({ 0, 5, -1, 3, 3, 1 });
}
