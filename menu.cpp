#include <iostream>
#include <mysql.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <cstring>
#include <limits>
using namespace std;

// MYSQL Error handling function
void finish_with_errors(MYSQL *con) {
  fprintf(stderr, "%s\n", mysql_error(con));
  mysql_close(con);
  exit(1);
}


// Function to Add Data
void addData() {
  MYSQL *con = mysql_init(NULL);

  if (con == NULL) {
    fprintf(stderr, "%s\n", mysql_error(con));
    exit(1);
  }

  if (mysql_real_connect(con, "localhost", "team", "qwerty", "testdb", 0, NULL, 0) == NULL) {
    finish_with_errors(con);
 }
 //
 // if (mysql_query(con, "DROP TABLE IF EXISTS kitchen")) {
 //   finish_with_errors(con);
 // }
 //
 // if (mysql_query(con, "CREATE TABLE kitchen(itemID INT(8), itemName TEXT(32), itemPrice DECIMAL(14,2), itemInv TINYINT(1))")) {
 //   finish_with_errors(con);
 // }

 string itemName;
 string itemPrice;
 string itemInv;

 // Get user input on item
 cout << "Add New Item: " << endl << "Item Name: " << endl;
 cin >> itemName;
 cin.ignore(256, '\n');
 cout << "Item Price: " << endl;
 cin >> itemPrice;
 cin.ignore(256, '\n');
 cout << "Item Count: " << endl;
 cin >> itemInv;
 cin.ignore(256, '\n');

 // MYSQL query
 string sqlString =  "INSERT INTO kitchen (itemID, itemName, itemPrice, itemInv) VALUES(itemId," + itemName + "," + itemPrice + "," + itemInv + ")";

 // turn sqlstring into proper data type
 const char *newString = sqlString.c_str();

 // Insert data into database
 if (mysql_query( con, newString )) {
  finish_with_errors(con);
 }

 mysql_close(con);
 cout << "Item Added Successfully!" << endl;
 // exit(0);

}

// function to display data
void dispData() {
  cout << "Display Data:" << '\n';
}

// function to search data
void searchData() {
  cout << "message" << '\n';
}

// function to switch table
void openTable() {
  cout << "message" << '\n';
}
char getMenuResponse();

void sqlInsert() {
  cout << "Item Category?";
};

int main( int argc, char *argv[] ) {
  bool run = true;
  do
  {
    cout << "Inventory Program - " << endl;

//Add data to database
  	switch ( getMenuResponse() )
  	{
	    case 'A': addData(); break;
  		case 'S': dispData(); break;
  		case 'L': openTable(); break;
  		case 'E': searchData(); break;
  		case 'Q': run = false; break;
  		default : cout << "That is NOT a valid choice" << endl;
  	}
  } while (run);
  cout << endl << "Program Terminated" << endl;
}

char getMenuResponse() {

  char response;
	cout << endl << "Pick Category: " << endl
		 << "(A)dd Item, (S)earh, (L)iving Room, b(E)droom, (Q)uit" << endl
		 << "> ";
	cin >> response;
	cin.ignore(256, '\n');
	return toupper(response);

}
