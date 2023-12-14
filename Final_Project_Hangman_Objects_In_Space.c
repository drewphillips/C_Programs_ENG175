// Objects in Space, Final Project ENG175
// FIX ME, capitalize first letter of printed word, while still accepting lower case from user guess
// FIXME, dont add correct letter to wrongLetter arry 
/*
check out ideas from ASCII Art Generator
(4 pts) update the wrong letter count to also display a list of wrong letters that the user incorrectly guessed
(2 pts) game should compile and run smoothly without delay or interruption
(2 pts) loop the game until the user wants to quit
*/

#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAXLEN 20            // maximum word length
#define MAXGUESS 10            // maximum number of guesses allowed
#define NUMWORDS 26            // number of words in hangman's dictionary

int getword(int[]);            /* chooses a word from the dictionary for the user to guess -- uses a random number
									   generator to determine which word to choose; a counter array is used to prevent
									   the same word being used twice until all words have been exhausted */

void initguess(char[]);        // initializes array that holds user's correct guesses to '_' character

char getguess(void);        // reads in the letter guessed by the user

int processguess(char[], char[], int, char);    /* compares guessed letter with word to be guessed
												--if guess is correct, letter is placed in user's word array;
												otherwise, wrong guesses are counted */

int checkwin(char[], char[], int);    // checks to see if user has won by matching the two arrays

void showLogo();

void printInstructions();

void drawfig(const int, char wrongLetters[21], int WordLen);    // draws hangman figure based on the number of wrong guesses by the user

//****************************************** INT  MAIN  VOID  ***********************************************
int main(void) {



	//(1 pts) update all program code to reflect your approved theme
	//hangman dictionary:  List of Flowers a to z
	char* secrets[NUMWORDS] = { "akatsuki", "blackhole", "curiosity", "dscovr", "earth", "fortuna", "ganymed",
		"hayabusa", "iris", "jupiter", "kepler", "leda", "mars", "neptune",
		"opportunity", "pluto", "quasar", "rhea", "saturn", "tesla", "uranus", "venus",
		"wells", "xanadu", "ymir", "zhurong" };

	char gword[MAXLEN];            // array that holds user's correct guesses

	char guess;                    // letter guessed

	char* challenge;            // current word to be guessed

	int used[NUMWORDS] = { 0 };    // frequency count of words used so far
	int wrongs = 0;            // count of wrong guesses
	int wordLen;            // length of current hangman word
	int loop;                // loop counter
	int again = 1;            // flags 1 to play again 0 to quit game
	int won = 0;            // flags 1 if win and 0 if loss
	char wrongLetters[26];
	int j, k;
	char loopAgain;

	srand(time(NULL));            //sends a "seed" for random number generation


	while (again)
	{
		for (k = 0; k < 22; k++) {
			wrongLetters[k] = '\0';
		}
		j = 0;

		initguess(gword);
		challenge = secrets[getword(used)];
		wordLen = strlen(challenge);

		while (wrongs < MAXGUESS && !won)
		{
			drawfig(wrongs, wrongLetters, wordLen);
			printf("\t");
			for (loop = 0; loop < wordLen; loop++)
				printf("%c ", gword[loop]);

			printf("\n");

			guess = getguess();


			//(4 pts) update the wrong letter count to also display a list of wrong letters that



			if (!processguess(challenge, gword, wordLen, guess))
				wrongs++;

			//(4 pts) update the wrong letter count to also display a list of wrong letters that
			for (k = 0; k < wordLen; k++) {

				if (guess == gword[k]) {
					k = wordLen;

				}
				else {
					wrongLetters[j] = guess;
					k = wordLen;
					j++;
				}
			}


			if (!won)
				won = checkwin(challenge, gword, wordLen);

			if (won)
			{
				printf("\t");
				for (loop = 0; loop < wordLen; loop++)
					printf("%c ", gword[loop]);
				printf("\n");
				printf("\tYou win!\n");
				wrongs = 0;
				won = 0;
				break;
			}

			if (wrongs >= MAXGUESS)
			{
				drawfig(wrongs, wrongLetters, wordLen);
				printf("\tYou lost! The word was %s\n", challenge);
				wrongs = 0;
				break;
			}

		}  /* end of inner while loop */

		printf("\tDo you want to play again? [y/n]: ");
		guess = getchar();
		getchar();
		if (guess == 'n' || guess == 'N')
			again = 0;
	} /* end of outer while loop */

	return 0;
}

int getword(int uct[])
{
	int index, i, sum = 0;

	/* reinitialize used word count to 0 if all words
	have been used -- start recycling */

	for (i = 0; i < NUMWORDS; i++)
		if (uct[i] != 0)
			sum++;
	if (sum == NUMWORDS)
		for (i = 0; i < NUMWORDS; i++)
			uct[i] = 0;

	index = rand() % NUMWORDS;    /* generate a candidate for the challenge */

	while (uct[index])
		index = rand() % NUMWORDS;    /* if this one has been used, get another */

	uct[index]++;        /* mark this index as used */
	return index;
}

void initguess(char g[])
{
	int i;
	for (i = 0; i < MAXLEN; ++i)
		g[i] = '_';
	return;
}

char getguess(void)
{
	char g;
	//(4 pts) add color to make your game more readable
	printf(CYAN"\tYour guess: "RESET);
	g = getchar();
	getchar();
	return g;
}

int processguess(char c[], char g[], int l, char gl)
{
	int i, hits = 0;
	for (i = 0; i <= l; i++)
	{
		if (c[i] == gl)
		{
			g[i] = gl;
			hits++;
		}
	}

	return hits;
}

int checkwin(char c[], char g[], int l)
{
	int i, matches = 0;
	for (i = 0; i < l; i++)
		if (c[i] == g[i])
			matches++;
	if (matches == l)
		return 1;
	else
		return 0;
}


void showLogo() {
	printf("\t***********************************************************\n");
	printf("\t                   \n");
	printf("\t     000000000            IIIIIIII        SSSSSSSSSSSSSSSS  \n");
	printf("\t   00:::::::::00          I::::::I      SS::::::::::::::::S \n");
	printf("\t 00:::::::::::::00        I::::::I     S:::::SSSSSSS::::::S \n");
	printf("\t0:::::::000:::::::0       II::::II     S:::::S      SSSSSSS \n");
	printf("\t0::::::0   0::::::0        I::::I      S:::::S              \n");
	printf("\t0:::::0     0:::::0        I::::I      S:::::S              \n");
	printf("\t0:::::0     0:::::0        I::::I       S::::SSSS           \n");
	printf("\t0:::::0     0:::::0        I::::I        SS::::::SSSSS      \n");
	printf("\t0:::::0     0:::::0        I::::I          SSS::::::::SS    \n");
	printf("\t0:::::0     0:::::0        I::::I             SSSSSS::::S   \n");
	printf("\t0:::::0     0:::::0        I::::I                  S:::::S  \n");
	printf("\t0::::::0   0::::::0        I::::I                  S:::::S  \n");
	printf("\t0:::::::000::::::0         I::::I      SSSSSSS     S:::::S  \n");
	printf("\t 00::::::::::::00         II::::II     S::::::SSSSSS:::::S  \n");
	printf("\t   00::::::::00           I::::::I     S:::::::::::::::SS   \n");
	printf("\t     00000000             IIIIIIII      SSSSSSSSSSSSSSS     \n");
	printf("\t                   \n");
	printf(CYAN"\t      OBJECTS                ");
	printf(BLUE"IN              "RESET);
	printf(MAGENTA"SPACE\n"RESET);
	//FIXME
	printf(MAGENTA "\t\n" RESET);
	puts(CYAN"\n\t\t\t     Welcome to Hangman!\n");
	printf(MAGENTA "\t\t\t    Coded by Drew Phillips\n" RESET);
	printf("\t***********************************************************\n\n");
}

//(2 pts) update wording in directions so the player knows how to play, what theme words to guess, etc.
void printInstructions() {
	//puts(MAGENTA"\t\tWelcome to Hangman!");
	puts(CYAN"\tTry to guess my secret word one letter at a time.");
	puts("\tThe theme of this game is OBJECTS IN SPACE!\n\tPlanets would be a good guess but what other objects are in space?\n\tMan made obects are inclueded and also things that just pass by...");
	puts("\tYou can enter both uppercase and lowercase letters.");
	puts("\tYou have a total of 10 guesses ... Ready set go!!\n\n"RESET);
}

void drawfig(const int i, char WrongLetters[21], int WordLen)
{

	//clrscr();


	showLogo();

	printInstructions();
	//(4 pts) update the hangman noose to a more creative one
	switch (i)
		/* Each case draws a different part of the hangman stick figure.
		Larger cases intentionally fall through to smaller ones, so
		the drawing is built from the bottom up. */
	{
	case 0:
		printf(BLUE"\tAmount of wrong letters: %d\n\n"RESET, i);
		printf(BLUE"\tPreviusly guessed letters:"RESET);
		for (int j = 0; j < i + WordLen; j++) {
			printf(" %c", WrongLetters[j]);
		}

		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf(GREEN"\t____________\n\n"RESET);
		break;
	case 1:
		printf(BLUE"\tAmount of wrong letters: %d\n\n"RESET, i);
		printf(BLUE"\tPreviusly guessed letters:"RESET);
		for (int j = 0; j < i + WordLen; j++) {
			printf(" %c", WrongLetters[j]);
		}
		printf("\n");
		printf("\n");
		printf(CYAN"\t  |\n");
		printf("\t  |\n");
		printf("\t  |\n");
		printf("\t  |\n");
		printf("\t  |\n"RESET);
		printf(GREEN"\t__"RESET);
		printf(CYAN"|"RESET);
		printf(GREEN"_________\n\n"RESET);
		break;
	case 2:
		printf(BLUE"\tAmount of wrong letters: %d\n\n"RESET, i);
		printf(BLUE"\tPreviusly guessed letters:"RESET);
		for (int j = 0; j < i + WordLen; j++) {
			printf(" %c", WrongLetters[j]);
		}

		printf("\n");
		printf("\n");
		printf(YELLOW"\t  _______\n"RESET);
		printf(CYAN"\t  |\n");
		printf("\t  |\n");
		printf("\t  |\n");
		printf("\t  |\n");
		printf("\t  |\n"RESET);
		printf(GREEN"\t__"RESET);
		printf(CYAN"|"RESET);
		printf(GREEN"_________\n\n"RESET);
		break;
	case 3:
		printf(BLUE"\tAmount of wrong letters: %d\n\n"RESET, i);
		printf(BLUE"\tPreviusly guessed letters:"RESET);
		for (int j = 0; j < i + WordLen; j++) {
			printf(" %c", WrongLetters[j]);
		}

		printf("\n");
		printf("\n");
		printf(YELLOW"\t  _______\n"RESET);
		printf(CYAN"\t  |/\n");
		printf("\t  |\n");
		printf("\t  |\n");
		printf("\t  |\n");
		printf("\t  |\n"RESET);
		printf(GREEN"\t__"RESET);
		printf(CYAN"|"RESET);
		printf(GREEN"_________\n\n"RESET);
		break;
	case 4:
		printf(BLUE"\tAmount of wrong letters: %d\n\n"RESET, i);
		printf(BLUE"\tPreviusly guessed letters:"RESET);
		for (int j = 0; j < i + WordLen; j++) {
			printf(" %c", WrongLetters[j]);
		}

		printf("\n");
		printf("\n");
		printf(YELLOW"\t  _______\n"RESET);
		printf(CYAN"\t  |/   |\n");
		printf("\t  |    ");
		printf(YELLOW"O\n"RESET);
		printf(CYAN"\t  |\n");
		printf("\t  |\n");
		printf("\t  |\n"RESET);
		printf(GREEN"\t__"RESET);
		printf(CYAN"|"RESET);
		printf(GREEN"_________\n\n"RESET);
		break;
		//body is drawn
	case 5:
		printf(BLUE"\tAmount of wrong letters: %d\n\n"RESET, i);
		printf(BLUE"\tPreviusly guessed letters:"RESET);
		for (int j = 0; j < i + WordLen; j++) {
			printf(" %c", WrongLetters[j]);
		}

		printf("\n");
		printf("\n");
		printf(YELLOW"\t  _______\n"RESET);
		printf(CYAN"\t  |/   |\n");
		printf("\t  |    ");
		printf(YELLOW"O\n"RESET);
		printf(CYAN"\t  |    ");
		printf(YELLOW"|\n"RESET);
		printf(CYAN"\t  |"RESET);
		printf(YELLOW"    |\n"RESET);
		printf(CYAN"\t  |\n"RESET);
		printf(GREEN"\t__"RESET);
		printf(CYAN"|"RESET);
		printf(GREEN"_________\n\n"RESET);
		break;
		//left arm
	case 6:
		printf(BLUE"\tAmount of wrong letters: %d\n\n"RESET, i);
		printf(BLUE"\tPreviusly guessed letters:"RESET);
		for (int j = 0; j < i + WordLen; j++) {
			printf(" %c", WrongLetters[j]);
		}

		printf("\n");
		printf("\n");
		printf(YELLOW"\t  _______\n"RESET);
		printf(CYAN"\t  |/   |\n");
		printf("\t  |    ");
		printf(YELLOW"O\n"RESET);
		printf(CYAN"\t  |   ");
		printf(YELLOW"\\|\n"RESET);
		printf(CYAN"\t  |"RESET);
		printf(YELLOW"    |\n"RESET);
		printf(CYAN"\t  |\n"RESET);
		printf(GREEN"\t__"RESET);
		printf(CYAN"|"RESET);
		printf(GREEN"_________\n\n"RESET);
		break;
		//right arm
	case 7:
		printf(BLUE"\tAmount of wrong letters: %d\n\n"RESET, i);
		printf(BLUE"\tPreviusly guessed letters:"RESET);
		for (int j = 0; j < i + WordLen; j++) {
			printf(" %c", WrongLetters[j]);
		}

		printf("\n");
		printf("\n");
		printf(YELLOW"\t  _______\n"RESET);
		printf(CYAN"\t  |/   |\n");
		printf("\t  |    ");
		printf(YELLOW"O\n"RESET);
		printf(CYAN"\t  |   ");
		printf(YELLOW"\\|/\n"RESET);
		printf(CYAN"\t  |"RESET);
		printf(YELLOW"    |\n"RESET);
		printf(CYAN"\t  |\n"RESET);
		printf(GREEN"\t__"RESET);
		printf(CYAN"|"RESET);
		printf(GREEN"_________\n\n"RESET);
		break;
		//left leg
	case 8:
		printf(BLUE"\tAmount of wrong letters: %d\n\n"RESET, i);
		printf(BLUE"\tPreviusly guessed letters:"RESET);
		for (int j = 0; j < i + WordLen; j++) {
			printf(" %c", WrongLetters[j]);
		}

		printf("\n");
		printf("\n");
		printf(YELLOW"\t  _______\n"RESET);
		printf(CYAN"\t  |/   |\n");
		printf("\t  |    ");
		printf(YELLOW"O\n"RESET);
		printf(CYAN"\t  |   ");
		printf(YELLOW"\\|/\n"RESET);
		printf(CYAN"\t  |"RESET);
		printf(YELLOW"    |\n"RESET);
		printf(CYAN"\t  |"RESET);
		printf(YELLOW"   /\n"RESET);
		printf(GREEN"\t__"RESET);
		printf(CYAN"|"RESET);
		printf(GREEN"_________\n\n"RESET);
		break;
		//right leg
	case 9:
		printf(BLUE"\tAmount of wrong letters: %d\n\n"RESET, i);
		printf(BLUE"\tPreviusly guessed letters:"RESET);
		for (int j = 0; j < i + WordLen; j++) {
			printf(" %c", WrongLetters[j]);
		}

		printf("\n");
		printf("\n");
		printf(YELLOW"\t  _______\n"RESET);
		printf(CYAN"\t  |/   |\n");
		printf("\t  |    ");
		printf(YELLOW"O\n"RESET);
		printf(CYAN"\t  |   ");
		printf(YELLOW"\\|/\n"RESET);
		printf(CYAN"\t  |"RESET);
		printf(YELLOW"    |\n"RESET);
		printf(CYAN"\t  |"RESET);
		printf(YELLOW"   / \\\n"RESET);
		printf(GREEN"\t__"RESET);
		printf(CYAN"|"RESET);
		printf(GREEN"_________\n\n"RESET);
		break;
		//dead
	case 10:
		printf(BLUE"\tAmount of wrong letters: %d\n\n"RESET, i);
		printf(BLUE"\tPreviusly guessed letters:"RESET);
		for (int j = 0; j < i + WordLen; j++) {
			printf(" %c", WrongLetters[j]);
		}

		printf("\n");
		printf("\n");
		printf(YELLOW"\t  _______\n"RESET);
		printf(CYAN"\t  |/   |\n");
		printf("\t  |    ");
		printf(RED"X\n"RESET);
		printf(CYAN"\t  |   ");
		printf(RED"\\|/\n"RESET);
		printf(CYAN"\t  |"RESET);
		printf(RED"    |\n"RESET);
		printf(CYAN"\t  |"RESET);
		printf(RED"   / \\\n"RESET);
		printf(GREEN"\t__"RESET);
		printf(CYAN"|"RESET);
		printf(GREEN"___");
		printf(RED"___"RESET);
		printf(GREEN"___"RESET);
		break;
	}
	printf("\n");
	return;
}