#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 1)  return nums[0] == target;
        int left = 0, right = n - 1;
        while(left <= right)
        {
            int mid = left + ((right - left) >> 2);
            if(nums[mid] == target) return true;
            if (nums[left] == nums[mid])
            {
                left++;
                continue;
            }
            if(nums[mid] >= nums[left])
            {
                if(target < nums[mid] && target >= nums[left])
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
            else
            {
                if(target > nums[mid] && target <= nums[right])
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }
            }
        }
        return false;
    }
};