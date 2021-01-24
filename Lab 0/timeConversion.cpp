#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

/*
 * Complete the timeConversion function below.
 */
string timeConversion(string s) 
{
    
    vector<string> times;
    istringstream ss(s);
    string timeString;
    char delim = ':';

    while(getline(ss, timeString, delim))
    {
        times.push_back(timeString);
    }

    string hourString = times[0];
    string minuteString = times[1];
    string secondString = times[2].substr(0, 2);
    string marker = times[2].substr(2, 2);

    if(marker == "AM")
    {
        if (hourString == "12")
            hourString = "00";
        return hourString + delim + minuteString + delim + secondString;
    }

    else
    {
        int hours = stoi(hourString);
        if(hours != 12)
            hours = (hours + 12) % 24;

        return to_string(hours) + delim + minuteString + delim + secondString;
    }

}

int main(int argc, char const *argv[])
{
    string s = argv[1];
    string result = timeConversion(s);

    cout << result << "\n";
    return 0;
}
