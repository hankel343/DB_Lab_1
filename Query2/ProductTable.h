#ifndef PRODUCTTABLE_H
#define PRODUCTTABLE_H
#include <iostream>
#include <string>
#include <fstream>
using std::string; using std::cout; using std::endl; using std::fstream;

struct ProductNode {
	string BARCODE;
	float PRICE;
	string PRODDESC;
	string MFG;
	string SUPPLIER;
	string TAXABLE;
	string CATEGORY;
	float SALE_PERCENT;
	ProductNode* next;
	
	//Node constructor
	ProductNode()
		: BARCODE{ "" }, PRICE{ 0.0 }, PRODDESC{ "" }, MFG{ "" }, SUPPLIER{ "" }, TAXABLE{ "" }, CATEGORY{ "" },
		SALE_PERCENT{ 0.0 }, next{ nullptr } {};
};

class ProductTable {
	private:
		//Pointer to head of the linked list
		ProductNode* ProductTableHead;

		/* Private Methods */
		//Pre: File stream to product file has opened successfully
		//Post: Information in the product file has been parsed into a Product record
		void ParseProductFile(string readLine, ProductNode* newNode);
		
		//Pre: Memory has been allocated for a ProductNode record
		//Post: A new product record is inserted in the ProductTable linked list
		void InsertRecord(ProductNode* newNode);

	public:
		//Constructor
		ProductTable(char* fileName);
		
		//Pre: none
		//Post: Memory address of the head of the Product table is returned.
		ProductNode* getProductHead() { return ProductTableHead; }

		//Destructor
		~ProductTable();
};

#endif