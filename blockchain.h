#pragma once

#include <iostream>
#include <string>
#include <functional>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <math.h>
#include <ctime>
#include "nodebc.h"

using namespace std;

template <class T>
class BlockChain {
private:
	NodeBc<T>* start;	//2
	NodeBc<T>* end;		//2
	unsigned long quantity;	//2
public:
	BlockChain() {
		start = end = nullptr;	//2

		quantity = 0;	//1
	}


	NodeBc<T>* getNE() {

		return end;	//1
	}


	string Hashfunction(T v, function<string(T)> getInfo, string prevhash = "") {
	   srand(time(NULL));	//2
		int seed = rand()%100;	//4
		int factor = rand()%6 + 2;	//4
		string data = getInfo(v);	//3
		string hash = "", prevh = "";	//3


		for (int i = 0; i < data.length()/factor; ++i) {	//1+n(1+2+....)

			hash = hash + data[i];	//2
		}

		long long hog = stoll(hash);	//4

		if (prevhash != "") {	//1+...
			for (int i = 0; i < prevhash.length() / factor; ++i) {	//1+n(1+2+...)

				prevh = prevh + prevhash[i];	//2
			}
			long long phog = stol(prevh);	//4

			phog = phog + hog;	//2
		}

		hog = hog * seed; 	//2

		return to_string(hog) + to_string(data.length());	//5

	}

	void insert(function<string(T)> getInfo, T value) {
		NodeBc<T>* new1 = new NodeBc<T>(value);	//3

		if (quantity == 0) {	//1+...
			start = end = new1;	//2
			new1->prevhash = "No hash";	//2
			new1->hash = Hashfunction(value, getInfo);	//2
		}
		else {
			end->next = new1;	//2
			new1->prev = end;	//2
			end = new1;	//1
			new1->prevhash = new1->prev->hash;	//2
			new1->hash = Hashfunction(value, getInfo, new1->prevhash);	//2
		}
		++quantity;	//2
		}



	void ChangeT(T data, function<bool(int, T, T)> compare, function<string(T)> getInfo) {
		NodeBc<T>* aux = start;	//2
		int j = 0;	//2
		while (aux != nullptr) {	//1+n(....)
			for (int i = 0; i < aux->value.size(); ++i) {	//1+n(1+2+...)
				if (compare(i, aux->value, data)) {	//1+...
					aux->value.at(i) = data.at(1);	//4
					changehash(j, getInfo);	//1
				}
			}
			aux = aux->next;	//2
			++j;	//2
		}
	}

	void display() {
		NodeBc<T>* aux = start;	//2
		int j = 1;	//2
		while (aux != nullptr) {
			cout << "Block " << j << "\n";	//3
			cout << "->Previous Hash: " << aux->prevhash << "\n";	//3
			cout << "->Hash: " << aux->hash << "\n";	//3
			cout << "->Transacciones: " << "\n";	//2
			for (int i = 0; i < aux->value.size(); ++i) {	//1+n(1+2+...)

				cout << aux->value.at(i) << "\n";	//3
			}
			cout << "\n";	//1

			aux = aux->next;	//2
			j++;	//2
		}

	}

	int getquantity() {
		return quantity;	//1


	}


	void changehash(int i, function<string(T)> getInfo) {
		NodeBc<T>* aux = start;	//2
		NodeBc<T>* aux2;	//2
		int j = 0;	//2
		while (aux != nullptr) {	//1+...
			if (j == i) {	//1+...
				aux->hash = aux->hash + "2";	//4
				aux2 = aux;	//1

				for (int c = j; c < quantity - j - 1; ++c) {	//1+n(1+2+...)
					aux2->next->prevhash = aux2->hash;	//4
					aux2->next->hash = Hashfunction(aux2->value, getInfo, aux2->hash);	//4

					aux2 = aux2->next;	//2
				}
			}
			aux = aux->next;	//2
			j++;	//2
		}
	}
};

//Big O: O(n^2)