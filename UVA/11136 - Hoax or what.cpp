#include <iostream>
#include <set>
using namespace std;

int main()
{
    int n;
    long long total_cost=0;
    multiset<int>bill_amounts;
    int n_bills;
    int bill_amount;
    multiset<int>::iterator it_end;
    multiset<int>::iterator it_begin;
    while(cin>>n && n!=0){
        for(int i=n; n>0; n--){
            cin>>n_bills;
            for(int j=n_bills; j>0; j--){
                cin>>bill_amount;
                bill_amounts.insert(bill_amount);
            }
            it_end=bill_amounts.end();
            it_end--;
            it_begin=bill_amounts.begin();
            total_cost=total_cost+((*it_end)-(*it_begin));
            bill_amounts.erase(it_end);
            bill_amounts.erase(it_begin);
        }
        cout<<total_cost<<endl;
        total_cost=0;
        bill_amounts.clear();
    }
    return 0;
}
