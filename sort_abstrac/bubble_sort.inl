template <class T>
void bubble_sort<T> :: fsort(T *A, int n)
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
template<class T>
bubble_sort<T> :: ~bubble_sort()
{
    delete [] A;
}
