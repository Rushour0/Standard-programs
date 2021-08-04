#include<iostream>
#include<cmath>
using namespace std;

class coordinatepoint
{
    friend float distance(coordinatepoint o1, coordinatepoint o2);
    int x,y;
public:
    coordinatepoint(int ,int );//Constructor Declaration
    void display()
    {
        cout << "Point = (" << x << "," << y << ")" << endl;
    }
};

float distance(coordinatepoint o1, coordinatepoint o2)
{
    float a,dist;
    dist = (pow((o1.x-o2.x),2) + pow((o1.y-o2.y),2));
    return sqrt(dist);
}

coordinatepoint :: coordinatepoint(int a,int b)//This is a parameterized constructor.
{
 x=a;
 y=b;
}

int main()
{
    float d;
    coordinatepoint p1(5,6);
    p1.display();

    coordinatepoint p2(3,4);
    p2.display();

    d=distance(p1,p2);
    cout<<"The distance between the given ponts is "<<d<<endl;
    return 0;
}