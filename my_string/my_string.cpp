#include<iostream>

using namespace std;

class my_string
{
    private:

        char *punta;

    public:

        my_string(const char *_punta=NULL)
        {
        int i=0;
            while(punta[i]!=0)
            {
                i++;
            }
            tamanio=i;

            punta= new char[tamanio];

            for(int i=0; i<tamanio;i++)
            {
                punta[i]=_punta[i];
            }
        }

        ~my_string(){delete[]punta;}

    int my_size() const{ return tamanio;}

    ostream & operator << (ostream & os, const my_string &s)
    {
            return os << s.punta;
    }
};


bool operator ==(const my_string& a, const my_string& b)
{
    if(a.tamanio == b.tamanio)
    {
        int i=0;
        int c=0;

        while(a[i]!=0)
        {
            if(a[i]!=b[i]) c++;
        }
        if(c>0)return false;
        else return true;
    }
    else
        return false;
    }



int main()
{
    my_string s1("hola");

    cout<< s1 << endl;

    return 0;
}
