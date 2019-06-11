#ifndef SORT_ABSTRAC
#define SORT_ABSTRAC

template<class T>
class sort_
{
public:
    virtual void fsort(T *A, int n)=0;
    virtual ~sort_() = default;
};

#endif // SORT_ABSTRAC
