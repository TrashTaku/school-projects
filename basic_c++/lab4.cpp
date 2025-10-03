// This program reads in from the keyboard a record of financial information
// consisting of a person’s name, income, rent, food costs, utilities and
// miscellaneous expenses. It then determines the net money
// (income minus all expenses)and places that information in a record
// which is then written to an output file.
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;
const int NAMESIZE = 15;
struct Budget
{
	char name[NAMESIZE + 1];
	float income;
	float rent;
	float food;
	float utilities;
	float miscell;
	float net; // person's net money after bills are paid
};
int main()
{
	fstream binaryDataFile; //File stream used for reading/writing binary files
	ofstream outTextFile; // Output file stream used for writing to text files
	// complete the code on next line to open the file as an output file and binary
	binaryDataFile.open("c:\\temp\\income.dat",ios::out|ios::binary );
	outTextFile.open("c:\\temp\\student.txt"); // output file that we will write student information to. This is a regular


		outTextFile << left << fixed << setprecision(2);
	Budget person, person2;
	cout << "Enter the following information" << endl;
	cout << "Person's name: ";
	cin.getline(person.name, NAMESIZE);
	cout << "Income :";
	cin >> person.income;
	cout << "Rent:";
	cin >> person.rent;
	cout << "Food:";
	cin >> person.food;
	cout << "Utilities: ";
	cin >> person.utilities;
	cout << "misc. expenses";
	cin >> person.miscell;
	// FILL IN CODE TO READ IN THE REST OF THE FIELDS:
	// rent, food, utilities AND miscell TO THE person RECORD
	person.net = person.income - (person.rent + person.food + person.utilities + person.miscell); // FILL IN CODE TO DETERMINE NET INCOME (income - expenses)
		// Fill IN CODE TO WRITE THE RECORD TO THE binaryDataFile (one instruction)
	binaryDataFile.write(reinterpret_cast<char*>(&person), sizeof(person));
		binaryDataFile.close();
	// FILL IN THE CODE TO REOPEN THE binaryDataFile FILE, NOW AS AN INPUT FILE and binary.
		binaryDataFile.open("c:\\temp\\income.dat", ios::in | ios::binary);
		if (!binaryDataFile) {
			cout << "could not find file" << endl;
		}
		else {
			binaryDataFile.read(reinterpret_cast<char*>(&person2), sizeof(person2));
			binaryDataFile.close();


			// FILL IN THE CODE TO READ THE RECORD FROM binaryDataFile AND PLACE IT IN THE
			// person2 RECORD (one instruction) (IMPORTANT: use the person2 )
			// close binaryDataFile file.
			// writing header information to outTextFile (this is a TEXT file)
			outTextFile << setw(20) << "Name" << setw(10) << "Income" << setw(10) << "Rent"
				<< setw(10) << "Food" << setw(15) << "Utilities" << setw(15)
				<< "Miscellaneous" << setw(10) << "Net Money" << endl << endl;
			// FILL IN CODE TO WRITE INDIVIDUAL FIELD INFORMATION OF THE person2 RECORD TO
			// outTextFile.(several instructions, outTextFile is a regular text file.)
			outTextFile << setw(20) << person2.name << setw(10) << person2.income << setw(10) << person2.rent
				<< setw(10) << person2.food << setw(15) << person2.utilities << setw(15)
				<< person2.miscell << setw(10) << person2.net << endl << endl;

			// Write each field of the person2 record to outTextFile using the same setw values
			// as the headings above. This will ensure the output is neatly aligned in columns.
		}
		// close outTextFile file.
				outTextFile.close();
		
	system("pause");
	return 0;
}

