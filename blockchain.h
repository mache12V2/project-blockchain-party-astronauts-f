#pragma once

#include <iostream>
#include <string>
#include <functional>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <math.h>
#include "nodebc.h"

using namespace std;

template <class T>
class BlockChain {
private:
	NodeBc<T>* start;
	NodeBc<T>* end;
	unsigned long quantity;
public:
	BlockChain() {
		start = end = nullptr;

		quantity = 0;
	}


	NodeBc<T>* getNE() {

		return end;
	}


	string Hashfunction(T v, function<string(T)> getInfo, string prevhash = "") {
	   

		string data = getInfo(v);
		string half = "", quarter = "";


		for (int i = 0; i < data.length() / 4; ++i) {

			half = half + data[i];
		}

		long long n = stoll(half);

		if (prevhash != "") {
			for (int i = 0; i < prevhash.length() / 8; ++i) {

				quarter = quarter + prevhash[i];
			}
			long m = stol(quarter);

			n = n + m;
		}

		n = n * M_PI;

		return to_string(n) + to_string(data.length());

	}

	void insert(function<string(T)> getInfo, T value) {
		NodeBc<T>* new1 = new NodeBc<T>(value);

		if (quantity == 0) {
			start = end = new1;
			new1->prevhash = "No hash";
			new1->hash = Hashfunction(value, getInfo);
		}
		else {
			end->next = new1;
			new1->prev = end;
			end = new1;
			new1->prevhash = new1->prev->hash;
			new1->hash = Hashfunction(value, getInfo, new1->prevhash);
		}
		++quantity;
			}



	void ChangeT(T data, function<bool(int, T, T)> compare, function<string(T)> getInfo) {
		NodeBc<T>* aux = start;
		int j = 0;
		while (aux != nullptr) {
			for (int i = 0; i < aux->value.size(); ++i) {
				if (compare(i, aux->value, data)) {
					aux->value.at(i) = data.at(1);
					changehash(j, getInfo);
				}
			}
			aux = aux->next;
			++j;
		}
	}

	void display() {
		NodeBc<T>* aux = start;
		int j = 1;
		while (aux != nullptr) {
			cout << "Block " << j << "\n";
			cout << "->Previous Hash: " << aux->prevhash << "\n";
			cout << "->Hash: " << aux->hash << "\n";
			cout << "->Transacciones: " << "\n";
			for (int i = 0; i < aux->value.size(); ++i) {

				cout << aux->value.at(i) << "\n";
			}
			cout << "\n";

			aux = aux->next;
			j++;
		}

	}

	int getquantity() {
		return quantity;


	}


	void changehash(int i, function<string(T)> getInfo) {
		NodeBc<T>* aux = start;
		NodeBc<T>* aux2;
		int j = 0;
		while (aux != nullptr) {
			if (j == i) {
				aux->hash = aux->hash + "2";
				aux2 = aux;

				for (int c = j; c < quantity - j - 1; ++c) {
					aux2->next->prevhash = aux2->hash;
					aux2->next->hash = Hashfunction(aux2->value, getInfo, aux2->hash);

					aux2 = aux2->next;
				}
			}
			aux = aux->next;
			j++;
		}
	}
};
