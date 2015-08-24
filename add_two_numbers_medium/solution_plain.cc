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

			while (l1 && l2) {
				int val = l1->val + l2->val;
				val = val % 10;
				ListNode *tmp = new ListNode(val);
				tmp->next = head->next;
				head->next = tmp;
				l1 = l1->next;
				l2 = l2->next;
			}

			if (l1) {
				ListNode *tmp = new ListNode(l1->val);
				tmp->next = head->next;
				head->next = tmp;
				l1 = l1->next;
			}
			if (l2) {
				ListNode *tmp = new ListNode(l2->val);
				tmp->next = head->next;
				head->next = tmp;
				l1 = l1->next;
			}

			return head->next;
		}
};
