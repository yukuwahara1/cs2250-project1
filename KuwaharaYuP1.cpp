#include <iostream>
#include <fstream> // Open and read a file
#include <string> // Use string in a file name and in converting numbers into alphabets
using namespace std;

// Function Prototypes
int readEncodingCipher(std::string name, int encodeKey[], int size);
void produceDecodingCipher(int encodeKey[], int decodeKey[], int size);
void useKeyOnString(int key[], int size, std::string text, std::string data, std::string &code); // Declare as references by using &

// main function
int main()
{
	const int SIZE = 26; // the size of numbers are always 26
	int choice; // Use int since choice is either 1 or 2 
	int encodeKey[SIZE]; // Declare a variable for numbers in the encoding part
	int decodeKey[SIZE]; // Declare a variable for numbers in the decoding part
	string name; 
	string text;
	string code = ""; // Use to add the text conjverted into the data, alphabets
	string data = "abcdefghijklmnopqrstuvwxyz"; // Use this way since it is simpler than ASCII

	cout << "Welcome to supersecret encoding society!\n";
	cout << "Please enter a file name with a key: ";
	getline(cin, name); // Use getline function since the file name contains .

	readEncodingCipher(name, encodeKey, SIZE); // Call the function for encoding part
	produceDecodingCipher(encodeKey, decodeKey, SIZE); // Call the function for decoding part

	cout << "What do you wish to do: \n"; // Show a menu
	cout << "1) Encode text \n"; // Show a choice
	cout << "2) Decode text \n";
	cin >> choice; // Let the user enter the choice

	switch (choice) // Show the result depending on the user's choice
	{
		case 1: // Show when the user chose 1, encoding
			cout << "Enter your text to encode: ";
			cin >> text;
			useKeyOnString(encodeKey, SIZE, text, data, code); // Call the function to convert numbers into alphabets
			break; 
		case 2: // Show when the user chose 2, decoding
			cout << "Enter your text to decode: ";
			cin >> text;
			useKeyOnString(decodeKey, SIZE, text, data, code);
			break;
		default: // Show when the user chose invalid choices
			cout << "You chose an invalid choice \n";
	}

	cout << "Thank you for using this system!";
	return 0;
}

// encoding function
int readEncodingCipher(std::string name, int encodeKey[], int size)
{
	ifstream fin; // Declare an object if type ifstream
	fin.open(name); // Open the file

	if (!fin) // Show an error message if the file cannot be located
	{
		cout << "There is an error opening a file.\n";
		cin.get(); // Avoid exiting the whole window and keep the message above showing
		exit(1); // Cut showing the menu 
	}
	else // Read the file if the file can be located
	{
		for (int i = 0; i < size; i++) // Read the file
		{
			fin >> encodeKey[i]; // Input the file
		}
	}
	return 0;
}

// decoding function
void produceDecodingCipher(int encodeKey[], int decodeKey[], int size)
{
	for (int i = 0; i < size; i++) // Repeat the if statement for 26 numbers for i values
	{
		for (int j = 0; j < size; j++) // Repeat the if statemenet for 26 numbers for j values
		{
			if (encodeKey[j] == i) // Swap the numberes from the encoded text
			{
				decodeKey[i] = j; 
			}
		}
	}
}

// converting numbers into alphabets 
void useKeyOnString(int key[], int size, std::string text, std::string data, std::string &code)
{
	for (int i = 0; i < text.size(); i++) // Repeat the if statement for 26 numbers for i values
	{
		for (int j = 0; j < data.size(); j++) // Repeat the if statement for 26 numbers for j values
		{
			if (text[i] == data[j]) // Convert numbers from the text into alphabets from the data
			{
				code = code + data[key[j]]; // This is the finak answer the user wanted
			}
		}
	}
	cout << "The text is now: " << code << endl; // Show the final answer
	return;
}
