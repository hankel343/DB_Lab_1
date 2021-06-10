#include "LineItemTable.h"

LineItemTable::LineItemTable(char* fileName)
	:LineItemHead{ nullptr }
{
	fstream inputFile;
	inputFile.open(fileName);

	if (!inputFile) {
		cout << fileName << " failed to open.\n";
	}

	int n{ 0 }; //used for skipping first two lines of input
	string input{ "" };
	while (std::getline(inputFile, input)) {
		if (n < 2) {
			n++;
		} else {
			ItemNode* newNode = new ItemNode;
			ParseLineItemFile(input, newNode);
			InsertRecord(newNode);
		}
	}
}

void LineItemTable::ParseLineItemFile(string readLine, ItemNode* newNode) {
	//UNAME: 0 to 19
	for (int i{ 0 }; i < 20; i++) {
		newNode->uname += readLine[i];
	}

	//DATE: 21 to 30
	for (int i{ 21 }; i < 31; i++) {
		newNode->date += readLine[i];
	}

	//TIME: 32 to 39
	for (int i{ 32 }; i < 40; i++) {
		newNode->time += readLine[i];
	}

	//BARCODE: 41 to 60
	for (int i{ 41 }; i < 61; i++) {
		newNode->BARCODE += readLine[i];
	}

	//QUANTITY: 62 to 69
	string quantityTemp{ "" };
	for (int i{ 62 }; i < 70; i++) {
		quantityTemp += readLine[i];
	}
	if (!quantityTemp.empty()) {
		newNode->quantity = std::stoi(quantityTemp);
	}

	//PRICE: 71 to 79
	string priceTemp{ "" };
	for (int i{ 71 }; i < 80; i++) {
		priceTemp += readLine[i];
	}
	if (!priceTemp.empty()) {
		newNode->price = std::stof(priceTemp);
	}
}

void LineItemTable::InsertRecord(ItemNode* newNode) {
	if (LineItemHead == nullptr) { //if list was empty to begin with
		LineItemHead = newNode;
	} else {
		ItemNode* iter{ LineItemHead };
		while (iter->next != nullptr) { //travel to end of linked list
			iter = iter->next;
		}
		iter->next = newNode; //Insert node at end of linked list
	}
}

LineItemTable::~LineItemTable() {
	ItemNode* temp{ nullptr };
	while (LineItemHead) {
		temp = LineItemHead;
		LineItemHead = LineItemHead->next;
		delete temp;
	}
}