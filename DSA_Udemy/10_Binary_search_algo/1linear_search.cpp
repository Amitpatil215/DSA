#include <iostream>
using namespace std;

int main()
{
    int n;
    int key;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "enter key";
    cin >> key;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == key)
        {
            cout << "Key found at " << i << endl;
            return 0;
        }
    }
    cout << "Key not found";

    return 0;
}