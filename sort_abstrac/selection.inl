template <class T>
void selection<T> :: fsort(T *A, int n)
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
template<class T>
selection<T> ::~selection()
{
    delete [] A;
}
