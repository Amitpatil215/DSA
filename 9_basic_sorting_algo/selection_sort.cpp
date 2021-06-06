#include <iostream>
using namespace std;

void selectionSort(int a[], int n)
{
    for (int i = 0; i <= n - 2; i++)
    {
        int smallest = i; // index of smallest element

        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[smallest])
            {
                smallest=j;
            }
        }

        if (a[i] > a[smallest])
        {
            swap(a[i], a[smallest]);
        }
    }
}

int main()
{
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    selectionSort(a, n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << endl;
    }
    return 0;
}