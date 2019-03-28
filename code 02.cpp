#include<iostream>

using namespace std;

void insert_ (int *a,int n)
{
    for(int i=1; i<n; i++)
    {
    int temp = a[i];
    int min_ = 0;
    int n = i-1;

    while(min_ <= n){
    int m = (min_+n)/2;
        if (temp < a[m])
            n = m - 1;
        else
            min_ = m + 1;
    }

    for (int j=i-1; j>=min_; j--){
        a[j+1]=a[j];
    }

    a[min_] = temp;
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

void bubble_sort(int *a, int n)
{
    n--;
    int n_=n;
    for(int j=0; j<=n_;++j)
    {
        for(int i=0; i<n; i++)
        {
            if(a[i]>a[i+1])
            {
                swap(a[i],a[i+1]);
            }
        }
    n_--;
    }
}

void selection (int *a, int n)
{
    n--;

    for(int i=0; i<n; i++)
    {
        int menor=i;
        for(int j=i+1; j<=n; j++)
        {
            if(a[j]<a[menor])
                menor=j;
        }
        swap(a[i],a[menor]);
    }
}
int main(){

    int a[5]={5,3,8,1,4};
    int m[5]={1,2,3,4,5};

    cout<<bin_r(m,5,1)<<endl;
    cout<<binary(m,5,1)<<endl;
    cout<<lineal(a,5,1)<<endl;

    bubble_sort(a,5);

    for(int i=0; i<5; i++)
    {
        cout<<a[i];
    }
    int tt[5]={5,3,8,1,4};
    cout<<endl;
    selection(tt,5);
	for(int i=0; i<5; i++)
    {
        cout<<tt[i];
    }
    cout<<endl;
    int sl[5]={8,2,6,7,1};
    for(int i=0; i<5; i++)
    {
        cout<<sl[i];
    }
    cout<<endl;
    insert_(sl,5);
    for(int i=0; i<5; i++)
    {
        cout<<sl[i];
    }
    cout<<endl;
	return 0;
}

