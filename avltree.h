#pragma once

#include <iostream>
#include <string>
#include <functional>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <vector>
#include "Nodeavl.h"
#include "blockchain.h"


template <class T, class A>
class AVlTree {
	NodeAVL<T, A>* root;
	function<int(T, T)> compare;
	int nodes = 0;
private:
	void insert(NodeAVL<T, A>*& thnode, T element, A ablock) {
		if (thnode == nullptr) {thnode = new NodeAVL<T, A>(element, ablock);nodes++;}
		else if (element < thnode->data) return insert(thnode->left, element, ablock);
		else if (element >= thnode->data)return insert(thnode->right, element, ablock);
		balance(thnode);
	}




	void InOrder(NodeAVL<T, A>* thnode) {
		if (thnode == nullptr) return;
		InOrder(thnode->left);
		cout << thnode->block << " ";
		InOrder(thnode->right);
	}



	void find(NodeAVL<T, A>* thnode, T data, vector<T>& stock, function<bool(T, T)> compare) {
		if (thnode == nullptr) return;
		find(thnode->left, data, stock, compare);

		if (compare(thnode->data, data))
			stock.push_back(thnode->data);
		find(thnode->right, data, stock, compare);
	}
	

	void changeTL(NodeAVL<T, A>* thnode, T data, T new1, function<bool(T, T)> compare) {
		if (thnode == nullptr) return;
		changeTL(thnode->left, data, new1, compare);

		if (compare(thnode->data, data))
			thnode->data = new1;
		changeTL(thnode->right, data, new1, compare);
	}
	/* 
	bool empty() {
		if (root == nullptr) return true;
	}
	 */
 /* 
	int size(NodeAVL<T, A>* thnode) {
		
		if (nodo == nullptr)
			return 0;
		else
		{
			int ci, cd;
			ci = _cantidad(nodo->izq);
			cd = _cantidad(nodo->der);
			return 1 + ci + cd;	
		}

	} */
	 
	void RotateRight(NodeAVL<T, A>*& thnode) {
		NodeAVL<T, A>* temp = thnode->left;
		thnode->left = temp->right;
		thnode->NewHeight();
		temp->right = thnode;
		thnode = temp;
		thnode->NewHeight();
	}
	
	void RotateLeft(NodeAVL<T, A>*& thnode) {
		NodeAVL<T, A>* temp = thnode->right;
		thnode->right = temp->left;
		thnode->NewHeight();
		temp->left = thnode;
		thnode = temp;
		thnode->NewHeight();
	}
	
	void balance(NodeAVL<T, A>*& thnode) { 
		int balance_fact = NodeAVL<T, A>::heighti(thnode->left) - NodeAVL<T, A>::heighti(thnode->right); 
		if (balance_fact > 1) { 
			int right_left_h = NodeAVL<T, A>::heighti(thnode->right->left);
			int right_right_h = NodeAVL<T, A>::heighti(thnode->right->right);			
			if (right_left_h > right_right_h) { 
				RotateRight(thnode->right);
			}
			 RotateLeft(thnode);
		}
		if (balance_fact < -1) { 
			int left_left_h = NodeAVL<T, A>::heighti(thnode->left->left);
			int left_right_h = NodeAVL<T, A>::heighti(thnode->left->right); 
			if (left_left_h < left_right_h) { 
				RotateLeft(thnode);
			}
			RotateRight(thnode); 
		}
	}

	T MinValue(NodeAVL<T, A>* thnode) 
	{
        while (thnode->left != nullptr)
        {
            thnode = thnode->left;
        }
        return thnode->data;
	}


	void MaxVlue(NodeAVL<T, A>* thnode) 
	{
		if (thnode->right == nullptr) 
		{
			cout << thnode->data; 
		}
		else
		{
			MaxVlue(thnode->right); 
		}
	}

	int height(NodeAVL<T,A> *thnode){
        if(!thnode) return -1;
        else{
            int tleft = height(thnode->left);
            int tright = height(thnode->right);
            if (tleft > tright) return tleft + 1;
            else
                return tright + 1;
        }
    }
	
public:
	AVlTree(function<int(T, T)> compare) : compare(compare) {

		root  = nullptr;
	}

	void find(T data, vector<T>& stock, function<bool(T, T)> compare) {
		find(root, data, stock, compare);
	}

	void ChangeTL(T data, T new1, function<bool(T, T)> compare) {
		changeTL(this->root, data, new1, compare);
	}

	void insert(T data, A block) {
		insert(this->root, data, block);
	}
	void InOrder() {
		InOrder(this->root);
	}
	int size() {
		return nodes;
	}
	int height() {
		return height(this->root);
	}
	void MinValue()
	{
		MinValue(this->node);
	}
	void MaxValue()
	{
		MaxValue(this->root);
	}

	bool empty() {
		if (root == nullptr) return true;
	}
	
};
