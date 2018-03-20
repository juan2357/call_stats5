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
void Initialize(call_record * & call_DB, int & count, int & size)
{
}

/***********************************************************************************************************************************/
//Name: Is_empty
//Precondition:
//Postcondition:
//Decription: returns true if call_DB is empty
/**********************************************************************************************************************************/

//ONE WAY TO MAKE A FUNCTION INLINE IS TO PUT THE KEYWORD "inline" in from of the
//FUNCTION HEADER AS SHOWN BELOW:
inline bool Is_empty(const int count)
{
	return -1;
}

//ONE WAY TO MAKE A FUNCTION INLINE IS TO PUT THE KEYWORD "inline" in from of the
//FUNCTION HEADER AS SHOWN BELOW:
/**********************************************************************************************************************************/
//Name: Is_full
//Precondition:
//Postcondition:
//Decription: returns true if call_DB is full
/*********************************************************************************************************************************/
inline bool Is_full(const int count, int size)
{
	return -1;
}

/**********************************************************************************************************************************/
//Name: search
//Precondition:
//Postcondition:
//Decription: locates key in call_DB if it is there; otherwise -1 is returned
/*********************************************************************************************************************************/
int Search(const call_record *call_DB, const int count, const string key)
{
	return -1;
}

/*********************************************************************************************************************************/
//Name: Add
//Precondition:
//Postcondition:
//Decription: add key to call_DB; if call_DB is full, double_size is called to increase the size of call_DB.
/********************************************************************************************************************************/
void Add(call_record * &call_DB, int & count, int & size, const string key)
{
}

/********************************************************************************************************************************/
//Name: Remove
//Precondition:
//Postcondition:
//Decription: remove key from call_DB if it is there.
/*******************************************************************************************************************************/
void Remove(call_record *call_DB, int & count, const string key)
{
}

/******************************************************************************************************************************/
//Name: Double_Size
//Precondition:
//Postcondition:
//Decription: doubles the size (capacity) of call_DB
/******************************************************************************************************************************/
void Double_size(call_record * &call_DB, int & count, int & size)
{
}


/******************************************************************************************************************************/
//Name: Process
//Precondition:
//Postcondition:
//Decription: calculate the net cost, tax rate, call tax and total cost for every call record in call_DB.
/*****************************************************************************************************************************/
void Process(call_record *call_DB, const int & count)
{
}


/****************************************************************************************************************************/
//Name: Print
//Precondition:
//Postcondition:
//Decription: prints every field of every call_record in call_DB formatted to the screen.
/***************************************************************************************************************************/
void Print(const call_record *call_DB, int & count)
{
}

/****************************************************************************************************************************/
//Name: Destroy_call_DB
//Precondition:
//Postcondition:
//Decription: de-allocates all memory allocated to call_DB.  This should be the last function to be called before the program
//            is exited.
/***************************************************************************************************************************/
void Destroy_call_DB(call_record * &call_DB)
{
}



int main()
{
	int size = 5; //total amount of memory (cells) allocated for the dynamic array of call records
	int count = 0;
	call_record *call_DB = new call_record[size];

	//put code here to test your funcitons



	Destroy_call_DB(call_DB);
	return 0;
}
