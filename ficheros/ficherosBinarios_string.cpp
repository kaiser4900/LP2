#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

struct A
{
    int x;
    string str;

    friend ostream & operator << (ostream & os, A &s)
    {
        return os << s.x<< " " <<s.str;
    }
    friend istream & operator>> (istream & is, A &s)
    {
        return is >> s.x>>s.str;
    }
};
int my_size(string s)
{
    int j=0;
    while(s[j]!='\0')
    {
        j++;
    }
    return j;
}
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
void save_binary(vector<A>vs)//guardando
{
    ofstream salidaBinary;
	salidaBinary.open("ficheroBinario.dat",ios::out|ios::binary);
	for(int i=0; i<vs.size();i++)
		{
		    salidaBinary.write((char*)&vs[i].x,sizeof(int));
		    int a = my_size(vs[i].str);
		    string b = vs[i].str;
		    salidaBinary.write((char*)&a,sizeof(int));
		    for(int j = 0; j<a; j++)
            {
                salidaBinary.write((char*)&b[j],sizeof(char));
            }
		}
	salidaBinary.close();
}

void binaryLoad(vector<A>&va)//leyendo
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
        int size_string;
        while (ficheroEntrada.read((char*)&a.x,sizeof(int)))
        {
            ficheroEntrada.read((char*)&size_string,sizeof(int));
            //ficheroEntrada.seekg(8, ios::beg);
            //int tamanyo = ficheroEntrada.tellg();
            //cout<<tamanyo<<endl;
            char c[size_string];
            char c2;
            for(int i =0; i < size_string; i++)
            {
                ficheroEntrada.read((char*)&c2,1);
                c[i]=c2;
            }
            a.str=c;
            va.push_back(a);

            //tamanyo = ficheroEntrada.tellg();
            //cout<<tamanyo<<endl;
            //ficheroEntrada.seekg(0, ios::end);
            //tamanyo = ficheroEntrada.tellg();
            //cout<<tamanyo<<endl;
        }
        ficheroEntrada.close();
    }
}
int main()
{
    A a;
    vector <A> va;
    //load_array(va);
    binaryLoad(va);//listo
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
    save_binary(va);//listo

    return 0;
}
