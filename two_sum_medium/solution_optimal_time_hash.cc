/*************************************************************************
	> File Name: solution_plain.cc
	> Author: MarkWoo
	> Mail:wcgwuxinwei@gmail.com 
	> Created Time: Thu 06 Aug 2015 10:09:09 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

#define DEBUG std::cout << "*****************" << std::endl;

//问题描述：
//1. 不一定有序
//2. 可能有相同的值
//3. 十分捉急

class Solution {
	public:
		struct hash_element {
			std::vector<int> data_;
			std::vector<std::size_t> location_;
			hash_element(): data_(0) {
			}
		};

		std::size_t makeHash(int num, int hash_seed) {
			return std::abs(num % hash_seed);
		}

		std::vector<int> twoSum(std::vector<int>& nums, int target) {
			std::vector<int> index(2, 0);
			std::vector<hash_element> hash_map(nums.size());

			for (std::size_t loc = 0; loc != nums.size(); ++loc) {
				std::size_t hash_loc = makeHash(nums[loc], nums.size());
				hash_map[hash_loc].data_.push_back(nums[loc]);
				hash_map[hash_loc].location_.push_back(loc+1);
			}

			for (std::size_t loc = 0; loc != nums.size(); ++loc) {
				std::size_t hash_loc = makeHash(target - nums[loc], nums.size());
				std::size_t index_2_loc = hash_map[hash_loc].data_.size();
				if (index_2_loc) {
					while (index_2_loc > 0) {
						if (hash_map[hash_loc].data_[index_2_loc - 1] == target - nums[loc] &&
								hash_map[hash_loc].location_[index_2_loc - 1] != loc + 1) {
							index[0] = loc + 1;
							index[1] = hash_map[hash_loc].location_[index_2_loc - 1];
							return index;
						}
						--index_2_loc;
					}
				}
			}

			return index;
		}

};

int main(void) {
	std::vector<int> vec_t;
	std::vector<int> vec_an;

	vec_t.push_back(-3);
	vec_t.push_back(4);
	vec_t.push_back(3);
	vec_t.push_back(90);

	Solution sol;
	vec_an = sol.twoSum(vec_t, 0);
	std::cout << vec_an[0] << " and " << vec_an[1] << std::endl;
	return 0;
}
