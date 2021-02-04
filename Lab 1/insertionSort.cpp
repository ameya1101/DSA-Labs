#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void insertionSort(int arr[], int n)
{
    for(int i = 1; i < n; i++)
    {
        int j = i;
        while(j > 0)
        {
            if(arr[j] < arr[j - 1])
                swap(arr[j], arr[j - 1]);
            j = j - 1;
        }
    }

}

void printArray(int arr[], int n)
{
    cout << endl;
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    insertionSort(arr, n);
    printArray(arr, n);
    return 0;
}
