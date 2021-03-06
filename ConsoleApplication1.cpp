// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <string>
#include <sstream> 
#include <time.h>

using namespace std;

//Makes A Board And Assigns Coordinates To A 2D Array
string** makeBoard(const int h, int w) {
	char letter[10] = { 'a','b','c','d','e','f','g','h','i','j' };
	int counter = 0;
	string pos;
	string **ary = new string*[h];
	for (int i = 0; i < h; ++i) {
		ary[i] = new string[w];
	}

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			pos = letter[i] + to_string(counter % 10);
			ary[i][j] = pos;
			counter++;
		}

	}

	return ary;
}


//Places Ship - 5 ships (2,3,3,4,5)
//Function takes the board and the starting coordinates of each ship
//The coordinates contain starting (a1) and the direction of the ship (left, right, up, down)
void placeShip(string** board, string cor, string corD, int shipLength) {
	char letterInCor = cor[0];
	int indexOfLetter;
	int numberCor = (int)cor[1] - 48;
	char letter[10] = { 'a','b','c','d','e','f','g','h','i','j' };
	for (int i = 0; i < sizeof(letter); i++) {
		if (letter[i] == letterInCor) {
			indexOfLetter = i;
		}
	}
	if (corD == "UP") {
		for (int i = 0; i < shipLength; i++) {
			board[indexOfLetter][numberCor-i] = "S ";
		}
	}
	if (corD == "RIGHT") {
		for (int i = 0; i < shipLength; i++) {
			board[indexOfLetter + i][numberCor] = "S ";
		}
	}
	if (corD == "LEFT") {
		for (int i = 0; i < shipLength; i++) {
			board[indexOfLetter - i][numberCor] = "S ";
		}
	}
	if (corD == "DOWN") {
		for (int i = 0; i < shipLength; i++) {
			board[indexOfLetter][numberCor + i] = "S ";
		}
	}

}

void instructions(string ** board, int ship) {
	string cor;
	string direction;

	cout << "Place your ship with length: " + to_string(ship) << endl;
	cout << "Choose the starting coordinate for the ship" << endl;
	cin >> cor; 
	cout << "Choose the direction of the ship" << endl;
	cin >> direction;

	placeShip(board, cor, direction, ship);
}

void computerShips(string ** board, int shipLength) {
	string corDirection[4] = { "UP", "DOWN", "RIGHT", "LEFT" };

	string corD = corDirection[rand() % 4];
	int indexOfLetter = rand() % 3 + 4;
	int numberCor = rand() % 3 + 4;

	if (corD == "UP") {
		for (int i = 0; i < shipLength; i++) {
			board[indexOfLetter][numberCor - i] = "S ";
		}
	}
	if (corD == "RIGHT") {
		for (int i = 0; i < shipLength; i++) {
			board[indexOfLetter + i][numberCor] = "S ";
		}
	}
	if (corD == "LEFT") {
		for (int i = 0; i < shipLength; i++) {
			board[indexOfLetter - i][numberCor] = "S ";
		}
	}
	if (corD == "DOWN") {
		for (int i = 0; i < shipLength; i++) {
			board[indexOfLetter][numberCor + i] = "S ";
		}
	}
}

void fire(string** board, string ** visualBoard, string cor) {
	char letter[10] = { 'a','b','c','d','e','f','g','h','i','j' };
	char corLetter = cor[0];
	int indexOfLetter;
	int corNumber = (int)cor[1] - 48;
	for (int i = 0; i < sizeof(letter); i++) {
		if (letter[i] == corLetter) {
			indexOfLetter = i;
		}
	}
	if (board[indexOfLetter][corNumber] != "X ")
	{
		if (board[indexOfLetter][corNumber] == "S ") {
			cout << "HIT" << endl;
			board[indexOfLetter][corNumber] = "X ";
			visualBoard[indexOfLetter][corNumber] = "X ";
		}
		else {
			cout << "Miss" << endl;
			board[indexOfLetter][corNumber] = "O ";
			visualBoard[indexOfLetter][corNumber] = "O ";
		}
	}

}

int main()
{
	srand(time(NULL));

	string ** memoryBoard = makeBoard(10, 10);
	string ** computerBoard = makeBoard(10, 10);
	string ** playerBoard = makeBoard(10, 10);

	cout << "Place Your Ships" << endl;
	instructions(playerBoard, 2);
	instructions(playerBoard, 3);
	instructions(playerBoard, 3);
	instructions(playerBoard, 4);
	instructions(playerBoard, 5);

	computerShips(memoryBoard, 2);
	computerShips(memoryBoard, 3);
	computerShips(memoryBoard, 3);
	computerShips(memoryBoard, 4);
	computerShips(memoryBoard, 5);
	

	while (true) {
		string cor = "";
		cout << "Enter Coordinate to FIRE!" << endl;
		cin >> cor;
		fire(memoryBoard, computerBoard, cor);

		//Print the Board in a 10x10 setting
		cout << "Memory BOARD" << endl << endl;
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				cout << memoryBoard[j][i] + " ";
			}
			cout << endl;
		}

		cout << "COMPUTER BOARD" << endl << endl;
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				cout << computerBoard[j][i] + " ";
			}
			cout << endl;
		}
		cout << endl << endl;
		cout << "YOUR BOARD" << endl << endl;
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				cout << playerBoard[j][i] + " ";
			}
			cout << endl;
		}

		////Testing
		//for (int i = 0; i < 10; i++) {
		//	for (int j = 0; j < 10; j++) {
		//		cout << computerBoard[i][j] << endl;
		//	}
		//}
	}
    return 0;
}

