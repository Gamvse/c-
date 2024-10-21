#include <iostream>
#include <windows.h>

using namespace std;

#define color SetConsoleTextAttribute

int main()
{
    HANDLE hConsole = GetStdHandle( STD_OUTPUT_HANDLE );

    /*
    color(hConsole,4);
    cout<< " wawa";
    color(hConsole,7);
    */

    for (int i=0;i<243;i++)
    {
        color(hConsole,i);
        cout<< " waos "<<i <<endl; 
    }

    color(hConsole,64);
    cout<< " " <<endl; 
    color(hConsole,15);

    return 0;
}