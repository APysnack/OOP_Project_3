#pragma once

#include <iostream>
#include <string>
using namespace std;

// if header is not define, define header
#ifndef CAT_H
#define CAT_H

// creation of the cat class
class Cat {

// public variables for the cat class
public:

	// function declaration: default constructor
	Cat();

	// function declaration: overloaded constructor
	Cat(string, string, string, string);

	// function declaration: destructor
	~Cat();

	// function declarations: getters
	string getName() const;
	string getOwnerName() const;
	string getBreed() const;
	string getFact() const;

	// function declarations: setters
	void setName(string);
	void setOwnerName(string);
	void setBreed(string);
	void setFact(string);

private:
	// Member Variables
	string catName;
	string catOwnerName;
	string catBreed;
	string catFact;

};


#endif