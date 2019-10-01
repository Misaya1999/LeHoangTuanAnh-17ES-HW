#include <iostream>
#include <conio.h>

using namespace std;

class Matrix
{
private:
    int n,m;
    float**data;
public:
    Matrix()//Construcror allows user to enter values for a matrix from keyboard
    {
        int i,j;
        cout<<"enter the capacity of row n=";
        cin>>n;
        cout<<"enter the capacity of column m=";
        cin>>m;
        data = new float*[n];//create rows
        for (i=0;i<n;i++)
        {
            data[i]=new float[m];//create columns
        }
        for (i=0;i<n;i++)
        {
            for (j=0;j<m;j++)
            {
                cout<<"\ndata["<<i<<"]["<<j<<"]=";//input matrix
                cin>>data[i][j];
            }
        }
    }
    ~Matrix(){}
    Matrix(int N, int M)//create M-by-N matrix of 0's
    {
        n=N;
        m=M;
        data=new float*[n];
        for (int i=0;i<n;i++)
        {
            data[i]=new float[m];
        }
    }
    Matrix(float**a)//Create matrix based on 2d array
    {
        data=new float*[n];
        for(int i=0;i<n;i++)
        {
            data[i]=new float[m];
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                a[i][j]=data[i][j];
            }
        }
    }
    void swap(int i, int j)//swap rows i and j
    {
        float*temp=data[i];
        data[i]=data[j];
        data[j]=temp;
    }
    Matrix transpose()//Create and return the transpose of the invoking matrix
    {
        Matrix A(n,m);
        cout<<"Transposition of the matrix A:"<<endl;
        for(int i=0;i<A.n;i++)
        {
            for (int j=0;j<A.m;j++)
            {
                A.data[j][i]=data[i][j];
            }
        }
        return A;
    }
    Matrix add(Matrix B)//return C = A + B
    {
        Matrix A=*this;
        if(A.n==B.n&&A.m==B.m)
        {
            Matrix C(n,m);
            for(int i=0;i<C.n;i++)
            {
                for(int j=0;j<C.m;j++)
                {
                    C.data[i][j]=A.data[i][j]+B.data[i][j];
                }
            }
            return C;
        }
        else
        {
            cout<<"Error!!!";
        }
    }
    Matrix sub(Matrix B)//return C = A – B
    {
        Matrix A=*this;
        Matrix D(n,m);
        if(A.n==B.n&&A.m==B.m)
        {
            for (int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    D.data[i][j]=A.data[i][j]-B.data[i][j];
                }
            }
            return D;
        }
        else
        {
            cout<<"Error!!!";
        }
    }
    bool equal(Matrix B)//check if A = B exactly?
    {
        Matrix A=*this;
        if(A.n==B.n&&A.m==B.m)
        {
            for (int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    if(data[i][j]==B.data[i][j])
                    return cout<<"Matrix A = Matrix B";
                    else
                    return cout<<"Matrix A != Matrix B";
                }
            }
        }
        else
        {
            cout<<"Error!!!";
        }
    }
    Matrix prod(Matrix B)//return C = A * B
    {
        Matrix A=*this;
        if (A.m==B.n)
        {
            Matrix E(n,B.m);
            E.n=A.n;E.m=B.m;
            for (int i=0;i<E.n;i++)
            {
                for (int j=0;j<E.m;j++)
                {
                    for(int k=0;k<A.m;k++)
                    {
                        E.data[i][j]=(data[i][k]*B.data[k][j]);
                    }
                }
            }
            return E;
        }
        else
        {
            cout<<"Error!!!"<<endl;
        }
    }
    Matrix display()//print matrix
    {
        cout<<"\nMatrix:\n";
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cout<<"\ndata["<<i<<"]["<<j<<"]="<<data[i][j]<<endl;
            }
        }
    }
    int main()
    {
        cout<<"Setup Matrix:"<<endl;
        cout<<"Matrix A\n";
        Matrix A;
        cout<<"\n*************************************************\n";

        cout<<"\nMatrix B\n";
        Matrix B;
        cout<<"\n*************************************************\n";

        A.transpose().display();
        cout<<"\n*************************************************\n";

        cout<<"\nSwap rows 0 and 1 of matrix A\n";
        A.swap(0,1);
        A.display();
        cout<<"\n*************************************************\n";

        cout<<"\nC = A + B: \n";
        A.add(B).display();
        cout<<"\n*************************************************\n";

        cout<<"\nD = A - B: \n";
        A.sub(B).display();
        cout<<"\n*************************************************\n";

        cout<<"\nE = A * B: \n";
        A.prod(B).display();
        cout<<"\n*************************************************\n";

        A.equal(B);
    }
    getch();
};
