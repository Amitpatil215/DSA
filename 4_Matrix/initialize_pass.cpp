#include <iostream>
using namespace std;

void printArray(int a[][5], int m, int n)
{
    //* Print Row wise
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int a[5][5] = {
        {1, 2},
        {3, 4},
    };

    // initialize 2D array with all zeros
    int b[4][5] = {{0}};

    printArray(a, 5, 5);

    cout << endl;

    printArray(b, 4, 4);
    return 0;
}
