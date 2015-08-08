/*************************************************************************
	> File Name: solution_1.cc
	> Author: MarkWoo
	> Mail:wcgwuxinwei@gmail.com 
	> Created Time: Mon 29 Jun 2015 07:15:50 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

class Solution {
	public:
		void Swap(int &a, int &b) {
			int temp;
			temp = a;
			a = b;
			b = temp;
		}

		int Partiation(std::vector<int> &vec_int, int left, int right) {
			int provt = rand() % (right - left) + left;
			Swap(vec_int[right], vec_int[provt]);
			provt = vec_int[right];

			while (left < right) {
				while (left < right && provt > vec_int[left]) ++left;
				while (left < right && provt < vec_int[right]) --right;
				if (left < right) {
					Swap(vec_int[left], vec_int[right]);
					if (vec_int[left] == provt && vec_int[right] == provt) {
						--right;
					}
				}
			}
			vec_int[left] = provt;

			return right;
		}

		void QuickSort(std::vector<int> &vec_int, int left, int right) {
			if (left < right) {
				int partion = Partiation(vec_int, left, right);
				QuickSort(vec_int, left, partion - 1);
				QuickSort(vec_int, partion + 1, right);
			}
		}

		int SingleNumber(std::vector<int>& nums) {
			if (nums.size() <= 1) {
				return nums.front();
			}
			srand(time(NULL));
			QuickSort(nums, 0, nums.size() - 1);

			for (std::size_t ptr = 0; ptr < nums.size(); ptr += 2) {
				//int single_num = nums[ptr];
				if (ptr == nums.size()) {
					return nums[ptr];
				} else if (nums[ptr] != nums[ptr+1]) {
					return nums[ptr];
				}
			}

			return 0;
		}
};

int main(void) {
	srand(time(NULL));
	Solution s1;
	std::vector<int> vec_t;

	/*
	for (int i = 0; i < 9999; ++i) {
		int num = rand();
		vec_t.push_back(num);
		vec_t.push_back(num);
	}

	int single_num = rand();
	vec_t.push_back(single_num);
	*/

	for (int i = 0; i <= 9999; ++i) {
		vec_t.push_back(i);
	}
	for (int i = 0; i <= 9999; ++i) {
		vec_t.push_back(i);
	}
	vec_t.push_back(10000);

	int count = 0;
	int single_num = s1.SingleNumber(vec_t);
	
	for (auto &r : vec_t) {
		if (count % 10 == 0) {
			std::cout << std::endl;
		}
		std::cout << r << " ";
		++count;
	}

	std::cout << std::endl;
	std::cout << "single num is " << single_num << std::endl;
	std::cout << std::endl;

	//std::cout << std::endl;
}
