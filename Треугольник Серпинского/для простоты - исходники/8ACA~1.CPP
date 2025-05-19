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

int diagonal(int** p, int dl, int dupx, int dupy, int ddpx, int ddpy)
{
    for (int i = 0; i < dl; i++)
    {
        p[ddpy - i][dupx - dl + i - 1] = 1;
    }
    return **p;
}

int verLine(int** p, int ll, int lupx, int lupy, int ldpx, int ldpy)
{
    for (int i = 0; i < ll; i++)
    {
        p[ldpy-ll+i][lupx-1] = 1;
    }
    return **p;
}

int gorLine(int** p, int ll, int lupx, int lupy, int ldpx, int ldpy)
{
    for (int i = 0; i < ll; i++)
    {
        p[ldpy-1][lupx - ll + i] = 1;
    }
    return **p;
}

int SeTri(int **p, int a, int o1x, int o1y, int o2x, int o2y, int d)
{
    if (d == 0)
    {
        return **p;
    }
    verLine(p, a, o1x, o1y, o2x, o2y);
    gorLine(p, a, o1x, o1y, o2x, o2y);
    diagonal(p, a, o1x, o1y, o2x, o2y);
    SeTri(p, a / 2, o1x - (a / 2), o1y, o2x, o2y - (a / 2), d - 1);
    SeTri(p, a / 2, o1x + (a / 2), o1y, o2x, o2y - (a / 2), d - 1);
    SeTri(p, a / 2, o1x - (a / 2), o1y, o2x, o2y + (a / 2), d - 1);
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

        SeTri(p, n / 2, n/2, 0, 0, n/2, d);

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
                    out << "1";
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