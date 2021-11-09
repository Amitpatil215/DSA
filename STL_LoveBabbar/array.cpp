#include <iostream>
#include <array>
using namespace std;

int main()
{
    int basic[3] = {1, 2, 3};

    array<int, 4> ar = {1, 2, 3, 4};
    int size = ar.size();

    for (int i = 0; i < size; i++)
    {
        cout << ar[i] << endl;
    }

    cout << "Element at 2nd index " << ar.at(2) << endl;
    cout << "is Empty " << ar.empty()<<endl;
    cout<<ar.front()<<" "<<ar.back()<<" ";

}