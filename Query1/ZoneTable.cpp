#include "ZoneTable.h"

ZoneTable::ZoneTable(char* zoneCostFile)
	: zoneTableHead{ nullptr } //init. list
{
	std::fstream zoneCostFileStream;
	zoneCostFileStream.open(zoneCostFile);

	if (!zoneCostFileStream) {
		cout << "Zone cost file failed to open.\n";
	}

	int n{ 0 }; //dummy var used to skip first two lines of input file
	string input{ "" }; //stores strings read from input file
	while (std::getline(zoneCostFileStream, input)) {
		if (n < 2) {
			n++;
		}
		else {
			ZoneNode* newNode = new ZoneNode(); //allocate memory for new zone node.
			parseZoneCostFile(newNode, input); //parse fields from input line
			insertZoneRecord(newNode); //insert new record into ZoneRecord table
		}
	}

	zoneCostFileStream.close();
}

ZoneNode* ZoneTable::getZoneHead() {
	return zoneTableHead;
}

//===================
/* Private Methods */
//===================

void ZoneTable::parseZoneCostFile(ZoneNode* newNode, string input) {

	//Range of indexes for each field in the text file are written in comments above the for loops

	//ZONEID: 0 to 5
	string zoneIDTemp{ "" };
	for (int i{ 0 }; i < 6 && input[i] != ' '; i++) {
		zoneIDTemp += input[i];
	}
	if (!zoneIDTemp.empty()) {
		newNode->zoneID = std::stoi(zoneIDTemp);
	}

	//ZONEDESC: 7 to 26
	for (int i{ 7 }; i < 27 && !(input[i] == ' ' && input[i + 1] == ' '); i++) {
		newNode->zoneDescription += std::tolower(input[i]); //std::tolower mitigates upper/lower case mismatch in future comparisons
	}

	//PRICE: 28 to 34
	string priceTemp{ "" };
	for (int i{ 28 }; i < 35 && input[i] != ' '; i++) {
		priceTemp += input[i];
	}
	if (!priceTemp.empty()) {
		newNode->price = std::stof(priceTemp);
	}
}

void ZoneTable::insertZoneRecord(ZoneNode* newNode) {
	if (zoneTableHead == nullptr) { //If head pointer is nullptr
		zoneTableHead = newNode;
	}
	else { //Insert at the end of the list
		ZoneNode* iter{ zoneTableHead };
		while (iter->next) {
			iter = iter->next;
		}
		iter->next = newNode;
	}
}

ZoneTable::~ZoneTable() {
	ZoneNode* temp{ nullptr };
	while (zoneTableHead) {
		temp = zoneTableHead;
		zoneTableHead = zoneTableHead->next;
		delete temp;
	}
}