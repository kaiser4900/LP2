#ifndef MY_MATRIX_H
#define MY_MATRIX_H

#include<iostream>
#include<vector>

using namespace std;

template<class T>
class my_matrix
{
	private:

		T *ptr;
		size_t n_cols, n_rows;

	public:

		my_matrix ( size_t n_cols = 0, size_t n_rows = 0 );
		my_matrix ( const my_matrix<T> & ptr_ );
		~my_matrix()
		{
		     delete [] ptr;
        }
        T & operator() ( size_t i, size_t j );
		my_matrix<T> & operator = ( const my_matrix<T> & a );
		bool operator == ( const my_matrix<T> & a );
		my_matrix operator + ( const my_matrix & a );
		my_matrix operator - ( const my_matrix & a );
		my_matrix operator * ( const my_matrix & a );
		friend ostream & operator << ( ostream & os , const my_matrix<T> s )
		{
            T *p = s.ptr;
            os << "\n";
            for(int i = 0; i< s.n_rows; ++i)
            {
                os << " ";
                for(int j = 0; j < s.n_cols; j++)
                {
                    os << *(p + i * s.n_cols + j) << " ";
                }
                os <<"\n";
            }
            return os;
        }
    	friend istream & operator >> ( istream & is , my_matrix<T> & s )
    	{
    	    for(int i = 0; i < s.n_cols * s.n_rows; i++)
            {
                is >> s.ptr[i];
            }

    	}
};
#include "my_matrix.inl"
#endif
