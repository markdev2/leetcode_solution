/*************************************************************************
	> File Name: solution_1.cc
	> Author: MarkWoo
	> Mail:wcgwuxinwei@gmail.com 
	> Created Time: Mon 29 Jun 2015 07:15:50 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>


class Solution {
	public:
		int SingleNumber(std::vector<int>& nums) {
			QuickSort(nums, 0, nums.size() - 1);

			for (std::size_t single_nums = 0; single_nums < nums.size() - 1; single_nums += 2) {
				int single_num = nums[single_nums];
				if (single_num != nums[single_nums + 1]) {
					return single_num;
				}
			}

			return 0;
		}
};

int main(void) {
	Solution s1;
	std::vector<int> vec_t = {1, 5, 3, 1, 5, 6, 7, 11, 11, 6, 3};
	std::cout << s1.SingleNumber(vec_t) << std::endl;

	std::cout << std::endl;
	for (auto &r : vec_t) {
		std::cout << r << " ";
	}
	std::cout << std::endl;
}
