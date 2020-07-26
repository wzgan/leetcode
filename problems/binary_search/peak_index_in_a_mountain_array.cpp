//
// Created by 甘唯哲 on 2020/7/26.
//

// https://leetcode.com/problems/peak-index-in-a-mountain-array/

#include <vector>

class Solution {
public:
    int peakIndexInMountainArray(std::vector<int>& A) {
        int left = 0, right = A.size()-1;
        while(left <= right)
        {
            int mid = (left + right)/2;
//            if(mid == 0)
//                return 1;
            if(mid+1<=A.size() && A[mid]<A[mid+1]) //make sure the target is in right side
                left = mid + 1;
//            else if(A[mid]<A[mid-1])
//                right = mid - 1;
//            else
//                return mid;
            else //if target is not in right side, then search in left side (make sure left is in target)
                right = mid - 1;

        }
        return left; //the left pointer will point to the target;
    }
};