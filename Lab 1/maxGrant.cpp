#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[]) 
{
    size_t t;
    cin >> t;
    
    while(t--)
    {
        int n;
        cin >> n;
        int a[n], b[n];

        for(size_t i = 0; i < n; i++)
            cin >> a[i];
        
        for(size_t i = 0; i < n; i++)
            cin >> b[i];

        sort(a, a+n);
        sort(b, b+n);

        long long int totFunds = 0;
        for(size_t i = 0; i < n; i++)
            totFunds += min(a[i], b[i]);

        cout << totFunds << endl;
    }


    return 0;
}

