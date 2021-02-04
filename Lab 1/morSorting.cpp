#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


void morSort(vector<int>& arr, int begin, int end, int k)
{
    if(begin >= end)
        return;
    
    int arrSize = (end - begin + 1);
    int pivotIndex = begin + k % arrSize;
    int pivot = arr[pivotIndex];

    cout << pivot << " ";

    vector<int> left, right;
    for(int i = begin; i <= end; i++)
    {
        if(i == pivotIndex)
            continue;
        if(arr[i] > arr[pivotIndex])
            right.push_back(arr[i]);
        else
            left.push_back(arr[i]);
    }

    int i = begin;
    for(int j = 0; j < left.size(); i++, j++)
        arr[i] = left[j];
    arr[i] = pivot;
    int newIndex = i;
    i++;
    for(int j = 0; j < right.size(); i++, j++)
        arr[i] = right[j];

    morSort(arr, begin, newIndex - 1, k);
    morSort(arr, newIndex + 1, end, k);
    
}

int main(int argc, char const *argv[]) 
{
    int n, k;
    vector<int> arr;

    cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
       int number;
       cin >> number;
       arr.push_back(number);
    }

    morSort(arr, 0, n - 1, k);
    cout << endl;
    return 0;
}

