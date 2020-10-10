#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <ctime>

//Ben Wallace, CPSC1021, Lab Section 04, bwalla5, Matt and Elliot

using namespace std;

typedef struct Employee{
	string lastName;
	string firstName;
	int birthYear;
	double hourlyWage;
}employee;

bool name_order(const employee& lhs, const employee& rhs);
int myrandom(int i) {return rand()%i;}


int main(int argc, char const *argv[]){
	int numOfEmployees;
	srand(time(0));

	cout << "Enter the number of employees you would like to input: ";
	cin >> numOfEmployees;
	cout << endl;
	employee test[numOfEmployees];	
	for (int i = 0; i < numOfEmployees; i++)
	{
		cout << "Enter the last name of employee " << i + 1 << ": ";
		cin >> test[i].lastName;
		cout << "Enter the first name of employee " << i + 1 << ": ";
		cin >> test[i].firstName;
		cout << "Enter the birth year of employee " << i + 1 << ": ";
		cin >> test[i].birthYear;
		cout << "Enter the hourly wage of employee " << i + 1 << ": ";
		cin >> test[i].hourlyWage;
		cout << endl;
	}

	
	//Prints out unordered list and displays it
	cout << endl << "Unordered list: " << endl;
	for (int i = 0; i < numOfEmployees; i++)
	{
		cout << setw(30) << test[i].firstName << ", " << test[i].lastName << endl;
		cout << setw(30) << test[i].birthYear << endl;
		cout << fixed << showpoint;
		cout << setw(30) << setprecision(2) << test[i].hourlyWage << endl;
	}

	//Prints out randomized list and displays it
	cout << endl << "Randomized list: " << endl;
	random_shuffle(test, test + numOfEmployees, myrandom);
	for (int i = 0; i < numOfEmployees; i++)
	{
		cout << setw(30) << test[i].firstName << ", " << test[i].lastName << endl;
		cout << setw(30) << test[i].birthYear << endl;
		cout << fixed << showpoint;
		cout << setw(30) << setprecision(2) << test[i].hourlyWage << endl;
	}
	
	//Prints out ordered list and displays it
	cout << endl << "Ordered list: " << endl;
	sort(test, test + numOfEmployees, name_order);
	for (int i = 0; i < numOfEmployees; i++)
	{
		cout << setw(30) << test[i].firstName << ", " << test[i].lastName << endl;
		cout << setw(30) << test[i].birthYear << endl;
		cout << fixed << showpoint;
		cout << setw(30) << setprecision(2) << test[i].hourlyWage << endl;
	}
	return 0;
}

bool name_order(const employee& lhs, const employee& rhs) {
	if (lhs.lastName < rhs.lastName)
	{
		return true;
	}
	else
	{
		return false;
	}
}
