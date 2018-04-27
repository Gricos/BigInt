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
        BigInt(long long u);
        BigInt(BigInt& nr);

        ///alte functii

        void Afisare();
        int getLungime();
        void Inversare();
        bool Paritate();

        ///friend

        friend bool operator<(BigInt& nr1, BigInt& nr2);
        friend bool operator>(BigInt& nr1, BigInt& nr2);
        friend bool operator<=(BigInt& nr1, BigInt& nr2);
        friend bool operator>=(BigInt& nr1, BigInt& nr2);
        friend bool operator==(BigInt& nr1, BigInt& nr2);
        friend bool operator!=(BigInt& nr1, BigInt& nr2);
        friend BigInt& operator+(BigInt& nr1, BigInt& nr2);
        friend BigInt& operator-(BigInt& nr1, BigInt& nr2);
        friend istream &operator>>(istream &is, BigInt&nr);
        friend ostream &operator<<(ostream &os, BigInt&nr);
};


int main()
{
    BigInt numar1, numar2("1234"), numar3(2343), numar4;
    cin>>numar1>>numar4;
    if(numar1==numar4)
        cout<<"egal";
    else
        cout<<"nu";
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

BigInt::BigInt(long long u)
{
    int i = 0;
    long long aux;
    aux = u;
    while(aux)
    {
        aux/= 10;
        lungime ++;
    }
    this->numar = new int[lungime];
    while(u)
    {
        numar[i] = u%10;
        u/=10;
        i++;
    }
}

BigInt::BigInt(BigInt& nr)
{
    lungime = nr.lungime;
    numar = new int[lungime];
    for(int i = 0; i < lungime; i++)
        numar[i] = nr.numar[i];
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


///Adunare

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


///Scadere

BigInt& operator-(BigInt& nr1, BigInt& nr2)
{
    int T = 0, lungime_t, aux[200] = {0};
    lungime_t = nr1.lungime;
    for(int i = 0; i < nr2.lungime ; i++)
    {
        aux[i] = nr1.numar[i] - nr2.numar[i] + T;
        if(aux[i] < 0)
        {
            aux[i] = aux[i] + 10;
            T = -1;
        }
        else
            T = 0;
    }
    for(int i = nr2.lungime; i < lungime_t; i++)
    {
        aux[i] = nr1.numar[i] + T;
        if(aux[i] < 0)
        {
            aux[i] = aux[i] + 10;
            T = -1;
        }
        else
            T = 0;
    }
    int i; i = lungime_t - 1;
    while(aux[i] == 0 && i > 0)
        i--;
    lungime_t = i + 1;
    BigInt rezultat(aux, lungime_t);
    return rezultat;
}


///COMPARARE

bool operator<(BigInt& nr1, BigInt& nr2)
{
    int i;
    if(nr1.lungime>nr2.lungime)
        return false;
    if(nr1.lungime==nr2.lungime)
    {
        for(i=nr1.lungime-1;i>=0;i--)
        {
            if(nr1.numar[i]>nr2.numar[i])
                return false;
            if(nr1.numar[i]<nr2.numar[i])
                return true;
        }
    }
    if(nr1.lungime<nr2.lungime)
        return true;
    return false;
}


bool operator>(BigInt& nr1, BigInt& nr2)
{
    int i;
    if(nr1.lungime>nr2.lungime)
        return true;
    if(nr1.lungime==nr2.lungime)
    {
        for(i=nr1.lungime-1;i>=0;i--)
        {
            if(nr1.numar[i]>nr2.numar[i])
                return true;
            if(nr1.numar[i]<nr2.numar[i])
                return false;
        }
    }
    if(nr1.lungime<nr2.lungime)
        return false;
    return false;
}


bool operator<=(BigInt& nr1, BigInt& nr2)
{
    int i;
    if(nr1.lungime>nr2.lungime)
        return false;
    if(nr1.lungime==nr2.lungime)
    {
        for(i=nr1.lungime-1;i>=0;i--)
        {
            if(nr1.numar[i]>nr2.numar[i])
                return false;
            if(nr1.numar[i]<nr2.numar[i])
                return true;
        }
    }
    if(nr1.lungime<nr2.lungime)
        return true;
    return true;
}


bool operator>=(BigInt& nr1, BigInt& nr2)
{
    int i;
    if(nr1.lungime>nr2.lungime)
        return true;
    if(nr1.lungime==nr2.lungime)
    {
        for(i=nr1.lungime-1;i>=0;i--)
        {
            if(nr1.numar[i]>nr2.numar[i])
                return true;
            if(nr1.numar[i]<nr2.numar[i])
                return false;
        }
    }
    if(nr1.lungime<nr2.lungime)
        return false;
    return true;
}


bool operator==(BigInt& nr1, BigInt& nr2)
{
    int i;
    if(nr1.lungime!=nr2.lungime)
        return false;
    for(i=nr1.lungime - 1; i>=0; i--)
        if(nr1.numar[i]!=nr2.numar[i])
            return false;
    return true;
}


bool operator!=(BigInt& nr1, BigInt& nr2)
{
    int i;
    if(nr1.lungime!=nr2.lungime)
        return true;
    for(i=nr1.lungime - 1; i>=0; i--)
        if(nr1.numar[i]!=nr2.numar[i])
            return true;
    return false;
}


///ALTE FUNCTII

int BigInt::getLungime()
{
    return this->lungime;
}

void BigInt::Inversare()
{
    int x[100];
    for(int i = 0; i < this->lungime; i++)
        x[i] = this->numar[i];
    for(int i = 0; i < this->lungime; i++)
        this->numar[i] = x[this->lungime - i - 1];
}
