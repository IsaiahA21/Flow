// list.h
struct ListItem {
	int year;
	double flow;
};

struct Node {
	ListItem item;
	Node *next;
};

class FlowList {
	public:
	FlowList(); // PROMISES: Creates empty list.
	//FlowList();// read from file
	//~FlowList();
	// will include many memeber functions as required:
	void insert(const int& itemYear, const double& itemFlow);
	void print();
	int scan(const int targetYear);
	double traverseforYear();
	void traverse(int& giveYear, double& giveFlow);
	void remove(const int deleteYear);
	//remove(); 

	private:
	  Node *headM;
	  int total_average;
     void destroy(); 
};