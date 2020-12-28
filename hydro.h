//hydro.h

void displayHeader();
// display introduction
// uses pressEnter

int menu();
//displays to the user the menu

int readData(FlowList &x);
// read from file 
// going to use the insert memeber function is list to populate linked list
// going to keep track of number of total variables
// going to put them in ascending order
// going to return number of variables

void display(FlowList& x, const int amount_of_elements);
//work similary to print in OLList
// going to call list print member function
// going to call the average function 

void addData(FlowList& x, int &numRecords);
// gonna check if there's a duplicate
// if there's a duplicate prints a message out
// if good, call insert memeber function

void removeData(FlowList& x, int &numRecords);
// calls remove 
//similar to OLList

double average (FlowList& x,const int amount_of_elements);
//returns the average 
// going to traverse the linked list like diplay does
// and it going to keep adding the flow 

void saveData (const FlowList x, const int numRecords);
// opens file for writing
// writes the linked list into file in ascending order

int pressEnter();
//gets called 
//return back to menu