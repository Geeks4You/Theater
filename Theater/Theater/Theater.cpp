// Week 5: Learning Team B: Theater Seating Program
// PRG/410: C++ Programming I
// October 24, 2016
// Marcia L. Allen
// Keith
// Michael Aust
// Pharaoh H
// As a culminating activity for Week Five, the Learning Team will be writing the following program
// that can be used by a small theater to sell tickets for performances. The theater's auditorium has
// 10 rows of seats with 9 seats in each row. The program should display a screen that shows which seats are 
// available and which are taken. The screen will show a chart depicting each seat in the theater.
// Seats that are taken are represented by an * symbol, and seats that are available are represented by a # symbol.
// Every time a ticket or group of tickets is purchased, the program should display the total ticket prices and 
// update the seating chart. The program should keep a total of all ticket sales.
// The program should also give the user an option to see a list of how many seats have been sold,
// how many seats are available in each row, and how many seats are available in the entire auditorium.

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

int _tmain(int argc, _TCHAR* argv[]) {

	// Intialize variables
	char matrix[numberOfRow][numberOfCol], seat[numberOfRow][numberOfCol];
	char option;
	int i, j;
	int row, col;
	int rowselect;
	int ticketsold = 0;
	bool another = true;

	// Initializes all of the seats to available (*)
	for (i = 0; i < numberOfRow; i++)
		for (j = 0; j < numberOfCol; j++)
			matrix[i][j] = '*';

	while (another)
	{
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

		switch (option)
		{
		// Loop changes the available seat (*) chosen to unavailable seat (#) or indicates that the seat is not available
		case '1':
		{
			cout << "Enter row: ";
			cin >> row;
			cout << "\nEnter seat: ";
			cin >> col;

			rowselect = row;

			if (matrix[row][col] == '*')
			{
				matrix[row][col] = '#';

				ticketPrice(&rowselect, &price);
				cout << " Sold Ticket Price: $" << price << endl;
				ticketsold++;
			}
			else
			{
				cout << "Sorry, This seat is already taken.\n\n";
			}

		// Option 2: Display Total Sales
		case '2': {

		}
		// Option 3: List Sales Report
		case '3': {

		}
		// Option 4: Exit Program
		case '4': {

			//exit(0);
			//break;
		}
		}
		}
	}

	//system("pause");
	//return 0;
}

// Function that displays the theater seating chart screen
void print(char matrix[][9], int numberOfRow, int numberOfCol)
{
	// Intialize variables
	int row, col, i, j;

	cout << "* = Seats Available\n";
	cout << "# = Reserved Seats\n";
	cout << "Seats:  0  1  2  3  4  5  6  7  8" << endl;
	
	// Loop to generate the rows
	for (i = 0; i < numberOfRow; i++)
	{
		cout << "Row" << setw(3) << i;
		for (j = 0; numberOfCol > j; j++)
			cout << setw(3) << matrix[i][j];

		cout << endl;
	}

}

//Prices for each row of the theater.
void ticketPrice(int *rowselect, double *price)
{
	switch (*rowselect)
	{
	case 0:
	{
		*price = 80.00;
		break;
	}

	case 1:
	{
		*price = 75.00;
		break;
	}

	case 2:
	{
		*price = 70.00;
		break;
	}

	case 3:
	{
		*price = 65.00;
		break;
	}

	case 4:
	{
		*price = 60.00;
		break;
	}

	case 5:
	{
		*price = 55.00;
		break;
	}

	case 6:
	{
		*price = 50.00;
		break;
	}

	case 7:
	{
		*price = 45.00;
		break;
	}

	case 8:
	{
		*price = 40.00;
		break;
	}

	case 9:
	{
		*price = 35.00;
		break;
	}


	}

}


