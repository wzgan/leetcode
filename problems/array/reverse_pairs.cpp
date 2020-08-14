//
// Created by 甘唯哲 on 2020/8/6.
//

//https://leetcode.com/problems/reverse-pairs/

#include <vector>

class Solution {
public:
    int reversePairs(std::vector<int>& nums)
    {
        int n = nums.size();
        int res = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = i+1; j < n; ++j)
            {
                if(nums[i]/2 > nums[j] || (nums[i]%2 == 1 && nums[i]/2 == nums[j]))
                    res++;
            }
        }
        return res;
    }

    int helper(std::vector<int>& nums, int start, int end)
    {
        if (start >= end)
            return 0;

        int mid = start + (end - start) / 2;
        int res = 0;
        res += helper(nums, start, mid);
        res += helper(nums, mid+1, end);

        int l = mid + 1;
        for (int k = start; k <= mid; ++k)
        {
            while (l <= end && (nums[k]/2 > nums[l] || (nums[k]%2 == 1 && nums[k]/2 == nums[l])))
                l++;
            res += l - mid - 1;
        }

        int i = start, j = mid+1, cur = 0;
        std::vector<int> temp(end-start+1, 0);
        while (i <= mid && j <= end)
        {
            if (nums[i] > nums[j])
            {
                if (nums[i]/2 > nums[j] || (nums[i]%2 == 1 && nums[i]/2 == nums[j]))
                    res += mid - i + 1;
                temp[cur++] = nums[j++];
            } else
            {
                temp[cur++] = nums[i++];
            }
        }
        while (i <= mid)
        {
            temp[cur++] = nums[i++];
        }
        while (j <= end)
        {
            temp[cur++] = nums[j++];
        }

        for (int m = 0; m < end-start+1; ++m)
        {
            nums[start + m] = temp[m];
        }

        return res;
    }

    int reversePairs2(std::vector<int>& nums)
    {
        return helper(nums, 0, nums.size()-1);
    }
};