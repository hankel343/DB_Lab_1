#ifndef LINEITEMTABLE_H
#define LINEITEMTABLE_H
#include <string>
#include <iostream>
#include <fstream>
using std::string; using std::fstream; using std::cout; using std::endl;
struct ItemNode {
	string uname;
	string date;
	string time;
	string BARCODE;
	int quantity;
	float price;
	ItemNode* next;

	//Node constructor
	ItemNode()
		: uname{ "" }, date{ "" }, time{ "" }, BARCODE{ "" }, quantity{ 0 }, price{ 0.0 }, next{ nullptr } {};
};

class LineItemTable {
	private:
		//Pointer to head of linked list
		ItemNode* LineItemHead;

		/* Private Methods */
		//Pre: File stream to lineitem file was opened successfully
		//Post: Information in the lineitem file has been parsed into fields of ItemNode record
		void ParseLineItemFile(string readLine, ItemNode* newNode);
		
		//Pre: Memory has been allocated for a ItemNode record
		//Post: ItemNode record has been inserted into the LineItemTable.
		void InsertRecord(ItemNode* newNode);

	public:
		//constructor
		LineItemTable(char* fileName);

		//Pre: none
		//Post: Memory address of head node of the LineItemTable record is returned
		ItemNode* getItemTableHead() { return LineItemHead; }

		//destructor
		~LineItemTable();
};

#endif 