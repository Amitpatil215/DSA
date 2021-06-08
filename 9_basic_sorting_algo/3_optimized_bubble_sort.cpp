#include <iostream>
using namespace std;

void bubbleSort(int a[], int n)
{

    for (int count = 0; count < n - 1; count++)
    {
        int flag = 0;
        for (int j = 0; j < n - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
                flag = 1;
            }
        }
        if (flag == 0)
            break;
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

    bubbleSort(a, n);

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << endl;
    }

    return 0;
}