#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> vectorizeString(string);
int birthdayCakeCandles(vector<int>);

vector<int> vectorizeString(string str)
{
    vector<int> vect;
    stringstream ss(str);
    int number;

    while(ss >> number)
        vect.push_back(number);

    return vect;
}

int birthdayCakeCandles(vector<int> candles)
{
    map<int, int> candleNumbers;
    for(auto& i : candles)
        candleNumbers[i]++;

    int max = INT_MIN;
    for (auto& i : candles)
    {
        if(i > max)
            max = i;
    }

    return candleNumbers[max];
}


int main(int argc, char const *argv[])
{
    string candleCountString;
    string candlesString;

    vector<int> candles;
    int candleCount;

    ifstream fin;
    string line;

    fin.open("input.txt");
    getline(fin, candleCountString);
    getline(fin, candlesString);
    fin.close();

    candles = vectorizeString(candlesString);
    candleCount = stoi(candleCountString);

    int result = birthdayCakeCandles(candles);
    cout << result << endl;

    return 0;
}
