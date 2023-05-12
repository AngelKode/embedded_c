/*
main:
	
	/*
	//Rock, paper, scisor game
	srand(time(NULL));
	bool isGameActive = true;
	int userSelection = 0;
	//If something go wrong, exit
	if (!(user != NULL && computer != NULL)) {
		exit(EXIT_FAILURE);
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
				checkGame();
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

#include <time.h>
#include <random>
#include <windows.h>
* enum Choices{
	ROCK = 0,
	PAPER = 1,
	SCISSORS = 2
};

class Player{
public:
	char* name;
	int victoryCount;
	int loseCount;
	int choice;
	Player() {
		name = NULL;
		victoryCount = 0;
		loseCount = 0;
		choice = -1;
	}
};

constexpr int NUMBER_CHOICES = 3;
constexpr int MAX_AGAINST_CHOICES = (NUMBER_CHOICES - 1);

Player* user =new Player();
Player* computer = new Player();
size_t listTypeSize = sizeof(int);

int* numberChoice();
void checkGame();
void checkComputerChoices(int*, int*);
int* numberChoice() {
	//Return a choice number between 0 and choice count
	int choice = (int)(rand() % NUMBER_CHOICES);
	return &choice;
}

void checkGame() {
	//When user selects rock
	if (user->choice == ROCK + 1) {
		checkComputerChoices((int*)PAPER, (int*) SCISSORS );
		return;
	}

	//When user selects paper
	if (user->choice == PAPER + 1) {
		checkComputerChoices((int*)SCISSORS, (int*)ROCK);
		return;
	}

	//When user selects scissors
	if (user->choice == SCISSORS + 1) {
		checkComputerChoices((int*)ROCK , (int*)PAPER);
		return;
	}
}

void checkComputerChoices(int* weakAgainst, int* strongAgainst) {
	size_t weakAgainstSize = sizeof(weakAgainst);
	size_t strongAgainstSize = sizeof(strongAgainst);

	for (int i = 0; i < (weakAgainstSize / listTypeSize) - 1;i++) {
		if (weakAgainst[i] + 1 == computer->choice + 1) {
			computer->victoryCount++;
			user->loseCount++;
			printf_s("Computer wins!!!");
			Sleep(5000);
			return;
		}
	}
	for (int i = 0; i < (strongAgainstSize / listTypeSize) - 1; i++) {
		if (strongAgainst[i] + 1 == computer->choice + 1) {
			computer->loseCount++;
			user->victoryCount++;
			printf_s("User wins!!!");
			Sleep(5000);
			return;
		}
	}

	printf_s("Tie");
	Sleep(5000);
}
*/