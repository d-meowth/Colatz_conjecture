///
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

using namespace std;

bool isOdd(int integer) // odd number function bool
{

	if (integer % 2 == 0) // if divisable by 2...
		return true; // ...return true
	else // otherwise...
		return false; // ...return false
}

int evenP(int integer) // divides num by 2
{
	integer = integer / 2; // division
	cout << integer << endl; // prints the new num
	return integer; // return num
}

int oddP(int integer) // multiplies num by 3 and adds 1 making the num even again
{
	integer = integer * 3 + 1; // division and addition
	cout << integer << endl; // prints the new num
	return integer; // returns num
}

int main()
{
	int c; // Press any key to continue
	int major = 0; // Version
	int minor = 1; // Version
	int steps = 0;
	cout << "Colatz conjecture simulator v." << major << "." << minor << endl; // Start message
	cout << "Press any key to continue..." << endl;
	c = _getch(); // Get's 'any' key
	bool repeat = true; // repeats the whole thing while true
	bool ask = true; // ask if to continue repeating. Useful in case of invalid imput

	int delay1 = 100; // delay between output (default = 100);
	int delay2 = 1000; // delay after number input (default = 1000);
	char input; // debug settings input

	ifstream settings("settings.txt"); // opens the settings file
	settings >> delay1; // reads delay between outputs
	settings >> delay2; // reads delay after number selection
	settings.close(); // closes the settings file

	if (c == 8)
	{
		cout << "Entering debug mode" << endl;
		for (int deb = 0; deb <= 2; deb++) // useless (. -> .. -> ...) animation
		{
			Sleep(300); // how fast the animation is
			cout << "."; // the character printed during the animation
		}
		system("CLS"); // clears the entire screen after the animation is done

		while (1 > 0)
		{
			cout << "Delay between output: " << delay1 << endl; // prints delay between outputs
			cout << "Delay after input: " << delay2 << endl; // prints delay after number selection
			cout << "Change settings?" << endl; // asks for change of settings
			input = _getch(); // gets input
			if (input == 110 || input == 78) // if n or N
			{
				system("CLS"); // clear the screen
				break; // break the loop
			}

			if (input == 121 || input == 89) // if y or Y
			{
				ofstream osett("settings.txt"); // open the settings file
				cout << "Delay between output?\n>"; // ask for delay bewteen output
				cin >> delay1; // asks for input
				osett << delay1 << endl; // pastes the input to the settings file
				cout << "Delay after input?\n>"; // ask for delay after number selection
				cin >> delay2; // asks for input
				osett << delay2 << endl; // pastes the input to the settings file
				osett.close(); // closes the settings file
				system("CLS"); // clears the screen
				cout << "Delay between output: " << delay1 << endl; // prints delay between outputs
				cout << "Delay after input: " << delay2 << endl; // prints delay after number selection
				cout << "Settings saved" << endl; // does nothing
				Sleep(1500); // waits 1500ms before...
				system("CLS"); // ...clearing the screen
				break; // breaks the loop
			}
		}
	}

	int num; // declares num

	while (repeat) // main loop
	{
		repeat = true; // repeats the loop
		ask = true; // asks if to repeat the loop
		steps = 0;
		cout << "Enter a number\n>"; // asks for num
		cin >> num; // asks for num input
		Sleep(delay2); // delay after num selection
		cout << num << endl; // prints the num

		do // calculations
		{
			if (isOdd(num) == true && num != 1) // checks if num is odd and is not 1. If true...
			{
				num = evenP(num); // ...divides by 2
				steps++; // Adds 1 step to the counter
			}
			else if (isOdd(num) == false && num != 1) // checks if num is not odd and not 1. If true...
			{
				num = oddP(num); // ...multiplies by 3 and adds 1
				steps++; // Adds 1 step to the counter
			}
			Sleep(delay1); // delay between outputs
		} while (num != 1); // repeats as long as num is NOT 1

		cout << "Steps: " << steps << endl;

		while (ask) // loops the y/n in case the input is invalid
		{
			cout << "Go again? y/n " << endl; // asks if the user wants to enter a new num and begin again
			char repchar; // declares input
			repchar = _getch(); // gets input
			if (repchar == 121 || repchar == 89) { system("CLS"); repeat = true; ask = false; } // if y or Y - clears the screen and repeats the parent loop (breaks the current loop with (ask = false) which is reset at the beggining of parent loop)
			else if (repchar == 110 || repchar == 78) { repeat = false; ask = false; } // if n or N - closes the program
			else { cout << "Unkown command.." << endl; ask = true; } // if neither outputs an error and asks for input again (ask = true)
		}
	}
	//system("Pause"); // pauses the program before closing. Useless with y/n repeat question above.
	return 0;
}