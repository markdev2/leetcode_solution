/*************************************************************************
	> File Name: solution_recurise.cc
	> Author: MarkWoo
	> Mail:wcgwuxinwei@gmail.com 
	> Created Time: 2015年08月24日 星期一 00时49分22秒
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        int tree_depth = 1;
        TreeNode *ptr = root;
				if (!root) {
					return 0;
				}
        if (ptr->left && ptr->right) {
						int left_child_depth = maxDepth(ptr->left);
						int right_child_depth = maxDepth(ptr->right);
            if (left_child_depth > right_child_depth)
							tree_depth += left_child_depth;
						else
							tree_depth += right_child_depth;
        } else if (ptr->left && NULL == ptr->right) {
            tree_depth += maxDepth(ptr->left);
        } else if (ptr->right && NULL == ptr->left) {
            tree_depth += maxDepth(ptr->right);
        }
        
        return tree_depth;
    }
};

int main(void) {
	Solution s1;
	return 0;
}
