#include "Cat.h"
#include <string>

/*************************************************************************/
// default constructor
Cat::Cat() {
// strings in C++ are automatically set to a NULL state
// Since all of our parameters for this function are strings, no need to initialize
}

// overloaded constructor that assigns traits based on arguments passed in
Cat::Cat(string name, string owner, string breed, string fact) {
	catName = name;
	catOwnerName = owner;
	catBreed = breed;
	catFact = fact;
}

// destructor
Cat::~Cat() {

}
/*************************************************************************/
// setter to retrieve the object's name
string Cat::getName() const {
	return catName;
}

// setter to retrieve the object's owner name
string Cat::getOwnerName() const {
	return catOwnerName;
}

// setter to retrieve the object's breed
string Cat::getBreed() const {
	return catBreed;
}

// setter to retrieve a fact about the object
string Cat::getFact() const{
	return catFact;
}

/*************************************************************************/
// mutator used to set the object's name
void Cat::setName(string name) {
	catName = name;
}

// mutator used to set the object's owner name
void Cat::setOwnerName(string owner) {
	catOwnerName = owner;
}

// mutator used to set the object's breed
void Cat::setBreed(string breed) {
	catBreed = breed;
}

// mutator used to set a fact about the object
void Cat::setFact(string fact) {
	catFact = fact;
}

/*************************************************************************/