/*************************************************************************
	> File Name: solution_plain.cc
	> Author: MarkWoo
	> Mail:wcgwuxinwei@gmail.com 
	> Created Time: Tue 03 May 2016 05:44:46 AM PDT
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

class Solution {
	public:
	void swap(char &pror, char &succ)
	{
		if (pror != succ)
		{
			char tmp = pror;
			pror = succ;
			succ = tmp;
		}
	}

  string reverseString(string s) 
	{
		size_t head = 0;
		size_t tail = 0;

		if (s.size() != 0)
		{
			tail = s.size() - 1;
		}

		for (; head < tail; ++head, --tail)
		{
			swap(s[head], s[tail]);
		}

		return s;
  }
};

int main(void)
{
	string s("hello");
	string answer;
	Solution solution;
	answer = solution.reverseString(s);

	std::cout << s << std::endl;
	std::cout << answer << std::endl;
	return 0;
}
