//---------------------------------------------------------------------------------------------------------------
//	Learning Team B: Theater Seating Program
//	Week 5
//	PRG/410: C++ Programming I
//	October 24, 2016
//	Marcia L. Allen, Michael Aust, Pharaoh Hurt, Keith Truesdell
//---------------------------------------------------------------------------------------------------------------
// As a culminating activity for Week Five, the Learning Team will be writing the following program
// that can be used by a small theater to sell tickets for performances. The theater's auditorium has
// 10 rows of seats with 9 seats in each row. The program should display a screen that shows which seats are 
// available and which are taken. The screen will show a chart depicting each seat in the theater.
// Seats that are taken are represented by an * symbol, and seats that are available are represented by a # symbol.
// Every time a ticket or group of tickets is purchased, the program should display the total ticket prices and 
// update the seating chart. The program should keep a total of all ticket sales.
// The program should also give the user an option to see a list of how many seats have been sold,
// how many seats are available in each row, and how many seats are available in the entire auditorium.
//---------------------------------------------------------------------------------------------------------------

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <istream>
#include <fstream>
using namespace std;

// Intialize variables
const int numberOfRow = 10;
const int numberOfCol = 9;

//ticket price by row
double price;

// Call function that displays the intialized theater seating chart screen
void print(char matrix[][9], int numberOfRow, int numberOfCol);

//Call function that stores the cost of seats per each row
void ticketPrice(int *row, double *price);

//Call function to validate number within range
int validateWithinRange(int userInput, int leastVal, int maxVal);

//Call function to validate user input is a number
int validateNumber(char userInput);

int _tmain(int argc, _TCHAR* argv[]) {

	// Intialize variables
	char matrix[numberOfRow][numberOfCol], seat[numberOfRow][numberOfCol];
	char option;
	int i, j;
	char rowUI, colUI;
	int row, col;
	int rowselect;
	int ticketsold = 0;
	bool another = true;
	double totalticketsale = 0.00;

	// Initializes all of the seats to available (*)
	for (i = 0; i < numberOfRow; i++) {
		for (j = 0; j < numberOfCol; j++) {
			matrix[i][j] = '*';
		}
	}

	while (another) {
		//display seat matrix
		print(matrix, numberOfRow, numberOfCol);

		// Display Menu selections
		cout << "\nTicket Sales Menu:\n\n";
		cout << "1)  Purchase Ticket\n";
		cout << "2)  Total Ticket Sales\n";
		cout << "3)  List Sales Report\n";
		cout << "4)  Exit\n\n";
		cout << "=========================\n";
		cout << "Enter Menu Choice: ";
		cin >> option;
		cout << endl << endl;

		//is user input a valid number?
		int valNum = validateNumber(option);
		if (valNum != 1) {
			//user did not enter valid number - prompt for re-entry
			cout << "You did not enter a valid number for a menu selection.  Please reenter.\n";
		}
		else {
			//convert user input to integer
			int optionInt;
			optionInt = option - '0';

			//is user input within the range?
			int valRange = validateWithinRange(optionInt, 1, 4);

			if (valRange != 1) {
				//user value not within range
				cout << "Your menu selection is not one of the given.  Please select again.\n";
			}
			else {
				switch (option) {
					// Loop changes the available seat (*) chosen to unavailable seat (#) or indicates that the seat is not available
				case '1': {
					//get user input for row and seat number
					cout << "Enter row: ";
					cin >> rowUI;
					cout << "\nEnter seat: ";
					cin >> colUI;
					cout << "\n";

					//validate user entry
					int valRow, valRowRange, valCol, valColRange;
					valRow = validateNumber(rowUI);
					valCol = validateNumber(colUI);

					//break out of menu selection (switch-case) if not valid number
					if (valRow != 1) {
						//
						cout << "Please select a valid number for the row.\n";
						break;
					}
					
					//break out of menu selection (switch-case) if not valid number
					if (valCol != 1) {
						//
						cout << "Please select a valid number for the column.\n";
						break;
					}

					//convert user input of row and column as char to int
					row = rowUI - '0';
					col = colUI - '0';

					//determine if row and column are within range
					valRowRange = validateWithinRange(row, 1, 10);
					valColRange = validateWithinRange(col, 1, 9);

					//break out of menu selection (switch-case) if not within range
					if (valRowRange != 1){
						//
						cout << "Row Selection not within the range of rows.  Please reselect.\n";
						break;
					}

					//break out of menu selection (switch-case) if not within range
					if (valColRange != 1) {
						//
						cout << "Column Selection not within the range of rows.  Please reselect.\n";
						break;
					}

					//after all validation assign rowselect variable value
					rowselect = row;
										
					//buy ticket IF its available (*)
					//note: display of "row number" and "column number" is reduced by 1, row-- & col-- decrements row & col and stores the new value in the variable, row/col - 1 will subtract 1 to row/col and not store it as a value, this adjustment is because the array begins at 0 and not 1 and the user will see a table beginning at 1, so all rows and columns are 1 more than their place in the array
					if (matrix[row - 1][col - 1] == '*') {
						matrix[row - 1][col - 1] = '#';

						ticketPrice(&rowselect, &price);
						cout << "Sold Ticket Price: $" << price << endl;

						//increment global variable of tickets sold
						ticketsold++;

						//Add a sold ticket price to the total sale amount (price is variable overwritten for each purchase, totalticketsale is global variable that has each price added to it)
						totalticketsale += price;
					}
					//not available - already sold (#)
					else
					{
						//tell user that seat is already sold
						cout << "Sorry, This seat is already taken.\n\n";
					}

					//end option 1
					break;
				}
						  // Option 2: Display Total Sales
				case '2': {
					cout << "Total Ticket Sales: $" << totalticketsale << endl;
					cout << "Total Tickets Sold: " << ticketsold << endl;
					cout << endl;

					//end option 2
					break;
				}
						  // Option 3: List Sales Report
				case '3': {
					//
					system("cls");
					//tally total tickets and sales
					int totalsales;
					totalsales = ticketsold * totalticketsale;
					//display report of sales
					cout << "List Sales Report\n";
					cout << "-----------------------\n";
					cout << "\n\n";
					cout << "The Total Sales for Today are : $ " << totalsales;
					cout << "\n\n\n";

					//end option 3
					break;
				}
						  // Option 4: Exit Program
				case '4': {

					//exit the application
					exit(0);

					//end option 4
					break;
				}
				}
			}
		}
	}
	//return 0;
}

//function to validate if input is within range
int validateWithinRange(int userInput, int leastVal, int maxVal ) {
	//return value - 1 means valid within range, 0 means not within range
	int retVal;
	retVal = 0;

	//determine if the user input is within the given range
	if (userInput >= leastVal && userInput <= maxVal) {
		retVal = 1;
	}

	//return value
	return retVal;
}

//function to validate if user input is a number or not
int validateNumber(char userInput) {
	//return value - 1 means valid number, 0 means invalid number
	int retVal;
	retVal = 0;

	//determine if the users input is actually a digit / integer or not
	if (isdigit(userInput)) {
		retVal = 1;
	}

	//return validation
	return retVal;
}

// Function that displays the theater seating chart screen
void print(char matrix[][9], int numberOfRow, int numberOfCol) {
	// Intialize variables
	//int row, col, i, j;
	int i, j;

	//display seat table legend
	cout << "* = Seats Available\n";
	cout << "# = Reserved Seats\n";
	cout << "Seats:  1  2  3  4  5  6  7  8  9" << endl;
	
	// Loop to generate the rows
	for (i = 0; i < numberOfRow; i++) {
		//beginning of each row
		//note: display of "row number" is added by 1, i++ increments i and stores the new value as i, i + 1 will add 1 to i and not store its new value, this adjustment is because the array begins at 0 and not 1
		cout << "Row" << setw(3) << (i + 1);
		//content of each row
		for (j = 0; numberOfCol > j; j++) {
			cout << setw(3) << matrix[i][j];
		}
		//end of row
		cout << endl;
	}
}

//Prices for each row of the theater.
void ticketPrice(int *rowselect, double *price) {
	//change price based on row...the closer the row, the more expensive
	switch (*rowselect)	{
		case 1:	{
			*price = 80.00;
			break;
		}

		case 2:	{
			*price = 75.00;
			break;
		}

		case 3:	{
			*price = 70.00;
			break;
		}

		case 4:	{
			*price = 65.00;
			break;
		}

		case 5:	{
			*price = 60.00;
			break;
		}

		case 6:	{
			*price = 55.00;
			break;
		}

		case 7:	{
			*price = 50.00;
			break;
		}

		case 8:	{
			*price = 45.00;
			break;
		}

		case 9:	{
			*price = 40.00;
			break;
		}

		case 10:	{
			*price = 35.00;
			break;
		}
	}
}