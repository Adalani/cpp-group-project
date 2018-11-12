#include <iostream>
#include <mysql.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <cstring>
#include <limits>
#include <fstream>

using namespace std;

// Using C library for MySQL
// To compile for MYSQL use these flags:
//  g++ menu.cpp -o menu1.out `mysql_config --cflags --libs`

char getCategoryResponse() {

  char response;
	cout << endl << "Pick Category: " << endl
		 << "(B)edroom, (K)itchen, b(A)throom, (L)ivingRoom (O)ffice" << endl
		 << "> ";
	cin >> response;
	cin.ignore(256, '\n');
  return response;
}

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

 // Add appropriate sql depending on category chosen
 switch (getCategoryResponse()) {
   case 'b': sqlString = "INSERT INTO bedroom (itemID, itemName, itemPrice, itemInv) VALUES(itemId," + itemName + "," + itemPrice + "," + itemInv + ")"; break;
   case 'k': sqlString = "INSERT INTO kitchen (itemID, itemName, itemPrice, itemInv) VALUES(itemId," + itemName + "," + itemPrice + "," + itemInv + ")"; break;
   case 'a': sqlString = "INSERT INTO bathroom (itemID, itemName, itemPrice, itemInv) VALUES(itemId," + itemName + "," + itemPrice + "," + itemInv + ")"; break;
   case 'l': sqlString = "INSERT INTO livingroom (itemID, itemName, itemPrice, itemInv) VALUES(itemId," + itemName + "," + itemPrice + "," + itemInv + ")"; break;
   case 'o': sqlString = "INSERT INTO office (itemID, itemName, itemPrice, itemInv) VALUES(itemId," + itemName + "," + itemPrice + "," + itemInv + ")"; break;
   default : cout << "Make a selection:" << '\n';
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

  // Add appropriate sql depending on category chosen
  switch (getCategoryResponse()) {
    case 'b': sqlString = "SELECT * FROM bedroom;"; break;
    case 'k': sqlString = "SELECT * FROM kitchen;"; break;
    case 'a': sqlString = "SELECT * FROM bathroom;"; break;
    case 'l': sqlString = "SELECT * FROM livingroom;"; break;
    case 'o': sqlString = "SELECT * FROM office;"; break;
    default : cout << "Make a selection:" << '\n';
  }


  // convert char
  const char *newString = sqlString.c_str();

  // Dump database rows:
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


//Function to clear text file
void clearFile() {


  std::ofstream myfile;
  myfile.open("orders.txt", ofstream::out | ofstream::trunc);
  myfile.close();
}

// function to search low inventory
void checkInv() {

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

    cout << "You are Low on...." << '\n';
    // Dump database rows:
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
        case 'n': run = false; break;
        case 'b': run = false; break;
        default: cout << "Please Make A Choice: " << '\n';
      }
    } while(run);

    //Since we are working with either a blank file or a file with content    // we can check to see if file is populated or blank.
    // If blank we will skip emailing.
    int count = 0;
    string line;
    ifstream file("orders.txt");

    while (getline(file, line))

        count++;

    if (count > 0) {
      cout << "Sending email to Purchasing Dept...." << '\n';
      system("cat /home/skunky/Documents/college/COMP1100_cpp/project/cpp-group-project/orders.txt | mail -s 'Items to Be ordered' randall.flagg15@gmail.com");
      cout << "Email Sent!" << '\n' << '\n';
    }

    // Clear file after email.....
    clearFile();

}




// Main menu function
char getMenuResponse() {

  char response;
	cout << endl << "Pick Option: " << endl
		 << "(A)dd Item, (S)earh, (I)nventory Check (Q)uit" << endl
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

    //
  	switch ( getMenuResponse() )
  	{
	    case 'A': addData(); break;
  		case 'S': dispData(); break;
  		case 'I': checkInv(); break;
  		case 'Q': run = false; break;
  		default : cout << "That is NOT a valid choice" << endl;
  	}
  } while (run);
  cout << endl << "Program Terminated" << endl;
}
<<<<<<< HEAD

char getMenuResponse() {

  char response;
	cout << endl << "Pick Category: " << endl
		 << "(A)dd Item, (S)earch, (L)iving Room, b(E)droom, (Q)uit" << endl
		 << "> ";
	cin >> response;
	cin.ignore(256, '\n');
	return toupper(response);

}
=======
>>>>>>> thomas
