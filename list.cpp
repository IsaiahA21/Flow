// list.cpp 

#include<fstream>
#include <stdlib.h>
#include "list.h"
#include "hydro.h"
#include <iostream>
using namespace std;

FlowList:: FlowList() :headM(0){
	
}

/*FlowList:: FlowList() {
	// should read from 
	// gets record from record data
}*/

void FlowList::insert(const int& itemYear,const double& itemFlow){
	Node *new_node = new Node;
    new_node->item.year = itemYear;
	new_node->item.flow = itemFlow;
    
    if (headM == 0 || itemYear <= headM->item.year ) {
        new_node->next = headM;
        headM = new_node;
    }
    else {
        Node *before = headM;      
        Node *after = headM->next; 
        while(after != 0 && itemYear > after->item.year) {
            before = after;
            after = after->next;
        }
        new_node->next = after;
        before->next = new_node;
    }
	
}


void FlowList::print() {

	if (headM != 0) {
      cout << ' ' << headM->item.year << "         "<< headM->item.flow<<endl;
      for (const Node *p = headM->next; p != 0; p = p->next){
	cout << ' ' << p->item.year << "         "<< p->item.flow<<endl;
	  }
    }

}

int FlowList::scan(const int targetYear) {
	//if year already eixist return 1
	
	// else return 0;
	Node *ptr = headM; 
	// if list is empty, do nothing
	if (ptr == 0 || targetYear < ptr->item.year){
        return 0;
	}
	
    // if the eleemnt to be check is the first element
    if (targetYear == ptr->item.year) {
		return 1;

    }
	
    else {
        while(ptr!=nullptr) {
			if (ptr->item.year==targetYear) {
				return 1;
			}
		ptr = ptr->next;
		}
    }
	return 0;
}

double FlowList::traverseforYear(){
	double summation =0;
	Node *ptr = headM; 
	//going to return the flows summation
	while(ptr!=nullptr) {
		summation += ptr->item.flow;
		ptr = ptr->next;
	}
	return summation;
}
void FlowList::traverse(int& giveYear, double& giveFlow) {
	if (headM == 0) {
		cout<<"The linked list is empty"<<endl;
		return;
	}
	if (headM !=0) {
		giveYear = headM->item.year;
		giveFlow = headM->item.flow;
	}
	headM= headM->next;
}

void FlowList::remove(const int deleteYear)
{
    // if list is empty, do nothing
    if (headM == 0 || deleteYear < headM->item.year)
        return;
    
    Node *place_to_delete = 0; 
	
    // if the eleemnt to be removed is the first element
    if (deleteYear == headM->item.year) {
        place_to_delete = headM;
        headM = headM->next;
		delete place_to_delete;
		return;

    }
    else {
				
        Node *before = headM;
        Node *place_to_delete = headM->next;
        while(place_to_delete != 0 && deleteYear != place_to_delete->item.year) {
            before = place_to_delete;
            place_to_delete = place_to_delete->next;
        }
		if (place_to_delete->item.year == deleteYear) {
			before->next = place_to_delete->next;
			delete place_to_delete;
			
		}
    }
}

/*void FlowList::destroy(){
	Node *gone = headM;
	Node *forward = new Node;
	
	while (headM != nullptr) {
		forward = gone->next;
		delete gone;
		headM = forward;
		gone = headM;
	}
	//default line
    headM =0;
}*/
