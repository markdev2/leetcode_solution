/*************************************************************************
	> File Name: solution_plain.cc
	> Author: MarkWoo
	> Mail:wcgwuxinwei@gmail.com 
	> Created Time: Sun 09 Aug 2015 03:48:08 AM CST
 ************************************************************************/

#include <iostream>

/**
 * Definition for singly-linked list.
 *  struct ListNode {
 *		int val;
 *		ListNode *next;
 *    ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
	int val;
	ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
	public:
    void DeleteNode(ListNode* node) {
			node->val = node->next->val;
			node->next = node->next->next;
	  }
};
