# 算法
## 1. 排序
| 算法 | 时间复杂度 | 空间复杂度 |
| :-----                                  | :----:   | :----: |
| [冒泡排序](./排序/BubbleSort.cpp)   | O($n^2$)  |  O()   |
| [插入排序](./排序/InsertSort.cpp)   | O($n^2$)  |  O()   |
| [选择排序](./排序/SelectSort.cpp)   | O($n^2$)  |  O()   |
| [快速排序](./排序/QuickSort.cpp) | O(n*logn)  |  O()   |
| [归并排序](./排序/MergeSort.cpp) | O(n*logn)  |  O()   |
| [堆排序](./排序/HeapSort.cpp) | O(n*logn)  |  O()   |

## 2. 二分查找
- 有序数组查找：[LeetCode35](https://leetcode-cn.com/problems/search-insert-position/)
```
while(left <= right)
{
    mid = left + ((right - left) >> 2);
    if(nums[mid] == target) return mid;
    else if(nums[mid] > target)  right = mid - 1;
    else    left = mid + 1;
}
return left;
如果为找到目标值target，left所指向位置为有序数组中target插入位置。
跳出循环时，如果nums[mid] > target,right = mid - 1,left = mid,必有nums[right] < target && nums[left] > target。如果nums[mid] < target,left = mid + 1,right = mid,必有nums[right] < target && nums[left] > target。插入位置都为left。
```
- 有序数组第一个大于等于k，最后一个小于等于k的位置：[LeetCode34](https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/)
```
有序数组最后一个等于target的位置：
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
```
- 局部最小问题：无序数组，相邻数一定不相等：[LeetCode162](https://leetcode-cn.com/problems/find-peak-element/)
```
通过与mid+1位置值比较大小判断峰值位置。
while(left < right)
{
    int mid = left + ((right - left) / 2);
    if(nums[mid] > nums[mid + 1])   right = mid;
    else    left = mid + 1;
}
```
- 局部有序问题（旋转数组）:[LeetCode33](https://leetcode-cn.com/problems/search-in-rotated-sorted-array/)
```
代码模版：
while (left <= right)
{
    int mid = left + ((right - left) >> 2);
    if(nums[mid] == target) return mid;
    if(nums[mid] >= nums[left]) // [0-mid]为有序数组，注意等号，不带等号当数组只有两个元素时划分错误。例如{3, 1}.
    {
        if(target < nums[mid] && target >= nums[left])  right = mid - 1;
        else    left = mid + 1;
    }
    else    // [mid-n]为有序数组
    {
        if(target > nums[mid] && target <= nums[right])  left = mid + 1;
        else    right = mid - 1;
    }
}
```

## 3. 递归
- master公式：T(n) = a * T($\frac{N}{b}$) + O($N^2$)</br>
其中，a为子问题的调用次数，b为子问题规模，O($N^d$)为除去子问题剩下的时间复杂度。</br>
$log_ba$ < d => O($N^d$)</br>
$log_ba$ > d => O($N*log_ba$)</br>
$log_ba$ = d => O($N^d * logN$)