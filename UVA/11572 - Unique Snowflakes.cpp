#include <iostream>
#include <set>
#include <assert.h>

using namespace std;
int main() {

    int t,n,j,r;
    cin>>t;
    while(t--)
    {
        n=0;
        r=0;
        cin>>n;
        assert(n<109);
        set<int,greater<int> >snowflakes;
        for(int i =0; i< n; i++)
        {
            cin>>j;
            snowflakes.insert(j);
        }
        for(auto i:snowflakes)
        {
            r++;
        }
        cout<<endl<<r<<endl;

    }

    return 0;
}
