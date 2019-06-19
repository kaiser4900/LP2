#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

struct A
{
    int x;
    char str[20];

    friend ostream & operator << (ostream & os, A &s)
    {
        return os << s.x<< " " <<s.str;
    }
    friend istream & operator>> (istream & is, A &s)
    {
        return is >> s.x>>s.str;
    }
};
void save_array(vector<A>vs)
{
    ofstream ficheroSalida;
    ficheroSalida.open ("ficheroTexto3.txt");
    for(int i = 0; i < vs.size(); i++)
    {
        ficheroSalida << vs[i]<<endl;
    }
    ficheroSalida.close();
}
void load_array(vector<A>&va)
{
    ifstream ficheroEntrada;
    A num;
    ficheroEntrada.open("ficheroTexto3.txt");
    while (ficheroEntrada >> num)
    {
    	va.push_back(num);
    }
    ficheroEntrada.close();
}
void save_binary(vector<A>vs)
{
    ofstream salidaBinary;
	salidaBinary.open("ficheroBinario.dat",ios::binary);
	for(int i=0; i<vs.size();i++)
		{
			salidaBinary.write((char*)&vs[i],sizeof(A));
		}
	salidaBinary.close();
}

void binaryLoad(vector<A>&va)
{
    ifstream ficheroEntrada;
	ficheroEntrada.open("ficheroBinario.dat",ios::binary);
    if(ficheroEntrada.fail())
    {
        cout << "Error al abrir el fichero" << endl;
        exit(1);
    }
	else
    {
        A a;
        while (ficheroEntrada.read((char*)&a,sizeof(A)))
        {
            va.push_back(a);
        }
        ficheroEntrada.close();
    }
}
int main()
{
    A a;
    vector <A> va;

    //load_array(va);
    binaryLoad(va);
    for(int i = 0; i < va.size();i++)
    {
        cout<<va[i]<<endl;
    }
    A b;
    int n;

    cin >> n;
    while(n--)
    {
        cin>>b;
        va.push_back(b);
    }
    //save_array(va);
    save_binary(va);

    return 0;
}
