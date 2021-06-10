#ifndef CUSTOMERTABLE_H
#define CUSTOMERTABLE_H
#include <string>
#include <fstream>
#include <iostream>
using std::string;

//a UserNode is a single record/entity in the Customer table
struct UserNode {
	string userName;
	string passWord;
	string lastName;
	string firstName;
	string address;
	int zone;
	char sex;
	int age;
	int limit;
	float balance;
	long long creditCardNum; //credit card nums stored as int could potentially exceed 2^32 bits causing overflow, so this is a long long
	string emailAddress;
	bool isActive;
	UserNode* next;

	//Constructor for user record
	UserNode() //default
		:userName{ "" }, passWord{ "" }, lastName{ "" }, firstName{ "" }, address{ "" },
		zone{ 0 }, sex{ '0' }, age{ 0 }, limit{ 0 }, balance{ 0.0 }, creditCardNum{ 0 }, emailAddress{ "" }, isActive{ true }, next{ nullptr } {};
};

class CustomerTable {
	private:
		//Head pointer to user table list
		UserNode *customerTableHead;

		//===================
		/* Private Methods */
		//===================
		
		//Pre: customer information file stream was opened successfully
		//Post: each customer entry is parsed into a record of UserNode
		void ParseCustomerFields(UserNode* newNode, string input);

		//Pre: customer file has been parsed into a CustomerTable object's fields
		//Post: A CustomerTable object is appended to the linked list representing the customer table.
		void insertUserRecord(UserNode* newNode);

	public:
		//constructor:
		CustomerTable(char* customerFile);

		//Pre: none
		//Post: The memory address of the head of the linked list representing the customer table is returned
		UserNode* getHeadNode() { return customerTableHead; }

		//destructor:
		~CustomerTable();
};

#endif