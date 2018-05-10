#include "BigInt.h"
#include <conio.h>
#include <windows.h>


///MENIU

void BigInt::Lista(){
    cout << "1. Afiseaza paritatea unui numar"<< '\n';
    cout << "2. Compara 2 numere"<< '\n';
    cout << "3. Aduna 2 numere"<< '\n';
    cout << "4. Scade 2 numere"<< '\n';
    cout << "5. Inmulteste 2 numere"<< '\n';
    cout << "6. Iesire"<< '\n';
    cout << "7. Revezi meniul"<< '\n';
    cout << "8. Sterge ecranul" << '\n';
}

void BigInt::Meniu()
{
    Lista();
    int i = 0;
    bool ok = false;
    do{
        cin >> i;
        switch(i){
            case 1:
                {
                    cout << "Introdu numarul"<< '\n';
                    BigInt numar1, numar2;
                    cin >> numar1;
                    if(numar1.Paritate())
                        cout << "Numarul este par" << '\n';
                    else
                        cout << "Numarul este impar" << '\n';
                }
                break;
            case 2:
                {
                    cout << "Introdu 2 numere"<< '\n';
                    BigInt numar1, numar2;
                    cin >> numar1 >> numar2;
                    if (numar1 > numar2)
                        cout << "Numarul 1 > numarul 2"<< '\n';
                    else if (numar1 < numar2)
                        cout << "Numarul 1 < numarul 2"<< '\n';
                    else
                        cout << "Numarul 1 = numarul 2" << '\n';
                }
                break;

            case 3:
                {
                    BigInt numar1, numar2;
                    cout << "Introdu 2 numere"<< '\n';
                    cin >> numar1 >> numar2;
                    numar1 = numar1 + numar2;
                    cout << numar1 << '\n';
                }
                break;
            case 4:
                {
                    BigInt numar1, numar2;
                    cout << "Introdu 2 numere (primul mai mare ca celalalt)"<< '\n';
                    cin >> numar1 >> numar2;
                    if(numar1 >= numar2){
                        numar1 = numar1 - numar2;
                        cout << numar1 << '\n';
                    }
                    else {
                        cout << "Numerele nu sunt bune" << '\n';
                    }
                }
                break;
            case 5:
                {
                    BigInt numar1;
                    int numar2;
                    cout << "Introdu 2 numere(al doilea de maxim 9 cifre)" << '\n';
                    cin>>numar1>>numar2;
                    numar1 = numar1 * numar2;
                    cout << numar1 << '\n';
                }
                break;
            case 6:
                {
                    ok = true;
                }
                break;
            case 7:
                {
                for(int i=0;i<=99;i++)
                    cout<<'\n';
                Lista();
            }
            break;
            case 8:
                {
                system("cls");
                }
            break;
        };
    }while(!ok);
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

///DESTRUCTOR

BigInt::~BigInt()
{
    delete []numar;
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
    //os<<"Lungimea numarului este : "<<nr.lungime<<'\n';
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


///INMULTIRE

BigInt& operator*(BigInt& nr1, int nr2)
{
    int i;
    int aux[200]={0}, lungime_t;
    int t=0;
    lungime_t=nr1.lungime;
    for(i=0; i<nr1.lungime; i++)
    {
        aux[i]=nr1.numar[i]*nr2+t;
        t=aux[i]/10;
        aux[i]=aux[i]%10;
    }
    while(t)
    {
        aux[lungime_t++]=t%10;
        t/=10;
    }
    BigInt nr3(aux, lungime_t);
    return nr3;
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

bool BigInt::Paritate()
{
    return (this->numar[0])%2?0:1;
}
