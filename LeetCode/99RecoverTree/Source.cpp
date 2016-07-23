#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}	
};

void InsertNode(TreeNode *root, int val) {
	if (val < root->val) {
		if (root->left == NULL) {
			TreeNode *n = new TreeNode(val);
			root->left = n;
		}
		else {
			InsertNode(root->left, val);
		}
	}
	else {
		if (root->right == NULL) {
			TreeNode *n = new TreeNode(val);
			root->right = n;
		}
		else {
			InsertNode(root->right, val);
		}
	}
}

TreeNode* CreateTree(initializer_list<int> il) {
	TreeNode *root = new TreeNode(*il.begin());
	for (auto iter = il.begin() + 1; iter != il.end(); iter ++) {
		InsertNode(root, *iter);
	}
	return root;
}

void printTree(TreeNode *root) {
	cout << "(";
	if (root != NULL) {
		cout << root->val;
		if (root->left != NULL) {
			printTree(root->left);
		}
		else if (root->right != NULL) {
			cout << "()";
		}
		if (root->right != NULL) {
			printTree(root->right);
		}
		else if (root->left != NULL) {
			cout << "()";
		}
	}
	cout << ")";
}

class Solution {
public:
	TreeNode *l1 = NULL, *r1 = NULL;
	TreeNode *l2 = NULL, *r2 = NULL;
	int numR = 0;
	TreeNode *last_n = NULL;

	void recoverTree(TreeNode* root) {
		FindReverse(root);
		if (numR == 1) {
			int tmp = l1->val;
			l1->val = r1->val;
			r1->val = tmp;
		}
		else if (numR == 2) {
			if (l1->val > r2->val) {
				int tmp = l1->val;
				l1->val = r2->val;
				r2->val = tmp;
			}
			else if (l2->val > r1->val) {
				int tmp = l2->val;
				l2->val = r1->val;
				r1->val = tmp;
			}
		}
	}

	void FindReverse(TreeNode *root) {
		if (root == NULL)
			return;
		if (root->left != NULL) {
			FindReverse(root->left);
		}

		if (last_n != NULL && last_n->val > root->val) {
			if (numR == 0) {
				l1 = last_n; r1 = root;
				numR = 1;
			}
			else if (numR == 1) {
				l2 = last_n; r2 = root;
				numR = 2;
			}
		}
		last_n = root;
		if (root->right != NULL) {
			FindReverse(root->right);
		}
	}
	
};

void TestTree(initializer_list<int> il) {
	printTree(CreateTree(il));
	cout << endl;
}

void swap(int &i1, int &i2) {
	int tmp = i1;
	i1 = i2;
	i2 = tmp;
}
int main() {
	Solution s;
	TreeNode *root = CreateTree({ 3,2,5,1,4,6 });
	swap(root->left->val, root->right->left->val);
	cout << "input tree:";
	printTree(root);
	cout << endl;
	s.recoverTree(root);
	cout << "recover1:";
	printTree(root);
	cout << endl;

	swap(root->val, root->left->val);
	cout << "input tree:";
	printTree(root);
	cout << endl;
	s.recoverTree(root);
	cout << "recover1:";
	printTree(root);
	cout << endl;
}
