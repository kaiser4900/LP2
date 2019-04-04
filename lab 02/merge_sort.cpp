#include<algorithm>
#include<ctime>
#include<stdlib.h>
#include<cstring>
#include<math.h>
#include<iostream>

using namespace std;

int *TA;
int *TB;
int *a;
int N=pow(10,5);


typedef void(*fun_sort)(int*,int,int);


bool test_sort(fun_sort sort, const int *A, int i, int n)
{
    memcpy(TA,A,sizeof(int)*n);
    memcpy(TB,A,sizeof(int)*n);

    clock_t t=clock();
    sort(TA,i,n);
    float time = float(clock()-t)/CLOCKS_PER_SEC;
    std::sort(TB,TB+n);

    for(int i=0; i<n; i++)
    {
        if(TA[i+1]!=TB[i])
        {
            cout<<"TA"<<endl;
            for(int j=0; j<n;j++)
            {
                cout<<TA[j]<<" ";
            }
            cout<<endl;
            cout<<"TB"<<endl;
            for(int j=0; j<n;j++)
            {
                cout<<TB[j]<<" ";
            }
            cout<<endl;

            return false;
        }
    }
    cout<<time<<" ";
    return true;
}


void merge_(int *A,int i,int m,int j)
{
    int b=i;int d=m+1; int c=0;
    while(b<=m&&d<=j)
    {
        if(A[b]>A[d])
        {
            a[c]=A[d];
            d++;c++;
        }
        else
        {
            a[c]=A[b];
            b++;c++;
        }
    }

    while(b<=m) a[c++]=A[b++];
    while(d<=j) a[c++]=A[d++];

    for(int in=0; in<(j-i)+1;in++)
        A[in+i]=a[in];
}

void merge_sort(int *A,int i,int j)
{
    if(i==j)return;
    int m=(i+j)/2;
    merge_sort(A,i,m);
    merge_sort(A,m+1,j);
    merge_(A,i,m,j);
}
int main()
{
    srand(time(NULL));

    int *A= new int[N];
    TA= new int[N];
    TB= new int[N];
    a= new int[N];

    fun_sort sort[1]={merge_sort};

    for(int n=100;n<=N;n*=10)
    {

        for(int i=0; i<n; i++)
        {
            A[i]=rand()%n;

        }
        cout<<n<<" \n";




        for(int s=0; s<1; s++)
        {
            if(!test_sort(sort[s],A,0,n))
               {
                   cout<<"FAIL\n";
                   return 0;
               }
        cout<<endl;
        }

    }
        delete[]A;
        delete[]TA;
        delete[]TB;
        delete[]a;
}
