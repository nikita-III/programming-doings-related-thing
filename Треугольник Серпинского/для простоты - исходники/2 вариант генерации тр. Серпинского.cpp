#include <iostream>
#include <fstream>
using namespace std;

int powForNatInt(int a, int b)
{
    if (b == 1)
    {
        return a;
    }
    if (b == 0)
    {
        return 1;
    }
    return a * powForNatInt(a, b - 1);
}

int SeTri(int** p, int a, int px, int py, int d)
{
    if (d == 0)
    {
        return **p;
    }
    int** p1 = new int* [a];
    for (int i = 0; i < a; i++)
    {
        p1[i] = new int[a];
    }
    for (int i = a-px; i < a+px; i+=2)
    {
        for (int j = a-py; j < a+py; j+=2)
        {
            p1[i / 2][j / 2] = p[i][j];
        }
    }
}

int main()
{
    ofstream out;
    out.open("Output text.txt");
    int n = 50, d;
    for (int i = 1; i <= 5; i++)
    {
        d = i;
        out << n << " " << d << endl << endl;
        int** p = new int* [n];
        for (int i = 0; i < n; i++)
        {
            p[i] = new int[n];
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                p[i][j] = 0;
            }
        }
        for (int i = 0; i < n; i++)
        {
            p[i][0] = 1;
            p[i][n - i - 1] = 1;
            p[0][i] = 1;
        }
        for (int i = 0; i < n; i++)
        {
            p[i][n / 2] = 1;
            p[i][n / 2 - i - 1] = 1;
            p[n / 2][i] = 1;
        }

        SeTri(p, n / 2, n / 2,  n / 2, d-1);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (p[i][j] == 0)
                {
                    out << " ";
                }
                else
                {
                    out << p[i][j];
                }
                out << " ";
            }
            out << endl;
        }
        out << endl;
    }
    out.close();
    return 0;
}