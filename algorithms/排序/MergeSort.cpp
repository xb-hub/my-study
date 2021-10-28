#include <iostream>
using namespace std;

void merge(int arr[], int L, int mid, int R)
{
    int help[R - L + 1];
    int p1 = L, p2 = mid + 1;
    int index = 0;
    while (p1 <= mid && p2 <= R)
    {
        help[index++] = arr[p1] > arr[p2] ? arr[p2++] : arr[p1++];
    }
    while (p1 <= mid)
    {
        help[index++] = arr[p1++];
    }
    while (p2 <= R)
    {
        help[index++] = arr[p2++];
    }
    for (int i = 0; i < R - L + 1; i++)
    {
        arr[L + i] = help[i];
    }
}

void MergeSort(int arr[], int L, int R)
{
    if(L == R)  return;
    int mid = L + ((R - L) >> 2);
    MergeSort(arr, L, mid);
    MergeSort(arr, mid + 1, R);
    merge(arr, L, mid, R);
}

int main()
{
    int arr[10] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 0};
    MergeSort(arr, 0, 9);
    for(int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}