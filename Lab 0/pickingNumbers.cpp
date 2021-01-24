#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <vector>
#include <algorithm>


using namespace std;

vector<int> vectorizeString(string);
int pickingNumbers(vector<int>);

vector<int> vectorizeString(string str)
{
    vector<int> vect;
    stringstream ss(str);
    int number;

    while(ss >> number)
        vect.push_back(number);

    return vect;
}

int pickingNumbers(vector<int> a)
{
    int frequencies[100] = {0};
    for(auto i : a)
        frequencies[i]++;

    int maxLength = 0;

    int prev = frequencies[0];
    for(size_t i = 1; i < 100; i++)
    {
        int current = frequencies[i];
        if(prev + current > maxLength)
            maxLength = prev + current;
        prev = current;
    }

    return maxLength;

}


int main(int argc, char const *argv[])
{
    ifstream fin;
    string line;

    string sizeString;
    string arrayString;

    size_t size;
    vector<int> a(size);


    fin.open("input.txt");
    getline(fin, sizeString);
    getline(fin, arrayString);
    fin.close();

    size = stoi(sizeString);
    a = vectorizeString(arrayString);

    int result = pickingNumbers(a);
    cout << result << endl;

    return 0;
}
