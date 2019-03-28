#include<iostream>

using namespace std;

//completsr busqueda binaria recursiva y insertion antes de subir

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

    cout<<lineal(m,5,1)<<endl;

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
	return 0;
}

