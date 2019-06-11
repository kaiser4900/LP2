template <class T>
void insert<T> :: fsort(T *A, int n)
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
template<class T>
insert<T> ::~insert()
{
    delete [] A;
}
