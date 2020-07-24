//
// Created by 甘唯哲 on 2020/7/23.
//

//https://leetcode.com/problems/sqrtx/

class Solution {
public:
    int mySqrt(int x)
    {
        if (x < 1) return 0;
        int left = 0, right = x;
        while (left <= right)
        {
            int mid = left + (right - left)/2;
            int sqrtx = x / mid;
            if (sqrtx == mid)
                return mid;
            else if (sqrtx < mid)
                right = mid-1;
            else if (sqrtx > mid)
                left = mid+1;
        }
        return right;
    }
};