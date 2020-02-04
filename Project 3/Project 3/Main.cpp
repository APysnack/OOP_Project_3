/*
Alan Pysnack
CSC 231
9/30/2019

*/


#include <iostream>
#include <string>
#include <cstdlib>
#include <conio.h>
#include "Cat.h"
#include "CatList.h"
#include "CatNode.h"

using namespace std;

// creates a new instance of the doubly linked list
CatList newCatList;

// driver class function declarations
void pressAnyKey();
void editSpecificCat();
void deleteCat();
void displaySpecificCat();

// driver class variable declarations
bool showMenu();
static bool keepGoing = true;

/*************************************************************************/
int main() {

	// creating a pre-set list of Cat objects
	Cat newCat1("garfield", "jon", "tabby", "loves lasagna");
	Cat newCat2("crookshanks", "hermoine", "half-persian, half-kneazle", "magical");
	Cat newCat3("chloe", "alan", "calicoe", "cutest cat in the world");
	Cat newCat4("puss", "unknown", "scottish straight shorthair", "wears boots");

	// adds the previously created Cat objects to the doubly-linked list
	newCatList.addBack(newCat1);
	newCatList.addBack(newCat2);
	newCatList.addBack(newCat3);
	newCatList.addBack(newCat4);

	// continues to prompt the user with menu options until they opt out
	while (keepGoing) {
		keepGoing = showMenu();
  }

	return 0;
}
/*************************************************************************/

/*************************************************************************/
void pressAnyKey() {
	cout << "Press any key to continue " << endl << endl;
	_getch();
}

/*************************************************************************/
bool showMenu() {
	// function variables
	char userInput;
	bool reprompt = true;
	bool endprogram = false;
	int choice;

	// outputs list with options for user to choose from
	cout << endl
		<< "---------------------------------------------------------------------\n"
		<< " Select an option from the menu below\n"
		<< " by entering the number of the choice\n"
		<< "---------------------------------------------------------------------\n"
		<< "\t1\tAdd a cat to the front of the list\n"
		<< "\t2\tAdd a cat to the back of the list\n"
		<< "\t3\tEdit a specific cat in the list\n"
		<< "\t4\tRemove a cat from the list\n"
		<< "\t5\tDisplay all cats in the list\n"
		<< "\t6\tSearch for and display a specific cat in the list\n"
		<< "\t7\tEnd program\n"
		<< "---------------------------------------------------------------------\n\n"
		<< "Enter your choice : \n\n";

	// switch statement that executes the case matching the user's input
	cin >> choice;
	switch (choice) {
	
	// executes getCatInfo function call and passes case number in as a parameter to
	// let the program know that the user wants to add to the front
	case 1: {
		int caseNum = 1;
		newCatList.getCatInfo(caseNum);
		break;
	}
	
	// executes getCatInfo function call and passes case number in as a parameter to
	// let the program know that the user wants to add to the back
	case 2: {
		int caseNumber = 2;
		newCatList.getCatInfo(caseNumber);
		break;
	}

	
	// executes editSpecificCat function call
	case 3: {
		editSpecificCat();
		break;
	}

	// executes deleteCat function call
	case 4: {
		deleteCat();
		break;
	}

	// executes displayList function call to display all cats
	case 5: {
		newCatList.displayList();
		break;
	}
	
	// executes displaySpecificCat function call to display the cat the user searches for
	case 6: {
		displaySpecificCat();
		break;
	}

	// ends the program 
	case 7: {
		keepGoing = false;
		cout << "The program is now ending." << endl;
		endprogram = true;
		userInput = 'N';
		break;
	}

	// handles the exception in case the user input does not match one of the cases
	default: {
		cout << "That option is currently not available\n";
		pressAnyKey();
		break;
	} // end default
  } // end switch

	// prompts the user asking if they'd like to see the menu again before displaying
	if (!endprogram) {
		cout << endl << "Would you like to see the menu again? Y/N: ";
		cin >> userInput;
	}

	// if user enters 'N' or 'n', the reprompt boolean is set to false and
	// program begins to terminate
	if (userInput == 'N' || userInput == 'n') {
		reprompt = false;
	}

	return reprompt;
}
/*************************************************************************/


// function definition for editing a specific cat in the list
void editSpecificCat() {
	string userInput; 

	// gets the name of the cat the user would like to modify
	cout << "Please enter the name of the Cat that you would like to edit: " << endl;
	cin >> userInput;

	// search function call that passes the name the user inputs,
	// along with an integer 1 to let the program know this is an "edit" function call
	if (userInput == newCatList.search(userInput, 1)) {
		cout << "Cat has been modified." << endl;
	}
	// exception in case user types a name that cannot be found
	else {
		cout << "The name you typed in could not be found." 
			<< " Please check to ensure that your spelling and case match" << endl;
	}
}

/*************************************************************************/
// delete cat function call
void deleteCat() {
	// function variables
	string userInput;

	// prompts the user for the name of the cat they'd like to delete
	cout << "Please enter the name of the Cat that you would like to delete: " << endl;
	cin >> userInput;

	//calls the deleteCat function with the cat name in the user's input as the argument
	if (userInput == newCatList.deleteCat(userInput)) {
		cout << "Cat has been deleted." << endl;
	}

	// exception in case the user enters a name that cannot be found and/or
	// uses a different form of capitalization
	else {
		cout << "The name you typed in could not be found."
			<< "Please check to ensure that your spelling and case match" << endl;
	}
}

/*************************************************************************/
// function call to display a single cat in the list
void displaySpecificCat() {
	string userInput;

	// prompts the user to enter a cat name and stores it in the userInput as a string
	cout << "Please enter the name of the Cat that you would like to display: " << endl;
	cin >> userInput;

	// search function call that passes the name the user inputs,
	// along with an integer 1 to let the program know this is an "display" function call
	if (userInput == newCatList.search(userInput, 3)) {
	}

	// exception in the event that the user types in a name that cannot be found
	else {
		cout << "The name you typed in could not be found."
			<< " Please check to ensure that your spelling and case match" << endl;
	}
}
