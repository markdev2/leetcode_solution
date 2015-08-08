/*************************************************************************
	> File Name: solution_plain.cc
	> Author: MarkWoo
	> Mail:wcgwuxinwei@gmail.com 
	> Created Time: Thu 06 Aug 2015 10:09:09 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>

//穷举暴力法
class Solution {
public:
	std::vector<int> twoSum(std::vector<int>& nums, int target) {
		std::vector<int> index(2, 0);

		for (std::size_t priority = 0; priority < nums.size() - 1; ++ priority) {
			index[0] = priority;
			for (std::size_t later = priority; later < nums.size() - 1; ++later) {
				if (nums[priority] + nums[later] == target) {
					index[1] = later;
					return index;
				}
			}
		}
		return index;
	}

};

int main(void) {
	std::vector<int> vec_t = {1, 4, 6, 7, 8, 99, 12, 34};
	std::vector<int> vec_an;

	Solution sol;
	vec_an = sol.twoSum(vec_t, 12);

	std::cout << vec_an[0] << " and " << vec_an[1] << std::endl;
 
	return 0;
}
