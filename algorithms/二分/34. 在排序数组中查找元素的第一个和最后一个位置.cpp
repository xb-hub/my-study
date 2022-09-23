#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 0)  return {-1, -1};
        int left = 0, right = n - 1, left_ans, right_ans;
        while(left <= right)
        {
            int mid = left + ((right - left) >> 2);
            if(nums[mid] >= target)
            {
                left_ans = mid;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        left = 0; right = n - 1;
        while(left <= right)
        {
            int mid = left + ((right - left) >> 2);
            if(nums[mid] > target)
            {
                right = mid - 1;
            }
            else
            {
                right_ans = mid;
                left = mid + 1;
            }
        }
        if(nums[left_ans] == target && nums[right_ans] == target)   return {left_ans, right_ans};
        return {-1, -1};
    }
};

int main()
{
    
}