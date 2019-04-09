
#include<iostream>

using namespace std;

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

void peter(int k)
{
     int cant, dife, dife_m,x,y;
     int libros[k];

    for(int i=0; i<k; i++)
    {
        cin>>libros[i];
    }

    cin>>cant;
    int cont=0;

    insert_(libros,k);

    for(int i=0; i<k; i++)
    {
        for(int j=i+1; j<k; j++)
        {
            if((libros[i]+libros[j])==cant)
            {
                dife=abs(libros[i]-libros[j]);

               if(cont==0)
               {
                  dife==dife_m;x=i;y=j;
               }


               else if(dife<dife_m)
               {
                    dife==dife_m;x=i;y=j;cont++;
               }
            }

        }
    }
    cout<<"Peter should buy books whose prices are "<<libros[x]<<" and "<<libros[y]<<"."<<endl;

}

int main()
{
    int k;
    cin>>k;
    bool stop=false;

    while(!stop)
    {
        if(k>2&&k<=10000)
        {
            peter(k);
            cin>>k;
        }
        else
            stop=true;
    }
    return 0;
}
