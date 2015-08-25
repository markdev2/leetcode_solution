/*************************************************************************
	> File Name: solution_plain.cc
	> Author: MarkWoo
	> Mail:wcgwuxinwei@gmail.com 
	> Created Time: 2015年08月24日 星期一 02时36分05秒
 ************************************************************************/

#include<iostream>
#include<string>
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
			if (!head->next && (val / 10 != 0)) {
				ListNode *tmp = new ListNode(val % 10);
				tmp->next = new ListNode(val / 10);
				head->next = tmp;
				ptr = tmp;
				overload = true;
			} else {
				ListNode *tmp = new ListNode(val % 10);
				if (!head->next) {
				    head->next = tmp;
				    ptr = tmp;
				    overload = false;
				} else {
				    ptr->val += val / 10;
				    ptr->next = tmp;
				    ptr = ptr->next;
				    overload = false;
				}
			}
			l1 = l1->next;
			l2 = l2->next;
		}

		while (l1) {
		    if (overload) {
		        ptr->val += l1->val;
		    } else {
    			ListNode *tmp = new ListNode(l1->val);
    			ptr->next = tmp;
		    }
		    ptr = ptr->next;
    		l1 = l1->next;
		}
		
		while (l2) {
		    if (overload) {
		        ptr->val += l2->val;
		    } else {
    			ListNode *tmp = new ListNode(l2->val);
    			ptr->next = tmp;
		    }
		    ptr = ptr->next;
    		l2 = l2->next;
		}
		

		return head->next;
		}
};

int main(void) {
	Solution s1;
	ListNode *l1 = NULL;
	ListNode *l2 = NULL;
	l1 = new ListNode(1);
	l1->next = new ListNode(8);
	l2 = new ListNode(0);
	//l2->next = new ListNode(3);

	s1.addTwoNumbers(l1, l2);

	return 0;
}
