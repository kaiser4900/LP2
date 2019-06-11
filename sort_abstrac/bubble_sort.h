#ifndef BUBBLE_SORT
#define BUBBLE_SORT

using namespace std;
template<class T>
class bubble_sort : public sort_<T>
{
private:
    T *A;
    int n;
public:
    ~bubble_sort();
    void fsort(T *A, int n);
};
#include "bubble_sort.inl"
#endif // BUBBLE_SORT
