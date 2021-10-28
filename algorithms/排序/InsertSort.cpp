#include <iostream>
using namespace std;

void swap(int arr[], int i, int j)
{
    arr[i] = arr[i] ^ arr[j];
    arr[j] = arr[i] ^ arr[j];
    arr[i] = arr[i] ^ arr[j];
}

void InsertSort(int arr[], int n)
{
    for(int i = 1; i < n; i++)
    {
        for(int j = i - 1; arr[j + 1] < arr[j] && j >= 0; j--)
        {
            swap(arr, j + 1, j);
        }
    }
}

int main()
{
    int arr[10] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 0};
    InsertSort(arr, 10);
    for(int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}