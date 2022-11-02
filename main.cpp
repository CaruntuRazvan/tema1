
#include <iostream>
#include <cstring>
#include <stdexcept>
#include <vector>

using namespace std;

// TODO: clasa e baza Obiect

class Obiect{
    char *t_nume; //t-trimite
    char *t_adresa;
    char *t_oras;
    char *p_nume;//p-primeste
    char *p_adresa;
    char *p_oras;
    double greutate;
    double cost;
public:

    //TODO: constructori
    Obiect(){}

    Obiect(const char* sendername, const char* senderadd,  const char* sendercity,
           const char* receivername , const char* receiveradd,  const char* receivercity,double g, double c) {
        size_t len1 = strlen(sendername);
        this->t_nume = new char[len1 + 1];
        strcpy(this->t_nume, sendername);
        /// t_nume = sendername;
        size_t len2 = strlen(senderadd);
        this->t_adresa = new char[len2 + 1];
        strcpy(this->t_adresa, senderadd);
        /// t_adresa = senderadd;
        size_t len3 = strlen(sendercity);
        this->t_oras = new char[len3 + 1];
        strcpy(this->t_oras, sendercity);
        ///t_oras = sendercity;
        size_t len4 = strlen(receivername);
        this->p_nume = new char[len4 + 1];
        strcpy(this->p_nume, receivername);
        ///p_nume = receivername;
        size_t len5 = strlen(receiveradd);
        this->p_adresa = new char[len5 + 1];
        strcpy(this->p_adresa, receiveradd);
        ///p_adresa = receiveradd;
        size_t len6 = strlen(receivercity);
        this->p_oras = new char[len6 + 1];
        strcpy(this->p_oras, receivercity);
        ///p_oras = receivercity;
        greutate = g;
        cost = c;
    }

    //TODO: copy constructorul
    Obiect(const Obiect &ob) {

        size_t len1 = strlen(ob.t_nume);
        this->t_nume = new char[len1 + 1];
        strcpy(this->t_nume, ob.t_nume);

        size_t len2 = strlen(ob.t_adresa);
        this->t_adresa = new char[len2 + 1];
        strcpy(this->t_adresa, ob.t_adresa);

        size_t len3 = strlen(ob.t_oras);
        this->t_oras = new char[len3 + 1];
        strcpy(this->t_oras, ob.t_oras);

        size_t len4 = strlen(ob.p_nume);
        this->p_nume = new char[len4 + 1];
        strcpy(this->p_nume, ob.p_nume);

        size_t len5 = strlen(ob.p_adresa);
        this->p_adresa = new char[len5 + 1];
        strcpy(this->p_adresa, ob.p_adresa);

        size_t len6 = strlen(ob.p_oras);
        this->p_oras = new char[len6 + 1];
        strcpy(this->p_oras, ob.p_oras);

        greutate =ob.greutate;
        cost = ob.cost;
    }

    //TODO: destructorul
    ~Obiect(){
        delete[] t_nume;
        delete[] t_adresa;
        delete[] t_oras;
        delete[] p_nume;
        delete[] p_adresa;
        delete[] p_oras;
    }

    //TODO: setteri si getteri pt toate atributele clasei
    void setSName( char* sendername) {
        /// t_nume = sendername;
        size_t len1 = strlen(sendername);
        t_nume = new char[len1 + 1];
        strcpy(t_nume, sendername);
    }

    char *getSName()const {
        return t_nume;
    }

    void setSAddress( char* senderadd) {
        ///t_adresa = senderadd;
        size_t len20 = strlen(senderadd);
        t_adresa = new char[len20 + 1];
        strcpy(t_adresa, senderadd);
    }

    char *getSAddress()const {
        return t_adresa;
    }

    void setSCity( char* sendercity) {
        /// t_oras = sendercity;
        size_t len30 = strlen(sendercity);
        t_oras = new char[len30 + 1];
        strcpy(t_oras, sendercity);
    }

    char *getSCity()const {
        return t_oras;
    }

    void setRName( char* receivername) {
        ///p_nume = receivername;
        size_t len40 = strlen(receivername);
        p_nume = new char[len40 + 1];
        strcpy(p_nume, receivername);
    }

    char *getRName()const {
        return p_nume;
    }

    void setRAddress( char* receiveradd) {
        p_adresa = receiveradd;
        size_t len50 = strlen(receiveradd);
        p_adresa = new char[len50 + 1];
        strcpy(p_adresa, receiveradd);
    }

    char *getRAddress()const {
        return p_adresa;
    }

    void setRCity( char* receivercity) {
        p_oras= receivercity;
        size_t len60 = strlen(receivercity);
        p_oras = new char[len60 + 1];
        strcpy(p_oras, receivercity);
    }

    char *getRCity()const {
        return p_oras;
    }

    void setWeight(double g) {
        greutate = g;
    }

    double getWeight() const {
        return greutate;
    }

    void setCost(double c) {
        cost = c;
    }

    double getCost() const {
        return cost;
    }
    //definite in afara clasei:
    //TODO: supradefinirea  =
    Obiect& operator = (const Obiect &ob);
    //TODO: supradefinirea  +=
    Obiect& operator += (const Obiect &ob);
    //TODO: supradefinirea  ==
    friend bool operator == (const Obiect &a, const Obiect &b) ;
    //TODO: supradefinirea  !=
    friend bool operator != (const Obiect& a, const Obiect& b);

    //TODO: supradefinirea >>
    friend istream&operator>>(istream&is, Obiect&ob)
    {
        char senderName[100],senderAdd[100],senderCity[100],receiverName[100],receiverAdd[100],receiverCity[100];
        double weight, price;
        cout << "-----------New object-----------\n";
        cout << "Sender name:\n";
        is >> senderName;
        ob.setSName(senderName);
        cout << "Sender address:\n";
        is >> senderAdd;
        ob.setSAddress(senderAdd);
        cout << "Sender City:\n";
        is >> senderCity;
        ob.setSCity(senderCity);
        cout << "Receiver Name:\n";
        is >> receiverName;
        ob.setRName(receiverName);
        cout<< "Receiver address:\n";
        is >> receiverAdd;
        ob.setRAddress(receiverAdd);
        cout << "Receiver city:\n";
        is >> receiverCity;
        ob.setRCity(receiverCity);
        cout << "Object weight:\n";
        is >> weight;
        ob.setWeight(weight);
        cout << "Price:\n";
        is >> price;
        ob.setCost(price);
        return is;
    }

    //TODO: supradefinirea <<
    friend ostream&operator<<( ostream &os, const Obiect&ob)
    {
        os << "Sender name: " << ob.t_nume << "\n";
        os << "Sender address: " << ob.t_adresa << "\n";
        os << "Sender City: " << ob.t_oras << "\n";
        os << "Receiver name: " << ob.p_nume << "\n";
        os << "Receiver address: " << ob.p_adresa << "\n";
        os << "Receiver City: " << ob.p_oras << "\n";
        os << "Weight of object: " << ob.greutate << "\n";
        os << "Price: " << ob.cost << "\n";

        return os;
    }

};
Obiect & Obiect::operator=(const Obiect &ob) {

    strcpy(this->t_nume , ob.t_nume);
    strcpy(this->t_adresa , ob.t_adresa);
    strcpy(this->t_oras , ob.t_oras);
    strcpy(this->p_nume , ob.p_nume);
    strcpy(this->p_adresa , ob.p_adresa);
    strcpy(this->p_oras , ob.p_oras);
    this->greutate = ob.greutate;
    this->cost = ob.cost;

    return *this;
}
Obiect & Obiect::operator +=(const Obiect &ob) {

    strcpy(this->t_nume , ob.t_nume);
    strcpy(this->t_adresa , ob.t_adresa);
    strcpy(this->t_oras , ob.t_oras);
    strcpy(this->p_nume , ob.p_nume);
    strcpy(this->p_adresa , ob.p_adresa);
    strcpy(this->p_oras , ob.p_oras);
    this->greutate = ob.greutate;
    this->cost = ob.cost;

    return *this;
}
bool operator==(const Obiect &a, const Obiect &b){
    int ok;
    if(strcmp(a.t_nume,b.t_nume) == 0)
        ok = 1;
    else
        ok = 0;
    return (ok);
}
bool operator!=(const Obiect& a, const Obiect& b){
    return (!(a==b));
}

//TODO: Meniul interactiv tip singleton
class FirmaCurierat{
private:
    vector <Obiect> obiecte;
    static FirmaCurierat* instance;
    FirmaCurierat()=default;
public:
    static FirmaCurierat* getInstance() {
        if (instance == nullptr) return new FirmaCurierat();
        return instance;
    }

    void citireComenzi();
    void afisareComenzi();
    void cautareComanda();


    ~FirmaCurierat(){}
};

FirmaCurierat* FirmaCurierat::instance = nullptr;

void FirmaCurierat::citireComenzi() {

    int nr;
    cout << "Cate comenzi adaugati?\n";
    cin >> nr;
    for (int i = 0; i < nr; ++i) {
        Obiect obj;
        Obiect aux("","","","","","",0,0);
        obiecte.push_back(aux);
        cin >> obj;
        obiecte[i] += obj;
    }
}

void FirmaCurierat::afisareComenzi() {
    cout << "Toate comenzile inregistrate pana acum:\n";
    for (int i = 0; i < obiecte.size(); ++i) {
        cout << "---------Obiect nr." << i <<"---------\n";
        cout << obiecte[i];
        cout << "\n";
    }
}
void FirmaCurierat::cautareComanda() {
    int optiune;
    cout << "Introduceti 1 pentru a cauta dupa senderName si 2 dupa receiverName:\n";
    cin >> optiune;
    if (optiune == 1){
        string nume;
        cout << "Introduceti numele:\n";
        cin >> nume;
        for (int i = 0; i < obiecte.size(); ++i) {
            if(obiecte[i].getSName() == nume)
                cout << obiecte[i];
            cout << "\n";
        }
    }
    else if (optiune == 2){
        string nume;
        cout << "Introduceti numele:\n";
        cin >> nume;
        for (int i = 0; i < obiecte.size(); ++i) {
            if(obiecte[i].getRName() == nume)
                cout << obiecte[i];
            cout << "\n";
        }
    }
    else cout <<"Nu s-a gasit obiectul!";
}
int main()
{
//    Obiect ob1("Andrei","a","a","a","a","a",12,23);
//    Obiect ob2 = ob1;
//    Obiect ob3(ob1);
//    if(ob3 == ob2)
//        cout << "egale";
//    else cout <<"nu";


    FirmaCurierat* A = A->getInstance();
    int var;
    while (true){
        cout << "1. Citire si adaugare n comenzi\n";
        cout << "2. Afisare n comenzi\n";
        cout << "3. Cautare obiect dupa senderName/receiverName\n";
        cout << "4. Inchide meniu\n";
        cin >> var;
        if (var == 1) A->citireComenzi();
        else if (var == 2) A->afisareComenzi();
        else if (var == 3) A->cautareComanda();
        else {
            cout << "Programul s-a incheiat cu succes!\n";
            cout << "----------------------------------------------------------\n";
            break;
        }
    }
    return 0;
}
