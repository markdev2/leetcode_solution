/*************************************************************************
	> File Name: solution_plain.cc
	> Author: MarkWoo
	> Mail:wcgwuxinwei@gmail.com 
	> Created Time: 2015年09月07日 星期一 00时45分42秒
 ************************************************************************/

/*
 * Given two binary trees, write a function to check if they are equal or not.
 * Two binary trees are considered equal if they are structurally identical and 
 * the nodes have the same value.
*/

#include<iostream>
#include<string>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
	public:
		bool isSameTree(TreeNode* p, TreeNode *q) {
			bool is_same_label = false;
			if (!p && !q) {
				is_same_label = true;
			} else if (p && q){
				if (p->val == q->val) {
					is_same_label = true;

					if (p->left && q->left) {
						is_same_label = isSameTree(p->left, q->left);
					} else if (p->left || q->left) {
						is_same_label = false;
					}

					if (p->right && q->right && is_same_label) {
						is_same_label = isSameTree(p->right, q->right);
					} else if (p->right || q->right) {
						is_same_label = false;
					}

				}
			}

			return is_same_label;
		}
};

int main(void) {
	return 0;
}
