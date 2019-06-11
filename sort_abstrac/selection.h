#ifndef SELECTION
#define SELECTION

using namespace std;
template<class T>
class selection : public sort_<T>
{
private:
    T *A;
    int n;
public:
    ~selection();
    void fsort(T *A, int n);

};
#include "selection.inl"
#endif // SELECTION
