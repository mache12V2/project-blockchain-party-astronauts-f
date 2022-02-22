#pragma once


template <class T, class A>
class NodeAVL {
public:
	T data;
	A block;
	NodeAVL* left;
	NodeAVL* right;
	int height = 0;
	NodeAVL(T data, A block) {
		this->data = data;
		this->block = block;
		left = right = nullptr;
		height = 0;

	}
	static int heighti(NodeAVL<T, A>* n) {
		return n == nullptr ? -1 : n->h;
	}
	void NewHeight() {
		height = max(heighti(right),heighti(left));
	}
};
