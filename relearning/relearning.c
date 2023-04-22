#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#define NUMBER_CHOICES 3

enum Choices{
	ROCK = 0,
	PAPER = 1,
	SCISSORS = 2
};

struct Player {
	char* name;
	int victoryCount;
	int loseCount;
	int choice;
};

int* numberChoice();
void checkGame(struct Player *, struct Player *);

int main() {
	
	//Assign dynamically memory
	//We cast malloc generic void response to int*, static size of 1
	/*
	int* dato1 = (int*) malloc(sizeof(int));

	//We cast malloc generic void response to int*, dynamic size depending user entry
	int integers_count = 0, *integers_list = NULL;

	printf_s("Enter size of the list: ");
	scanf_s("%d", &integers_count);
	
	integers_list = (int*) malloc(sizeof(int) * integers_count);

	//Print dynamic memory size reserved
	printf_s("Array size: %d\n",(int) sizeof(integers_list) * integers_count);
	for (int listIndex = 0; listIndex < integers_count; listIndex++) {
		printf_s("Enter integer value: ");
		scanf_s("%d", &integers_list[listIndex]);
	}
	
	//Print all enter values
	for (int listIndex = 0; listIndex < integers_count; listIndex++) {
		printf_s("Integer value: %d\n", integers_list[listIndex]);
	}

	//Free reserved space in memory
	free(integers_list);
	integers_list = NULL;
	*/

	//Rock, paper, scisor game
	srand(time(NULL));
	bool isGameActive = true;
	int userSelection = 0;
	struct Player* user = (struct Player *) malloc(sizeof(struct Player));
	struct Player* computer = (struct Player*) malloc(sizeof(struct Player));

	if (user != NULL) {
		user->name = "Angel";
		user->victoryCount = 0;
		user->loseCount = 0;
		user->choice = -1;
	}
	
	if (computer != NULL) {
		computer->name = "Computadora";
		computer->victoryCount = 0;
		computer->loseCount = 0;
		computer->choice = -1;
	}

	do {
		system("cls");
		printf_s("-----ROCK, PAPER, SCISORS------\n");
		printf_s("OPTIONS:\n");
		printf_s("1. Start/Keep playing\n");
		printf_s("2. Show partial score\n");
		printf_s("3. Exit\n");
		printf_s("SELECTED OPTION: ");
		scanf_s("%d", &userSelection);
		_flushall();//Clearing buffer

		switch (userSelection){
			case 1: {
				//Ask the user to enter an option
				system("cls");
				printf_s("Choose one: \n");
				printf_s("1. Rock\n");
				printf_s("2. Paper\n");
				printf_s("3. Scissors\n");
				printf_s("SELECTED OPTION: "); scanf_s("%d", &user->choice);

				//Generate random computer choice
				computer->choice = *numberChoice();

				//Check who wins
				checkGame(user, computer);
				break;
			};
			case 2: {
				system("cls");
				printf_s("----SCORE----\n");
				printf_s("USER %s -> Victory Count=%d - Lose Count=%d\n", user->name, user->victoryCount, user->loseCount);
				printf_s("USER %s -> Victory Count=%d - Lose Count=%d\n", computer->name, computer->victoryCount, computer->loseCount);
				printf_s("1. GO TO PRINCIPAL MENU\n");
				printf_s("2. EXIT\n");
				printf_s("OPCION ELEGIDA: ");
				scanf_s("%d", &userSelection);

				if (userSelection == 2) {
					exit(EXIT_SUCCESS);
				}
				break;
			};
			default: {
				isGameActive = false;
				free(user); user = NULL;
				free(computer); computer = NULL;
				break;
			}
		}
	} while (isGameActive);

	return 0;
}

int* numberChoice() {
	//Return a choice number between 0 and choice count
	int choice = (int)(rand() % NUMBER_CHOICES);
	return &choice;
}

void checkGame(struct Player *user, struct Player* computer) {
	//When user selects rock
	if (user->choice == ROCK + 1) {
		//Check first the non-winnable options
		if (computer->choice == ROCK + 1) {
			printf_s("Tie. No winners");
			Sleep(1500);
			return;
		}
		if (computer->choice == PAPER + 1) {
			printf_s("Computer wins!");
			computer->victoryCount++;
			user->loseCount++;
			Sleep(1500);
			return;
		}

		printf_s("User wins!");
		user->victoryCount++;
		computer->loseCount++;
		Sleep(1500);
		return;
	}

	//When user selects paper
	if (user->choice == PAPER) {

	}

	//When user selects scissors
	if (user->choice == SCISSORS) {

	}
}