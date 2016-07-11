#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		if (head == NULL || k <= 1)
			return head;
		ListNode *ret = NULL;
		ListNode *waitForNext = NULL;
		ListNode *sp = head;
		ListNode *ep = sp;

		int counter;
		for (counter = 0; counter < k && ep != NULL; ep = ep->next, counter++);
		if (counter < k)
			return head;
		while (true) {
			ListNode *p0 = sp;
			ListNode *p1 = p0->next;
			ListNode *p2 = p1->next; // notice p2 may be null
			while (p1 != ep) {
				p1->next = p0;
				p0 = p1;
				p1 = p2;
				if (p2 != NULL) {
					p2 = p2->next;
				}
			}
			// first one: p0, last one: sp
			if (ret == NULL) {
				ret = p0;
			}
			else {
				waitForNext->next = p0;
			}
			waitForNext = sp;
			sp = ep;
			ep = sp;
			for (counter = 0; counter < k && ep != NULL; ep = ep->next, counter++);
			if (counter < k) {
				waitForNext->next = sp;
				break;
			}
				
		}
		return ret;
	}
};

void outputList(ListNode *l) {
	while (l != NULL) {
		cout << l->val << " ";
		l = l->next;
	}
	cout << endl;
}

ListNode* createList(initializer_list<int> il) {
	ListNode *p = NULL, *prev = NULL, *head = NULL;
	
	for (auto x : il) {
		p = new ListNode(x);
		if (head == NULL) head = p;
		if (prev != NULL) prev->next = p;
		prev = p;
	}

	return head;
}

void TestList(initializer_list<int> il, int k) {
	ListNode *l = createList(il);
	cout << "Test " << k << endl;
	outputList(l);
	Solution s;
	outputList(s.reverseKGroup(l, k));
}
int main() {
	Solution s;
	// Test
	TestList({ 1,2,3 }, 5);
	TestList({ 1,2,3,4,5 }, 3);
	TestList({ 1,2,3,4,5 }, 5);
	TestList({ 1,2,3,4,5 }, 2);
	TestList({ 1,2,3,4,5 }, 4);
	TestList({ 1,2,3,4,5,6 }, 3);

}