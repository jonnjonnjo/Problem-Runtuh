#include <bits/stdc++.h>
using namespace std;
int r,c;
string papan[20];
string satu;
string nol ;

bool runtuh_tidak()
{
    for(int y = 0;y < r;y++)
    {
        if(papan[y] == satu) return true;
    }
    return false;
}


void runtuhkan()
{
    int batasbawah = 0;

    for(int y = 0;y < r;y++)
    {
        if(papan[y] == satu)
        {
            papan[y] = nol;
            batasbawah = y;
        }
    }


    for(int x = 0;x < c;x++)
    {
        int jumlahsatu = 0;
        int batasss = r;

        for(int y = 0;y <batasbawah;y++)
        {
            if(papan[y][x] == '1')
            {
                papan[y][x] = '0';
                jumlahsatu +=1;
            }
        }

        for(int y = batasbawah; y <r;y++)
        {
            if(papan[y][x] == '1')
            {
                batasss = y;
                break;
            }
        }

        for(int y = batasss-1;(jumlahsatu > 0 && y>=0);y--)
        {
            papan[y][x] = '1';
            jumlahsatu -=1;
        }

    }
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> r >> c;

    for(int x = 0;x < r;x++) cin >> papan[x];

    for(int x = 0;x < c;x++)
    {
        satu += '1';
        nol += '0';
    }

    cout << "\n\n";


    while(runtuh_tidak())
    {
        runtuhkan();
    }

    for(int y= 0;y < r;y++) cout << papan[y] << "\n";
}
