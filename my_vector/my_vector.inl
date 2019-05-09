#include<cassert>
template<class T>
my_vector<T> :: my_vector ( size_t _size_ )
{
    size_=_size_;
    ptr = new T[size_];
    for(int i = 0; i < size_; i++)
    {
        ptr[i] = '\0';
    }
}
template<class T>
my_vector<T> :: my_vector( const my_vector<T> & m )
{
    size_ = m.size_;
    ptr = new T[size_];
    for(int i=0; i< size_; i++)
    {
        ptr[i] = m.ptr[i];
    }
}
template<class T>
my_vector<T> my_vector<T> :: operator = (const my_vector<T> & m)
{
   my_vector<T> ptr(m);
}
template<class T>
T & my_vector<T> :: operator () (size_t index)
{
    assert(index<size_);
    return ptr[index];
}
/*
template<class T>
my_vector<T> :: T swap( my_vector<T> & a)
{
    my_vector<T> aux(a);
    delete [] a.ptr;
    a.ptr = new T[size_];
    for(int i = 0; ptr[i] < size_ ;i++)
    {
        a.ptr[i]=ptr[i];
    }
    delete [] ptr;
    ptr = new T[aux.size_];
    for(int i = 0; i < aux.size_; i++)
    {
        ptr[i]=aux.ptr[i];
    }
}
*/
template<class T>
void my_vector<T> :: clear()
{
    delete [] ptr;
    size_ = 0;
}
template<class T>
bool my_vector<T> :: empty()
{
    return (size_==0);
}
template<class T>
void my_vector<T> :: push_back( T a)
{
    ptr[size_]=a;
    size_++;
}
/*
template<class T>
my_vector<T> my_vector<T> :: operator + ( const my_vector<T> & m )
{
    //if( n_cols != m.n_cols || n_rows != m.n_rows ) return 1;
    assert(n_cols == m.n_cols);
    assert(n_rows == m.n_rows);
    my_vector<T> result( n_cols , n_rows );
    for(int i = 0; i < n_cols * n_rows; i++)
    {
        result.ptr[i] = m.ptr[i]+ptr[i];
    }
    return result;
}
template<class T>
my_vector<T> my_vector<T> :: operator - (const my_vector<T> & m)
{
    //if(n_cols != m.n_cols || n_rows != m.n_rows) return 1;
    assert(n_cols == m.n_cols);
    assert(n_rows == m.n_rows);
    my_vector<T> result( n_cols , n_rows );
    for(int i = 0; i < n_cols * n_rows; i++)
    {
        result.ptr[i] = m.ptr[i]-ptr[i];
    }
    return result;
}
template<class T>
my_vector<T> my_vector<T> :: operator * (const my_vector<T> & m)
{
    //if(n_cols != m.n_rows) return 1;
    assert(n_cols == m.n_rows);
    my_vector<T> result(n_rows, m.n_cols);
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

*/
