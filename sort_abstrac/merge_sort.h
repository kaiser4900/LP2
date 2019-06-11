#ifndef MERGE_SORT
#define MERGE_SORT
int *a;
template<class T>
class merge_s: public sort_<T>
{
private:
    T *A;
    int n;
public:

    ~merge_s();
    void merge_(int *A,int i,int m,int j);
    void merge_sort(int *A,int i,int j);
    void fsort(T *A, int n);

};
#include "merge_sort.inl"
#endif // MERGE_SORT
