/*************************************************************************
	> File Name: solution_plain.cc
	> Author: MarkWoo
	> Mail:wcgwuxinwei@gmail.com 
	> Created Time: Mon 10 Aug 2015 04:01:01 AM CST
 ************************************************************************/

#include <iostream>
#include <string>

/* O(1) runtime
 * based on digital root
 * formula of the digital root
 * dr(n) = n - 9 [(n - 1) / 9]
 * https://en.wikipedia.org/wiki/Digital_root
 */

class Solution {
	public:
	int AddDigits(int num) {
		return num - 9 * ((num - 1) / 9);
	}
};

int main(void) {
	Solution s1;
	std::cout << s1.AddDigits(38) << std::endl;
	return 0;
}
