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
const int numberOfCol = 10;

// Call function that displays the intialized theater seating chart screen
void print(char matrix[][10], int numberOfRow, int numberOfCol);

int _tmain(int argc, _TCHAR* argv[]) {

	// Intialize variables
	char matrix[numberOfRow][numberOfCol], seat[numberOfRow][numberOfCol];
	char option;
	int i, j;
	int row, col;
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
		cout << "\nSales Menu:\n";
		cout << "1)  Purchase Ticket\n";
		cout << "2)  Total Sales and Exit\n\n";
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

			if (matrix[row][col] == '*')
			{
				matrix[row][col] = '#';
				ticketsold++;
			}
			else
			{
				cout << "Sorry, This seat is already taken.\n\n";
			}

			//total revenue
		}

		/*case '2' :
		{
		another=false;
		}

		default :
		cout << "Invalid choice";*/

		}
	}

	system("pause");
}

// Function that displays the theater seating chart screen
void print(char matrix[][10], int numberOfRow, int numberOfCol)
{
	// Intialize variables
	int row, col, i, j;

	cout << "* = Seats Available\n";
	cout << "# = Reserved Seats\n";
	cout << "Seats:  0  1  2  3  4  5  6  7  8  9" << endl;
	
	// Loop to generate the rows
	for (i = 0; i < numberOfRow; i++)
	{
		cout << "Row" << setw(3) << i;
		for (j = 0; numberOfCol > j; j++)
			cout << setw(3) << matrix[i][j];

		cout << endl;
	}

	// return 0;
}
//...................................................
void defaultChart()
{
	setDefaultChart(seat);
	// Hiding Bug
	checkRowSeat(tempArray, myTable);
}

//.......................................................
char setDefaultChart(char s[rows][cols])
{
	char pound = '#';



	for (int i = 1; i <= rows; i++)
	{
		for (int j = 1; j <= cols; j++)
		{
			s[i][j] = pound;

		}
	}
}
//.......................................................
void displayChart() {
	printChart(seat);
}

//........................................................
void printChart(char t[rows][cols])
{
	char blank = ' ';
	cout << blank << blank << blank << blank << blank << blank;
	for (int k = 1; k <= cols; k++)
	{
		cout << k;
	}
	cout << endl;

	for (int i = 1; i <= rows; i++)
	{
		cout << "ROW " << i << " ";
		for (int j = 1; j <= cols; j++)
		{
			cout << t[i][j];
		}
		cout << endl;
	}
}

//........................................................
void getSeatSold() {
	replacePound(seat);
}

//.......................................................



char replacePound(char r[rows][cols])
{
	char choice;
	int i = 1, rw, cl, numtickets = 0;
	char star = '*';
	bool flag = true;
	int total = 0;

	getTicketToBuy(numtickets);
	while (i <= numtickets)
	{


		cout << " Enter Row and Column Number " << " ";

		do {

			cin >> rw >> cl;
			if (Check(rw, cl, star))
			{
				cout << " Seats are Available " << endl;
			}
			else
			{
				cout << " Seats are Not Available " << endl;
				cout << " Please select different seats " << "  ";

			}

		} while (Check(rw, cl, star) != flag);

		// Print total Cost of ticket

		total += price[rw];
		printTotal(rw);
		r[rw][cl] = star;

		// catch Bug

		catchBug(rw);

		i++;

	}

	printChart(r);

	cout << " Your Grand Total is " << total << " $  " << endl;



	totalSeatSale = totalSeatSale + numtickets;

	cout << " Thanks you for purchasing ticket   " << endl;



}
//...........................................................

bool Check(int r, int c, char ch)
{

	if (char(seat[r][c]) != ch)
	{
		return true;
	}
	else
	{
		return false;
	}
}


