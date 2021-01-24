#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

bool isBeautiful(int n, int k)
{
    int rev = 0;
    int num = n;
    while(n != 0)
    {
        int digit = n % 10;
        rev = rev * 10 + digit;
        n = n / 10;
    }

    return (abs(num - rev) % k == 0);
}

int beautifulDays(int i, int j, int k)
{
    size_t beautifulDayCounter = 0;
    for(int m = i; m <= j; m++)
    {
        if(isBeautiful(m, k))
            ++beautifulDayCounter;
    }

    return beautifulDayCounter;
}


int main(int argc, char const *argv[])
{
    int i = stoi(argv[1]);
    int j = stoi(argv[2]);
    int k = stoi(argv[3]);

    int result = beautifulDays(i, j, k);
    cout << result << endl;
    return 0;
}
