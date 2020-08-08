//
// Created by 甘唯哲 on 2020/7/29.
//

#include <vector>

class Solution {
public:
    int partition(std::vector<int>& nums, int l, int r)
    {
        int pivot = nums[l];
        while (l < r)
        {
            while (l < r && nums[r] <= pivot)
                --r;
            nums[l] = nums[r];
            while (l < r && nums[l] > pivot)
                ++l;
            nums[r] = nums[l];
        }
        nums[l] = pivot;
        return l;
    }

    int findKthLargest(std::vector<int>& nums, int k)
    {
        int l = 0, r = nums.size()-1;
        while (l < r)
        {
            int pivot = partition(nums, l, r);
            if (pivot == k-1)
                return nums[pivot];
            else if (pivot > k-1)
                r = pivot - 1;
            else
                l = pivot + 1;
        }
        return nums[l];
    }
};