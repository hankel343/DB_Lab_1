/*	Hankel Haldin
*	Databases
*	Lab 1 Query 1
*	Due: 6/11/2021
*	Desc: List all the last names (LNAME) of the active customers that live in Toronto. */

#include <iostream>
#include <fstream>
#include "CustomerTable.h"
#include "ZoneTable.h"
using std::cout; using std::endl;

//Takes two character string args. from command-line
//args. should be file names.
int main(int argc, char* argv[]) {

	//CustomerTable and ZoneTable are linked lists representing tables of data
	CustomerTable customers(argv[1]);
	ZoneTable zoneCost(argv[2]);

	//Declaring iterators to compare data in each table
	UserNode* custIter{ customers.getHeadNode() };
	ZoneNode* zoneIter{ zoneCost.getZoneHead() };
	
	while (custIter) {
		zoneIter = zoneCost.getZoneHead(); //Scans through zoneCost for each record in customer table
		while (zoneIter && custIter->zone == 1 && custIter->isActive) { //Customer zone is 1 (toronto) and is active
			if (zoneIter->zoneID == 1 && zoneIter->zoneDescription == "toronto") { //Zone id is 1 and description is toronto
				cout << custIter->lastName << endl;
			}
			zoneIter = zoneIter->next;
		}
		custIter = custIter->next;
	}

	return 0;
}