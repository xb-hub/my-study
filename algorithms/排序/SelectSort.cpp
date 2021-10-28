#include <iostream>
using namespace std;

void swap(int arr[], int i, int j)
{
    arr[i] = arr[i] ^ arr[j];
    arr[j] = arr[i] ^ arr[j];
    arr[i] = arr[i] ^ arr[j];
}

void SelectSort(int arr[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        int index = i;
        for(int j = i + 1; j < n; j++)
        {
            if(arr[index] > arr[j])
            {
                index = j;
            }
        }
        if(i != index)  swap(arr, i, index);
    }
}

int main()
{
    int arr[10] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 0};
    SelectSort(arr, 10);
    for(int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}