#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string intToRoman(int num)
{
}

int number(int num)
{
    vector<int> test = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};

    for (int i = 12; i >= 0; i--)
    {
        if (test[i] <= num)
        {
            return test[i];
        }
    }
    return -1;
}
string mainAns(int num, map<int, string> &roman)
{
    if (num == 0)
    {
        return "";
    }
    // if it s direct finded
    if (roman.find(num) != roman.end())
    {
        return roman[num];
    }

    // find largest small value
    int value = number(num);

    int count = num / value;

    string ans = "";
    while (count > 0)
    {
        ans = ans + roman[value];
        count--;
    }

    cout << ans << endl;
    return ans + mainAns(num % value, roman);
}
int main()
{
    map<int, string> roman;
    roman[1] = "I";
    roman[4] = "IV";
    roman[5] = "V";
    roman[9] = "IX";
    roman[10] = "X";
    roman[40] = "XL";
    roman[50] = "L";
    roman[90] = "XC";
    roman[100] = "C";
    roman[400] = "CD";
    roman[500] = "D";
    roman[900] = "CM";
    roman[1000] = "M";
    cout << mainAns(3749, roman);
    return 0;
}