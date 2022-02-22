#pragma once

template <typename T>

class NodeBc {
public:
  	T value;
	string hash;
	string prevhash;
	NodeBc* next;
	NodeBc* prev;

	NodeBc(T v, NodeBc* n = nullptr, NodeBc* p = nullptr) : value(v), next(n), prev(p) {  }

};