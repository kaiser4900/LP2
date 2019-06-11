#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef unsigned long long my_int;
typedef vector <my_int> cds;
int main () {
  my_int m,n,id;
  cds a,b,v(1000000);
  vector<my_int>::iterator it;
  cin >> m >> n;
  while(m != 0 && n!=0){
      for(int i = 0; i<m;i++)
        {
            cin >> id;
            a.push_back(id);
        }
      for(int i = 0; i<n;i++)
        {
            cin >> id;
            b.push_back(id);
        }
      it=set_intersection(a.begin(), a.end(), b.begin(), b.end(), v.begin());
      cout << it - v.begin() << endl;
      cin >> m >> n;
      a.clear();
      b.clear();
      v.clear();
  }

  return 0;
}

