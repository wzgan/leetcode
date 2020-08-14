//
// Created by 甘唯哲 on 2020/7/27.
//

#include <vector>

// merge sort
void merge(std::vector<int>& nums, int start, int mid, int end)
{
    std::vector<int> temp(end - start + 1, 0);
    int p1 = start, p2 = mid + 1, i = 0;
    while (p1 <= mid && p2 <= end)
    {
        temp[i++] = nums[p1] <= nums[p2] ? nums[p1++] : nums[p2++];
    }

    while (p1 <= mid)
    {
        temp[i++] = nums[p1++];
    }
    while (p2 <= end)
    {
        temp[i++] = nums[p2++];
    }

    for (i = 0; i < temp.size(); ++i)
    {
        nums[start+i] = temp[i];
    }
}

void merge_sort(std::vector<int>& nums, int start, int end)
{
    if (start == end) return;
    int mid = (start + end) / 2;
    merge_sort(nums, start, mid);
    merge_sort(nums, mid+1, end);
    merge(nums, start, mid, end);
}

// quick sort
int partition(std::vector<int>& nums, int l, int r)
{
    int pivot = nums[l];
    while (l < r)
    {
        while(l < r && pivot <= nums[r])
            r--;
        nums[l] = nums[r];
        while (l < r && pivot >= nums[l])
            l++;
        nums[r] = nums[l];
    }
    nums[l] = pivot;
    return l;
}

void quick_sort(std::vector<int>& nums, int start, int end)
{
    if (start >= end)
        return;
    int pivot = partition(nums, start, end);
    quick_sort(nums, start, pivot);
    quick_sort(nums, pivot+1, end);
}