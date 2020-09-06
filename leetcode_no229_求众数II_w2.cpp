/*------------------------------------------------------------------|
给定一个大小为 n 的数组，找出其中所有出现超过 ⌊ n/3 ⌋ 次的元素。	|
																	|
说明: 要求算法的时间复杂度为 O(n)，空间复杂度为 O(1)。				|
																	|
示例 1:																|
																	|
输入: [3,2,3]														|
输出: [3]															|
示例 2:																|
																	|
输入: [1,1,1,3,3,2,2,2]												|
输出: [1,2]															|
																	|
来源：力扣（LeetCode）												|
链接：https://leetcode-cn.com/problems/majority-element-ii			|
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。|
-------------------------------------------------------------------*/

/*	摩尔投票法
*
*	执行用时：12 ms, 在所有 C++ 提交中击败了100%的用户
*	内存消耗：15.1 MB, 在所有 C++ 提交中击败了55.77%的用户
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>

using namespace std;

vector<int> majorityElement(vector<int>& nums)
{
	vector<int> res;
	if (nums.size() < 2)
	{
		return nums;
	}

	int num1 = nums[0];
	int cnt1 = 0;
	int num2 = nums[0];
	int cnt2 = 0;

	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] == num1)
		{
			cnt1++;
			continue;
		}
		else if (nums[i] == num2)
		{
			cnt2++;
			continue;
		}

		else
		{
			if (cnt1 == 0 && cnt2 == 0)
			{
				num1 = num2 = nums[i];
				cnt1 = cnt2 = 1;
			}
			else if (cnt1 > 0 && cnt2 == 0)
			{
				num2 = nums[i];
				cnt2 = 1;
				continue;
			}
			else if (cnt1 > 0 && cnt2 > 0)
			{
				cnt1--;
				cnt2--;
				continue;
			}
			else if (cnt1 == 0 && cnt2 > 0)
			{
				num1 = nums[i];
				cnt1 = 1;
				continue;
			}
		}
	}

	cnt1 = cnt2 = 0;																/*	留下来的是出现频率前二高的，但是满不满足超过n/3还需要再验证一遍	*/
	for (int num : nums)
	{
		if (num == num1)
		{
			cnt1++;
		}
		else if (num == num2)
		{
			cnt2++;
		}
	}
	if (cnt1 > nums.size() / 3)
	{
		res.push_back(num1);
	}
	if (cnt2 > nums.size() / 3)
	{
		res.push_back(num2);
	}
	return res;
}

int main()
{
	vector<int> nums = { 4,2,1,1 };
	vector<int> res;
	
}