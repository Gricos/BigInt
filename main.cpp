#include <iostream>
#include <stdlib.h>

using namespace std;

class BigInt
{
    private:
        int *numar, lungime;
    public:
        void citeste_Numar();
};

void BigInt::citeste_Numar()
{
    int ln, i;
    string str;
    cin>>str;
    ln=str.length();
    this->lungime=ln;
    this->numar = new int[ln];
    for(i=0;i<ln;i++)
        this->numar[i]=(int)str[i];
    cout<<"lungime "<<this->lungime<<endl;
    cout<<"numar "<<*this->numar<<endl;
}

int main()
{
    BigInt ob1;
    cout<<"Introdu numarul: ";
    ob1.citeste_Numar();
}
