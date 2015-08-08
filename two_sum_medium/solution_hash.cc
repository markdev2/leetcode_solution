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
		std::vector<int> index(2, 0);
		std::unordered_map<int, std::vector<int> > nums_map;
		std::unordered_map<int, std::vector<int> >::iterator nums_map_iterator = nums_map.end();
		int count = 0;

		for (auto &r : nums) {
			++count;
			if ((nums_map_iterator = nums_map.find(r)) != nums_map.end()) {
				nums_map_iterator->second.push_back(count);
			} else {
				std::vector<int> count_vec(1, count);
				nums_map.insert(std::make_pair(r, count_vec));
			}
		}

		for (auto &r : nums) {
			if (target - r == r && nums_map[r].size() != 1) {
				index[0] = nums_map[r][0];
				index[1] = nums_map[r][1];
				return index;
			}

			if (nums_map.end() != nums_map.find(target-r) &&
					nums_map.find(r) != nums_map.find(target-r)) {
				if (nums_map[r].front() < nums_map[target-r].front()) {
					std::cout << " **** " << nums_map[r][0] << std::endl;
					index[0] = nums_map[r].front();
					index[1] = nums_map[target-r].front();
					return index;
				} else {
					index[1] = nums_map[r].front();
					index[0] = nums_map[target-r].front();
					return index;
				}
			}
		}

		return index;
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
