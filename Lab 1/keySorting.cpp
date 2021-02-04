#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool customSort(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.second < b.second;
}

int merge(int value[], int low, int mid, int high)
{
    int left = mid - low + 1;
    int right = high - mid;
    int count = 0;

    int a[left], b[right];

    for(int i = 0; i < left; i++)
        a[i] = value[low + i];
    
    for(int i = 0; i < right; i++)
        b[i] = value[mid + 1 + i];
    
    int i = 0, j = 0, k = low;

    while(i < left && j < right)
    {
        if(a[i] <= b[j])
        {
            value[k] = a[i]; 
            i++;
        }
        else
        {
            value[k] = b[j];
            count += (left - i);
            j++;
        }     
        k++;
    }

    while(i < left)
    {
        value[k] = a[i];
        k++;
        i++;
    }

    while(j < right)
    {
        value[k] = a[j];
        k++;
        j++;
    }
    
    return count;
}

int mergeSort(int value[], int low, int high)
{
    int count = 0;
    if(low < high)
    {
        int mid = (low + high)/2;
        count += mergeSort(value, low, mid);
        count += mergeSort(value, mid+1, high);
        count += merge(value, low, mid, high);
    }

    return count;
}


int main(int argc, char const *argv[]) 
{
    int n;
    cin >> n;
    pair<int,int> arr[n];

    for(int i = 0; i < n; i++)
        cin >> arr[i].first;

    for(int i = 0; i < n; i++)
        cin >> arr[i].second;

    sort(arr, arr + n, customSort);

    int value[n];
    for(int i = 0; i < n; i++)
        value[i] = arr[i].first;
    
    int count = mergeSort(value, 0, n - 1);
    cout << count << endl;

    return 0;
}

