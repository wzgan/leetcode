//
// Created by 甘唯哲 on 2020/7/25.
//

#include <vector>

class Solution {
public:
    int search(std::vector<int>& arr, int target) {
        int left = 0, right = arr.size()-1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (arr[mid] > arr[left])
            {
                if (target <= arr[mid] && target >= arr[left])
                    right = mid - 1;
                else
                    left = left + 1;
            } else if (arr[mid] < arr[left])
            {
                if (target > arr[mid] && target < arr[left])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
            else if (arr[mid] == arr[left])
            {
                if (arr[mid] == target)
                    return left;
                else
                    left += 1;
            }
        }
        if (left == arr.size() || arr[left] != target)
            return -1;
        else
            return left;
    }
};