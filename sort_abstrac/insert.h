#ifndef INSERT
#define INSERT
template<class T>
class insert : public sort_<T>
{
private:
    T *A;
    int n;
public:
    ~insert();
    void fsort(T *A, int n);
};
#include "insert.inl"
#endif // INSERT
