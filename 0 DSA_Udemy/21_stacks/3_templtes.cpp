#include <bits/stdc++.h>
using namespace std;

template <typename T, typename V>
class Pair
{
    T x;
    V y;

public:
    void setX(T x)
    {
        this->x = x;
    }

    T getX()
    {
        return x;
    }

    void setY(V y)
    {
        this->y = y;
    }

    V getY()
    {
        return y;
    }
};

int main()
{
    Pair<int, int> intP;
    intP.setX(12);
    cout << intP.getX() << endl;

    Pair<double, int> doubleP;
    doubleP.setX(12.22);
    cout << doubleP.getX() << endl;

    // triplet implementaion in pair class
    Pair<Pair<int, int>, double> triplet;
    Pair<int, int> p;
    p.setX(10);
    p.setY(20);
    triplet.setX(p);
    cout<<triplet.getX().getX()<<endl;

    return 0;
}