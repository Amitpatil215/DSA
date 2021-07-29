#include <iostream>
using namespace std;

// recusrsion solution of fabonaci
int fib(int n) // T=O(2^n)
{

    if (n == 0 || n == 1)
    {
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}

// improved complexity by storing the repeated calucluated fabonaci values
int fib2(int n, int *arr) // T= O(2n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    if (arr[n] != 0)
    {
        return arr[n];
    }
    else
    {
        int output = fib2(n - 1, arr) + fib2(n - 2, arr);
        arr[n] = output;
        return output;
    }
}

// any way we are storing n fabonaci values in array, for that we can just store them
// initially and return the desired value
int fib3(int n) // T=O(n) S=O(n)
{
    int *arr = new int(n + 1);
    arr[0] = 0;
    arr[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    int value = arr[n];
    delete[] arr;
    return value;
}
int main()
{
    int n;

    cin >> n;
    int *arr = new int(n + 1);
    for (int i = 0; i <= n; i++)
    {
        arr[i] = 0;
    }
    cout << fib2(n, arr) << endl;
    cout << fib3(n);
    return 0;
}