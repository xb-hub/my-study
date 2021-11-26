#include <iostream>
using namespace std;

/**
 * @brief 大根堆
 */
// void HeapInsert(int arr[], int index)
// {
//     int parent = (index - 1) / 2;
//     while (arr[index] > arr[parent])
//     {
//         swap(arr[index], arr[parent]);
//         index = parent;
//         parent = (index - 1) / 2;
//     }
// }

// void Heapidy(int arr[], int index, int heapsize)
// {
//     int left = index * 2 + 1;
//     while (left < heapsize)
//     {
//         int largest = left + 1 < heapsize && arr[left] < arr[left + 1] ? left + 1 : left;
//         largest = arr[index] > arr[largest] ? index : largest;
//         if(largest == index)    break;
//         swap(arr[index], arr[largest]);
//         index = largest;
//         left = index * 2 + 1;
//     }
// }

/**
 * @brief 小根堆
 */
void HeapInsert(int arr[], int index)
{
    int parent = (index - 1) / 2;
    while (arr[index] < arr[parent])
    {
        swap(arr[index], arr[parent]);
        index = parent;
        parent = (index - 1) / 2;
    }
}

void Heapidy(int arr[], int index, int heapsize)
{
    int left = 2 * index + 1;
    while (left < heapsize)
    {
        int smallest = left + 1 < heapsize && arr[left] > arr[left + 1] ? left + 1 : left;
        smallest = arr[index] < arr[smallest] ? index : smallest;
        if(index == smallest)   break;
        swap(arr[index], arr[smallest]);
        index = smallest;
        left = 2 * index + 1;
    }
}

void HeapInit(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        HeapInsert(arr, i);
    }
}

void HeapSort(int arr[], int heapsize)
{
    HeapInit(arr, heapsize);
    swap(arr[0], arr[--heapsize]);
    while (heapsize > 0)
    {
        Heapidy(arr, 0, heapsize);
        swap(arr[0], arr[--heapsize]);
    }
}

int main()
{
    int arr[10] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 0};
    HeapSort(arr, 10);
    for(int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}