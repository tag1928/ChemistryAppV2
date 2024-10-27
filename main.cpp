#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <thread>

using namespace std;

struct Atom
{
	string name;
	unsigned short int atomic;
	float mass;
	string symbol;
	string group;
	string period;
};

void printAtom(Atom &input)
{
	input.name[0] = toupper(input.name[0]);
	
	cout << "\n================\n" << '\n';
	cout << "Name: " << input.name << '\n';
	cout << "Atomic number: " << input.atomic << '\n';
	cout << "Mass: " << input.mass << '\n';
	cout << "Symbol: " << input.symbol << '\n';
	cout << "Group: " << input.group << '\n';
	cout << "Period: " << input.period << endl;
	
	input.name[0] = tolower(input.name[0]);
}

vector <Atom> element(0);

////

bool haveRead = false;

void fileRead()
{
	ifstream jamal("data.txt");
	
	Atom a;
	
	while (!jamal.eof())
	{
		jamal >> a.name;
		jamal >> a.atomic;
		jamal >> a.mass;
		jamal >> a.symbol;
		jamal >> a.group;
		jamal >> a.period;
		element.push_back(a);
	}
	
	return;
}

////

void showByName()
{
	cout << "\n================\n" << '\n';
	cout << "Enter the name of an element:" << '\n';
	cout << "\"return\" to return to main menu." << endl;
	
	string input;
	
	cin >> input;
	
	for (int i = 0; i < input.size(); i++)
	{
		input[i] = tolower(input[i]);
	}
	
	if (input == "return") return;
	
	for (int i = 0; i < element.size(); i++)
	{
		if (element[i].name == input)
		{
			system("cls");
			printAtom(element[i]);
			return showByName();
		}
	}
	
	system("cls");
	cout << "Element not found" << endl;
	
	return showByName();
}

void showBySymbol()
{
	cout << "\n================\n" << '\n';
	cout << "Enter the symbol of an element:" << '\n';
	cout << "\"return\" to return to main menu." << endl;
	
	string input;
	
	cin >> input;
	
	if (input == "return") return;
	
	for (int i = 0; i < element.size(); i++)
	{
		if (element[i].symbol == input)
		{
			system("cls");
			printAtom(element[i]);
			return showBySymbol();
		}
	}
	
	system("cls");
	cout << "Element not found" << endl;
	
	return showBySymbol();
}

void showByAtomic()
{
	cout << "\n================\n" << '\n';
	cout << "Enter the atomic number of an element:" << '\n';
	cout << "0 to return to main menu." << endl;
	
	unsigned short int input;
	
	cin >> input;
	
	if (input == 0) return;
	
	for (int i = 0; i < element.size(); i++)
	{
		if (element[i].atomic == input)
		{
			system("cls");
			printAtom(element[i]);
			return showByAtomic();
		}
	}
	
	system("cls");
	cout << "Element not found" << endl;
	
	return showByAtomic();
}

int main()
{
	if (haveRead == false)
	{
		fileRead();
		haveRead = true;
	}
	
	unsigned short int input;
	
	system("cls");
	
	cout << "\n================\n" << '\n';
	cout << "Enter the number of choice:" << '\n';
	cout << "0.Exit" << '\n';
	cout << "1.Name" << '\n';
	cout << "2.Symbol" << '\n';
	cout << "3.Atomic number" << endl;
	
	cin >> input;
	
	switch(input)
	{
		case 0: return 0;
		case 1: showByName(); break;
		case 2: showBySymbol(); break;
		case 3: showByAtomic(); break;
		default: break;
	}
	
	return main();
}
