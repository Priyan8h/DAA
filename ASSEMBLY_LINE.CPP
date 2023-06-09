#include <iostream>
#include <string.h>
using namespace std;

int assemblyline(int a[][4], int t[][4], int e[], int x[])
{
    int T1[4], T2[4];
    T1[0] = e[0] + a[0][0];
    T2[0] = e[1] + a[1][0];
    for (int i = 1; i < 4; i++)	
    {
        T1[i] = min(T1[i - 1] + a[0][i], T2[i - 1] + t[1][i] + a[0][i - 1]);
        T2[i] = min(T2[i - 1] + a[1][i], T1[i - 1] + t[0][i] + a[1][i - 1]);
    }
    return min(T1[3] + x[0], T2[3] + x[1]);
}
int main()
{
    int a[][4] = {{4, 5, 3, 2}, {2, 10, 1, 4}};
    int t[][4] = {{0, 7, 4, 5}, {0, 9, 2, 8}};
    int e[] = {10, 12};
    int x[] = {18, 7};
    cout << "The minimum time taken is : " <<assemblyline(a, t, e, x);
    return 0;
}
