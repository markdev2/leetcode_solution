/*************************************************************************
	> File Name: solution_plain_o_1.cc
	> Author: MarkWoo
	> Mail:wcgwuxinwei@gmail.com 
	> Created Time: Tue 10 May 2016 09:19:49 PM CST
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

struct ListNode
{
	int val_;
	ListNode *next_;
	ListNode *prev_;

	ListNode(int val):val_(val), next_(NULL), prev_(NULL)
	{
	}
};

class Solution
{
	public:
		void reverse_linked_list(ListNode* head)
		{
			if (!head || !(head->next_))
				return ;

			ListNode *ptr = head->next_;
			head->next_ = NULL;
			head->prev_ = NULL;

			while (ptr != NULL)
			{
				ListNode *tmp_next = ptr->next_;
				ptr->next_ = head->next_;
				if (ptr->next_ != NULL)
				{
					ptr->next_->prev_ = ptr;
				}
				head->next_ = ptr;
				ptr = tmp_next;
			}
		}
};

int main(void) {
	Solution s1;
	ListNode *head = new ListNode(0);
	ListNode *ptr = head;
	srand(time(NULL));

	std::cout << "before: " << std::endl;
	for (int i = 0; i < 5; ++i) {
		ListNode *new_node = new ListNode(rand());
		std::cout << new_node->val_ << " ";
		new_node->prev_ = ptr;
		ptr->next_ = new_node;

		if (new_node->prev_ != NULL)
			std::cout << " ptr->prev = " << new_node->prev_->val_ <<  ";" << std::endl;
		else
			std::cout << " ptr->prev = NULL " << std::endl;
		ptr = ptr->next_;
	}
	std::cout << std::endl;

	s1.reverse_linked_list(head);

	ptr = head->next_;
	std::cout << "after: " << std::endl;
	for (int i = 0; i < 5; ++i) {
		std::cout << ptr->val_ << " ";
		if (ptr->prev_ != NULL)
			std::cout << " ptr->prev = " << ptr->prev_->val_ <<  ";" << std::endl;
		else
			std::cout << " ptr->prev = NULL " << std::endl;

		ptr = ptr->next_;
	}
	std::cout << std::endl;
	return 0;
}
