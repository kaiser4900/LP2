#include<iostream>
//Guillermo Aleman Zambrano
using namespace std;

class my_string
{
    private:
        int tamanio=0;
        char *punta;

    public:

        my_string() {
            punta = new char[tamanio];
        }

        my_string(const char* str='\0') {
        int i=0;

            while(str[i]!='\0')
            {
                i++;
            }
            i++;

        tamanio=i;
		punta = new char[tamanio];
		for (int i = 0; i < tamanio; ++i) {
			punta[i] = str[i];
		}
	}
        ~my_string(){delete[]punta;}

    int my_size() const{ return tamanio-1;}

    friend bool operator ==(const my_string& a, const my_string& b);
    const char& operator[](const int i);
    my_string &operator =(const my_string& str);
    my_string &operator +(const my_string& str);


    friend bool operator <(const my_string& a, const my_string& b);
    friend bool operator >(const my_string& a, const my_string& b);





    friend ostream & operator << (ostream & os, const my_string &s);
    friend istream& operator >>(istream& is , my_string& a );


};
my_string& my_string ::operator =(const my_string& str)
    {
        delete[] punta;
        punta=new char[str.tamanio];

        for(int i=0; i< str.tamanio; i++)
        {
            punta[i]=str.punta[i];
        }
        return *this;
    }

bool operator >(const my_string& a, const my_string& b)
{
    int i=0;
    bool aux;

    if(b.tamanio>a.tamanio)
    {
        aux=false;

        while (a.punta[i]!='/0')
        {
            if(a.punta[i]>=b.punta[i]) i++;
            else return aux;
            if(i==a.tamanio) return true;
        }
        return aux;
    }
    else
    {
        aux=true;

        while (b.punta[i]!='/0')
        {
            if(a.punta[i]>=b.punta[i]) i++;
            else return false;
            if(i==a.tamanio) return false;
        }
        return aux;

    }
}

bool operator <(const my_string& a, const my_string& b)
{
    int i=0;
    bool aux;
    if(a.tamanio>b.tamanio) aux=false;
    else aux=true;

    return aux;
}



my_string& my_string::operator + (const my_string & str){

	int tam=str.my_size();

	int x=0;
	char *aux=new char[tamanio];

	for(int i=0;i<tamanio;i++)
    {
        aux[i]=punta[i];
    }
	punta=new char[tam-1];

	for(int i=0;i<tamanio;i++)
    {
         punta[i]=aux[i];
    }
    for(int i=tamanio-1;i<tamanio+tam-1;i++)
    {
        punta[i]=str.punta[x++];
    }
    tamanio=tamanio+tam-1;
    delete[] aux;
    return *this;
}

const char& my_string::operator[](int i)
{
	return this->punta[i];
}

istream& operator >>(istream& is , my_string& a )
{
    return is>>a.punta;
}

ostream & operator << (ostream & os, const my_string &s)
    {
            return os << s.punta;

    }



bool operator ==(const my_string& a, const my_string& b)
{

    if(a.tamanio == b.tamanio)
    {
        int i=0;
        int x=0;

        while(a.punta[i]!='\0')
        {
            if(a.punta[i]!=b.punta[i]) x++;
            else i++;
        }
        if(x>0)return false;
        else return true;
    }
    else
        return false;
}



int main()
{
    my_string s1("1 2 3 4 5 6 7 8 9 10 11");
    my_string s2("1 2 3 4");


    cout<<s2<<endl;
    cout<<s2.my_size()<<endl;
    bool comp = s2<s1;

    if(comp) cout<<"true\n";
    else cout<<"false \n";


    bool comp2 = s1>s2;

    if(comp2) cout<<"true\n";
    else cout<<"false\n";


    cout<<s1[2]<<endl;
    cout<< s1 << endl;
    cout<<s1.my_size()<<endl;

    my_string s3(" :v ");
    s3=s1+s2;
    cout<<"suma"<<s3<<endl;

    s1=s2;
    cout<< s1 << endl;


    return 0;
}
