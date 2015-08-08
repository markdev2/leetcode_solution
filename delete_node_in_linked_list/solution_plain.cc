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
			if (NULL == node || NULL == node->next) {
				return ;
			}

			int val = node->val;
			ListNode *pointer = node;

			if (NULL == pointer->next->next && 
					NULL != pointer->next) {
				if (pointer->next->val == val) {
					ListNode *delete_node = pointer->next;
					pointer->next = pointer->next->next;
					delete delete_node;
					delete_node = NULL;
					return ;
				}
			}

			while (NULL != pointer->next->next) {
				if (pointer->next->val == val) {
					std::cout << pointer->next->val << "********" << std::endl;
					ListNode *delete_node = pointer->next;
					pointer->next = pointer->next->next;
					delete delete_node;
					delete_node = NULL;
				}
				pointer = pointer->next;
			}
	  }
};

int main(void) {
	Solution s1;
	ListNode* node_header = new ListNode(3);
	ListNode* ptr = node_header;

	for (int i = 0; i < 10; ++i) {
		ListNode* node = new ListNode(i);
		ptr->next = node;
		ptr = ptr->next;
		//std::cout << node->val << " ";
	}
	std::cout << std::endl;

	std::cout << "before : " << std::endl;
	ptr = node_header;
	while (ptr->next) {
		std::cout << ptr->val << " ";
		ptr = ptr->next;
	}
	std::cout << std::endl;

	s1.DeleteNode(node_header);

	std::cout << "after : " << std::endl;
	ptr = node_header;
	while (ptr->next) {
		std::cout << ptr->val << " ";
		ptr = ptr->next;
	}
	std::cout << std::endl;

	return 0;
}
