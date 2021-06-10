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

	//constructor
	ItemNode()
		: uname{ "" }, date{ "" }, time{ "" }, BARCODE{ "" }, quantity{ 0 }, price{ 0.0 }, next{ nullptr } {};
};

class LineItemTable {
	private:
		//Pointer to head of linked list
		ItemNode* LineItemHead;

		/* Private Methods */
		void ParseLineItemFile(string readLine, ItemNode* newNode);
		void InsertRecord(ItemNode* newNode);

	public:
		//constructor
		LineItemTable(char* fileName);

		ItemNode* getItemTableHead() { return LineItemHead; }

		//destructor
		~LineItemTable();
};

#endif 