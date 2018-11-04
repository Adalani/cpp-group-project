#include <iostream>
#include <mysql.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <cstring>
#include <limits>
using namespace std;

// To compile for MYSQL use these flags:
//  g++ menu.cpp -o menu1.out `mysql_config --cflags --libs`


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


  // Conn to MYSQL follows this syntax: "host", "user", "pass", "database"
  if (mysql_real_connect(con, "localhost", "team", "qwerty", "testdb", 0, NULL, 0) == NULL) {
    finish_with_errors(con);
 }

 string itemName;
 string itemPrice;
 string itemInv;
 string sqlString;

 cout << "Add New Item: " << endl << "Item Name: " << endl;
 cin >> itemName;
 cin.ignore(256, '\n');
 cout << "Item Price: " << endl;
 cin >> itemPrice;
 cin.ignore(256, '\n');
 cout << "Item Count: " << endl;
 cin >> itemInv;
 cin.ignore(256, '\n');
 char cat;
 cout << "Which Category? " << endl <<
     "(B)edroom, (K)itchen, b(A)throom, (L)ivingRoom" << endl;

 cin >> cat;
 cin.ignore(256, '\n');


 // Add appropriate sql depending on category chosen
 switch (cat) {
   case 'b': sqlString = "INSERT INTO bedroom (itemID, itemName, itemPrice, itemInv) VALUES(itemId," + itemName + "," + itemPrice + "," + itemInv + ")"; break;
   case 'k': sqlString = "INSERT INTO kitchen (itemID, itemName, itemPrice, itemInv) VALUES(itemId," + itemName + "," + itemPrice + "," + itemInv + ")"; break;
   case 'a': sqlString = "INSERT INTO bathroom (itemID, itemName, itemPrice, itemInv) VALUES(itemId," + itemName + "," + itemPrice + "," + itemInv + ")"; break;
   case 'l': sqlString = "INSERT INTO livingroom (itemID, itemName, itemPrice, itemInv) VALUES(itemId," + itemName + "," + itemPrice + "," + itemInv + ")"; break;
   default : cout << "Make a selection:";
 }

 // turn sqlstring into proper data type
 const char *newString = sqlString.c_str();

 // Insert data into database
 if (mysql_query( con, newString )) {
  finish_with_errors(con);
 }

 mysql_close(con);
 cout << "Item Added Successfully!" << endl << endl;

}
//
// function to display data
// //////////////////////
void dispData() {
  MYSQL *con = mysql_init(NULL);

  if (con == NULL) {
    fprintf(stderr, "%s\n", mysql_error(con));
    exit(1);
  }

  if (mysql_real_connect(con, "localhost", "team", "qwerty", "testdb", 0, NULL, 0) == NULL) {
    finish_with_errors(con);
 }

 // Code to ask user a Category
  string sqlString;
  char choice;
  cout << "Which Category? " << endl <<
      "(B)edroom, (K)itchen, b(A)throom, (L)ivingRoom" << endl;

  cin >> choice;

  // Add appropriate sql depending on category chosen
  switch (choice) {
    case 'b': sqlString = "SELECT * FROM bedroom;"; break;
    case 'k': sqlString = "SELECT * FROM kitchen;"; break;
    case 'a': sqlString = "SELECT * FROM bathroom;"; break;
    case 'l': sqlString = "SELECT * FROM livingroom;"; break;
    default : cout << "Make a selection:";
  }
 // Code to ask user a Category

  // convert char
  const char *newString = sqlString.c_str();

  // Dumo database rows:
  if (mysql_query(con, newString)) {
    finish_with_errors(con);
 }

  MYSQL_RES *result = mysql_store_result(con);

  int num_fields = mysql_num_fields(result);

  MYSQL_ROW row;

  while ((row = mysql_fetch_row(result))) {
    for (int i = 0; i < num_fields; i++) {
      printf("%s ", row[i] ? row[i] : "NULL" );

    }
    printf("\n" );
  }

    mysql_free_result(result);
    mysql_close(con);
    cout << " " << endl;
}

// function to search data
void searchData() {
  // code //
}

// function to switch table
void openTable() {
  cout << "message" << '\n';
}

void sqlInsert() {
  cout << "Item Category?";
};

// menu function
char getMenuResponse() {

  char response;
	cout << endl << "Pick Category: " << endl
		 << "(A)dd Item, (S)earh, (C)hange Category, (Q)uit" << endl
		 << "> ";
	cin >> response;
	cin.ignore(256, '\n');
	return toupper(response);

}


int main( int argc, char *argv[] ) {
  bool run = true;
  do
  {
    cout << "Inventory Program - " << endl;

    //
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
