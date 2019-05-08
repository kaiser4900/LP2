#include<algorithm>
#include<ctime>
#include<stdlib.h>
#include<cstring>
#include<math.h>
#include<iostream>

using namespace std;


bool lineal(int *A, int n,int b)
{
    for(int i=0;i<n;i++)
    {
        if(A[i]==b)
        {
            return true;
        }
    }
    return false;
}

bool binary(int *A, int n, int b)
{
    int i=0, j=n;

    while(i<j)
    {
        int m =(i+j)/2;

        if(A[m]==b)
            return true;

        if(A[m]>b)
            j=m;

        else
            i=m;
    }

    return false;
}
bool bin_r(int *A,int n,int x,int min_=0)
{
    n--;
    if(min_>n)
        return false;
    int m=(min_+n)/2;

    if(A[m]==x)
        return true;
    if(A[m]>x)
    {
        n=m;
        bin_r(A,n,x,min_);
    }
    else
    {
        min_=m;
        bin_r(A,n,x,min_);
    }
}
int main()
{
    return 0;
}
