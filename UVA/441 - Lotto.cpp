#include<iostream>

using namespace std;

void lotto(int K)
{
    int nums[K];

        for(int i=0; i<K; i++)
        {
            cin>>nums[i];
        }

    for(int p=0;p<K-5;p++)
    {
        for(int s=p+1;s<K-4;s++)
        {
            for(int t=s+1;t<K-3;t++)
            {
                for(int c=t+1;c<K-2;c++)
                {
                    for(int q=c+1;q<K-1;q++)
                    {
                        for(int sx=q+1;sx<K;sx++)
                        {
                            cout<<nums[p]<<" "<<nums[s]<<" "<<nums[t]<<" "<<nums[c]<<" "<<nums[q]<<" "<<nums[sx]<<endl;
                        }
                   }
                }
            }
        }
    }

}

int main()
{
    int K;
    cin>>K;
    while(K!=0)
    {
       if(6<K&&K<13) lotto(K);
       cin>>K;
    }

    return 0;
}
