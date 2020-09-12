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

	if (!in)
	{
		cout << "Error opening file.\n";
		return 1;
	} // end if

	in >> x >> y;
	while (!in.eof())
	{
		Point aPoint(x, y);

		if (!pointBag.add(aPoint)) // Breaks out of the while loop if the bag is full.
		{
			cout << "The pointBag is full!\n";
			break;
		} // end if
		in >> x >> y;
	} // end while

	// Have the user input a pair of coordinates to check against the bag.
	cout << "Guess a pair of x and y coordinates to see if the bag contains it (enter an x, then a y int from 1-5): \n";
	cin >> guessX >> guessY;
	Point guessPair(guessX, guessY);

	if (pointBag.contains(guessPair))
	{
		cout << "The pair: ";
		guessPair.display();
		cout << " is in the bag.\n";
	}
	else
	{
		cout << "The pair: ";
		guessPair.display();
		cout << " is not the bag.\n";
	} // end if

	//Displaying the pairs in the pointBag.
	cout << "The contents of the pointBag are: \n";
	vector<Point> vectorPointBag = pointBag.toVector();
	for (i = 0; i < vectorPointBag.size(); i++)
	{
		vectorPointBag[i].display();
		cout << endl;
	} // end for

	return 0;
} // end main

