#include "avltree.h"
#include "Nodeavl.h"
#include "Pokemon.h"
#include "Trainer.h"
#include <iostream>

using namespace std;


class DataSet {

    BlockChain<vector<Pokemon>>* intercambios;
    AVlTree<Pokemon, NodeBc<vector<Pokemon>>*>* transacciontree;
    vector<Pokemon> block;

public:

    DataSet() {
       
       intercambios = new BlockChain<vector<Pokemon>>();

        transacciontree = new AVlTree<Pokemon, NodeBc<vector<Pokemon>>*>([](Pokemon a, Pokemon b) {

            if (a > b)return 1;

            else if (a < b)return -1;

            else return 0;

            });

    }

    void Print() {
        cout << "--BlockChain--\n";
        intercambios->display();
    }


    void readCSV(string s = " ", bool header = true) {
        ifstream file(s);
        auto getInfo = [](vector<Pokemon> a)->string {
            string file_data = "";
            for (int i = 0; i < a.size(); ++i) {
                file_data = file_data + a.at(i).getinfo();
            }
            return file_data;
        };

        string name, type_1,type_2, st_number,st_total,st_hp,st_attack,st_defense,st_special_atk,st_special_def,st_speed,st_gen;
        
        int number,total,hp,attack,defense,special_atk,special_def,speed,gen;

        string line, registerf;

        if (header)
            getline(file, registerf);


        while (getline(file, registerf))
        {

            stringstream stream(registerf); 

            getline(stream, st_number, ',');
            getline(stream, name, ',');
            getline(stream, type_1, ',');
            getline(stream, type_2, ',');
            getline(stream, st_total, ',');
            getline(stream, st_hp, ',');
            getline(stream, st_attack, ',');
            getline(stream, st_defense, ',');
            getline(stream, st_special_atk, ',');
            getline(stream, st_special_def, ',');
            getline(stream, st_speed, ',');
            getline(stream, st_gen);
            number = stoi(st_number);
            total = stoi(st_total);
            hp = stoi(st_hp);
            attack = stoi(st_attack);
            defense = stoi(st_defense);
            special_atk = stoi(st_special_atk);
            special_def = stoi(st_special_def);
            speed = stoi(st_speed);
            gen = stoi(st_gen);




            block.push_back(Pokemon(number, name, type_1, type_2, hp, attack, defense, special_atk, special_def, speed ,gen));

            if (block.size() == 10) {
                intercambios->insert(getInfo, block);

                for (int i = 0; i < 6; ++i) {
                    transacciontree->insert(block.at(i), intercambios->getNE());

                }

                block.clear();
            }


        }

        file.close();
    }

    void Menu() {
        
        Trainer entrenador;
        string name;
        int op, Tid;
        do {
            do {
                cout << "\n--Menu--\n";
                cout << "1.Iniciar sesion\n";
                cout << "2.Ver todos los equipos\n";
                cout << "3.Salir\n";
                cin >> op;

                system("cls");
            } while (op > 3 || op < 1);


            switch (op) {


            case 1:
                cout << "\n--INICIO DE SESION--\n";
                cout << "Nombre del entrenador: "; cin >> name;

                cout << "Id del entrenador: "; cin >> Tid;

                entrenador = Trainer(name, Tid);

                MenuOp(entrenador);

                ; break;

            case 2:
                Print();

                ; break;
            case 3:
                exit(1);
                ; break;
            }
        } while (op != 3);
    }


    void MenuOp(Trainer entrenador) {

        int numero,vida,totalstats,ataque,defensa,ataque_sp,defensa_sp,velocidad,generacion, menu;
        string nombre,tipo_1,tipo_2,trainer,poke;
        vector<Pokemon> team;
        vector<Pokemon> stock;
        vector<Pokemon> changes;
        Pokemon search;
        
        auto getInfo = [](vector<Pokemon> a)->string {
            string info = "";

            for (int i = 0; i < a.size(); ++i) {

                info = info + a.at(i).getinfo();
            }

            return info;
        };

        auto compare1 = [](Pokemon a, Pokemon b)->bool {
            return a == b;
        };

        auto compare2 = [](Pokemon a, Pokemon b)->bool {
            if (a.getName()[0] == b.getName()[0]) {
                return true;
            }
            else return false;
        };

        auto compare3 = [](Pokemon a, Pokemon b)->bool {

            if (a.getName()[a.getName().length() - 1] == b.getName()[0]) {
                return true;
            }
            else return false;
        };

        auto compare4 = [](Pokemon a, Pokemon b)->bool {

            if (a.getName() == b.getName()) {
                return true;
            }
            else return false;
        };
        auto compare5 = [](Pokemon a, Pokemon b)->bool {

            if (a.getName() != b.getName()) {
                return true;
            }
            else return false;
        };
        auto compare6 = [](int i, vector<Pokemon> a, vector<Pokemon> b)->bool {

            if (a.at(i).getName() == b.at(0).getName()) {
                return true;
            }
            else return false;
        };

        auto compare7 = [](Pokemon a, Pokemon b)->bool {

            if (a.getName() == b.getName()) {
                return true;
            }
            else return false;
        };

        do {
            do {
                cout << "\n--Menu del Pc--\n";
                cout << "1.Retirar un pokemon del pc\n";
                cout << "2.Depositar un pokemon en el pc\n";
                cout << "3.Revisar equipo pokemon\n";
                cout << "4.Salir\n";
                cin >> menu;

                system("cls");
            } while (menu < 1 || menu>9);




            switch (menu) {

            case 1:
                cout << "--Menu PC--\n";
                cout << "Ingrese el nombre del pokemon que desea retirar:"; cin >> nombre;

                 if (team.size() <=5) {
                    team.push_back(Pokemon(0 ,nombre,"","",0,0,0,0,0,0,0));
                    cout << "El Pokemon se ha ingresado a su equipo\n";
                } 
                else if (team.size() == 6) {

                    cout << "Solo puedes llevar 6 pokemones al mismo tiempo\n";

                }; break; 

            case 2:
                if (team.size() == 0) {cout << "No tiene ningun pokemon en su equipo para depositar";}
                else {
                cout << "--Menu PC--/n";
                cout << "Ingrese el nombre del pokemon que desea depositar"; cin >> nombre;
                
                }
                ; break; 

            case 3:
                cout << "--Menu PC--\n";
                if (team.size() == 0) {cout << "No tiene ningun pokemon en su equipo";}
                else {
                cout << "Su equipo pokemon es: \n";
                for(int i = 0 ; i < team.size();++i){
                    cout << team.at(i)<< "\n";
                }
                }
            case 4:
                 break;
            }
        } while (menu != 4);

    }
            
};