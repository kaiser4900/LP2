#ifndef MY_MATRIX_H
#define MY_MATRIX_H

#include<iostream>
#include<vector>

using namespace std;

template<class T>

class my_matrix
{
	private:

		T **ptr;
		size_t n_cols, n_rows;

	public:

		my_matrix ( size_t n_cols_ = 0, size_t n_rows_ = 0);
		my_matrix ( const my_matrix<T> & ptr_);
		~my_matrix()
		{
		    for(int i = 0; i < n_rows; i++)
		     delete [] ptr;
        }
        T & operator() (size_t i, size_t j);
		my_matrix<T> & operator = ( const my_matrix<T> & a );
		bool operator == ( const my_matrix<T> & a );
		my_matrix operator + ( const my_matrix & a );
		my_matrix operator - ( const my_matrix & a );
		my_matrix operator * ( const my_matrix & a );
		friend ostream & operator << ( ostream & os , const my_matrix<T> s );
    	friend istream & operator >> ( istream & is , my_matrix<T> & a );



};
#include "my_matrix.inl"
#endif
