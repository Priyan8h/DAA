#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
int max(int a, int b) {
    return (a > b) ? a : b;
}
 
// A utility function to find maximum of three integers
int max(int a, int b, int c) {
    return max(max(a, b), c);
}
int maxcs(int arr[], int l, int m, int h)
{
    int sum = 0;
    int left_sum = INT_MIN;
    for (int i = m; i >= 0; i--)
    {
        sum += arr[i];
        if (sum > left_sum)
            left_sum = sum;
    }

    sum = 0;
    int right_sum = INT_MIN;
    for (int i = m; i <= h; i++)
    {
        sum += arr[i];
        if (sum > right_sum)
            right_sum = sum;
    }

    return max(left_sum + right_sum - arr[m], left_sum, right_sum);
}
int maxsubarraysum(int arr[], int l, int h)
{
    if (l > h)
        return INT_MIN; // invalid condition
    if (l == h)
        return arr[l]; // base condition
    int m = (l + h) / 2;
    return max(maxsubarraysum(arr, l, m - 1), maxsubarraysum(arr, m + 1, h), maxcs(arr, l, m, h));
}
int main()
{
    int N;
    cout << "Enter number of elements : ";
    cin >> N;
    int arr[N];
    for (int i = 0; i < N; i++)
    {
        cout << "Enter " << i << " element : ";
        cin >> arr[i];
    }
    cout << "The maximum contigous sum is : " << maxsubarraysum(arr, 0, N - 1);
    return 0;
}
