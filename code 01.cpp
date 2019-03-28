#include<iostream>
#include<vector>

using namespace std;

int swap_(int &num1, int &num2)
{
    num1 = num1 + num2;
    num2 = num1 - num2;
    num1 = num1 - num2;

}
int indi(vector<int>nums, int ingre)
{
    int size_ = nums.size();

    int aux =0;

    for(int i=0;i<size_;i++)
    {
        for(int j=0; j<size_;j++)
        {
            if(nums[i]<nums[j])
            {
               aux= nums[i];
               nums[i]=nums[j];
               nums[j]=aux;
               j=0;
            }
        }
    }

    return nums[ingre];

}
bool palin(string word)
{
    int size_;

    size_=word.size()-1;

    for(int a=0; a < size_;a++)
    {
        if(word[a]!=word[size_])
        {
            return false;
        }
        else
            return true;

        size_-=1;

    }
}
int pow__(int b,int n)
    {
        int aux_n=n, cont=1, aux_b= b;

    if(n==0 || b==1)
    {
        return 1;
    }
    else
    {
        while(cont*2<=n)
        {
            aux_b*=aux_b;
            cont*=2;
        }
        aux_n-=cont;

        while(aux_n>0)
        {
            aux_b*=b;
            aux_n--;
        }

        return aux_b;
    }

}
int pow_(int b,int n)
{
    if(n==1)
    {
        return b;
    }
    int aux=1;

    if(n%2!=0)
    {
        aux=b;

        n-=1;
    }
    if(n==2)
    {
        return b*b*aux;
    }
    else
    {
        n/=2;
        return pow_(b*b,n)*aux;
    }
}

int main(){

        int a, b;
        vector<int>nums;
        nums.push_back(2);nums.push_back(8);nums.push_back(3);nums.push_back(7);nums.push_back(6);

        cin>>a;
        cout<<indi(nums,a);
        string word;
        cout<<palin(word);//true or false
        cin>>a;
        cin>>b;
        cout<<swap_(a,b);
        cout<<pow_(a,b);
        cout<<pow__(a.b);

	return 0;
}

