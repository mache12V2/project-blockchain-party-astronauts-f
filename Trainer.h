#pragma one

#include <string>

using namespace std;

class Trainer {
private:
    string nombre;
    int Idno;
public:
    Trainer(string nome, int id) : nombre(nome), Idno(id) {}
    Trainer() {}
    string getName() {
        return nombre;
    }


};