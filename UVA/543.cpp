#include<iostream>
using namespace std;

size_t *P;
int main()
{
    size_t n;
    cin>>n;
    size_t*P = new size_t[n];
    bool B[n];
    for(size_t i = 0; i < n; i++)
    {
        B[i]=0;
    }
    size_t q=0;
    for(size_t i = 3; i < n; i+=2)
    {
        if(!B[i])
        {
            P[q++]=i;
            for(size_t j = i*i; j < n; j+=2*i)
            {
                B[j]=1;
            }
         }
    }
    size_t size_=0;
    for(size_t i = 0; P[i] !=0; i++)
    {
        size_++;
    }
    for(size_t i=0; i<size_;i++)
    {
        for(size_t j =size_-1; j > 0; j--)
        {
            if((P[i]+P[j])==n)
            {
                cout<<n<<" = "<<P[i]<<" + "<<P[j];
                i=size_;
            }
        }
    }
    return 0;
    delete []P;
}
