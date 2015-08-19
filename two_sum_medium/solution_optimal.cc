/*************************************************************************
	> File Name: solution_plain.cc
	> Author: MarkWoo
	> Mail:wcgwuxinwei@gmail.com 
	> Created Time: Thu 06 Aug 2015 10:09:09 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

#define DEBUG std::cout << "*****************8" << std::endl;

//问题描述：
//1. 不一定有序
//2. 可能有相同的值
//3. 真捉急

class Solution {
public:
	std::vector<int> twoSum(std::vector<int>& nums, int target) {
	}

};

int main(void) {
	std::vector<int> vec_t = {0, 4, 3, 0};
	std::vector<int> vec_an;

	Solution sol;
	vec_an = sol.twoSum(vec_t, 0);
	std::cout << vec_an[0] << " and " << vec_an[1] << std::endl;
	return 0;
}
