#include <iostream>
#include <vector>
#include<ctime>
#include<math.h>
#include<cstring>
#include<stdlib.h>
#include<algorithm>
#include "Sort_abstrac.h"
#include "selection.h"
#include "merge_sort.h"
#include "insert.h"
#include "bubble_sort.h"
#include "fun_test.h"

using namespace std;

int N=pow(10,8);

int main()
{
    vector<sort_<int>*>VS;
    srand(time(NULL));
    int* A=new int[N];
	TA=new int [N];
	TB=new int [N];
	a= new int[N];
	VS.push_back(new merge_s<int>());
	VS.push_back(new insert<int>());
    VS.push_back(new selection<int>());
    VS.push_back(new bubble_sort<int>());

    for(int n=100;n<=N;n*=10)
    {
        for(int i=0; i<n; i++)
        {
            A[i]=rand()%n;

        }
        cout<<n<<" \n";

        for(int s=0; s<VS.size(); s++)
        {
            if(!test_sort(VS[s],A,n))
               {
                   cout<<"FAIL\n";
                   return 0;
               }
        cout<<endl;
        }

    }

    delete[]TA;
    delete[]TB;

    return 0;
}
