/*

Name: Juan Perez   Z#:23026404
Course: COP 3014
Professor: Dr. Lofton Bullard
Due Date: 3/20/18     Due Time: 11:59
Total Points: 20
Assignment 8: call_stats5.cpp

Description
1. Read the contents of a data file one record at a time in a dynamic array;
2. Process the data that was read from the data file one record at a time, into
a dynamic array;
3. Print the records in a dynamic array to a datafile using an ofstream
object;
4. Use the operator new to allocate memory for a dynamic array;
5. Use the operator delete to de-allocate the memory allocated by the new;
(basically, making previously used memory available for use again) 6. Copy the content of one dynamic array into another dynamic array
(basically, copying memory from one location to another)
4. Be able to use the fstream library;
5. Be able to use a dynamic array of record records;
6. Be able to use an ifstream object;
7. Be able to use an ofstream object;
*/

#include <iostream>
using namespace std;


class call_record
{
public:
	string firstname;
	string lastname;
	string cell_number;
	int relays;
	int call_length;
	double net_cost;
	double tax_rate;
	double call_tax;
	double total_cost;
};


void Initialize(call_record *& call_DB, int & count, int & size);
bool Is_empty(const int count); //inline implementation
bool Is_full(const int count, int size);//inline implementation
int Search(const call_record *call_DB, const int count, const string key);//returns location if item in listl; otherwise return -1
void Add(call_record * &call_DB, int & count, int & size, const string key); //adds item inorder to the list
void Remove(call_record *call_DB, int & count, const string key); //removes an item from the list
void Double_size(call_record * &call_DB, int & count, int & size);
void Process(call_record *call_DB, const int & count);
void Print(const call_record *call_DB, int & count); //prints all the elements in the list to the screen
void Destroy_call_DB(call_record * &call_DB); //de-allocates all memory allocate to call_DB by operator new.



/************************************************************************************************************************************/
//Name: Initialize
//Precondition:
//Postcondition:
//Decription: Reads the data file of call information (cell number, relays and call length) into the dynamic array of call record,
//call_DB. If the count because equal to the size the function double_size is called and the memory allocated to call_DB is doubled.
/************************************************************************************************************************************/
void Initialize(call_record * & call_DB, int & count, int & size) {
	ifstream in; //input file stream object declaration
	in.open("callstats_data.txt"); //bind the file "call_data.txt" to the input
	count = 0;  //remember to initialize count before the first come
	if (in.fail()) //if file not found print message and exit program
	{
		cout << "Input file did not open correctly" << endl;
		exit(1);
	}
	//Remember to use a while loop when reading from a file because
	//you do not know how many records you will be reading.
	while (!in.eof()) {
		if (Is_full(count, size)) {
			Double_Size(call_DB, count, size);
		}
		in >> call_DB[count].firstname;
		in >> call_DB[count].lastname;
		in >> call_DB[count].cell_number;
		in >> call_DB[count].relays;
		in >> call_DB[count].call_length;
		count++;
	}
	in.close();//file stream "in" closes.
}

/***********************************************************************************************************************************/
//Name: Is_empty
//Precondition:
//Postcondition:
//Decription: returns true if call_DB is empty
/**********************************************************************************************************************************/

//ONE WAY TO MAKE A FUNCTION INLINE IS TO PUT THE KEYWORD "inline" in from of the
//FUNCTION HEADER AS SHOWN BELOW:
inline bool Is_empty(const int count) {
	if (count == 0){
		return 0;
	} else {
		return -1;
	}
}

//ONE WAY TO MAKE A FUNCTION INLINE IS TO PUT THE KEYWORD "inline" in from of the
//FUNCTION HEADER AS SHOWN BELOW:
/**********************************************************************************************************************************/
//Name: Is_full
//Precondition:
//Postcondition:
//Decription: returns true if call_DB is full
/*********************************************************************************************************************************/
inline bool Is_full(const int count, int size) {
	if (count == size){
		return 0;
	} else {
		return -1;
	}
}

/**********************************************************************************************************************************/
//Name: search
//Precondition:
//Postcondition:
//Decription: locates key in call_DB if it is there; otherwise -1 is returned
/*********************************************************************************************************************************/
int Search(const call_record *call_DB, const int count, const string key) {
	for (int i = 0; i < count; i++){
		if (call_DB[i].cell_number == key) {
			return i;
		} else {
			return -1;
		}
	}
}

/*********************************************************************************************************************************/
//Name: Add
//Precondition:
//Postcondition:
//Decription: add key to call_DB; if call_DB is full, double_size is called to increase the size of call_DB.
/********************************************************************************************************************************/
void Add(call_record * &call_DB, int & count, int & size, const string key) {
int index = count;
if (Is_full(count, size)) {
	Double_size(call_DB, count, size);
	call_DB[index].cell_number = key;
	std::cout << "Enter First Name" << '\n';
	std::cin >> call_DB[index].firstname;
	std::cout << "Enter Last Name" << '\n';
	std::cin >> call_DB[index].lastname;
	std::cout << "Enter number of Relays" << '\n';
	std::cin >> call_DB[index].relays;
	std::cout << "Enter Call Length" << '\n';
	std::cin >> call_DB[index].call_length;
	count++;
}

}

/********************************************************************************************************************************/
//Name: Remove
//Precondition:
//Postcondition:
//Decription: remove key from call_DB if it is there.
/*******************************************************************************************************************************/
void Remove(call_record *call_DB, int & count, const string key) {
	if (Is_empty(count) == 0) {
		return;
	}
	int location = Search(call_DB, count, size);
	if (location == -1) {
		std::cout << "Location" << location << '\n';
		return;
	} else if (location != -1){
		for (int j = location; j < count - 1; j++) {
			call_DB[j] = call_DB[j+1];
		}
		count = count - 1;
	}
}

/******************************************************************************************************************************/
//Name: Double_Size
//Precondition:
//Postcondition:
//Decription: doubles the size (capacity) of call_DB
/******************************************************************************************************************************/
void Double_size(call_record * &call_DB, int & count, int & size) {
	size *= 2;
	call_record * temp = new call_record[size];
	for (int i = 0; i < count; i++) {
		temp[i] = call_DB[i];
	}
	std::cout << "Size: " << size << '\n';
	delete[] call_DB;
	call_DB = temp;
}


/******************************************************************************************************************************/
//Name: Process
//Precondition:
//Postcondition:
//Decription: calculate the net cost, tax rate, call tax and total cost for every call record in call_DB.
/*****************************************************************************************************************************/
void Process(call_record *call_DB, const int & count) {
	//Remember to use a "for" loop when you know how many items
	//you will be processing.  Use the dot operator when you are
	//accessing fields in a record.  For example, when we need
	//to access the relay field in the first record in the array use
	//call_DB[0].relay
	for (int i = 0; i < count; i++)
	{
		call_DB[i].net_cost = call_DB[i].relays / 50.0 * .40 * call_DB[i].call_length;
		call_DB[i].call_tax = call_DB[i].net_cost * call_DB[i].tax_rate;
		call_DB[i].total_cost = call_DB[i].net_cost + call_DB[i].call_tax;
		//Conditional statements to determine tax rates
		if (call_DB[i].relays <= 0 && call_DB[i].relays <=5) {
			call_DB[i].tax_rate = 0.01;
		} else if (call_DB[i].relays <= 6 && call_DB[i].relays <=11) {
			call_DB[i].tax_rate = 0.03;
		} else if (call_DB[i].relays <= 12 && call_DB[i].relays <=20) {
			call_DB[i].tax_rate = 0.05;
		} else if (call_DB[i].relays <= 21 && call_DB[i].relays <=50) {
			call_DB[i].tax_rate = 0.08;
		} else {
			call_DB[i].tax_rate = 0.12;
		}
	}
}


/****************************************************************************************************************************/
//Name: Print
//Precondition:
//Postcondition:
//Decription: prints every field of every call_record in call_DB formatted to the screen.
/***************************************************************************************************************************/
void Print(const call_record *call_DB, int & count) {
	ofstream out; //declare the output file stream "out".

	out.open("weekly4_call_info.txt");//bind the file "weekly4_call_info.txt" to
	                       //to the output file stream "out".
	//Magic Formula
	out.setf(ios::showpoint);
 	out.precision(2);
 	out.setf(ios::fixed);

	if (out.fail()) // if problem opening file, print message and exit program
	{
		cout << "Output file did not open correctly" << endl;
		exit(1);
	}
  // use a "for" loop here to
	// print the output to file
	for (int i = 0; i < count; i++) {
		out<< std::left << setw(30)<< "First Name " <<call_DB[i].firstname<<"  "<<endl;
		out<< std::left << setw(30)<< "Last Name " <<call_DB[i].lastname<<"  "<<endl;
		out<< std::left << setw(30)<< "Cell Phone " <<call_DB[i].cell_number<<"  "<<endl;
		out<< std::left << setw(30)<< "Number of Relay Stations " <<call_DB[i].relays<<"   "<<endl;
		out<< std::left << setw(30)<< "Minutes Used " <<call_DB[i].call_length<<endl;
	  out<< std::left << setw(30)<< "Net Cost " <<call_DB[i].net_cost<<endl;
	  out<< std::left << setw(30)<< "Tax Rate " <<call_DB[i].tax_rate<<endl;
	  out<< std::left << setw(30)<< "Call Tax " <<call_DB[i].call_tax<<endl;
	  out<< std::left << setw(30)<< "Total Cost of Call " <<call_DB[i].total_cost<<endl<<endl;
	}
	out.close();
}

/****************************************************************************************************************************/
//Name: Destroy_call_DB
//Precondition:
//Postcondition:
//Decription: de-allocates all memory allocated to call_DB.  This should be the last function to be called before the program
//            is exited.
/***************************************************************************************************************************/
void Destroy_call_DB(call_record * &call_DB) {
	delete[] call_DB;
}



int main()
{
	int size = 5; //total amount of memory (cells) allocated for the dynamic array of call records
	int count = 0;
	call_record *call_DB = new call_record[size];

	//put code here to test your funcitons
	Initialize(call_DB, count, size);
	Is_empty(count); //inline implementation
	Is_full(count, size);//inline implementation
	Search(call_DB, count, key);//returns location if item in listl; otherwise return -1
  Add(call_DB, count, size, key); //adds item inorder to the list
  Remove(call_DB, count, key); //removes an item from the list
  Double_size(call_DB, count, size);
  Process(call_DB, count);
  Print(call_DB, count); //prints all the elements in the list to the screen
  Destroy_call_DB(call_DB); //de-allocates all memory allocate to call_DB by operator new.

	return 0;
}
