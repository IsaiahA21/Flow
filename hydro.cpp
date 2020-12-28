//hydro.cpp

#include <fstream>
#include <stdlib.h>
#include "list.h"
#include "hydro.h"
#include <iostream>
using namespace std;

main (void) {
	int to_reset =1;
	FlowList x;
	int numRecords;
	displayHeader();
	to_reset =pressEnter();
	//cin.get();
	numRecords = readData(x);
	int quit =0;
	while(to_reset){
		switch(menu()){
			case 1: 
			display(x, numRecords);
			to_reset =pressEnter();
			break;
			case 2: 
			addData(x,numRecords);
			to_reset =pressEnter();
			break;
			case 3: 
			saveData(x, numRecords);
			to_reset =pressEnter();
			break;
			case 4: 
			removeData(x,numRecords);
			to_reset =pressEnter();
			break;
			case 5: cout << "\nProgram terminated!\n\n";
			quit = 1;
			// default saveData
			saveData(x, numRecords);
			break;
			default:  cout <<  "\nNot a valid input.\n";
			// pressEnter();
		}
	if(quit == 1) break;
	//return 0;
    }
}
void displayHeader() {
	cout<< "Program: Flow Studies, fall 2020"<<endl;
	cout<< "Produced by: Isaiah Asaolu"<<endl;


}

int pressEnter() {
cout<< "<<press enter to continue>>";
    cin.ignore(1);
	cin.get();
	return 1;
}

int readData(FlowList& x) {
	int TheYear;
    double TheFlow;
	ifstream TheFile;
	
	int howManydata=0;
	TheFile.open("flow.txt");
	
	if (! TheFile) {
		cout << "Error: cannot open the file" << "flow.txt" << endl;
		exit(1);
	}
	while (!TheFile.eof()){
		TheFile>> TheYear >> TheFlow;
		//cout<<"The file is "<<TheYear<<TheFlow;
		x.insert(TheYear,TheFlow);
	    //cout <<"\n";
		howManydata++;
	}
	TheFile.close();
	return howManydata;
}

int menu() {
	int usersInput=0;
	cout << "lease select on the following operations"<<endl;
	cout <<"1.  Display flow list, and the average" <<endl;
	cout<< "2.  Add data." << endl;
	cout <<"3.  Save data into the file"<<endl;
	cout <<"4.  Remove data"<<endl;
	cout <<"5.  Quit"<<endl;
	cout <<"Enter your choice (1, 2, 3, 4, of 5): ";
	cin >> usersInput;
	//cout << ""<<endl;
	
	
	return usersInput;
}
void display (FlowList& x,const int amount_of_elements){
	
	
	// calls average function
	
	cout<<"Year         Flow(in billions of cubic meters)"<<endl;
	x.print();
	double TheAverage = average(x,amount_of_elements);
	cout << "The annual average of flow is: "<<TheAverage<<endl;

} 

double average( FlowList& x,const int amount_of_elements) {
	//going to find the flows, sums them and then return the average
	double divided =0;
	divided = x.traverseforYear();
	divided = divided/amount_of_elements;
	return divided;
}

void addData(FlowList& x, int& numRecords) {
	int userYear;
	double userFlow;
	//going to ask the user for year and flow
	cout<< "Please enter a year: ";
	cin>>userYear;
	cout<<endl;
	cout<< "Please enter a flow: ";
	cin>>userFlow;
	cout<<endl;
	
	//call the memeber functuon can to first check if year already it exist
		int checking = x.scan(userYear);
		
	// if it exist, display error: duplicate
	if (checking ==1) {
		cout<<"error: year duplicated"<<endl;
		
	}
	// else insert into list	
	else {
		x.insert(userYear,userFlow);
		numRecords++;
		cout<<"New record inserted Successfully "<<endl;
	}
	
//	
}
void saveData(const FlowList x, const int numRecords) {
	int TheYear;
    double TheFlow;
	ofstream TheOutFile;
	FlowList y = x;
	
	TheOutFile.open("flow.txt");
	
	if (! TheOutFile) {
		cout << "Error: cannot open the file" << "flow.txt" << endl;
		exit(1);
	}
	for (int i =0; i< numRecords; i++) {
		// going to link TheYear and TheFlow by reference and find the 
		// in other to preserve flowlist x orignal position, I created y and y is  going to keep moving
				if((i+1)==numRecords) {
			y.traverse(TheYear, TheFlow);
			TheOutFile<<TheYear << "     "<<TheFlow;
			
		} else {
		y.traverse(TheYear, TheFlow);
		TheOutFile<<TheYear << "     "<<TheFlow<<endl;
		}

	}
	cout <<"Data are saved into the file."<<endl;
	TheOutFile.close();
}

void removeData(FlowList& x, int& numRecords) {
	int Year_to_delete;
	//going to ask the user for year and flow
	cout<< "Please enter the year that you want to remove: ";
	cin>>Year_to_delete;
	cout<<endl;

	
	//call the memeber functuon can to first check if year already it exist
		int checking = x.scan(Year_to_delete);
		
	if (checking ==1) {
		x.remove(Year_to_delete);
		numRecords--;
		cout<<"Record was Successfully removed "<<endl;
		
	}
	else {
	  cout<<"error: No such data"<<endl;

	}
	
//	
}
