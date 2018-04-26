#include <fstream>
#include <iostream>

using namespace std;

class BigInt
{
    private:
        int *numar, lungime;
    public:
        // ~BigInt();
        ///constructori
        BigInt(string s="");
        BigInt(int v[], int lg = 0);
        ///alte functii
        void Afisare();
        int getLungime();
        void inversare();
        ///friend
        friend BigInt& operator+(BigInt& nr1, BigInt& nr2);
        friend istream &operator>>(istream &is, BigInt&nr);
        friend ostream &operator<<(ostream &os, BigInt&nr);
};

int main()
{
    int x;
    BigInt numar1, numar2("1234"), numar3;
    cin>>numar1;
    cout<<numar1;
    numar3 = numar1 + numar2;
    cout << numar3;
}

///CONSTRUCTORI
BigInt::BigInt(string s)
{
    int ln, i;
    ln=s.length();
    this->lungime=ln;
    this->numar = new int[ln];
    for(i=0;i<=ln-1;i++)
        this->numar[ln-i-1]=s[i]-'0';
}
BigInt::BigInt(int v[], int lg)
{
    this->lungime = lg;
    this->numar = new int[lg];
    for(int i = 0; i < lg; i++)
        numar[i] = v[i];
}
///OPERATORI
istream &operator>>(istream &is, BigInt&nr)
{
    int ln, i;
    string str;
    is>>str;
    ln=str.length();
    nr.lungime=ln;
    nr.numar = new int[ln];
    for(i=0;i<=ln-1;i++)
        nr.numar[i]=str[ln-i-1]-'0';
    return is;
}

ostream &operator<<(ostream &os, BigInt&nr)
{
    os<<"Lungimea numarului este : "<<nr.lungime<<'\n';
    os<<"Numarul este : ";
    for(int i = nr.lungime - 1; i >= 0 ; i--)
        os << nr.numar[i];
    os<<'\n'<<'\n';
    return os;
}

///Adunare - merge
BigInt& operator+(BigInt& nr1, BigInt& nr2)
{
    int aux[200]={0}, T = 0, lungime_t;
    lungime_t = min(nr1.lungime, nr2.lungime);
    if(nr1.lungime > nr2.lungime)
    {
        for(int i = 0; i < lungime_t; i++)
        {
            aux[i] = nr1.numar[i] + nr2.numar[i]+ T;
            T = aux[i]/10;
            aux[i] = aux[i] % 10;
        }
        for(int i = lungime_t; i < nr1.lungime; i++)
        {
            aux[i] = nr1.numar[i] + T;
            T = aux[i]/10;
            aux[i] %=10;
        }
        lungime_t = nr1.lungime;
    }
    else if(nr1.lungime < nr2.lungime)
    {
        for(int i = 0; i < lungime_t; i++)
        {
            aux[i] = nr1.numar[i] + nr2.numar[i]+ T;
            T = aux[i]/10;
            aux[i] = aux[i] % 10;
        }
        for(int i = lungime_t; i < nr2.lungime; i++)
        {
            aux[i] = nr2.numar[i] + T;
            T = aux[i]/10;
            aux[i] %=10;
        }
        lungime_t = nr2.lungime;
    }
    else {
        for(int i = 0; i < lungime_t; i++)
        {
            aux[i] = nr1.numar[i] + nr2.numar[i]+ T;
            T = aux[i]/10;
            aux[i] = aux[i] % 10;
        }
    }
    if(T)
        aux[lungime_t++] = T;
    BigInt rezultat(aux, lungime_t);
    return rezultat;
}
///ALTE FUNCTII
int BigInt::getLungime(){
    return this->lungime;
}
void BigInt::inversare(){
    int x[100];
    for(int i = 0; i < this->lungime; i++)
        x[i] = this->numar[i];
    for(int i = 0; i < this->lungime; i++)
        this->numar[i] = x[this->lungime - i - 1];
}
