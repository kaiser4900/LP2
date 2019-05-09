#ifndef MY_VECTOR_H
#define MY_VECTOR_H

#include<iostream>

using namespace std;

template<class T>
class my_vector
{
	private:

		T *ptr;
		size_t size_;

	public:

		my_vector ( size_t _size_ = 0 );
		my_vector ( const my_vector<T> & ptr_ );
		~my_vector()
		{
		     delete [] ptr;
        }
        T & operator() ( size_t index);
		bool operator == ( const my_vector<T> & a );
		my_vector operator + ( const my_vector & a );
		my_vector operator - ( const my_vector & a );
		my_vector operator * ( const my_vector & a );
		my_vector operator = ( const my_vector & a );
		void push_back( T a);
		void clear();
		bool empty();
		my_vector swap();
		size_t size()const{return size_;}
		friend ostream & operator << ( ostream & os , const my_vector<T> s )
		{
            T *p = s.ptr;
            os << "\n";
            for(int i = 0; i < s.size_; ++i)
            {
                os << s.ptr[i] << " ";
            }
            os<<endl;
            return os;
        }
    	friend istream & operator >> ( istream & is , my_vector<T> & s )
    	{
    	    for(int i = 0; i < s.size_; i++)
            {
                is >> s.ptr[i];
            }

    	}
};
#include "my_vector.inl"
#endif
