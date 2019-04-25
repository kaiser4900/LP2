#include "my_matrix.h"

#include<iostream>
using namespace std;
int main()
{
    my_matrix<int> s1(1,2);
    my_matrix<int> s2(s1);
    cout<<"hi\n";
    return 0;
}
