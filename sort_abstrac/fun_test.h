#ifndef FUN_TEST
#define FUN_TEST
int *TA;
int *TB;
bool test_sort( sort_<int> * s, const int *A, int n)
{
    memcpy(TA,A,sizeof(int)*n);
    memcpy(TB,A,sizeof(int)*n);

    clock_t t=clock();
    s->fsort(TA,n);
    float time = float(clock()-t)/CLOCKS_PER_SEC;
    std::sort(TB,TB+n);
    for(int i=0; i<n; i++)
        if(TA[i]!=TB[i]) return false;
    cout<<time<<" ";
    return true;
}
#endif
