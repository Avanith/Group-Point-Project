// File Name: main.cpp
// Authors: Zoga Duka, Gustavo Rosales, Daniel Targonski
// Date: 9/9/2020
// Assignment: Bag of points - group project

#include<iostream>
#include"Bag.h"
#include"Point.h"
#include<fstream>

using namespace std;

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
		return 1;
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
	vector<Point> vectorPointBag = pointBag.toVector();

	cout << "Do you want to guess for pairs in the bag? [y\\n]\n";
	cin >> yOrN;
	if (yOrN == 'y' || yOrN == 'Y')
	{
		std::cout << "Guess a pair of x and y coordinates to see if the bag contains it (enter an x, then a y int from 0-2): \n";
		std::cout << "Correct guesses will remove the pair from the bag. The loop will end when there are no pairs left.\n";
		cin >> guessX >> guessY;

		while (!pointBag.isEmpty())
		{
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

			std::cout << "Input another pair of coordinates or enter -999 to exit.\n";
			cin >> guessX;
			if (guessX == -999)
				break;
			cin >> guessY;
		} // end while
	} // end if

	//Displaying the pairs in the pointBag.
	std::cout << "The contents of the pointBag are: \n";
	for (i = 0; i < vectorPointBag.size(); i++)
	{
		vectorPointBag[i].display();
		std::cout << endl;
	} // end for

	return 0;
} // end main

