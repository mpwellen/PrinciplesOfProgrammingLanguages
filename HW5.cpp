#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main()
{
	map<char, char> matchingTable;
	matchingTable['0'] = 'zero';
	matchingTable['1'] = 'oct';
	matchingTable['2'] = 'oct';
	matchingTable['3'] = 'oct';
	matchingTable['4'] = 'oct';
	matchingTable['5'] = 'oct';
	matchingTable['6'] = 'oct';
	matchingTable['7'] = 'oct';
	matchingTable['8'] = 'dec';
	matchingTable['9'] = 'dec';
	matchingTable['+'] = '+';
	matchingTable['-'] = '-';

	map<char, map<char, char>> automaton;
	automaton['S']['+'] = 'A';
	automaton['S']['-'] = 'A';
	automaton['S']['zero'] = 'F';
	automaton['S']['oct'] = 'F';
	automaton['S']['dec'] = 'F';
	automaton['A']['oct'] = 'B';
	automaton['A']['dec'] = 'B';
	automaton['A']['zero'] = 'Z';
	automaton['Z']['oct'] = 'C';
	automaton['Z']['zero'] = 'F';
	automaton['Z']['dec'] = 'F';
	automaton['B']['zero'] = 'B';
	automaton['B']['oct'] = 'B';
	automaton['B']['dec'] = 'B';
	automaton['B']['+'] = 'F';
	automaton['B']['-'] = 'F';
	automaton['C']['oct'] = 'C';
	automaton['C']['dec'] = 'F';
	automaton['C']['-'] = 'F';
	automaton['C']['+'] = 'F';
	automaton['F']['-'] = 'F';
	automaton['F']['+'] = 'F';
	automaton['F']['oct'] = 'F';
	automaton['F']['dec'] = 'F';
	automaton['F']['zero'] = 'F';
	string arr[2] = { "Rejected","Accepted" };
	//string input = "-034-21";
	//+0 -03489 -00 +9803467 -184 -04650 + -034-21
	//+0 - 03489 - 00 + 9803467 - 184 - 04650 + -034 - 21
	// filestream variable file 
	fstream file;
	string input, filename;

	// filename of the file 
	filename = "test-data.txt";

	// opening file 
	file.open(filename.c_str());

	// extracting words form the file 
	while (file >> input)
	{
		// displaying content 
		char state = 'S';
		char value;
		int i = 0;
		char currentState;
		char nextState;
		while (i < input.length())
		{
			value = matchingTable[input[i]];
			state = automaton[state][value];
			//cout << value << endl;
			//cout << state << endl;
			i++;
		}
		int result = (state != 'F' && state != 'A');
		cout << arr[result] << ":  ";
		cout << input << endl;
	}
}
