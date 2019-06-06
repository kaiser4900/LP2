#include <iostream>
#include <set>
using namespace std ;


int main(){
    multiset <int > green ;
    multiset <int > blue ;
    multiset <int> :: iterator fit ,it ;
    int t , power ,n_battles , n_green ,n_blue;
    cin>>t;
    while ( t-- ){
           cin>>n_battles;
           cin>>n_green;
           cin>>n_blue;
           for (int i = 0 ; i < n_green ; i++)
           {
                cin>>power;
                green.insert ( power );
           }
           for (int i = 0 ; i < n_blue; i++)
           {
                 cin>>power;
                 blue.insert ( power );
           }

          while ( green.size() > 0 && blue.size() > 0)
          {
                 for (int i = 0 ; i < n_battles ; i++)
                  {
                        it = green.end() ; it -- ;
                        fit = blue.end() ; fit-- ;
                        if ( *it > *fit)
                        {
                            green.erase(it); blue.erase(fit);
                            green.insert(*it - *fit);
                        }
                        else if ( *it < *fit)
                        {
                            green.erase(it); blue.erase(fit);
                            blue.insert(*fit - *it);
                        }
                        else
                        {
                            green.erase(it); blue.erase(fit);
                        }


                        if (green.size() == 0 || blue.size() == 0)
                            break ;
                  }
          }


          if ( green.size() == 0 && blue.size() == 0)
          {
               cout<<"green and blue died"<<endl;;
          }
          else if (green.size() > 0)
          {
                cout <<"green wins"<<endl;
                it = green.end() ;
              do {
                  it --;
                  cout<<*it<<endl;
              }
              while ( it != green.begin());

          }
          else if (blue.size() > 0)
          {
             cout<<"blue wins"<<endl;;
              it = blue.end() ;
              do {
                  it --;
                  cout<<*it<<endl;
              }
              while ( it != blue.begin());

          }
          if (t>0)
            cout<<endl;

            green.clear ()  ; blue.clear() ;

      }


    return 0;

}
