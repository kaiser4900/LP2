#include<algorithm>
#include<ctime>
#include<stdlib.h>
#include<cstring>
#include<math.h>
#include<iostream>

using namespace std;

int *TA;
int *TB;

int N=pow(10,5);

typedef void(*fun_sort)(int*,int);


bool test_sort(fun_sort sort, const int *A, int n)
{
    memcpy(TA,A,sizeof(int)*n);
    memcpy(TB,A,sizeof(int)*n);

    clock_t t=clock();
    sort(TA,n);
    float time = float(clock()-t)/CLOCKS_PER_SEC;
    std::sort(TB,TB+n);
    for(int i=0; i<n; i++)
        if(TA[i]!=TB[i]) return false;
    cout<<time<<" ";
    return true;
}
void insert_ (int *A,int n)
{
    for(int i=1; i<n; i++)
    {
    int temp = A[i];
    int min_ = 0;
    int n = i-1;

    while(min_ <= n){
    int m = (min_+n)/2;
        if (temp < A[m])
            n = m - 1;
        else
            min_ = m + 1;
    }

    for (int j=i-1; j>=min_; j--){
        A[j+1]=A[j];
    }

    A[min_] = temp;
    }
}
bool lineal(int *a, int n,int b)
{
    for(int i=0;i<n;i++)
    {
        if(a[i]==b)
        {
            return true;
        }
    }
    return false;
}

bool binary(int *a, int n, int b)
{
    int i=0, j=n;

    while(i<j)
    {
        int m =(i+j)/2;

        if(a[m]==b)
            return true;

        if(a[m]>b)
            j=m;

        else
            i=m;
    }

    return false;
}
bool bin_r(int *a,int n,int x,int min_=0)
{
    n--;
    if(min_>n)
        return false;
    int m=(min_+n)/2;

    if(a[m]==x)
        return true;
    if(a[m]>x)
    {
        n=m;
        bin_r(a,n,x,min_);
    }
    else
    {
        min_=m;
        bin_r(a,n,x,min_);
    }
}

void bubble_sort(int *A, int n)
{
   n--;

    bool stop=false;

    while(!stop)
    {
        stop=true;
        for(int j=0; j<n;++j)
        {
            if(A[j]>A[j+1])
            {
                swap(A[j],A[j+1]);
                stop=false;
            }
         }
    }

}
void selection (int *A, int n)
{
    n--;

    for(int i=0; i<n; i++)
    {
        int menor=i;
        for(int j=i+1; j<=n; j++)
        {
            if(A[j]<A[menor])
                menor=j;
        }
        swap(A[i],A[menor]);
    }
}
int main()
{
    srand(time(NULL));

    int *A= new int[N];
    TA= new int[N];
    TB= new int[N];

    fun_sort sort[3]={insert_,selection,bubble_sort};

    for(int n=100;n<=N;n*=10)
    {
        for(int i=0; i<n; i++)
        {
            A[i]=rand()%n;

        }
        cout<<n<<" \n";

        for(int s=0; s<3; s++)
        {
            if(!test_sort(sort[s],A,n))
               {
                   cout<<"FAIL\n";
                   return 0;
               }
        cout<<endl;
        }
        delete[]TA;
        delete[]TB;
    }
}
