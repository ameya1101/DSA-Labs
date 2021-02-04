#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void quickSort(int arr[], int begin, int end);
int partition(int arr[], int begin, int end);

int partition(int arr[], int begin, int end)
{
    int pivot = arr[end];
    size_t i = begin;

    for(size_t j = begin; j < end; j++)
    {
        if(arr[j] < pivot)
        {
            swap(arr[j], arr[i]);
            i++;
        }
    }
    swap(arr[i], arr[end]);
    return i;
}

void quickSort(int arr[], int begin, int end)
{
    if(begin < end)
    {
        size_t partitionIndex = partition(arr, begin, end);
        quickSort(arr, begin, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, end);
    }
}

int main(int argc, char const *argv[])
{
    int n, arr[n];
    cin >> n;

    for(size_t i = 0; i < n; i++)
        cin >> arr[i];

    quickSort(arr, 0, n-1);
    cout << endl;
    for(size_t i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}
