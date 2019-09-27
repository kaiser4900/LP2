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
    int i=0;

    while(i<n)
    {
        int m =(i+n)/2;

        if(A[m]==b)
            return true;

        if(A[m]>b)
            n=m-1;

        else
            i=m+1;
    }

    return false;
}
bool bin_r(int *A,int n,int x,int min_=0)
{
    if(min_>n)
        return false;
    int m=(min_+n)/2;
    if(A[m]==x)
        return true;
    if(A[m]>x)
    {
        n=m-1;
        bin_r(A,n,x,min_);
    }
    else
    {
        min_=m+1;
        bin_r(A,n,x,min_);
    }
}
int main()
{
    return 0;
}
