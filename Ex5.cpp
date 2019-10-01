#include <iostream>
#include <conio.h>

class Vector
{
private:
    int n;//number of elements
    float*data;//values of vector elements
public:
    Vector()//constructor allows user to enter values from keyboard
    {
        cout<<"Enter the values of vector\n";
        cout<<"The number of element: ";
        cin>>n;
        cout<<"The value of vector element:\n";
        data=new float[n];
        for (int i=0;i<n;i++)
        {
            cout << "data["<<i<<"] = ";
            cin >> data[i];
        }
    }
    Vector(float *a , int n)// Constructor initializes values to data members from another array
    {
        n = m;
        data = new float[n];
        for (int j=0; j<m; j++)
        data[j]=a[j];
    }
    int capacity()//Returns the current capacity of this vector
    {
            return n;
    }
    void clear()// Removes all of the elements from this Vector
    {
        delete [] data;
        n=0;
    }
    bool contains(float elem)//Tests if the specified object is a component in this
    {
        for (int j=0; j<n; j++)
        {
            if (data[j]==elem)
            return true;
        }
        return false;
    }
    int indexOf(float elem)//Searches for the first occurrence of the given argument
    {
        for (int j=0; j<n; j++)
        {
            if (data[j]==elem)
            return j;
        }
        return -1;
    }
    int lastIndexOf(float elem) //Returns the index of the last occurrence of the specified
    {
        for (int j=n-1; j>=0; j--)
        {
            if (data[j]==elem)
            return j;
        }
        return -1;
    }
    float elementAt(int index) //check element at specified index
    {
        return data[index];
    }
    bool isEmpty() // Tests if this vector has no components.
    {
        if (n==0)
        return true;
        else
        return false;
    }
    float* toArray() //Returns an array containing all of the elements in this Vector in the correct order
    {
        return data;
    }
    void display() // Show values of vector
    {
        for (int i=0; i<n; i++)
        cout << data[i]<<" ";
    }

};
class Matrix
{
private:
    int n, m;//Row and Column of a matrix
    float data[100][100];//Data of matrix
public:
    Matrix();//Construcror allows user to enter values for a matrix from
    {
        cout<<"Enter the values for a matrix.\n";
        cout<<"Number of Rows: ";
        cin>>n;
        cout<<"Number of Columns: ";
        cin>>m;
        for (int i=0;i<n;i++)
        {
            for(int j=0; j<m; j++)
            {
                cout <<"data["<<i<<"]["<<j<<"]= ";
                cin >> data[i][j];
            }
        }
    }
    Matrix(int M, int N)
    {
        n=M;
        m=N;
        for (int i=0;i<n;i++)
        {
            for(int j=0; j<m; j++)
            {
                data[i][j]=0;
            }
        }
    }
    Matrix(float a*[100], int M, int N)
    {
        n=M;
        m=N;
        for (int i=0;i<n;i++)
        {
            for(int j=0; j<m; j++)
            {
                this ->data[i][j]=data[i][j];
            }
        }
    }
    void swap(int i, int j)
    {
        float tmp;
        for (int k=0; k<m;k++)
        {
            tmp = data[i][k];
            data[i][k] = data[j][k];
            data[j][k] = tmp;
        }
    }
    Matrix transpose()
    {
        Matrix trans(m,n);
        for (int i=0;i<n;i++)
        {
            for(int j=0; j<m; j++)
            {
                trans.data[j][i] = data[i][j];
            }
        }
        return trans;
    }
    Matrix add(Matrix B)
    {
        Matrix C(n,m);
        if ((B.n==n)&&(B.m==m))
        {
            for (int i=0;i<n;i++)
            {
                for(int j=0; j<m; j++)
                C.data[i][j] = B.data[i][j] + data[i][j];
            }
        }
        else cout<<"\nIt's invalid, cannot add !";
        return C;
    }
    Matrix sub(Matrix B)
    {
        Matrix C(n,m);
        if ((B.n==n)&&(B.m==m))
        {
            for (int i=0;i<n;i++)
            {
                for(int j=0; j<m; j++)
                C.data[i][j] = data[i][j]-B.data[i][j];
            }
        }
        else cout<<"\nIt's invalid, cannot subtract !";
        return C;
    }
    bool Matrix::equal(Matrix B)
    {
        if ((B.n==n)&&(B.m==m))
        {
            for (int i=0;i<n;i++)
            {
                for(int j=0; j<m; j++)
                {
                    if (B.data[i][j] != data[i][j])
                    return false;
                    else continue;
                }
            }
            return true;
        }
        else return false;
    }
    Matrix prod(Matrix B)
    {
        Matrix C(n,B.m);
        if (m==B.n)
        {
            for (int i=0; i<n; i++)
            {
                for (int j=0; j<B.m; j++)
                {
                    C.data[i][j]=0;
                    for (int k=0; k<m; k++)
                    {
                        C.data[i][j]+= (data[i][k]*B.data[k][j]);
                    }
                }
            }
        }
        else cout<<"\nIt's invalid, cannot multiply !";
        return C;
    }
    void Matrix::display()
    {
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<m; j++)
            cout <<data[i][j] << " ";
            cout<<"\n";
        }
    }
    inline void swap(float &a, float &b)
    {
        int temp;
        temp = a;
        a = b;
        b= temp;
    }
    void swap(Vector &A, Vector &B)
    {
        if (A.n==B.n)
        {
            for (int i=0; i< A.n; i++)
            swap(A.data[i], B.data[i]);
        }
        else cout << "\nThe two vectors are not equal in size! cannot swap "<<endl;
    }
    void swap(Matrix &A, Matrix &B)
    {
        if (B.m == A.m && B.n == A.n)
        {
            for (int i =0; i<A.n; i++)
            for (int j=0; j<A.m; j++)
            swap (A.data[i][j], B.data[i][j]);
        }
        else cout <<"The two matrix is not equal in size, cannot swap!"<<endl;
    }
    Vector &prod(Matrix &A, Vector &B)
    {
        float * product = new float [B.n];
        for (int i=0; i<B.n; i++)
        product[i]=0;
        for (int i=0; i<A.m; i++)
            for (int j=0; j<B.n; j++)
            product[i] = product[i] + B.data[j]*A.data[j][i];
        Vector b(product, B.n);
        return b;
    }
    Vector &prod(Matrix &A)
    {
        float* product = new float[n];
        for (int i=0; i<A.m; i++)
            for (int j=0; j<n; j++)
            product[i] = product[i] + data[j]*A.data[j][i];
        Vector a(product, n);
        return a;
    }
};
main()
{
    float a, b;
    cout << "Enter two numbers.\n";
    cout << "Number a : "; cin>>a;
    cout << "Number b : "; cin >>b;
    cout << "\n";
    swap (a, b);
    cout << "Swap a and b.\n";
    cout << "Number a : "<<a<<"\n";
    cout << "Number b : "<<b<<"\n";
    cout << "\n";
    cout <<"Enter two vectors:\n";
    Vector A;
    cout << "Vector A is: ";
    A.display();
    cout<<"\nVector B:\n";
    Vector B;
    cout <<"Vector B is: ";
    B.display();
    cout << "\n";
    swap(A, B);
    cout <<"\nSwap vector A and vector B:\n";
    cout<<"Vector A: ";
    A.display();
    cout <<"\nVector B: ";
    B.display();
    cout <<"\nEnter two matrix.\n";
    Matrix A1;
    cout << "Matrix A: \n";
    A1.display();
    cout << "\n";
    Matrix B1;
    cout << "Matrix B: \n";
    B1.display();
    cout << "\n";
    swap (A1, B1);
    cout <<"Swap matrix A and matrix B.  \n";
    cout << "Matrix A:\n";
    A1.display();
    cout << "Matrix B:\n";
    B1.display();
    cout<<"Product of Matrix B and vector A :\n";
    Vector C = prod(B1,A);
    C.display();
    cout <<"\nProduct of Matrix B and vector A using another function:\n";
    Vector D = A.prod(B1);
    cout <<"\n";
    D.display();
    getch();
}

