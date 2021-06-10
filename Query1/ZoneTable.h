#ifndef ZONETABLE_H
#define ZONETABLE_H
#include <string>
#include <iostream>
#include <fstream>
using std::string; using std::cout; using std::endl;

//a ZoneNode is a single record/entity in the ZoneCost table
struct ZoneNode {
	int zoneID;
	std::string zoneDescription;
	float price;
	ZoneNode* next;

	//Constructor
	ZoneNode()
		: zoneID{ 0 }, zoneDescription{ "" }, price{ 0.0 }, next{ nullptr } {};
};

class ZoneTable {
	private:
		//Pointer to the head of the linked list representing a table of zone records
		ZoneNode* zoneTableHead;

		/* Private Methods */
		//Pre: Associated file stream is opened successfully
		//Post: Data from zonecost file is parsed into ZoneTable object fields
		void parseZoneCostFile(ZoneNode* newNode, string input);

		//Pre: zonecost file has been parsed into a ZoneTable object's fields
		//Post: A ZoneTable object is appended to the linked list representing the ZoneCost table.
		void insertZoneRecord(ZoneNode* newNode);

	public:
		//Constructor:
		ZoneTable(char* zoneCostFile);

		//Pre: none
		//Post: The memory address of the head of the ZoneCostTable list is returned to caller.
		ZoneNode* getZoneHead();

		//Destructor:
		~ZoneTable();

};

#endif