/*************************************************************************
	> File Name: solution_plain.cc
	> Author: MarkWoo
	> Mail:wcgwuxinwei@gmail.com 
	> Created Time: Mon 10 Aug 2015 04:01:01 AM CST
 ************************************************************************/

#include <iostream>
#include <string>

class Solution {
	public:
	int AddDigits(int num) {
		if (num / 10 != 0)
			return AddDigits(num / 10 + num % 10);
		else
			return num;
	}
};

int main(void) {
	Solution s1;
	std::cout << s1.AddDigits(38) << std::endl;
	return 0;
}
