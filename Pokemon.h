#include <iostream>
#include <string>

using namespace std;

class Pokemon{
    string Name, Type1, Type2, Legendary;
    int Numero, Total, HP, Attack, Defense, SP_Atk, SP_Def, Speed, Generation;

public: 

    Pokemon(int Num = 0, string name ="", string Type1="", string Type2="", int Total = 0, int HP =0, int Attack = 0, int Defense = 0, int SP_Atk = 0, int SP_Def = 0, int Speed =0, int Generation =0, string Legendary = ""){
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

    friend ostream& operator<<(ostream& os, const Pokemon& e){
        os << e.Numero << " " << e.Name << " " << e.Type1 << " " << e.Type2 << " " << e.Total << " "
            <<  e.HP << " " << e.Attack << " " << e.Defense << " " << e.SP_Atk << " " << e.SP_Def << " "
            << e.Speed << " " << e.Generation << " " << e.Generation;
        return os;
    }

    int GetNumero(){return Numero;}
    string GetName(){return Name;}
    string GetType1(){return Type1;}
    string GetType2(){return Type2;}
    int GetTotal(){return Total;}
    int GetHP(){return HP;}
    int GetAttack(){return Attack;}
    int GetDefense(){return Defense;}
    int GetSP_Atk(){return SP_Atk;}
    int GetSP_Def(){return SP_Def;}
    int GetSpeed(){return Speed;}
    int GetGeneration(){return Generation;}
    string GetLegendary(){return Legendary;}

    string GetString(){
        return to_string(Numero) + " " + Name + " " + Type1 + " " + Type2 + " " + to_string(Total) + " " + to_string(HP) + " " + to_string(Attack) + " " + 
        to_string(Defense) + " " + to_string(SP_Atk) + " " + to_string(SP_Def) + " " + to_string(Speed) + " " + to_string(Generation) + " " + Legendary;
    }
};

