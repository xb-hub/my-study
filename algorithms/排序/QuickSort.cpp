#include <iostream>
using namespace std;

int partition(int arr[], int L, int R)
{
    int tmp = arr[L];
    while (L < R)
    {
        while (L < R && arr[R] >= tmp)    R--;
        arr[L] = arr[R];
        while (L < R && arr[L] <= tmp)    L++;
        arr[R] = arr[L];
    }
    arr[L] = tmp;
    return L;
}

void QuickSort(int arr[], int L, int R)
{
    if(L < R)
    {
        int localation = partition(arr, L, R);
        QuickSort(arr, L, localation - 1);
        QuickSort(arr, localation + 1, R);
    }
}

int main()
{
    int arr[10] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 0};
    QuickSort(arr, 0, 9);
    for(int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}