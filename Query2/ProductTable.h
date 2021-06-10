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

	ProductNode()
		: BARCODE{ "" }, PRICE{ 0.0 }, PRODDESC{ "" }, MFG{ "" }, SUPPLIER{ "" }, TAXABLE{ "" }, CATEGORY{ "" },
		SALE_PERCENT{ 0.0 }, next{ nullptr } {};
};

class ProductTable {
	private:
		ProductNode* ProductTableHead;

		/* Private Methods */
		void ParseProductFile(string readLine, ProductNode* newNode);
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