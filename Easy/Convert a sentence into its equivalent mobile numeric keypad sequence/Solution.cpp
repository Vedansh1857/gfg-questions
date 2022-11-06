#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cout<<"Enter the string : ";
    cin>>str;
    string vacant = "";
    map<char,string> ansmap;
    ansmap['A'] = "2"; ansmap['B'] = "22"; ansmap['C'] = "222"; ansmap['D'] = "3"; ansmap['E'] = "33"; ansmap['F'] = "333"; ansmap['G'] = "4"; ansmap['H'] = "44"; ansmap['I'] = "444"; ansmap['J'] = "5"; ansmap['K'] = "55"; ansmap['L'] = "555"; ansmap['M'] = "6"; ansmap['N'] = "66"; ansmap['O'] = "666"; ansmap['P'] = "7"; ansmap['Q'] = "77"; ansmap['R'] = "777"; ansmap['S'] = "7777"; ansmap['T'] = "8"; ansmap['U'] = "88"; ansmap['V'] = "888"; ansmap['W'] = "9"; ansmap['X'] = "99"; ansmap['Y'] = "999"; ansmap['Z'] = "9999";
    for(char i : str){
        map<char,string> :: iterator iter = ansmap.find(i);
        string ans = iter->second;
        vacant += ans;
    }
    cout<<vacant;
    return 0;
}
