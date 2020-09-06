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

/*	unordered_map法，时间复杂度符合要求，但是空间复杂度超标了
*
*	执行用时：24 ms, 在所有 C++ 提交中击败了93.64%的用户
*	内存消耗：15.4 MB, 在所有 C++ 提交中击败了5.33%的用户
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>

using namespace std;

vector<int> majorityElement(vector<int>& nums)
{
	if (nums.size() < 2)
	{
		return nums;
	}
	unordered_map<int, int> nMap;
	for (int num : nums)
	{
		nMap[num]++;
	}
	vector<int> res;

	unordered_map<int,int>::iterator it = nMap.begin();

	while (it != nMap.end())
	{
		if (it->second > (nums.size() / 3))
		{
			res.push_back(it->first);
		}
		it++;
	}
	return res;
}

int main()
{
	vector<int> nums = { 1,1,1,3,3,2,2,2,10 };
	vector<int> res;
	unordered_map<int, int> nMap;
	for (int num : nums)
	{
		nMap[num]++;
	}
	//res = majorityElement(nums);

}