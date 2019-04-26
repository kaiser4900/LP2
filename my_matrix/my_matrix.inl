template<class T>
my_matrix<T> :: my_matrix ( size_t n_cols_, size_t n_rows_ )
{
    n_cols = n_cols_;
    n_rows = n_rows_;
    ptr = new T*[ n_rows ];
    for(int i =0; i < n_rows; i++)
    {
         ptr[i] = new T[ n_cols ];
    }
}
template<class T>
my_matrix<T> :: my_matrix( const my_matrix<T> & m )
{
    ptr = new T*[ m.n_cols * m.n_rows ];
    n_cols = m.n_cols;
    n_rows = m.n_rows;

    for(int i=0; i< n_cols * n_rows; i++)
    {
        ptr[i] = m.ptr[i];
    }
}
template<class T>
T & my_matrix<T> :: operator () (size_t i, size_t j)
{
    return ptr[i][j];
}
template<class T>
my_matrix<T> my_matrix<T> :: operator + ( const my_matrix<T> & m )
{
    if( n_cols != m.n_cols || n_rows != m.n_rows ) return 1;

    T aux;
    my_matrix<T> result( n_cols , n_rows );
    for(int i = 0; i < n_cols * n_rows; i++)
    {
        aux = *( m.ptr + i );
        *( result.ptr + i )= *( ptr + i ) + aux;
    }
    return result;
}
template<class T>
my_matrix<T> my_matrix<T> :: operator - (const my_matrix<T> & m)
{
    if(n_cols != m.n_cols || n_rows != m.n_rows) return 1;

    T aux;
    my_matrix<T> result( n_cols , n_rows );
    for(int i = 0; i < n_cols * n_rows; i++)
    {
        aux = *( m.ptr + i );
        *( result.ptr + i ) = *( ptr + i ) - aux;
    }
    return result;
}
template<class T>
my_matrix<T> my_matrix<T> :: operator * (const my_matrix<T> & m)
{
    if(n_cols != m.n_rows) return 1;

    my_matrix<T> result(n_rows, m.n_cols);
    size_t index_a = 0;
    size_t index_b = 0;
    size_t index_result = 0;
    for(int i = 0; i < result.n_rows; i++)
    {
        for(int j = 0; j < result.n_cols; j++)
        {
            index_result = i * result.cols + j;
            *( result.ptr + index_result ) = 0;
            for(int k = 0; k < result.n_cols; k++)
            {
                index_a = i*n_cols + k;
                index_b = k*m.n_cols + j;
                *( result.ptr + index_result) = *( result.ptr + index_result) + *(ptr + index_a) * (*(m.ptr + index_b));
            }
        }
    }
    return result;
}/*
template<class T>
ostream & operator << ( ostream & os , const my_matrix<T> & s )
{
    T *p = s.ptr;
    os << "\n";
    for(int i = 0; i< s.rows; ++i)
    {
        os << " ";
        for(int j = 0; j < s.cols; j++)
        {
            os << *(p + i * s.cols + j) << " ";
        }
        os <<"\n";
    }
    os <<"\n";
    return os;
}
*/
