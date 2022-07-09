/**
 * @file day-9-jump-vi.cpp
 * @author sandeep singh(sandeepss128961@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-07-09
 * @copyright Copyright (c) 2022
 *
 *
 * @problem description:
 *
 * You are given a 0-indexed integer array nums and an integer k.

You are initially standing at index 0. In one move, you can jump at most k steps forward without going outside the boundaries of the array. That is, you can jump from index i to any index in the range [i + 1, min(n - 1, i + k)] inclusive.

You want to reach the last index of the array (index n - 1). Your score is the sum of all nums[j] for each index j you visited in the array.

Return the maximum score you can get.
 */

// solution TC: O(nlogk)
class Solution
{
public:
    int maxResult(vector<int> &nums, int k)
    {
        vector<int> dp(size(nums));
        multiset<int> ms;
        ms.insert({dp[0] = nums[0]});

        for (int i = 1; i < nums.size(); i++)
        {
            // erase elements from which jump is not possible
            if (i > k)
            {
                ms.erase(ms.find(nums[i - k - 1]));
            }
            // insert new element
            ms.insert({dp[i] = nums[i] + *ms.rbegin()});
        }
        return dp[nums.size() - 1];
    }
};

// tc: O(n)
class Solution
{
public:
    int maxResult(vector<int> &nums, int k)
    {
        vector<int> dp(nums.size());
        deque<int> q{0};
        dp[0] = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (q.front() < i - k)
            {
                q.pop_front();
            }
            dp[i] = dp[q.front()] + nums[i];
            while (!q.empty() && dp[q.back()] <= dp[i])
            {
                q.pop_back();
            }
        }
        return dp.back();
    }
};