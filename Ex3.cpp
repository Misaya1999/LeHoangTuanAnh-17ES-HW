#include <iostream>
#include <conio.h>
using namespace std;
class vector
{
private:
    int n;//Number of elements
    float*data;//Values of vector elements
public:
    vector()//Constructor allows user to enter values from keyboard
    {

        cout<<"the numbers of elements of the vector n=:";
        cin>>n;
        cout<<"enter the value: \n";
        data=new float[n];
        for (int i=0;i<n;i++)
        {
            cout<<"data["<<i<<"]=";
            cin>>data[i];
            cout<<endl;
        }
    }
    vector(float*a,int n)// Constructor initializes values to data members from another array
    {
        for(int i=n+1;i>0;i++)
        {
            a[i]=data[i];
        }
    }
    ~vector()//Destructor
    {
        delete data;
        n=0;
    }
    int capacity()//Returns the current capacity of this vector
    {
        return n;
    }
    void clear()//Removes all of the elements from this Vector.
    {
        delete data;
        n=0;
    }
    bool contains(float elem)//Tests if the specified object is a component in this vector
    {
        for (int j=0;j<n;j++)
        if(data[j]==elem) return true;
        return false;
    }
    int indexOf(float elem)//Searches for the first occurrence of the given argument
    {
    for(int i=1;i<=n;i++)
    {
        if(data[i]=elem)
        {
            return i;
        }
    }
    }
    int lastIndexOf(float elem)//Returns the index of the last occurrence of the specified object in this vector
    {
        int i=n-1;
        for (;i<n;i--);
        if (data[i]==elem)
        return i;
        else
        return -1;
    }
    float elementAt(int index)// Returns the component at the specified index
    {
        return data[index];
    }
    bool isEmpty()//Tests if this vector has no components
    {
        return 0;
    }
    float* toArray() //Returns an array containing all of the elements in this vector in the correct order
    {
        return data;
    }
    void display() //Show values of vector
    {
        if(!isEmpty())
        for (int i=0;i<n;i++)
        cout<<"Index"<<i<<"Value="<<std::endl;
        else
        cout<<"The Vector empty";
    }
};
main()
{
    Vector A;
    A.contains(11); //data[1]=6
                    //data[2]=2
                    //data[3]=7
    cout<<"\nelement 11 has index:"<<A.indexOf(11)<<endl;       //data[4]=4
    cout<<"The capacity of this vector="<<A.capacity()<<endl;   //data[5]=11
    A.isEmpty();    //data[6]=3
    cout<<"\nindex 8 contains the element:"<<A.elementAt(8)<<endl;  //data[7]=7
    cout<<"The last ocurency of element 7 is at index "<<A.lastIndexOf(7)<<endl;    //data[8]=12
    A.display();    //data[9]=23
    getch();
}
