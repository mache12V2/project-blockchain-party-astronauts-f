#include <iostream>

using namespace std;

class User{
private:
    string nombre;
    int cuenta;
public:
    User(string nom, int cuet){
        this->nombre = nom;
        this->cuenta = cuet;
    }
};
