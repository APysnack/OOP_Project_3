#include "CatList.h"

/*************************************************************************/
// default constructor setting the head and tail pointers to null
CatList::CatList() 
{
	head = NULL;
	tail = NULL;
}

/*************************************************************************/
// list destructor
CatList::~CatList() {
	while (!empty()) {
		removeFront();
	}
}
/*************************************************************************/
// checks whether the list is empty and returns true if true 
bool CatList::empty() const {
	return(head == NULL);
}

/*************************************************************************/
// checks to see the first element of the list and returns the cat object stored within
const Cat& CatList::front() const {
	return head->cat;
}

/*************************************************************************/
// search function to traverse the list until the name the user typed in is found
string CatList::search(string name, int functionCase)  {
	// creates a new cat node name temp and points it to the head
	CatNode* temp = new CatNode;
	temp = head;

	// returns string to let the program know if this function call was successful
	string successReturn = "fail";

	// while loop that moves temp pointer to next node in the list until it reaches the end
	while (temp != NULL) {

		// if state that executes when user input value for cat name is found
		if (name == temp->cat.getName()) {

			// switch that edits or displays the user's cat depending on the integer 
			// passed in by the function call
			switch (functionCase) {
				
				// function call to edit the cat, passes in the pointer that's pointing
				// at the user's inputted cat
				case 1: {
					editCatInfo(temp);
					temp = NULL;
					successReturn = name;
					break;
				}

				// displays the information associated with the user's inputted cat
				case 3: {

					cout << endl << temp->cat.getName() << endl << temp->cat.getName() << " is a(n) " <<
						temp->cat.getBreed() << " and is owned by " << temp->cat.getOwnerName() << ". " << endl
						<< "A fact about " << temp->cat.getName() << ": " << temp->cat.getFact() << endl << endl;

					temp = NULL;
					successReturn = name;
					break;
				}
			}
			
		}
		// moves temp to the next node in the array
		else {
			temp = temp->next;
		}
	}

	// returns as fail if none of the above conditions were met
	return successReturn;
}

/*************************************************************************/
// function to add a CatNode containing a cat to the front of the list
void CatList::addFront(const Cat& newCat) {
	// if statement that executes only if list is not empty
	if (!empty()) {

		// creates a new temporary cat node and stores the user's inputted cat in the data
		CatNode* temp = new CatNode;
			temp->cat = newCat;

			// changes the (soon-to-be) former head's pointer to the temp node
			head->prev = temp;

			// sets the temp's next pointer to the (soon-to-be) former head
			temp->next = head;

			// changes head to temp. temp is now the new head of the list
			head = temp;
	}
	else {
		// creates a new CatNode and fills it with the user's inputted cat
		CatNode* temp = new CatNode;
			temp->cat = newCat;

			// sets temps next pointer to null since there are no other elements
			temp->next = NULL;

			// sets temps previous pointer to null
			temp->prev = NULL;

			// assigns temp node as the head of the list
			head = temp;

			// assigns temp node as the tail of the list
			tail = temp;

			// sets the tail's next to null
			tail->next = NULL;
	}
}

/*************************************************************************/
void CatList::addBack(const Cat& newCat) {
	if (!empty()) {
		// create new node
		CatNode* temp = new CatNode;

		//fill node with cat
		temp->cat = newCat;

		// sets former tail's next to temp
		tail->next = temp;

		// set node's previous as the old tail
		temp->prev = tail;

		// sets tail to temp
		tail = temp;

		//set node's next to null
		temp->next = NULL;
	
	}
	else {
		// if array is empty, adds the cat to the front of the array and assigns the 
		// head and tail to each other.
		addFront(newCat);
		tail = head;
		head = tail;
	}
}

/*************************************************************************/
// function to remove the first element in the list
void CatList::removeFront() {

	// if that executes if array is not empty
	if (!empty()) {
		// creates a temp node and points it to the head
		CatNode* temp = head;

		// sets head to the next element in the list
		head = temp->next;

		// assigns the head's previous pointer to null
		head->prev = NULL;

		// delete's temp node
		delete temp;
	}
}

/*************************************************************************/
// function to display list 
void CatList::displayList() const {

	// if statement that executes if not empty
	if (!empty()) {

		// output prompt to user
		cout << endl << "Here are the cats in the list: " << endl;

		// creates a temp CatNode
		CatNode* temp = head;
		
		// while loop that executes until temp reaches last element in the list
		while (temp != NULL) {
			
			// outputs the cat information stores in the current temp node
			cout << temp->cat.getName() << endl << temp->cat.getName() << " is a(n) " <<
				temp->cat.getBreed() << " and is owned by " << temp->cat.getOwnerName() << ". " << endl
				<< "A fact about " << temp->cat.getName() << ": " << temp->cat.getFact() << endl << endl;
			
			// moves the temp pointer to the next node
			temp = temp->next;
		} // end while

		//line break
		cout << endl;
	} // end if

	// exception for when list is empty, outputs that there are no cats in the list
	else {
		cout << "There are no cats in this list" << endl;
	}
}

/*************************************************************************/
void CatList::getCatInfo(int caseNum) {

	// creation of variables for the function
	string name, owner, breed, fact;

	// takes in user input and stores it in the name, owner, breed, and fact variables
	cout << "Please enter your Cat's name: ";
	cin.ignore();
	getline(cin, name);
	cout << "Please enter the name of your Cat's owner: ";
	getline(cin, owner);
	cout << "What Breed is your cat? (or type \"unknown breed\" if unknown): ";
	getline(cin, breed);
	cout << "Tell me an interesting fact about your cat: ";
	getline(cin, fact);

	// creates a new instance of the cat object and uses the inputted values as arguments
	Cat newCat(name, owner, breed, fact);

	// adds to the front of the list if the integer passed in through the function
	// call is equal to 1
	if (caseNum == 1) {
		addFront(newCat);
	}

	// adds to the back of the list if the integer passed in through the function
	// call is equal to 2
	else if (caseNum == 2) {
		addBack(newCat);
	}

	// exception for unrecognized input
	else {
		cout << "The program does not recognize your response.";
	}
}

/*************************************************************************/
// function call to edit a specific cat in the list, receives pointer from search function
void CatList::editCatInfo(CatNode* pointer) {

	// declaration of function integers
	string name, owner, breed, fact;

		// prompts the user to enter the information they'd like to edit with
		// stores the input in string variables
		cout << "Please enter the name you would like to use for this cat: ";
		cin.ignore();
		getline(cin, name);
		cout << "Please enter name of this cat's owner: ";
		getline(cin, owner);
		cout << "What Breed is this cat? (or type \"unknown breed\" if unknown): ";
		getline(cin, breed);
		cout << "What interesting fact do you want us to know about this cat?: ";
		getline(cin, fact);

		// passes the user's input to the Cat class to created a Cat with
		// the user's newly inputted information
		Cat newCat(name, owner, breed, fact);

		// Replaces the cat object stored at the pointer address with the newly created cat
		pointer->cat = newCat;
}

/*************************************************************************/
// delete cat function definition
string CatList::deleteCat(string name) {

	// creates a new temp cat node and points it to the head
	CatNode* temp = new CatNode;
	temp = head;
	string successReturn = "fail";

	// if statement that executes if not empty
	if (!empty()) {
		
		// while loop that executes until temp reaches the end of the list 
		while (temp != NULL) {

			// if statement that executes if the cat at temp is the cat matching user's input
			if (name == temp->cat.getName()) {
				// calls the function to delete the node at this location
				deleteNode(temp);
				return name;
				break;
			}

			// pointer moves onto the next node in the array
			else {
				temp = temp->next;
			}
		}
	}

	// exception for when the list is already empty
	else {
		cout << "Cannot remove object because this list is already empty." << endl;
	}
	return successReturn;
}

/*************************************************************************/
// function to delete a specific node that's passed in through the argument
void CatList::deleteNode(CatNode* pointer) {
	
		// if statement that executes if the pointer is the head of the list
		if (pointer == head) {
			
			// if the next element in the array is not equal to null
			if (pointer->next != NULL) {

				// assigns the head pointer to the next element in the list
				head = pointer->next;

				// assigns the head's previous pointer to null
				head->prev = NULL;
			}

			// sets the head to NULL
			else {
				head = NULL;
			}

			// deletes the pointer
			delete pointer;
		}

		// else if statement that executes if the pointer is the tail of the list
		else if (pointer == tail) {
			// points the pointer to the tail of the list
			pointer = tail;

			// sets the node at the tail's previous pointer to the new tail
			tail = tail->prev;

			// sets the new tail's next pointer to null
			tail->next = NULL;

			// deletes pointer
			delete pointer;


		}
		
		// else statement for when pointer is one of the middle elements of the list
		else {
			// sets the next node's previous pointer to the element that pointer's 
			// previous pointer is pointing to
			pointer->next->prev = pointer->prev;

			// sets the previous node's next pointer to the element that pointer's
			// next pointer is pointing to
			pointer->prev->next = pointer->next;

			// delete pointer
			delete pointer;

		}
}

/*************************************************************************/