#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int left = 0, right = n * m - 1;
        while(left <= right)
        {
            int mid= left + ((right - left) >> 2);
            int value = matrix[mid / n][mid % n];
            if(target == value)    return true;
            else if(target > value)    left = mid + 1;
            else    right = mid - 1;
        }
        return false;
    }
};

int main()
{
    
}