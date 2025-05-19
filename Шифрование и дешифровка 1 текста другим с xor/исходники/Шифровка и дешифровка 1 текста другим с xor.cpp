#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <ctime>
#include <cmath>
#include <string>
using namespace std;

int main()
{
    ifstream in1, in2;
    ofstream out;
    in1.open("Source text 1.txt");
    in2.open("Source text 2.txt");
    out.open("Output text.txt");
    int indofi=0, n=0;
    string s1, s2, s3;
    getline(in1, s1);
    getline(in2, s2);
    cout << s1 << '\n' << s2 << '\n' << s3 << '\n';
    out << s1 << '\n' << s2 << '\n' << s3 << '\n';
    while (n< s1.size()-1)
    {
        for (int i=0; i< s1.size()&&i< s2.size(); i++)
        {
            s3.push_back(s1[i] ^ s2[i]);
            indofi = i;
        }
        n += indofi;
    }
    cout << '\n' << s1 << '\n' << s2 << '\n' << s3 << '\n';
    out << '\n' << s1 << '\n' << s2 << '\n' << s3 << '\n';
    s1="";
    n = 0;
    while (n < s3.size()-1)
    {
        for (int i = 0; i < s3.size() && i < s2.size(); i++)
        {
            s1.push_back(s3[i] ^ s2[i]);
            indofi = i;
        }
        n += indofi;
    }
    cout << '\n' << s3 << '\n' << s2 << '\n' << s1 << '\n';
    out << '\n' << s3 << '\n' << s2 << '\n' << s1 << '\n';
    in1.close();
    in2.close();
    out.close();
    return 0;
}