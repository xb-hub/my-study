#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n - 1;
        if (n == 1) 
        {
            return nums[0] == target ? 0 : -1;
        }
        while (left <= right)
        {
            int mid = left + ((right - left) >> 2);
            if(nums[mid] == target) return mid;
            if(nums[mid] >= nums[0]) // [0-mid]为有序数组，注意等号，不带等号当数组只有两个元素时划分错误。例如{3, 1}.
            {
                if(target < nums[mid] && target >= nums[0])  right = mid - 1;
                else    left = mid + 1;
            }
            else    // [mid-n]为有序数组
            {
                if(target > nums[mid] && target <= nums.back())  left = mid + 1;
                else    right = mid - 1;
            }
        }
        return -1;
    }
};

int main()
{

}