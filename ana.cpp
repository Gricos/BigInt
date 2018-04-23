#include <fstream>
#include <iostream>

using namespace std;

class BigInt{
  private:
    int *numar, lungime;
  public:
    //~BigInt();
    BigInt(string str = "", int lg = 0);
    void citeste_Numar();
    void Parcurgere();
    int getLungime(); //acces la lungime
friend BigInt& operator+(BigInt& nr1, BigInt& nr2);
};

int main(){
  BigInt numar1;
  numar1.citeste_Numar();
  numar1.Afisare();
  return 0;
}
/* BigInt::~BigInt(){
  cout << "A mers";
  delete numar;
  delete &lungime;
}*/
void BigInt::citeste_Numar()
{
    int ln, i;
    string str;
    cin>>str;
    ln=str.length();
    this->lungime=ln;
    this->numar = new int[ln];
    for(i=ln-1;i>=0;i--)
        this->numar[ln-i-1]=str[i]-'0';
    cout<<"lungime "<<this->lungime<<endl;
}
void BigInt::Afisare(){
  for(int i = this->lungime - 1; i >= 0; i--)
    cout << *(this->numar + i);
}
int BigInt::getLungime(){
    return this->lungime;
}
BigInt::BigInt(string str, int lg){
    //momentan fac doar pt lungime dar ar trebui sa aiba si pt string cred
    lungime = lg;
}

BigInt& operator+(BigInt nr1, BigInt nr2){
    int i, T = 0, lungime1, lungime2;
    lungime1 = nr1.getLungime();
    lungime2 = nr2.getLungime();
    BigInt nr3("" ,lungime1 + lungime2);

    /*if(nr2.lungime > nr1.lungime){
    // link la functie: https://www.infoarena.ro/lucrul-cu-nr-mari
    else {

    }*/
    for(i = 0; i < lungime1 + lungime2; i++){

    }
    if(T){
    }
    return nr3;
}

