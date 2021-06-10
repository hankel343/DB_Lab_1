#include <iostream>
#include <map>
#include "LineItemTable.h"
#include "ProductTable.h"

int main(int argc, char* argv[]) {
	LineItemTable itemTable(argv[1]);
	ProductTable productTable(argv[2]);

	std::multimap<string, string> dictionary; //Multimap allows for duplicate keys with different values (in practice, duplicate barcodes with different usernames)
	ItemNode* itemIter{nullptr};
	ProductNode* prodIter{ productTable.getProductHead() };

	//Building dictionary of <barcode, username> pairs from itemTable and productTable
	while (prodIter != nullptr) {
		itemIter = itemTable.getItemTableHead();
		while (itemIter != nullptr) {
			if (itemIter->BARCODE == prodIter->BARCODE) { //If user's item barcode matches the current product barcode
				dictionary.insert(std::pair<string, string> (prodIter->BARCODE, itemIter->uname)); //Insert a pair associating a barcode with a username
			}
			itemIter = itemIter->next;
		}
		prodIter = prodIter->next;
	}
	
	prodIter = productTable.getProductHead(); //Iterate through each record in the product table and count how many unique <barcode, username> entries there are
	while (prodIter != nullptr) {
		if (dictionary.count(prodIter->BARCODE) >= 2) { //If count of unique <barcode, username> pairs is greater than or equal to 2, print output
			cout << prodIter->BARCODE << "\t" << prodIter->PRODDESC << endl;
		}
		prodIter = prodIter->next;
	}
	return 0;
}