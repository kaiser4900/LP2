#include<iostream>

using namespace std;

class my_string
{
    private:
        int i=0;
        char *punta; //definiendo el puntero para trabajar

    public:

        my_string() {
            punta = new char[i];
        }

        my_string(const char* a) {
        int i=0;

            while(punta[i]!=0)
            {
                i++;
            }
            i++;

		punta = new char[i];
		for (int i = 0; i < i; ++i) {
			punta[i] = a[i];
		}
	}
        //destructor para limpiar el espacio de la memoria

        ~my_string(){delete[]punta;}

    //funcion size

    int my_size() const{ return i;}

    //funcion para imprimir

    friend ostream & operator << (ostream & os, const my_string &s)
    {
            return os << s.punta;

    }
    friend bool operator ==(const my_string& a, const my_string& b);
};

//funcion para devolver el char en []
// const char& my_string::operator[](int & i)
  //  {
    //    return punta[i];
    //}
//funcion para ver si son iguales
/*bool operator ==(const my_string& a, const my_string& b)
{
    if(a.i == b.i)
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
*/
//main creando un my_string

int main()
{
    my_string s1("hola");

    cout<< s1 << endl;

    return 0;
}
//ya compila pero no imprime xd
