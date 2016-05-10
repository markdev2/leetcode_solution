/*************************************************************************
	> File Name: solution_plain.cc
	> Author: MarkWoo
	> Mail:wcgwuxinwei@gmail.com 
	> Created Time: Tue 10 May 2016 11:21:32 PM CST
 ************************************************************************/

#include<iostream>
#include<string>
#include <vector>
using namespace std;

class Solution {
	public:
		vector<int> countBits(int num) 
		{
			vector<int> result;

			for (int i = 0; i <= num; ++i)
			{
				if (i == 0)
				{
					result.push_back(0);
				}
				else if (i == 1)
				{
					result.push_back(1);
				}

				result.push_back(result[i >> 1] + (i & 1));
			}

			return result;
		}
};

int main(void)
{
	Solution solution;

	vector<int> result = solution.countBits(5);
	for (auto i : result)
	{
		std::cout << i << std::endl;
	}
	return 0;
}
