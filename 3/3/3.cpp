//Name: Xiaosong Zhan
//File: 3.cpp
//Project: 2
//Class: CIS 2541 - Fall 2015
//Date: Octorber 27, 2015




#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

//Fuction: void loadSeats(char seat[][30])
//Parameters: seat[15][30] - seat status(available or not available)
//Returns: Nothing
void loadSeats(char[][30]);

//Function: Void loadPrices(float prices[])
//Parameters: prices[15] - prices status(what is the prices for each row)
//Returns: Nothing
void loadPrices(float[]);

//Function: void savePrices(float prices[])
//Parameters: prices[] - save current prices status to file
//Return: Nothing
void savePrices(float[]);

//Function: void saveSeats(char seat[][30])
//Parameters: seat[15][30] - save current seat status to file
//Return: Nothing
void saveSeats(char[][30]);

//Function: int main(float newTotal)
//Parameters: newTotal - current total sales for those sold seats
//Return: choice - user's option
int meau(float);

//Function: void dispalySeatingChart(char seat[][30], float prices[])
//Parameters: seat[15][30] - current seat status
//            prices[] - current prices status
//Return: Nothing
void displaySeatingChart(char[][30], float[]);

//Function: void changePrices(float prices[])
//Parameters: prices[] - currect prices status
//Return: Nothing
void changePrices(float[]);

//Function: Float purchaseTickets(char seat[][30], float prices[])
//Parameters: seat[15][30] - current seat status
//            prices[15] - current prices status
//Return: totalSales - the total sales for this purchase
float purchaseTickets(char[][30], float[]);


int main()
{
	const int row = 15;
	const int col = 30;
	int choice;
	char seat[row][30];
	float prices[row];
	float total = 0;
	float newTotal = 0;;
	float totalSales = 0;;
	bool loop = true;

	//Fuction: void loadSeats(char seat[][30])
	//Parameters: seat[15][30] - seat status(available or not available)
	//Returns: Nothing
	loadSeats(seat);

	//Function: Void loadPrices(float prices[])
	//Parameters: prices[15] - prices status(what is the prices for each row)
	//Returns: Nothing
	loadPrices(prices);

	while (loop)
	{
		//Function: int main(float newTotal)
		//Parameters: newTotal - current total sales for those sold seats
		//Return: choice - user's option
		choice = meau(newTotal);

		system("cls");

		if (choice == 1)
		{
			//Function: void dispalySeatingChart(char seat[][30], float prices[])
			//Parameters: seat[15][30] - current seat status
			//            prices[] - current prices status
			//Return: Nothing
			displaySeatingChart(seat, prices);

			system("pause");
			system("cls");

			loop = true;
		}
		else if (choice == 2)
		{
			//Function: Float purchaseTickets(char seat[][30], float prices[])
			//Parameters: seat[15][30] - current seat status
			//            prices[15] - current prices status
			//Return: totalSales - the total sales for this purchase
			totalSales = purchaseTickets(seat, prices);
			newTotal = newTotal + totalSales;


			system("pause");
			system("cls");

			loop = true;
		}
		else if (choice == 3)
		{
			//Function: void changePrices(float prices[])
			//Parameters: prices[] - currect prices status
			//Return: Nothing
			changePrices(prices);

			system("pause");
			system("cls");

			loop = true;

		}
		else if (choice == 4)
		{
			system("exit");
			loop = false;
		}
	}
	return 0;
}

//Fuction: void loadSeats(char seat[][30])
//Parameters: seat[15][30] - seat status(available or not available)
//Returns: Nothing
void loadSeats(char seat[][30])
{
	fstream dataFile;
	string fileName = "seatingChart.dat";
	int count, count1;
	const char available = '#';
	const char notAvailable = '*';
	const int row = 15;
	const int col = 30;

	dataFile.open(fileName);
	if (!dataFile)
	{
		dataFile.open(fileName, ios::out);
		cout << "No Seating File Found. . ." << endl;
		cout << "Clearing Seating Chart. . ." << endl;
		for (count = 0; count < row; count++)
		{
			for (count1 = 0; count1 < col; count1++)
			{
				dataFile << available;
				seat[count][count1] = available;

			}
		}

		dataFile.close();

		system("pause");
		system("cls");
	}
	else
	{
		dataFile.open(fileName);
		cout << "File Found . . . " << endl;
		cout << "Loading Seating Chart . . . " << endl;

		system("Pause");
		system("cls");
	}
}


//Function: Void loadPrices(float prices[])
//Parameters: prices[15] - prices status(what is the prices for each row)
//Returns: Nothing
void loadPrices(float prices[])
{
	fstream pricesFile;
	string NameFile = "rowPrices.dat";
	int count;
	const int row = 15;

	pricesFile.open(NameFile);
	if (!pricesFile)
	{

		cout << "No Pricing File Found. . ." << endl;
		cout << "Setting Default Pricing ($15 for each row). . ." << endl;

		pricesFile.open(NameFile, ios::out);
		for (count = 0; count < row; count++)
		{
			const float ticketPrices = 15;

			pricesFile << ticketPrices << endl;
			prices[count] = ticketPrices;


		}



		system("pause");
		system("cls");
	}
	else
	{
		pricesFile.open(NameFile);
		cout << "File Found . . . " << endl;
		cout << "Loading Pricing Chart . . . " << endl;

		pricesFile.close();

		system("Pause");
		system("cls");
	}
	pricesFile.close();
}

//Function: int main(float newTotal)
//Parameters: newTotal - current total sales for those sold seats
//Return: choice - user's option
int meau(float newTotal)
{
	int choice;
	bool loop3 = true;

	while (loop3)
	{
		cout << "*** Main Meau ***" << endl;
		cout << fixed << showpoint << setprecision(2);
		cout << "*** Sales This Session <$ " << newTotal << " > ***" << endl;

		cout << endl;
		cout << "1. Display Seating Chart" << endl;
		cout << "2. Purchase Tickets" << endl;
		cout << "3. Change Ticket Prices" << endl;
		cout << "4. Exit " << endl;
		cout << "Enter your Choice: ";
		cin >> choice;

		
		if (choice > 4 || choice <= 0)
		{
			cout << "*** Invalid Choice ***" << endl;
			loop3 = true;

			system("pause");
		}
		else
		{
			loop3 = false;
		}
         system("cls");
	}
	
	return choice;
}

//Function: void dispalySeatingChart(char seat[][30], float prices[])
//Parameters: seat[15][30] - current seat status
//            prices[] - current prices status
//Return: Nothing
void displaySeatingChart(char seat[][30], float prices[])
{
	ifstream dataFile;
	ifstream pricesFile;
	string NameFile = "rowPrices.dat";
	string fileName = "seatingChart.dat";
	int count1, count;
	const int row = 15;
	const int col = 30;

	dataFile.open(fileName);
	pricesFile.open(NameFile);

	for (count = 0; count < row; count++)
	{
		pricesFile >> prices[count];
	}

	for (count = 0; count < row; count++)
	{
		for (count1 = 0; count1 < col; count1++)
		{
			dataFile >> seat[count][count1];
		}
	}

	cout << setw(23) << "Seats" << endl;
	cout << "           123456789012345678901234567890 ";
	cout <<  setw(11) << right << "Price" << endl;

	for (count = 0; count < row; count++)
	{
		cout << "Row " << count + 1;
		if (count + 1 < 10)
		{
			cout << setw(7) << right;
		}
		else
		{
			cout << setw(6) << right;
		}
		for (count1 = 0; count1 < col; count1++)
		{
			cout << seat[count][count1];
		}
		cout << setw(12) << right << prices[count] << endl;
	}

	dataFile.close();
	pricesFile.close();
}

//Function: void changePrices(float prices[])
//Parameters: prices[] - currect prices status
//Return: Nothing
void changePrices(float prices[])
{
	int count;
	int change;
	const int row = 15;
	bool loop1 = true;
	char option;
	float newPrices;
	ifstream pricesFile;
	string NameFile = "rowPrices.dat";

	while (loop1)
	{
		pricesFile.open(NameFile);
		for (count = 0; count < row; count++)
		{
			pricesFile >> prices[count];
		}


		cout << "*** Change Seating Price ***" << endl;
		cout << endl;
		for (count = 0; count < row; count++)
		{
			
			cout << "Row " << count + 1;
			if (count + 1 < 10)
			{
				cout << setw(12) << right;
			}
			else
			{
				cout << setw(11) << right;
			}
			cout << prices[count] << endl;
		}

		cout << endl;
		cout << "Enter Row Number to Change: ";
		cin >> change;
		if (change > 0 && change <= 15)
		{
			cout << "Enter New Price: ";
			cin >> newPrices;
			while (newPrices < 0)
			{
				cout << "Error! Price Cannot be less than 0.00" << endl;
				cout << "Try Again: ";
					cin >> newPrices;
			}
		}
		else
		{
			cout << "That is an invalid row" << endl;
		}

		for (count = 0; count < row; count++)
		{
			if (count + 1 == change)
			{
				prices[count] = newPrices;
			}
			else
			{
				pricesFile >> prices[count];
			}
		}
		pricesFile.close();

		//Function: void savePrices(float prices[])
		//Parameters: prices[] - save current prices status to file
		//Return: Nothing
		savePrices(prices);

		cout << "Do you want to change another <y/n>: ";
		cin >> option;

		if (option == 'n' || option == 'N')
		{
			loop1 = false;
		}
		else if (option == 'y' || option == 'Y')
		{
			loop1 = true;

			system("pause");
			system("cls");
		}
		else
		{
			loop1 = false;
		}
	}
}

//Function: void savePrices(float prices[])
//Parameters: prices[] - save current prices status to file
//Return: Nothing
void savePrices(float prices[])
{
	int count;
	const int row = 15;
	ofstream pricesFile;
	string NameFile = "rowPrices.dat";

	pricesFile.open(NameFile);
	for (count = 0; count < row; count++)
	{
		pricesFile << prices[count] << endl;
	}
	pricesFile.close();
}


//Function: Float purchaseTickets(char seat[][30], float prices[])
//Parameters: seat[15][30] - current seat status
//            prices[15] - current prices status
//Return: totalSales - the total sales for this purchase
float purchaseTickets(char seat[][30], float prices[])
{
	int count, count1;
	int sum;
	int num = 0;
	int changeSeats;
	int seatsNumber;
	int ticketsAmount;
	const int row = 15;
	const int col = 30;
	char notAvailable = '*';
	char available = '#';
	char option1;
	bool loop2 = true;
	float total = 0;
	float totalSales = 0;
	ifstream dataFile;
	string fileName = "seatingChart.dat";
	bool check = true;

	while (loop2)
	{
		int num = 0;
		dataFile.open(fileName);

		for (count = 0; count < row; count++)
		{
			for (count1 = 0; count1 < col; count1++)
			{
				dataFile >> seat[count][count1];
			}
		}

		displaySeatingChart(seat, prices);
		cout << "Enter Row: ";
		cin >> changeSeats;
		if (0 < changeSeats && changeSeats <= 15)
		{
			cout << "Enter Seat: ";
			cin >> seatsNumber;
			if (seatsNumber > 0 && seatsNumber <= 30)
			{
				cout << "Enter Number of Tickets: ";
				cin >> ticketsAmount;
				if (seatsNumber + ticketsAmount >= 31 || ticketsAmount <= 0)
				{
					cout << "Those seats numbers are invaild" << endl;
					cout << "There is a problem with your input" << endl;
					cout << "Do you want to purchase more <y/n>: ";
					cin >> option1;
					if (option1 == 'n' || option1 == 'N')
					{
						loop2 = false;
					}
					else if (option1 == 'y' || option1 == 'Y')
					{
						loop2 = true;

						system("pause");
						system("cls");
					}
					else
					{
						loop2 = false;
					}
				}
				else
				{

					sum = ticketsAmount + seatsNumber;

					for (count = 0; count < row; count++)
					{
						for (count1 = 0; count1 < col; count1++)
						{

							if (changeSeats == count + 1)
							{
								if (seatsNumber - 1 <= count1 && count1 < sum - 1)
								{
									if (seat[count][count1] == notAvailable)
									{
											num = num + 1;
									}
								}
							}
						}
					}


					if (num == 0)
					{ 
						for (count = 0; count < row; count++)
						{
							for (count1 = 0; count1 < col; count1++)
							{
								if (count + 1 == changeSeats)
								{
									if (seatsNumber - 1 <= count1 && count1 < sum - 1)
									{
										seat[count][count1] = notAvailable;
									}
									else
									{
										dataFile >> seat[count][count1];
									}
								}
								else
								{
									dataFile >> seat[count][count1];
								}
							}
						}
					}
					else
					{
						cout << "Sorry one or more of those are already sold";
						cout << endl;
					}

				
					

					dataFile.close();

					//Function: void saveSeats(char seat[][30])
					//Parameters: seat[15][30] - save current seat status to file
					//Return: Nothing
					saveSeats(seat);

					total = ticketsAmount * prices[changeSeats - 1];

					cout << endl;
					cout << ticketsAmount << " * " << prices[changeSeats - 1] << " = " << total << endl;


					cout << "Do you want to purchase more <y/n>: ";
					cin >> option1;
					if (option1 == 'n' || option1 == 'N')
					{
						loop2 = false;

						if (num == 0)
						{
							totalSales = total + totalSales;
						}
					}
					else if (option1 == 'y' || option1 == 'Y')
					{

						loop2 = true;

						if (num == 0)
						{
							totalSales = totalSales + total;
							
						}

						system("pause");
						system("cls");
					}
					else
					{
						loop2 = false;
						totalSales = totalSales + total;
					}
				}
			}
			else
			{
				cout << "There was a problem with your input" << endl;
				cout << "Do you want to purchase more <y/n>: ";
				cin >> option1;
				if (option1 == 'n' || option1 == 'N')
				{
					loop2 = false;
				}
				else if (option1 == 'y' || option1 == 'Y')
				{

					loop2 = true;

					system("pause");
					system("cls");
				}
				else
				{
					loop2 = false;
				}
			}
		}
		else
		{
			cout << "There was a problem with your input" << endl;
			cout << "Do you want to purchase more <y/n>: ";
			cin >> option1;
			if (option1 == 'n' || option1 == 'N')
			{
				loop2 = false;
			}
			else if (option1 == 'y' || option1 == 'Y')
			{ 

				loop2 = true;

				system("pause");
				system("cls");
			}
			else
			{
				loop2 = false;
			}
		}


	}
	
	return totalSales;
}

//Function: void saveSeats(char seat[][30])
//Parameters: seat[15][30] - save current seat status to file
//Return: Nothing
void saveSeats(char seat[][30])
{
	int count, count1;
	const int row = 15;
	const int col = 30;
	ofstream dataFile;
	string fileName = "seatingChart.dat";

	dataFile.open(fileName);
	for (count = 0; count < row; count++)
	{
		for (count1 = 0; count1 < col; count1++)
		{
			dataFile << seat[count][count1];
		}
	}
	dataFile.close();
}