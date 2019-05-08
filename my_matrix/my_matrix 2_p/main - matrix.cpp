#include "my_matrix.h"

#include<iostream>
using namespace std;
int main()
{
    my_matrix<int> s1(3,3);
    my_matrix<int> s4(3,3);
    cout<<"hi\n";
    cin>>s1;
    cin>>s4;
    my_matrix<int> s2(s1);
    cout<<s1<<endl;
    cout<<endl<<s1(1,1)<<endl;
    cout<<s2<<endl;
    my_matrix<int> s3(s1+s2);
    cout<<s3;
    my_matrix<int> s5(s1-s2);
    cout<<s5;
    my_matrix<int> s6(s1*s4);
    cout<<"\n s6 "<<s6<<endl;
    return 0;
}
