#include<cassert>
template<class T>
my_matrix<T> :: my_matrix ( size_t n_cols_, size_t n_rows_ )
{
    n_cols = n_cols_;
    n_rows = n_rows_;
    ptr = new T[n_cols * n_rows];
    for(int i = 0; i < n_cols * n_rows; i++)
    {
        ptr[i] = 0;
    }
}
template<class T>
my_matrix<T> :: my_matrix( const my_matrix<T> & m )
{
    n_cols = m.n_cols;
    n_rows = m.n_rows;
    ptr = new T[n_cols * n_rows];
    for(int i=0; i< m.n_cols * m.n_rows; i++)
    {
        ptr[i] = m.ptr[i];
    }
}
template<class T>
T & my_matrix<T> :: operator () (size_t p_cols, size_t p_rows)
{
    assert(p_cols <= n_cols);
    assert(p_rows <= n_rows);
    return ptr[p_rows*n_cols+p_cols];
}
template<class T>
my_matrix<T> my_matrix<T> :: operator + ( const my_matrix<T> & m )
{
    //if( n_cols != m.n_cols || n_rows != m.n_rows ) return 1;
    assert(n_cols == m.n_cols);
    assert(n_rows == m.n_rows);
    my_matrix<T> result( n_cols , n_rows );
    for(int i = 0; i < n_cols * n_rows; i++)
    {
        result.ptr[i] = m.ptr[i]+ptr[i];
    }
    return result;
}
template<class T>
my_matrix<T> my_matrix<T> :: operator - (const my_matrix<T> & m)
{
    //if(n_cols != m.n_cols || n_rows != m.n_rows) return 1;
    assert(n_cols == m.n_cols);
    assert(n_rows == m.n_rows);
    my_matrix<T> result( n_cols , n_rows );
    for(int i = 0; i < n_cols * n_rows; i++)
    {
        result.ptr[i] = m.ptr[i]-ptr[i];
    }
    return result;
}
template<class T>
my_matrix<T> my_matrix<T> :: operator * (const my_matrix<T> & m)
{
    //if(n_cols != m.n_rows) return 1;
    assert(n_cols == m.n_rows);
    my_matrix<T> result(n_rows, m.n_cols);
    T aux = 0;
    for(int i = 0; i < n_rows; i++)
    {
        for(int j = 0; j < n_cols; j++)
        {
            for(int k = 0; k < n_cols; k++)
            {
                aux += ptr[k*n_rows+i] * m.ptr[j*n_rows+k];
            }
            result.ptr[i*n_rows+j]=aux;
            aux = 0;
        }
    }

    return result;
}

