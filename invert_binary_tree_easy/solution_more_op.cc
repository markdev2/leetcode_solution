/*************************************************************************
	> File Name: solution_template.cc
	> Author: MarkWoo
	> Mail:wcgwuxinwei@gmail.com 
	> Created Time: Tue 10 May 2016 11:21:46 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	public:
		TreeNode* invertTree(TreeNode *root) {
			if (root == NULL)
				return root;
			
			if (root->left != NULL)
				invertTree(root->left);

			if (root->right != NULL)
				invertTree(root->right);

			TreeNode *tmp = root->right;
			root->right = root->left;
			root->left = tmp;
			return root;
		}
};

int main(void)
{
	Solution solution;

	return 0;
}
