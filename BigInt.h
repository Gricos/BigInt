#include <fstream>
#include <iostream>

using namespace std;

class BigInt
{
    private:
        int *numar, lungime;

    public:
        ///constructori

        BigInt(string s="");
        BigInt(int v[], int lg = 0);
        BigInt(long long u);
        BigInt(BigInt& nr);

        ///destructor

        ~BigInt();

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
        friend BigInt& operator*(BigInt& nr1, int nr2);
        friend istream &operator>>(istream &is, BigInt&nr);
        friend ostream &operator<<(ostream &os, BigInt&nr);
};
