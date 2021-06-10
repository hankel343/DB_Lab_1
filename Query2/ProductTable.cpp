#include "ProductTable.h"

ProductTable::ProductTable(char* fileName)
	:ProductTableHead{ nullptr }
{
	fstream inputFileStream;
	inputFileStream.open(fileName);

	if (!inputFileStream) {
		cout << fileName << " failed to open.\n";
	}

	int n{ 0 }; //Used to skip lines in input file
	string readLine{ "" }; //Stores lines read from product file
	while (std::getline(inputFileStream, readLine)) {
		if (n < 2) {
			n++;
		} else {
			ProductNode* newNode = new ProductNode;
			ParseProductFile(readLine, newNode);
			InsertRecord(newNode);
		}
	}
}

void ProductTable::ParseProductFile(string readLine, ProductNode* newNode) {
	//barcode: 0 to 19
	for (int i{ 0 }; i < 20; i++) {
		newNode->BARCODE += readLine[i];
	}

	//price: 21 to 30
	string priceTemp{ "" };
	for (int i{ 21 }; i < 31; i++) {
		priceTemp += readLine[i];
	}
	if (!priceTemp.empty()) {
		newNode->PRICE = std::stof(priceTemp);
	}

	//Proddesc: 32 to 81
	for (int i{ 32 }; i < 82; i++) {
		newNode->PRODDESC += readLine[i];
	}

	//mfg 83 to 102
	for (int i{ 83 }; i < 103; i++) {
		newNode->MFG += readLine[i];
	}

	//supplier: 104 to 123
	for (int i{ 104 }; i < 124; i++) {
		newNode->SUPPLIER += readLine[i];
	}

	//taxable: 125 to 131
	for (int i{ 125 }; i < 132; i++) {
		newNode->TAXABLE += readLine[i];
	}

	//category: 133 to 152
	for (int i{ 133 }; i < 153; i++) {
		newNode->CATEGORY += readLine[i];
	}

	//sale_percent: 154 to 165
	string percentTemp{ "" };
	for (int i{ 154 }; i < 166; i++) {
		percentTemp += readLine[i];
	}
	if (!percentTemp.empty()) {
		newNode->SALE_PERCENT = std::stof(percentTemp);
	}
}

void ProductTable::InsertRecord(ProductNode* newNode) {
	if (ProductTableHead == nullptr) {
		ProductTableHead = newNode;
	} else {
		ProductNode* iter{ ProductTableHead };
		while (iter->next != nullptr) {
			iter = iter->next;
		}
		iter->next = newNode;
	}
}

ProductTable::~ProductTable() {
	ProductNode* temp{ ProductTableHead };
	while (ProductTableHead) {
		temp = ProductTableHead;
		ProductTableHead = ProductTableHead->next;
		delete temp;
	}
}