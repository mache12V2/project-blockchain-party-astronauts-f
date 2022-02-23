#include <iostream>

using namespace std;

class TransaccionPokemon{
    string Name, Type1, Type2, Legendary;
    int Numero, Total, HP, Attack, Defense, SP_Atk, SP_Def, Speed, Generation;

public: 

    TransaccionPokemon(int Num = 0, string name ="", string Type1="", string Type2="", int Total = 0, int HP =0, int Attack = 0, int Defense = 0, int SP_Atk = 0, int SP_Def = 0, int Speed =0, int Generation =0, string Legendary = ""){
        this->Numero = Num;
        this->Name = name;
        this->Type1 = Type1;
        this->Type2 = Type2;
        this->Total = Total;
        this->HP = HP;
        this->Attack = Attack;
        this->Defense = Defense;
        this->SP_Atk = SP_Atk;
        this->SP_Def = SP_Def;
        this->Speed = Speed;
        this->Generation = Generation;
        this->Legendary = Legendary;
    }

    friend ostream& operator<<(ostream& os, const TransaccionPokemon& e){
        os << e.Numero << " " << e.Name << " " << e.Type1 << " " << e.Type2 << " " << e.Total << " "
            <<  e.HP << " " << e.Attack << " " << e.Defense << " " << e.SP_Atk << " " << e.SP_Def << " "
            << e.Speed << " " << e.Generation << " " << e.Generation;
        return os;
    }
};

