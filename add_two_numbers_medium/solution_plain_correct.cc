/*************************************************************************
	> File Name: solution_plain.cc
	> Author: MarkWoo
	> Mail:wcgwuxinwei@gmail.com 
	> Created Time: 2015年08月24日 星期一 02时36分05秒
 ************************************************************************/

#include<iostream>
#include<string>
#define DEBUG std::cout << "DEBUG" << std::endl;
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL) {}
};

class Solution {
	public:
		ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
			if (!l1) {
				return l2;
			} else if (!l2) {
				return l1;
			}

			ListNode* head = new ListNode(0);
			ListNode* ptr = NULL;
			bool overload = false;

			while (l1 && l2) {
				int val = l1->val + l2->val;
				if (!head->next) {
					if (val / 10 != 0) {
						ListNode *tmp = new ListNode(val % 10);
						tmp->next = new ListNode(1);
						head->next = tmp;
						ptr = tmp->next;
						overload = true;
					} else {
						ListNode *tmp = new ListNode(val % 10);
						ptr = tmp;
						head->next = tmp;
						overload = false;
					}
				} else if (overload) {
					val += ptr->val;
					ptr->val = val % 10;
					if (val / 10 != 0) {
						ListNode *tmp = new ListNode(1);
						ptr->next = tmp;
						ptr = ptr->next;
					} else { 
						overload = false;
					}
				} else {
					if (val / 10 != 0) {
						DEBUG
						ptr->next = new ListNode(val % 10);
						ptr->next->next = new ListNode(1);
						ptr = ptr->next->next;
						overload = true;
					} else {
						ptr->next = new ListNode(val);
						ptr = ptr->next;
					}
				}
				l1 = l1->next;
				l2 = l2->next;
			}

			while (l1) {
				if (overload) {
					int val = ptr->val + l1->val;
					ptr->val = val % 10;
					if (val / 10 != 0) {
						ListNode *tmp = new ListNode(1);
						ptr->next = tmp;
						ptr = ptr->next;
					} else { 
						overload = false;
					}
				} else {
					ptr->next = new ListNode(l1->val);
					ptr = ptr->next;
				}
				l1 = l1->next;
			}

			while (l2) {
				if (overload) {
					int val = ptr->val + l2->val;
					ptr->val = val % 10;
					if (val / 10 != 0) {
						ListNode *tmp = new ListNode(1);
						ptr->next = tmp;
						ptr = ptr->next;
					} else { 
						overload = false;
					}
				} else {
					ptr->next = new ListNode(l2->val);
					ptr = ptr->next;
				}
				l2 = l2->next;
			}

			return head->next;
		}
};

int main(void) {
	Solution s1;
	ListNode *l1 = NULL;
	ListNode *l1_ptr = NULL;
	ListNode *l2 = NULL;
	ListNode *l2_ptr = NULL;
	ListNode *l3 = NULL;
	l1 = new ListNode(0);
	l1->next = new ListNode(0);
	l1->next->next = new ListNode(1);
	l1->next->next->next = new ListNode(9);
	l1->next->next->next->next = new ListNode(0);
	l1->next->next->next->next->next = new ListNode(1);
	l1->next->next->next->next->next->next = new ListNode(6);
	l2 = new ListNode(8);
	l2->next = new ListNode(6);
	l2->next->next = new ListNode(2);
	l2->next->next->next = new ListNode(5);
	l2->next->next->next->next = new ListNode(8);
	l2->next->next->next->next->next = new ListNode(2);
	l2->next->next->next->next->next->next = new ListNode(6);
	l1_ptr = l1;
	l2_ptr = l2;
	std::cout << "l1: " << std::endl;
	while (l1_ptr) {
		std::cout << "node: " << l1_ptr->val << std::endl;
		l1_ptr = l1_ptr->next;
	}
	std::cout << "l2: " << std::endl;
	while (l2_ptr) {
		std::cout << "node: " << l2_ptr->val << std::endl;
		l2_ptr = l2_ptr->next;
	}
	//l2->next = new ListNode(3);

	l3 = s1.addTwoNumbers(l1, l2);

	std::cout << "l3: " << std::endl;
	while (l3) {
		std::cout << "node: " << l3->val << std::endl;
		l3 = l3->next;
	}

	return 0;
}
