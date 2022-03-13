/**
 * Demo program for mat exercise.
 * 
 * Author: Idan Kaminetsky
 * Since : 2022-03
 */

#include "mat.hpp"

#include <iostream>
#include <stdexcept>
using namespace std;

int main() {

	cout << "Let's see few examples that work: "<< endl << endl << endl;

	cout << "input A: (9, 7, '@', '-')	-	result:" << endl << endl;
	cout << ariel::mat(9, 7, '@', '-') << endl << endl;

	cout  << "input B: (13, 5, '@', '-')	-	result:" << endl << endl;
	cout << ariel::mat(13, 5, '@', '-') << endl << endl; 

	cout  << "input C: (3, 5, '$', '+')	-	result:" << endl << endl;
	cout << ariel::mat(3, 5, '$', '+') << endl << endl; 

	cout  << "input E: (5, 3, '#', '#')	-	result:" << endl << endl;
	cout << ariel::mat(5, 3, '#', '#') << endl << endl; 
	
	cout  << "input D: (1 , 1, '$', '+')	-	result:" << endl << endl;
	cout << ariel::mat(1 , 1, '$', '+') << endl << endl << endl; 


	cout << "Let's see few examples that don't work (pay attention to the inputs): "<< endl << endl;
	
	try {
		cout  << "input A: (10, 5, '$', '%')	-	result:" << endl;
		cout << ariel::mat(10, 5, '$', '%') << endl; // Exception - not a valid code
	} catch (exception& ex) {
	 	cout << "   caught exception: " << ex.what() << endl << endl;
	}

	try {
		cout  << "input A: (1, 2, '$', '%')	-	result:" << endl;
		cout << ariel::mat(1, 2, '$', '%') << endl; // Exception - not a valid code
	} catch (exception& ex) {
	 	cout << "   caught exception: " << ex.what() << endl << endl;
	}

	try {
		cout  << "input A: (3, -1, '$', '%')	-	result:" << endl;
		cout << ariel::mat(3, -1, '$', '%') << endl; // Exception - not a valid code
	} catch (exception& ex) {
	 	cout << "   caught exception: " << ex.what() << endl << endl;
	}

	try {
		cout  << "input A: (0, 1, '$', '%')	-	result:" << endl;
		cout << ariel::mat(0, 1, '$', '%') << endl; // Exception - not a valid code
	} catch (exception& ex) {
	 	cout << "   caught exception: " << ex.what() << endl << endl;
	}

	
	char flag;
	char symbol1;
	char symbol2;
	int length;
	int width;

	cout  << "Now it is your turn to enter inputs!" << endl;
	cout  << "Do you want to enter (more) inputs? [Y/N]" << endl;

	cin >> flag;
	while(flag != 'N'){

		cout << "enter number of columns:";
		cin >> length;
		cout << "enter number of rows:";
		cin >> width;
		cout << "enter first symbol (char):";
		cin >> symbol1;
		cout << "enter second symbol (char):";
		cin >> symbol2;

		try {
		cout  << "your input: (" << length << ", " << width << ", '" << symbol1 << "', '" << symbol2 << "')	-	result:" << endl;
		cout << ariel::mat(length, width, symbol1, symbol2) << endl;
		} catch (exception& ex) {
			cout << "   caught exception: " << ex.what() << endl;
		}
		
		cout  << "Do you want to enter (more) inputs? [Y/N]" << endl;
		cin >> flag;
	}

	cout  << "Thank you! have a nice day!" << endl;
}
