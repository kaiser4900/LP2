template<class T>
void merge_s<T> :: fsort(T *A, int n)
{
    merge_sort(A,0,n-1);
}
template<class T>
void merge_s<T>:: merge_sort(int *A,int i,int j)
{
    if(i==j)return;
    int m=(i+j)/2;
    merge_sort(A,i,m);
    merge_sort(A,m+1,j);
    merge_(A,i,m,j);
}
template<class T>
void merge_s<T> :: merge_(int *A,int i,int m,int j)
{
    int b=i;int d=m+1; int c=0;
    while(b<=m&&d<=j)
    {
        if(A[b]>=A[d])
        {
            a[c]=A[d];
            d++;
            c++;
        }
        else
        {
            a[c]=A[b];
            b++;
            c++;
        }
    }

    while(b<=m) a[c++]=A[b++];
    while(d<=j) a[c++]=A[d++];

    for(int in=0; in<(j-i)+1;in++)
        A[in+i]=a[in];
}
template<class T>
merge_s<T> :: ~merge_s()
{
    delete [] A;
    delete[]a;
}
