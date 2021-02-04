#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void arrayInput(int arr[], int n)
{
    for(int i = 0; i < n; i++)
        cin >> arr[i];
}

void arrayOutput(int arr[], int n)
{
    cout << endl;
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void merge(int arr[], int low, int mid, int high)
{
    int lowerPartitionIndex = mid - low + 1;
    int higherPartitionIndex = high - mid;

    int left[lowerPartitionIndex], right[higherPartitionIndex];

    for(int i = 0; i < lowerPartitionIndex; i++)
        left[i] = arr[low + i];

    for(int i = 0; i < lowerPartitionIndex; i++)
        right[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = low;
    while(i < lowerPartitionIndex && j < higherPartitionIndex)
    {
        if(left[i] <= right[j])
            arr[k] = left[i++];
        else
            arr[k] = right[j++];
        k++;
    }

    while(i < lowerPartitionIndex)
        arr[k++] = left[i++];

    while(j < higherPartitionIndex)
        arr[k++] = right[j++];
}

void mergeSort(int arr[], int low, int high)
{
    if(low < high)
    {
        int mid = (low + high)/2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int arr[n];

    arrayInput(arr, n);
    mergeSort(arr, 0, n - 1);
    arrayOutput(arr, n);
    return 0;
}
