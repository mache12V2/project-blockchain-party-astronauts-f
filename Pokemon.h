#pragma once

#include <iostream>
#include <string>

using namespace std;

class Pokemon {
    string name, type_1,type_2;
    int number,total,hp,attack,defense,special_atk,special_def,speed,gen;

public:
    Pokemon(int number = 0 , string name = "", string type_1 = "", string type_2 = " ", int total = 0, int hp = 0, int attack = 0, int defense = 0, int special_atk = 0, int special_def = 0, int gen = 0) {
        this->number = number;
        this->name = name;
        this->type_1 = type_1;
        this->type_2 = type_2;
        this->total = total;
        this->hp = hp;
        this->attack = attack;
        this->defense = defense;
        this->special_atk = special_atk;
        this->special_def = special_def;
        this->speed = speed;
        this->gen = gen;

       
    }

    friend ostream& operator<<(ostream& op, const Pokemon& x) {
       op << x.number << " " << x.name << " " <<x.type_1 << " " << x.type_2 << " " <<  x.total<< " " << x.hp << " "<< x.attack<< " " << x.defense<< " " << x.special_atk << " " << x.special_def << " " << x.speed << " " << x.gen;
        return op;
    }

    bool operator<(const Pokemon& op) {

        return this->name < op.name;

    }

    bool operator>=(const Pokemon& op) {

        return this->name >= op.name;

    }

    bool operator>(const Pokemon& op) {

        return this->name >  op.name;

    }

    bool operator==(const Pokemon& op) {

        return this->name == op.name;

    }

/* 
    bool operator+(const double& r) {

        return this->glob_sales + r;

    }
     */

    string getinfo() {
        return to_string(number) + to_string(total);
    }

    int getNumber(){
        return number;
    }

    string getName() {
        return name;
    }

    string getType_1() {
        return type_1;
    }

    string getType_2(){
        return type_2;
    }

    int getTotal(){
        return total;
    }
    int getHp(){
        return hp;
    }

    int getAttack(){
        return attack;
    }

    int getDefense(){
        return defense;
    }

    int getSpecialAtk(){
        return special_atk;
    }

    int getSpecialDef(){
        return special_def;
    }

    int getSpeed(){
        return speed;
    }

    int getGen(){
        return gen;
    }

};