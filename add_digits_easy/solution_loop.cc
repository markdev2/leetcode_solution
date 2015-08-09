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
		int loc_10 = 0;
		while ((loc_10 = num / 10) != 0) {
			num = loc_10 + num % 10;
		}
		return num;
	}
};

int main(void) {
	Solution s1;
	std::cout << s1.AddDigits(38) << std::endl;
	return 0;
}
