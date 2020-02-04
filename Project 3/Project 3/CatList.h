#pragma once
#include "catNode.h"

class CatList {

// public function declarations

public:
	// Empty list constructor
	CatList();

	// list destructor
	~CatList();

	// boolean value that returns true if list is empty
	bool empty() const;

	// return front element in the list
	const Cat& front() const;

	// add element to the front of the list
	void addFront(const Cat& e);
	
	// add element to the back of the list
	void addBack(const Cat& e);

	// removes item in the front of the list
	void removeFront();

	// display full list of objects
	void displayList() const;

	// search for an element in the array, int functionCase should be
	// 1 if you wish to edit this array. 3 if you wish to delete the array
	string search(string name, int functionCase);

	// prompts the user to input information about a new cat
	// int caseNumber should be 1 if you wish to add this cat to the front of the list
	// int caseNumber should be 2 if you wish to add to the back of the list
	void getCatInfo(int caseNumber);

	// passes in a pointer to edit the cat contained in the node at that pointer's location
	void editCatInfo(CatNode* pointer);

	// executes a search function that finds the node containing the cat that matches
	// the string name argument. Takes the node found, then calls the deleteNode()
	// function and passes the node found in as an argument
	string deleteCat(string name);

	// passes in a pointer to delete the node at that pointer's location
	void deleteNode(CatNode* pointer);

/*************************************************************************/
// private variables
private: 
	// CatNode that specifies the head node
	CatNode* head;

	// CatNode that specifies the tail node
	CatNode* tail;

};
/*************************************************************************/