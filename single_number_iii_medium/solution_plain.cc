/*************************************************************************
	> File Name: solution_plain.cc
	> Author: MarkWoo
	> Mail:wcgwuxinwei@gmail.com 
	> Created Time: Tue 10 May 2016 01:37:22 AM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
	public:
		vector<int> singleNumber(vector<int>& nums) {
			int differ = 0;
			int singleNum_1 = 0;
			int singleNum_2 = 0;
			vector<int> result;

			for (int i = 0; i < nums.size(); ++i)
				differ ^= nums[i];

			differ &= (~(differ - 1)); 

			for (int i = 0; i < nums.size(); ++i)
			{
				if ((nums[i] & differ) != 0)
					singleNum_1 ^= nums[i];
				else
					singleNum_2 ^= nums[i];
			}

			result.push_back(singleNum_1);
			result.push_back(singleNum_2);
		}
};

int main(void)
{
	return 0;
}
