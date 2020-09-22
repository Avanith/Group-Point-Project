// File Name: main.cpp
// Authors: Zoga Duka, Gustavo Rosales, Daniel Targonski
// Date: 9/9/2020
// Assignment: Bag of points - group project

#include<iostream>
#include"Bag.h"
#include"Point.h"
#include<fstream>

using namespace std;

// Input: Gets an integer from user and makes sure it's an integer.
// Output: None.
// Post-condition: returns the integer that was input from the user.
int get_user_input();

int main()
{
	int x, y, i, guessX, guessY;
	ifstream in;
	in.open("points.txt");
	Bag<Point> pointBag;
	char yOrN;

	if (!in)
	{
		std::cout << "Error opening file.\n";
		return -1;
	} // end if

	in >> x >> y;
	while (!in.eof())
	{
		Point aPoint(x, y);

		if (!pointBag.add(aPoint)) // Breaks out of the while loop if the bag is full.
		{
			std::cout << "The pointBag is full!\n";
			break;
		} // end if
		in >> x >> y;
	} // end while


	// Creating a vector to clone pointBag.
	// We create this here before the guessing game because correctly guessed points remove points from the bag.
	vector<Point> vectorPointBag = pointBag.toVector();

	cout << "Do you want to guess for pairs in the bag? [y\\n]\n";
	cin >> yOrN;
	if (yOrN == 'y' || yOrN == 'Y')
	{

		std::cout << "Guess a pair of x and y coordinates to see if the bag contains it (enter an x, then a y int from 0-2): \n";
		std::cout << "Correct guesses will remove the pair from the bag. The loop will end when there are no pairs left.\n";

		while (!pointBag.isEmpty())
		{
			std::cout << "Input another pair of coordinates or enter -999 to exit.\n";
			guessX = get_user_input();
			if (guessX == -999)
				break;
			guessY = get_user_input();
			if (guessY == -999)
				break;

			// Have the user input a pair of coordinates to check against the bag.
			Point guessPair(guessX, guessY);

			if (pointBag.contains(guessPair))
			{
				std::cout << "The pair: ";
				guessPair.display();
				std::cout << " is in the bag.\n";
				pointBag.remove(guessPair);
				cout << "There are " << pointBag.getCurrentSize() << " pairs left.\n";
				if (pointBag.isEmpty())
					break;
			}
			else
			{
				std::cout << "The pair: ";
				guessPair.display();
				std::cout << " is not the bag.\n";
			} // end if

		} // end while
	} // end if

	//Displaying the pairs in the pointBag.
	std::cout << "The contents of the pointBag initially were: \n";
	for (i = 0; i < vectorPointBag.size(); i++)
	{
		vectorPointBag[i].display();
		std::cout << endl;
	} // end for

	return 0;
} // end main

int get_user_input() {
	while (true) {
		std::cout << "> ";
		int guess{};
		std::cin >> guess;

		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Invalid input.\n";
		}
		else {
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			return guess;
		}
	}
}
