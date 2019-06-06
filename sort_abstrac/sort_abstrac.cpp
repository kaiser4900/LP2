#include <iostream>
#include <vector>
#include<ctime>
#include<math.h>
#include<cstring>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int *TA;
int *TB;
int N=pow(10,5);

template<class T>
class sort_
{
public:
    virtual void fsort(T *A, int n)=0;
    virtual ~sort_() = default;
};


template<class T>
class insert : public sort_<T>
{
private:
    T *A;
    int n;
public:
   /* insert(T* a,int n_)
    {
        A=a;
        n=n_;
    }*/
    ~insert()
    {
        delete [] A;
    }
    void fsort(T *A, int n)
    {
        for(int i=1; i<n; i++)
        {
            int temp = A[i];
            int min_ = 0;
            int n = i-1;

            while(min_ <= n)
            {
            int m = (min_+n)/2;
                if (temp < A[m])
                    n = m - 1;
                else
                    min_ = m + 1;
            }

            for (int j=i-1; j>=min_; j--)
            {
                A[j+1]=A[j];
            }

            A[min_] = temp;
        }
    }

};
template<class T>
class bubble_sort : public sort_<T>
{
private:
    T *A;
    int n;
public:
    /*bubble_sort(T* a,int n_)
    {
        A=a;
        n=n_;
    }*/
    ~bubble_sort()
    {
        delete [] A;
    }
    void fsort(T *A, int n)
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
};
template<class T>
class selection : public sort_<T>
{
private:
    T *A;
    int n;
public:
    /*selection(T* a,int n_)
    {
        A=a;
        n=n_;
    }*/
    ~selection()
    {
        delete [] A;
    }
    void fsort(T *A, int n)
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
};
bool test_sort( sort_<int> * s, const int *A, int n)
{
    memcpy(TA,A,sizeof(int)*n);
    memcpy(TB,A,sizeof(int)*n);

    clock_t t=clock();
    s->fsort(TA,n);
    float time = float(clock()-t)/CLOCKS_PER_SEC;
    std::sort(TB,TB+n);
    for(int i=0; i<n; i++)
        if(TA[i]!=TB[i]) return false;
    cout<<time<<" ";
    return true;
}

int main()
{
    vector<sort_<int>*>VS;
    int* A=new int[N];

    VS.push_back(new selection<int>());
    VS.push_back(new bubble_sort<int>());
    VS.push_back(new insert<int>());

    for(int n=100;n<=N;n*=10)
    {
        for(int i=0; i<n; i++)
        {
            A[i]=rand()%n;

        }
        cout<<n<<" \n";

        for(int s=0; s<3; s++)
        {
            if(!test_sort(VS[s],A,n))
               {
                   cout<<"FAIL\n";
                   return 0;
               }
        cout<<endl;
        }

    }

    delete[]TA;
    delete[]TB;
    return 0;
}
