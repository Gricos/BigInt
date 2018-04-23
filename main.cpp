#include <fstream>
#include <iostream>

using namespace std;

class BigInt
{
    private:
        int *numar, lungime;
    public:
        // ~BigInt();
        BigInt();
        void citeste_Numar();
        void Afisare();
        int getLungime();
        friend BigInt& operator+(BigInt& nr1, BigInt& nr2);
};

int main()
{
    int x;
    BigInt numar1, numar2, numar3;

    numar1.citeste_Numar();

    x=numar1.getLungime();
    cout<<"Lungimea din getLungime() este: "<<x<<'\n'<<'\n';

    numar1.Afisare();

    numar2.citeste_Numar();

    x=numar2.getLungime();
    cout<<"Lungimea din getLungime() este: "<<x<<'\n'<<'\n';

    numar2.Afisare();

   // numar3=numar1+numar2;

    x=numar3.getLungime();
    cout<<"Lungimea din getLungime() este: "<<x<<'\n'<<'\n';

    numar3.Afisare();
}

/*
BigInt::~BigInt()
{
  cout << "A mers";
  delete numar;
  delete &lungime;
}*/

BigInt::BigInt()
{
    this->numar=NULL;
    this->lungime=0;
}

void BigInt::citeste_Numar()
{
    int ln, i;
    string str;
    cin>>str;
    ln=str.length();
    this->lungime=ln;
    this->numar = new int[ln];
    for(i=0;i<=ln-1;i++)
        this->numar[i]=str[i]-'0';
}

void BigInt::Afisare()
{
    cout<<"Lungimea numarului este : "<<this->lungime<<'\n';
    cout<<"Numarul este : ";
    for(int i = 0; i <= this->lungime - 1; i++)
        cout << *(this->numar + i);
    cout<<'\n'<<'\n';
}

int BigInt::getLungime()
{
    return this->lungime;
}

/// Adunare nefunctionala.
/*

BigInt& operator+(BigInt& nr1, BigInt& nr2)
{
    int rest=0, i;
    BigInt nr3;
    nr3.lungime=max(nr1.lungime, nr2.lungime);
    for(i=0;i<nr3.lungime;i++)
    {
        nr3.numar[i]=nr1.numar[i]+nr2.numar[i]+rest;
        rest=nr3.numar[i]/10;
        nr3.numar[i]=nr3.numar[i]%10;
    }
    if(rest!=0)
    {
        nr3.lungime=nr3.lungime+1;
        nr3.numar[nr3.lungime-1]=rest;
    }
    return nr3;
}

*/

