#include "CustomerTable.h"

CustomerTable::CustomerTable(char* customerFile)
	: customerTableHead{ nullptr } //init. list
{
	std::fstream customerInput;
	customerInput.open(customerFile);

	if (!customerInput) {
		std::cout << "Customer information file failed to open.\n";
	}

	int n{ 0 }; //counts line skips to remove first two lines of heading info.
	string input{ "" };
	while (std::getline(customerInput, input)) {
		if (n < 2) {
			n++;
		}
		else {
			UserNode* newNode = new UserNode; //allocate memory for new user entity
			ParseCustomerFields(newNode, input); //populate entity attributes
			insertUserRecord(newNode); //insert new entity into appropriate table
		}
	}
	customerInput.close();
}

void CustomerTable::ParseCustomerFields(UserNode* newNode, string input) {
	//UNAME: indexes from 0 - 19
	for (int i{ 0 }; i < 20 && input[i] != ' '; i++) {
		newNode->userName += input[i];
	}

	//PASSWD: 21 - 40
	for (int i{ 21 }; i < 41 && input[i] != ' '; i++) {
		newNode->passWord += input[i];
	}

	//LNAME: 42 to 61
	for (int i{ 42 }; i < 62 && input[i] != ' '; i++) {
		newNode->lastName += input[i];
	}

	//FNAME: 63 to 82
	for (int i{ 63 }; i < 83 && input[i] != ' '; i++) {
		newNode->firstName += input[i];
	}

	//ADDR: 84 to 133
	for (int i{ 84 }; i < 134 && !(input[i] == ' ' && input[i + 1] == ' '); i++) {
		newNode->address += input[i];
	}

	//ZONE: 135 to 140
	string zoneTemp{ "" };
	for (int i{ 135 }; i < 141 && input[i] != ' '; i++) {
		zoneTemp += input[i];
	}
	if (!zoneTemp.empty()) {
		newNode->zone = std::stoi(zoneTemp);
	}

	//SEX: 142 to 144
	for (int i{ 142 }; i < 145 && input[i] != ' '; i++) {
		newNode->sex = std::tolower(input[i]);
	}

	//AGE: 146 to 151
	string ageTemp{ "" };
	for (int i{ 146 }; i < 152 && input[i] != ' '; i++) {
		ageTemp += input[i]; //Convert ASCII char to int value
	}
	newNode->age = std::stoi(ageTemp);

	//LIMIT: 153 to 158
	string limitTemp{ "" };
	for (int i{ 153 }; i < 159 && input[i] != ' '; i++) {
		limitTemp += input[i];
	}
	newNode->limit = std::stoi(limitTemp);

	//BALANCE: 160 to 169
	string balanceTemp{ "" }; //For converting string to float value
	for (int i{ 160 }; i < 169 && input[i] != ' '; i++) {
		balanceTemp += input[i];
	}
	if (!balanceTemp.empty()) {
		newNode->balance = std::stof(balanceTemp);
	}

	//CREDITCARD: 171 to 190
	string creditTemp{ "" };
	for (int i{ 171 }; i < 191 && input[i] != ' '; i++) {
		creditTemp += input[i];
	}
	if (!creditTemp.empty()) { //Converting an empty string to an integer is undefined behavior for std::stoi
		newNode->creditCardNum = std::stoll(creditTemp);
	}

	//EMAIL: 192 to 241
	for (int i{ 192 }; i < 242 && input[i] != ' '; i++) {
		newNode->emailAddress += input[i];
	}

	//ACTIVE: 243 to 248
	for (int i{ 243 }; i <= 248 && input[i] != ' '; i++) {
		newNode->isActive = input[i] - 48;
	}
}

void CustomerTable::insertUserRecord(UserNode* newNode) {
	if (customerTableHead == nullptr) { //If the node to be inserted is the first node in the list
		customerTableHead = newNode;
	}
	else { //Inserting new node at the end of the linked list
		UserNode* iter{ customerTableHead };
		while (iter->next) {
			iter = iter->next;
		}
		iter->next = newNode;
	}
}

CustomerTable::~CustomerTable() {
	UserNode* temp{nullptr};
	while (customerTableHead) {
		temp = customerTableHead;
		customerTableHead = customerTableHead->next;
		delete temp;
	}
}