#include <iostream>
#include <conio.h>

using namespace std;

class Cube
{
private:
    double size=10;

public:
    Cube(double val)
    {
        if(val>0)
        {
            size=val;
        }
    }
    void setSize(double val)
    {
        if(val>0)
        {
            size=val;
        }
    }
double getSize()
    {
        return size;
    }
    volume()
    {
        return size*size*size;
    }
void details()
{
    cout<<"\ndetails of rectangle";
    cout<<"width="<<size;
    cout<<"height="<<size;
    cout<<"length="<<size;
    cout<<"volume="<<volume()<<"\n\n";
}

};

int main()
{
    Cube Cube1(4), Cube2(3), Cube3(-2);
    Cube1.details();
    Cube2.details();
    Cube3.details();
}
