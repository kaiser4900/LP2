#include "my_vector.h"
//#include<vector>
#include<iostream>
using namespace std;
int main()
{
    my_vector<int>nums1(2);
    cout<<"hi\n";
    cin>>nums1;
    my_vector<int>nums2(nums1);
    cout<<"nums 1 = "<<nums1;
    cout<<"nums 2 = "<<nums2;
    cout<<"nums 2 (1) = "<<nums2(0)<<endl;
    nums2.push_back(2);
    nums2.push_back(4);
    nums2.push_back(4);
    nums2.push_back(4);
    nums2.push_back(4);
    nums2.push_back(4);
    nums2.push_back(4);
    nums2.push_back(4);
    nums2.push_back(4);
    nums2.push_back(4);
    nums2.push_back(4);
    nums2.push_back(4);
    nums2.push_back(4);
    nums2.push_back(4);
    nums2.push_back(4);
    nums2.push_back(4);
    nums2.push_back(4);
    nums2.push_back(4);
    nums2.push_back(4);
    nums2.push_back(4);
    nums2.push_back(4);
    nums2.push_back(4);
    nums1.push_back(52);
    cout<<"nums 2 = "<<nums2;
    cout<<"nums 2 (5) "<<nums2(23);
    cout<<"\nsize = "<<nums2.size();
    cout<<"\nbool = "<<nums2.empty();
    /*cout<<"este es nums2 = "<<nums2<<endl;
    cout<<"este es nums 1 = "<<nums1<<endl;
    nums2.swap(nums1);
    cout<<"ahora esto es nums 2 = "<<nums2<<endl;
    cout<<"ahora este es nums 1 = "<<nums1<<endl;
    */
    cout<<"\neste es nums 2 = "<<nums2<<endl;
    nums2.clear();
    cout<<"nums 2 limpio = "<<nums2;
    return 0;
}
