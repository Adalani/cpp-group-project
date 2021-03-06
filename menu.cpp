#include <iostream>
#include <iomanip>
#include <mysql.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <cstring>
#include <limits>
#include <fstream>

// Using C library for MySQL
// To compile for MYSQL use these flags:
// g++ menu.cpp -o menu1.out `mysql_config --cflags --libs` --> compiling

using namespace std;

char getCategoryResponse() {

  char response;
	cout << endl << "Pick Category: " << endl
		 << "(B)edroom, (K)itchen, b(A)throom, (L)ivingRoom (O)ffice" << endl
		 << "> ";
	cin >> response;
	cin.ignore(256, '\n');
  cout << string(100, '\n');
  return response;
}
//////////
// MYSQL Error handling function
void finish_with_errors(MYSQL *con) {
  fprintf(stderr, "%s\n", mysql_error(con));
  mysql_close(con);
  exit(1);
}


////////
//Function to choose by Name within chosen category
void choose_name(string itemNAME, string category){
  MYSQL *con = mysql_init(NULL);

  if (con == NULL) {
    fprintf(stderr, "%s\n", mysql_error(con));
    exit(1);
  }


  // Conn to MYSQL follows this syntax: "host", "user", "pass", "database"
  if (mysql_real_connect(con, "localhost", "team", "qwerty", "testdb", 0, NULL, 0) == NULL) {
    finish_with_errors(con);
 }
  cout << "Please enter an Item Name." << endl;
  cin >> itemNAME;
  string sqlString = "SELECT * FROM " +category+ " WHERE itemNAME='" + itemNAME + "';";

  const char *newString = sqlString.c_str();

  cout << string(100, '\n');
  cout << "\033[1;34mResults: \033[0m" << '\n';
  cout << "__________________________________________________" << '\n';
  if (mysql_query(con, newString)) {
    finish_with_errors(con);
 }


  MYSQL_RES *result = mysql_store_result(con);

  int num_fields = mysql_num_fields(result);

  MYSQL_ROW row;

  while ((row = mysql_fetch_row(result))) {
    for (int i = 0; i < num_fields; i++) {
      printf("%-10s | ", row[i] ? row[i] : "NULL" );

    }
    printf("\n" );
  }

    mysql_free_result(result);
    mysql_close(con);
    cout << " " << endl;
}

// //////
//Function to choose by ID number within chosen category
void choose_id (string itemID, string category){
  MYSQL *con = mysql_init(NULL);

  if (con == NULL) {
    fprintf(stderr, "%s\n", mysql_error(con));
    exit(1);
  }


  // Conn to MYSQL follows this syntax: "host", "user", "pass", "database"
  if (mysql_real_connect(con, "localhost", "team", "qwerty", "testdb", 0, NULL, 0) == NULL) {
    finish_with_errors(con);
 }
  cout << "Please enter an Item ID number." << endl;
  cin >> itemID;
  string sqlString = "SELECT * FROM " + category + " WHERE itemID=" + itemID + ";";
  cout << string(100, '\n');
  cout << "\033[1;34mResults\033[0m" << '\n';
  cout << "ID     " << "Item     " << "Price     " <<
  "Stock     " << '\n';
  cout << "---------------------------------------------------------" << '\n';
    const char *newString = sqlString.c_str();

   if (mysql_query(con, newString)) {
    finish_with_errors(con);
 }


  MYSQL_RES *result = mysql_store_result(con);

  int num_fields = mysql_num_fields(result);

  MYSQL_ROW row;

  while ((row = mysql_fetch_row(result))) {
    for (int i = 0; i < num_fields; i++) {
      printf("%-5s  |    ", row[i] ? row[i] : "NULL" );

    }
    printf("\n" );
  }

    mysql_free_result(result);
    mysql_close(con);
    cout << " " << endl;
}


///////////////
// Function to Add Data
void addData() {
  // Connect to mysql
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
 cout << string(100, '\n');
 cout << "Add New Item: " << endl;
 cout << "--------------" << endl;
 cout << "Item Name: " << endl;
 cin >> itemName;

 cin.ignore(256, '\n');
 cout << string(100, '\n');
 cout << "Item Price: " << endl;
 cin >> itemPrice;
 cin.ignore(256, '\n');
 cout << "Item Count: " << endl;
 cin >> itemInv;
 cin.ignore(256, '\n');

  // Add appropriate sql depending on category chosen
  switch (getCategoryResponse()) {
    case 'b': sqlString = "INSERT INTO bedroom (itemID, itemName, itemPrice, itemInv) VALUES(itemId, '" + itemName + "'," + itemPrice + "," + itemInv + ")"; break;
    case 'k': sqlString = "INSERT INTO kitchen (itemID, itemName, itemPrice, itemInv) VALUES(itemId,'" + itemName + "'," + itemPrice + "," + itemInv + ")"; break;
    case 'a': sqlString = "INSERT INTO bathroom (itemID, itemName, itemPrice, itemInv) VALUES(itemId,'" + itemName + "'," + itemPrice + "," + itemInv + ")"; break;
    case 'l': sqlString = "INSERT INTO livingroom (itemID, itemName, itemPrice, itemInv) VALUES(itemId,'" + itemName + "'," + itemPrice + "," + itemInv + ")"; break;
    case 'o': sqlString = "INSERT INTO office (itemID, itemName, itemPrice, itemInv) VALUES(itemId,'" + itemName + "'," + itemPrice + "," + itemInv + ")"; break;
    default : cout << "Make a selection:" << '\n';
  }

    // turn sqlstring into proper data type
    const char *newString = sqlString.c_str();

    // Insert data into database
    if (mysql_query( con, newString )) {
      finish_with_errors(con);
    }

    mysql_close(con);
    cout << string(100, '\n');
    cout << "Item Added Successfully!" << endl << endl;
    cout << string(100, '\n');
  }

// //////////////////////// //
// function to display data //
// //////////////////////// //
void dispData() {
  MYSQL *con = mysql_init(NULL);

  if (con == NULL) {
    fprintf(stderr, "%s\n", mysql_error(con));
    exit(1);
  }

  if (mysql_real_connect(con, "localhost", "team", "qwerty", "testdb", 0, NULL, 0) == NULL) {
    finish_with_errors(con);
 }
  string sqlString;
  string itemID;
  string itemNAME;
  string category;
  char choice;

  cout << "Search by [i]d or by [n]ame." << endl;
  cin >> choice;
  cin.ignore(254, '\n');


switch (choice){
  case 'i': {
    switch (getCategoryResponse()) {
      case 'b': category= "bedroom"; choose_id(itemID, category); break;
      case 'k': category= "kitchen"; choose_id(itemID, category); break;
      case 'a': category= "bathroom"; choose_id(itemID, category); break;
      case 'l': category= "livingroom"; choose_id(itemID, category); break;
      case 'o': category= "office"; choose_id(itemID, category); break;
      default : cout << "Make a selection:" << '\n';
    }; break;
  }
  case 'n': {
    switch (getCategoryResponse()) {
      case 'b': category= "bedroom"; choose_name(itemNAME, category); break;
      case 'k': category= "kitchen"; choose_name(itemNAME, category); break;
      case 'a': category= "bathroom"; choose_name(itemNAME, category); break;
      case 'l': category= "livingroom"; choose_name(itemNAME, category); break;
      case 'o': category= "office"; choose_name(itemNAME, category); break;
      default : cout << "Make a selection:" << '\n';
    }; break;
  }
}
}

/////////////////
//Function to clear text file
void clearFile() {

  std::ofstream myfile;
  myfile.open("orders.txt", ofstream::out | ofstream::trunc);
  myfile.close();
}


/////////////
//Update inventory function.
void updateData() {

  MYSQL *con = mysql_init(NULL);

  if (con == NULL) {
    fprintf(stderr, "%s\n", mysql_error(con));
    exit(1);
  }

  // Conn to MYSQL follows this syntax: "host", "user", "pass", "database"
  if (mysql_real_connect(con, "localhost", "team", "qwerty", "testdb", 0, NULL, 0) == NULL) {
    finish_with_errors(con);
  }


  // Code for Queries
  //
  string sqlString;
  string name;
  string amount;
  char a;
  cout << "(A)dd Inventory, (R)emove Inventory" << '\n';
  cin >> a;

  if (a == 'a') {
    cout << "Item Name: " << '\n';
    cin >> name;
    cin.ignore(256, '\n');
    cout << "How Many to Add?" << '\n';
    cin >> amount;


    switch (getCategoryResponse()) {
      case 'b': sqlString = "UPDATE bedroom SET itemInv = itemInv + " + amount + " WHERE itemName = '" + name + "';"; break;
      case 'k': sqlString = "UPDATE kitchen SET itemInv = itemInv + " + amount + " WHERE itemName = '" + name + "';"; break;
      case 'a': sqlString = "UPDATE bathroom SET itemInv = itemInv + " + amount + " WHERE itemName = '" + name + "';"; break;
      case 'l': sqlString = "UPDATE livingroom SET itemInv = itemInv + " + amount + " WHERE itemName = '" + name + "';"; break;
      case 'o': sqlString = "UPDATE office SET itemInv = itemInv + " + amount + " WHERE itemName = '" + name + "';"; break;
      default: cout << "Pick an Option" << '\n'; break;
    }
  } else if(a == 'r') {

    cout << "Item Name: " << '\n';
    cin >> name;
    cout << string(100, '\n');
    cin.ignore(256, '\n');
    cout << "How many Sold?" << '\n';
    cin >> amount;


    switch (getCategoryResponse()) {
      case 'b': sqlString = "UPDATE bedroom SET itemInv = itemInv - " + amount + " WHERE itemName = '" + name + "';"; break;
      case 'k': sqlString = "UPDATE kitchen SET itemInv = itemInv - " + amount + " WHERE itemName = '" + name + "';"; break;
      case 'a': sqlString = "UPDATE bathroom SET itemInv = itemInv - " + amount + " WHERE itemName = '" + name + "';"; break;
      case 'l': sqlString = "UPDATE livingroom SET itemInv = itemInv - " + amount + " WHERE itemName = '" + name + "';"; break;
      case 'o': sqlString = "UPDATE office SET itemInv = itemInv - " + amount + " WHERE itemName = '" + name + "';"; break;
      default: cout << "Pick an Option" << '\n'; break;
    }
  } else {
    cout << "Pick an Option:" << '\n';
  }
  // Convert string into chars
  const char *newString = sqlString.c_str();

  // Insert data into database
  if (mysql_query( con, newString )) {
    finish_with_errors(con);
  }

  mysql_close(con);
  cout << "\033[1;34mItem Updated!\033[0m" << endl << endl;
}

/////////////////////
// function to search low inventory
void checkInv() {
  cout << string(100, '\n');
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

  // Add appropriate sql depending on category chosen
  switch ( getCategoryResponse() ) {
    case 'b': sqlString = "SELECT * FROM bedroom WHERE itemInv < 5;"; break;
    case 'k': sqlString = "SELECT * FROM kitchen WHERE itemInv < 5;"; break;
    case 'a': sqlString = "SELECT * FROM bathroom WHERE itemInv < 5;"; break;
    case 'l': sqlString = "SELECT * FROM livingroom WHERE itemInv < 5;"; break;
    case 'o': sqlString = "SELECT * FROM office WHERE itemInv < 5;"; break;
    default : cout << "Make a selection:";
  }

  // convert char
  const char *newString = sqlString.c_str();

  cout << "\033[1;31mYou are Low on....\033[0m" << '\n';
  cout << '\n' << "ID          "   << "Item          " << "Price         " <<
  "Stock     " << '\n';
  cout << "-------------------------------------------------------" << '\n';

  if (mysql_query(con, newString)) {
    finish_with_errors(con);
  }

  MYSQL_RES *result = mysql_store_result(con);

  int num_fields = mysql_num_fields(result);

  MYSQL_ROW row;

  // Dump database rows:
  while ((row = mysql_fetch_row(result))) {
    for (int i = 0; i < num_fields; i++) {
      printf("%-10s |  ", row[i] ? row[i] : "NULL" );

    }
    printf("\n" );

  }

  mysql_free_result(result);
  mysql_close(con);
  cout << " " << endl;

  char answer;
  string ans;
  int amount;
  bool run = true;

  do {

    cout << '\n' << "Order More? " << '\n';
    cout << "(Y)es, (N)o, (B)ack to Main" << '\n';
    cin >> answer;
    cin.ignore(256, '\n');

    switch (answer) {
      case 'y': {cout << "Order more of: " << '\n';
                cin >> ans;
                cin.ignore(256, '\n');
                cout << "Quantity? " << '\n';
                cin >> amount;
                cin.ignore(256, '\n');
                cout << "You Have ordered " << amount << " more " << ans << '\n';
                ofstream myfile;
                myfile.open("orders.txt", std::ios::app);
                myfile << ans << " " << amount << '\n';
                myfile.close();} break;
      case 'n': run = false; cout << string(100, '\n'); break;
      case 'b': run = false; cout << string(100, '\n'); break;
      default: cout << "Not valid. Please Make A Choice: " << '\n';
    }
  } while(run);

  // Since we are working with either a blank file or a file with content
  // we can check to see if file is populated or blank.
  // if blank we will skip emailing.
  int count = 0;
  string line;
  ifstream file("orders.txt");

  while (getline(file, line))

      count++;

  if (count > 0) {
    cout << "\033[1;34mSending email to Purchasing Dept....\033[0m" << '\n';
    // system("cat /home/group/github/cpp-group-project/orders.txt | mail -s 'Orders' randall.flagg15@gmail.com");
    system("cat /home/skunky/Documents/college/COMP1100_cpp/project/cpp-group-project/orders.txt | mail -s 'Orders' randall.flagg15@gmail.com");

    cout << "Email Sent!" << '\n' << '\n';
    // Clear File after email sends....
    clearFile();
  }

}

////////////////
// Main menu function
char getMenuResponse() {

  char response;
	cout << endl << "Pick Option: " << endl
		 << "(A)dd Item, (U)pdate Item (S)earch, (I)nventory Check (Q)uit" << endl
		 << "> ";
	cin >> response;
	cin.ignore(256, '\n');
	return toupper(response);

}

/////////////////////////////////////
////////Main Function////////////////
////////////////////////////////////
int main( int argc, char *argv[] ) {
  bool run = true;
  cout << string(100, '\n');
  cout << "######################" << '\n';
  cout << "######################" << '\n';
  cout << "\033[1;31mCNTS GROUP 7 INVENTORY\033[0m" << '\n';
  cout << "###\033[1;31mCONTROL PROGRAM\033[0m####" << '\n';
  cout << "######################" << '\n';
  cout << "#\033[1;33mJoel\033[0m######\033[1;34mSamir\033[0m######" << '\n';
  cout << "######################" << '\n';
  cout << "#\033[1;35mDamon\033[0m#####\033[1;37mThomas\033[0m#####" << '\n';
  cout << "######################" << '\n';
  cout << "######################" << '\n';

  do
  {
    cout << "Inventory Program - " << endl;

  	switch ( getMenuResponse() )
  	{

	    case 'A': addData();break;
      case 'U': updateData(); break;
  		case 'S': dispData(); break;
  		case 'I': checkInv(); break;
  		case 'Q': run = false; break;
  		default : cout << "That is NOT a valid choice" << endl;
  	}
  } while (run);
  cout << endl << "Program Terminated" << endl;
}
