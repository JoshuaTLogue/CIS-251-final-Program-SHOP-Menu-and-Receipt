//Joshua Logue
// CIS 251
// 12-7-22
//Chapter 7 programming assignment
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

const int Tax = 10;// the Tax variable is constant, it wont change
const string ShopName = "Joshua's Soda Stop";
const unsigned MAX = 20;
const unsigned MIN = 1;
const int ITEMS = 5;
const int LuckyNums = 10;

bool Discount(int, int);

void shopMenu(string MenuItems[],double MenuPrices[])
{
	ofstream fout;
	ifstream fin;
	string MenuTemp;

	fout.open("Menu.txt");// This clump of code is my menu being written to a file.

	fout << "Coke" << endl;
	fout << 2.50 << endl;
	fout << "Sprite" << endl;
	fout << 3.50 << endl;
	fout << "Mr.Pib" << endl;
	fout << 3.50 << endl;
	fout << "Mtn-Dew" << endl;
	fout << 4.00 << endl;
	fout << "Fanta" << endl;
	fout << 2.50 << endl;
	
	fout.close();

	fin.open("Menu.txt");// my menu being read and displayed from the file
	if (fin.fail())
		cout << "Error reading file!";
	else
		for (int i = 0; i < ITEMS; i++)
		{
			getline(fin, MenuItems[i]); //Grab a menu item from the file
			fin >> MenuPrices[i]; // Grab the price from the file
			fin.ignore(); //Ignore the carriage return after the price	
		}
	cout << "+----------------------+" << endl;
	cout << "|  " << ShopName << "  |" << endl;
	cout << "+----------------------+" << endl;
	cout << "| 1. Coke      $2.50   |" << endl;
	cout << "| 2. Sprite    $3.50   |" << endl;
	cout << "| 3. Mr.Pib    $3.50   |" << endl;
	cout << "| 4. Mtn-Dew   $4.00   |" << endl;
	cout << "| 5. Fanta     $2.50   |" << endl;
	cout << "+----------------------+" << endl;

	fin.close();
}


void BillTotalFile(double TotalTemp)
{
	ofstream fout;
	ifstream fin;

	fout.open("Bill.txt");

	fout << setprecision(2) << fixed << "$" << TotalTemp << endl;// writes the total amount to a text file

	fout.close();

}

void OptionMenu()
{


	// numeric menu with 3 options
	cout << "----------------------" << endl;
	cout << "1)" << " Daily Special" << endl;
	cout << "2)" << " Calculate Bill" << endl;
	cout << "3)" << " Exit" << endl;
	cout << "----------------------" << endl;

	cout << "Pick an option (1-3)" << endl;

}

void DailySpecials()
{
	cout << "----------------------" << endl;
	cout << "1." << " Monday" << endl;
	cout << "2." << " Tuesday" << endl;
	cout << "3." << " Wednesday" << endl;
	cout << "4." << " Thursday" << endl;
	cout << "5." << " Friday" << endl;
	cout << "----------------------" << endl;
	cout << "Enter the number of the day of the week." << endl;
}

void TipOptionMenu()
{
	cout << "----------------------" << endl;
	cout << "A)" << "15%" << endl;
	cout << "B)" << "18%" << endl;
	cout << "C)" << "20%" << endl;
	cout << "D)" << "Other" << endl;
	cout << " " << endl;
	cout << "Please select a Tip Option:" << endl;
}

double calculations(double tempTipAmount, double tempPreTipBill, double& tempTotal)
{
	tempTotal = (tempPreTipBill)+(tempTipAmount);//calculates the total the user owes

	return tempTotal;
}



int main()

{

	// The double variables change with every different input
	double BillAmount, TipPercent, Total = 0, PreTipBill, TipAmount, ItemPrice, MenuPrices[ITEMS], LuckyNumbers[LuckyNums];
	int DayOfTheWeek, MenuOption = 0, numberOfItems, ItemSelect;
	string ServerName, MenuItems[ITEMS];
	char TipOption = 0, Case1repeat = 0, Case2repeat = 0;
	unsigned seed = time(0), TableNumber;
	bool DiscountCheck = false;// FLAG
	

	shopMenu(MenuItems, MenuPrices);

	cout << " " << endl;// this outputs a blank line, its just aesthetic
	do
	{

		OptionMenu();

		cin >> MenuOption;// user input for the menu options

		while (MenuOption < 1 || MenuOption > 3)//"dogfood" check
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "\nYou entered invalid input.  Please try again: ";
			cin >> MenuOption;
		}

		switch (MenuOption)// the switch for thr menu options
		{
		case 1:// daily special case menu
			do
			{

				DailySpecials();

				cin >> DayOfTheWeek;

				while (DayOfTheWeek < 1 || DayOfTheWeek > 5)//"dogfood" check
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');

					cout << "\nYou entered invalid input.  Please try again: ";
					cin >> DayOfTheWeek;
				}

				if (DayOfTheWeek == 1)// if/else if/else  for the daily special outputs
				{
					cout << "----------------------" << endl;
					cout << "Mountain Monday!" << endl;
					cout << "Half price Mtn-Dew!" << endl;
					cout << "----------------------" << endl;
				}
				else if (DayOfTheWeek == 2)
				{
					cout << "----------------------" << endl;
					cout << "Sorry, no specials on tuesdays." << endl;
					cout << "----------------------" << endl;
				}
				else if (DayOfTheWeek == 3)
				{
					cout << "----------------------" << endl;
					cout << "Wild Wednesday!" << endl;
					cout << "Random discount on a purcase above $8.00" << endl;
					cout << "----------------------" << endl;
				}
				else if (DayOfTheWeek == 4)
				{
					cout << "----------------------" << endl;
					cout << "Sorry, no specials on thursdays." << endl;
					cout << "----------------------" << endl;
				}
				else if (DayOfTheWeek == 5)
				{
					cout << "----------------------" << endl;
					cout << "Fanta Friday!" << endl;
					cout << "$1.00 off for fanta!" << endl;
					cout << "----------------------" << endl;
				}
				else
				{
					cout << "Invalid input." << endl;
				}

				cout << "would you like to see the other specials (Y/N):" << endl;
				cin >> Case1repeat;

			} while (Case1repeat == 'y' || Case1repeat == 'Y');// repeat for case 1 y for yes anything else for no


			break;

		case 2:// the case for the bill calculator
			do
			{


				cout << setprecision(2) << fixed;//sets all float outputs to have 2 places after the decimal

				cout << "Enter the name of the Server: " << endl;
				cin.ignore();
				getline(cin, ServerName);

				numberOfItems = 0; //resets these variables
				DiscountCheck = 0;
				BillAmount = 0;
				ItemPrice = 0;
				

				cout << "Enter the number of items you purchased:";
				cin >> numberOfItems;

				while (cin.fail())//"dogfood" check
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');

					cout << "\nYou entered invalid input.  Please try again: ";
					cin >> numberOfItems;
				}

				for (int i = 1; i <= numberOfItems; i++)// user inputs price of each item and adds them into the bill amount
				{
					
						cout << "+----------------------+" << endl;
						cout << "|  " << ShopName << "  |" << endl;
						cout << "+----------------------+" << endl;
						cout << "| 1. Coke      $2.50   |" << endl;
						cout << "| 2. Sprite    $3.50   |" << endl;
						cout << "| 3. Mr.Pib    $3.50   |" << endl;
						cout << "| 4. Mtn-Dew   $4.00   |" << endl;
						cout << "| 5. Fanta     $2.50   |" << endl;
						cout << "+----------------------+" << endl;

						cout << "Choose your item #" << i << ": ";
						cin >> ItemSelect;

						while (ItemSelect > 5 || ItemSelect < 1)//"dogfood" check
						{
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');

							cout << "\nYou entered invalid input.  Please try again: ";
							cin >> ItemSelect;
						}

						if (ItemSelect == 1)
						{
							ItemPrice = MenuPrices[0];
							
						}
						if (ItemSelect == 2)
						{
							ItemPrice = MenuPrices[1];

						}
						if (ItemSelect == 3)
						{
							ItemPrice = MenuPrices[2];

						}
						if (ItemSelect == 4)
						{
							ItemPrice = MenuPrices[3];

						}
						if (ItemSelect == 5)
						{
							ItemPrice = MenuPrices[4];

						}
						
						BillAmount += ItemPrice;
				}



				TipOptionMenu();

				cin >> TipOption;

				switch (TipOption)// Alphabetic Tip switch Uper and lower case
				{
				case 'a':
				case 'A':
					TipPercent = 15;
					break;

				case 'b':
				case 'B':
					TipPercent = 18;
					break;

				case 'c':
				case 'C':
					TipPercent = 20;
					break;

				case 'd':
				case 'D':
					cout << "Enter your tip percentage (as a whole number): ";
					cin >> TipPercent; // where the user inputs the tip percent, sets the input to the variable

					while (cin.fail())//"dogfood" check
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');

						cout << "\nYou entered invalid input.  Please try again: ";
						cin >> TipPercent;
					}

					break;

				default:
					cout << "----------------------" << endl;
					cout << " Invalid input." << endl;
					break;
				}



				cout << "----------------------" << endl;
				cout << " " << endl;// this outputs a blank line, its just aesthetic

				cout << "You entered: \n";

				cout << "bill Amount:" << right << setw(9) << "$" << BillAmount << endl;// lines 37 and 38 echo the user inputs
				cout << "\tTip: " << right << setw(11) << static_cast<int>(TipPercent) << "%" << endl;

				cout << " " << endl;// this outputs a blank line, its just aesthetic

				cout << "Tax Percent: " << right << setw(11) << static_cast<int>(Tax) << "%" << endl;

				cout << " " << endl;// these output a blank line, its just aesthetic
				cout << " " << endl;

				cout << "\tTax:" << setw(9) << "$" << BillAmount * (static_cast<double>(Tax) / 100) << endl; // calculates and outputs the tax amount

				PreTipBill = (BillAmount * (static_cast<double>(Tax) / 100));// PreTipBill is the tax amount added to the BillAmount
				PreTipBill += BillAmount;// added the BillAmount here // used a comb. assign. op.

				TipAmount = PreTipBill * (static_cast<double>(TipPercent) / 100);//calculates the tip amount

				cout << setw(12) << left << "Tip Amount :" << setw(9) << right << "$" << TipAmount << endl;//outputs the tip amount

				cout << "----------------------------" << endl;// aesthetic line


				calculations(PreTipBill, TipAmount, Total);


				if (Discount(BillAmount, TipPercent) == true)// conditional 5% discount
				{
					cout << " You qualify for a 5% discount!" << endl;
					Total -= (Total * .05);
				}

				cout << "----------------------------" << endl;

				cout << "Total bill amount:" << setw(3) << "$" << Total << endl;// displays the total the user owes

				//This code creates the random table number
				srand(seed);
				TableNumber = (rand() % (MAX - MIN + 1)) + MIN;

				BillTotalFile(Total);// call to my void to write the bill total to file

				// this code is the post bill message
				cout << " " << endl;
				cout << "Thanks for visiting " << ShopName << endl;
				cout << " " << endl;
				cout << "Your Table number today was: " << "#" << TableNumber << endl;
				cout << " " << endl;
				cout << "Your server's name was: " << ServerName << endl;
				cout << " " << endl;
				cout << "We hope you enjoyed it! " << "Come back soon!" << endl;
				cout << " " << endl;

				cout << "Press [ENTER] to continue..." << endl;// creates a pause
				cin.ignore();
				cin.get();

				cout << "would you like to Calculate another bill (Y/N):" << endl;
				cin >> Case2repeat;

			} while (Case2repeat == 'y' || Case2repeat == 'Y');// repeat for case 2 y for yes anything else for no



			break;

		case 3:// the exit case
			cout << "----------------------" << endl;
			cout << "Goodbye! Have a nice day!" << endl;// this is the EXIT option output
			break;

		default:
			cout << "----------------------" << endl;
			cout << "Invalid input." << endl;
			break;
		}
	} while (MenuOption != 3);// repeats first menu options until case 3 "exit"

	return 0;
}

bool Discount(int tempBillAmount, int tempTipPercent)
{

	if (tempBillAmount > 10.00 && tempTipPercent >= 18) // this is my FLAG
	{
		return true;
	}
	return false;
}

