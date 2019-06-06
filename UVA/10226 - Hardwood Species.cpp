#include <iostream>
#include <iomanip>
#include <map>
using namespace std;
int main() {
	int t;
	cin>>t;
	getchar();
    getchar();
	while(t--) {
		map<string, int> trees;
		string tree;
		int n = 0;
		while(getline(cin, tree)) {
			if(tree.compare("") == 0)
                {
                    break;
                }
			trees[tree]++;
			n++;
		}
		for(auto i: trees)
        {
            cout << i.first << " " << fixed << setprecision(4) << (i.second*100.0)/n << endl;

        }
        if(t>0)cout<<"\n";
	}
    return 0;
}
