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
	for (auto iter = il.begin() + 1; iter != il.end(); iter++) {
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
	int maxPath = INT_MIN;
	int maxPathSum(TreeNode* root) {
		maxPathDownSum(root);
		return maxPath;
	}
	int maxPathDownSum(TreeNode *root) {
		if (root == NULL)
			return 0;
		int sum = root->val;
		int maxL = maxPathDownSum(root->left);
		int maxR = maxPathDownSum(root->right);
		if (maxL > 0 && maxR <= 0) {
			sum += maxL;
		}
		else if (maxL <= 0 && maxR > 0) {
			sum += maxR;
		}
		else if (maxL > 0 && maxR > 0) {
			int tmp = maxL + root->val + maxR;
			if (tmp > maxPath) {
				maxPath = tmp;
			}
			sum += max(maxL, maxR);
		}
		if (sum > maxPath)
			maxPath = sum;
		// cout << "root->val:" << root->val << ", maxL:" << maxL << ", maxR:" << maxR << ", sum:" << sum << ", maxPath:" << maxPath << endl;
		return sum;
	}
};

void swap(int &i1, int &i2) {
	int tmp = i1;
	i1 = i2;
	i2 = tmp;
}

int main() {
	Solution s;
	//TreeNode *root = CreateTree({ 2,1,3 });
	//swap(root->val, root->left->val);
	//
	//cout << "MaxPath:" << s.maxPathSum(root) << endl;

	TreeNode *root = CreateTree({ 1,2 });
	cout << "MaxPath:" << s.maxPathSum(root) << endl;
}
