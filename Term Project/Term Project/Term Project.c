#define _CRT_SECURE_NO_WARNINGS

// Necessary libraries
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

int size = 10; // Maximum size limit for words



// Function declarations
void Draw(int planePos, int bombPosX, int bombPosY, int score, char codeword[]);	// This function will draw and update the screen the whole game
void Change(char string[]);														// This function will change the codeword as the user types it
void NewWord(char word[], int row, int size);									// This function will pick a word from the codewords list

int main(void) {

	//Positions
	int planePos = 1;
	int bombPosX = 1;
	int bombPosY = 1;
	int row = 1; // Row is the line we are reading in the file;
	int score = 0;
	int newScore = 0; // The score for the current codeword
	int speed = 1; // Bomb speed;


	char word[10] = { " " }; // Initalize the first word
	NewWord(word, row, 10);
	row++;

	char c = ' ';

	int time1 = clock(); // Create a time clock to use later as time between movements

	while (1) {
		int time2 = clock(); // Another time clock to use as time between movements

		if (strlen(word) == 0) { // If the last codeword is written by the user

			NewWord(word, row, 10);
			row++;

			bombPosY = 1;
			bombPosX = planePos; // Plane drops bomb from its own position
			score = score + newScore; // Update the score
			newScore = 0; // Reset the new score for the new word;
			Draw(planePos, bombPosX, bombPosY, score, word); // Draw the game since the word and score are updated

			// Every 5 successful answer speeds up the bomb;
			if (row - 1 % 5 == 0) {
				speed++;
			}

		}

		while (_kbhit()) { // Check keyboard hits
			c = _getch();
			printf("%c", c);

			// Every wrong typed key reduces the score by 1
			if (c != word[0]) {

				newScore--;

			}

			// If the typed key is the same as codeword's first letter, score is increased by 1
			else if (c == word[0]) {
				Change(word);
				Draw(planePos, bombPosX, bombPosY, score, word); // Every true key type updates the screen
				newScore++;

			}
		}

		// Make move if the movement time has come
		if (time2 - time1 > 400) { // Time in milliseconds between moves

			// Plane's rightmost position is picked as 60 because so the bombs land on the city
			if (planePos < 60) { // If the plane is not at the console's rightmost position, move right
				planePos++;
			}

			else if (planePos >= 60) { // If the plane is at the console's rightmost position, move back to the start
				planePos = 1;
			}

			if (bombPosY < 18) { // If the bomb is over the city, move down
				bombPosY = bombPosY + speed;
			}
			else if (bombPosY >= 18) { // If the bomb reached the city, game is over

				system("cls");


				printf("Game Over.\n");
				getchar();

			}


			Draw(planePos, bombPosX, bombPosY, score, word);
			time1 = clock();
		}
	}

	return 0;
}


void NewWord(char word[], int row, int size) {

	int i = 0;
	FILE* wordptr; // Point to file

	if ((wordptr = fopen("codewords.txt", "r")) == NULL) { // Check if file is there
		printf("The file cannot be opened.\n");
	}

	else {
		while (i < row) { // Loop the rows one by one
			fscanf_s(wordptr, "%s", word, 11); // read file
			i++;
		}

	}

	fclose(wordptr);

}

// Draw the entire screen
void Draw(int planePos, int bombPosX, int bombPosY, int score, char codeword[]) {
	
	system("cls"); // Clear the screen

	// Draw the space behind the plane as the plane moves on
	for (int left = planePos - 1; left > 0; left--) {
		printf(" ");
	}

	// Draw the plane's top row
	printf("(|__.-. |");

	// Draw the space between the plane and the score
	for (int right = 80 - planePos; right > 0; right--) {
		printf(" ");
	}

	// Draw score
	printf("Score: ");
	printf("%d\n", score);


	// Draw the plane's middle row
	for (int left = planePos - 1; left > 0; left--) {
		printf(" ");
	}
	printf("== ===_]+\n");


	// Draw the plane's bottom row
	for (int left = planePos - 1; left > 0; left--) {
		printf(" ");
	}
	printf("        |\n");

	// Draw the spaces between the plane and the bomb
	for (int up = bombPosY - 1; up > 0; up--) {
		printf("\n");
	}

	// Space between the left side and the bomb's top row
	for (int left = bombPosX - 1; left > 0; left--) {
		printf(" ");

	}

	printf("   <|>\n"); // Draw the bomb's top row

	// Space between the left side and the bomb's middle row
	for (int left = bombPosX - 1; left > 0; left--) {
		printf(" ");

	}

	printf("    |"); // Draw the bomb's middle row
	printf("%s \n", codeword); // The codeword

	// Space between the left side and the bomb's bottom row
	for (int left = bombPosX - 1; left > 0; left--) {
		printf(" ");
	}

	printf("    *\n"); // // Draw the bomb's bottom row

	//Draw the space between the bomb and the city
	for (int down = 18 - bombPosY; down > 0; down--) {
		printf("\n");
	}


	//Draw the city
	printf(" _____        _____    _________________ ________    _________\n");
	printf("|o o o|_______|    |__|               | | # # # |____|o o o o|\n");
	printf("|o o o|* * *|: ::|. . |               |o| # # # |. . |o o o o|\n");
	printf("|o o o|* * *|::  |. . | []  []  []  []|o| # # # |. . |o o o o|\n");
	printf("|o o o|**** |:  :| . .| []  []  []    |o| # # # |. . |o o o o|\n");
	printf("|_[]__|__[]_|_||_|__< |____________;;_|_|___[]__|_.|_|__[]___|\n");
}



// Edit the word as the user types it by removing the first letter
void Change(char string[]) {
	int i, length = strlen(string);


	for (i = 1; i < length + 1; i++) {
		string[i - 1] = string[i];
	}

}