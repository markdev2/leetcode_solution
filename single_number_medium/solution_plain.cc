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
			srand((unsigned) time(NULL));
			if (left < right) {
				int partion = Partiation(vec_int, left, right);
				QuickSort(vec_int, left, partion - 1);
				QuickSort(vec_int, partion + 1, right);
			}
		}

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
