#pragma once
#include "Cat.h"
#include <cstdlib>
#include <iostream>
#include <string>

// class defining the the CatNode structure 
class CatNode {

public:
	// the cat element in this node
	Cat cat;

	// pointer that points to the next item in the list
	CatNode* next;

	// pointer that points to the previous item in the list
	CatNode* prev;

	// allows CatList to access and utilize the CatNode structure
	friend class CatList;
};