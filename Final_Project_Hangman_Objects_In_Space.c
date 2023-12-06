/*

(2 pts) have a creative opening banner
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

	int    used[NUMWORDS] = { 0 };    // frequency count of words used so far
	int    wrongs = 0;            // count of wrong guesses
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

			for (loop = 0; loop < wordLen; loop++)
				printf("%c ", gword[loop]);

			printf("\n");

			guess = getguess();


			//(4 pts) update the wrong letter count to also display a list of wrong letters that
			//wrongLetters[j] = getguess();


			if (!processguess(challenge, gword, wordLen, guess))
				wrongs++;

			for (k = 0; k <= wordLen + 1; k++) {

				if (guess == gword[k]) {
					k = wordLen + 1;

				}
				else { //(guess != challenge[k]) {
					wrongLetters[j] = guess;
					k = wordLen + 1;
					j++;
				}
			}


			if (!won)
				won = checkwin(challenge, gword, wordLen);

			if (won)
			{
				for (loop = 0; loop < wordLen; loop++)
					printf("%c ", gword[loop]);
				printf("\n");
				printf("You win!\n");
				wrongs = 0;
				won = 0;
				break;
			}

			if (wrongs >= MAXGUESS)
			{
				drawfig(wrongs, wrongLetters, wordLen);
				printf("You lost! The word was %s\n", challenge);
				wrongs = 0;
				break;
			}

		}  /* end of inner while loop */

		printf("Do you want to play again? [y/n]: ");
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
	printf(CYAN"Your guess: "RESET);
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
	printf("**********************************************************\n");
	printf("\n");
	//FIXME
	printf(MAGENTA "BANNER>>>> " RESET);
	printf(MAGENTA "\t\t Coded by Dean Phillips\n" RESET);
	printf("**********************************************************\n\n");
}

//(2 pts) update wording in directions so the player knows how to play, what theme words to guess, etc.
void printInstructions() {
	puts(MAGENTA"\t\tWelcome to Hangman!");
	puts("\t\tTry to guess my secret word one letter at a time.");
	puts("\t\tThe theme of this game is OBJECTS IN SPACE,\n\t\tplanets would be a good guess but what other objects are in space?\n\t\tMan made obects are inclueded and also things that just pass by...");
	puts("\t\tYou can enter both uppercase and lowercase letters.");
	puts("\t\tYou have a total of 10 guesses ... Ready set go!!\n\n"RESET);
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
		printf(BLUE"Amount of wrong letters: %d\n\n"RESET, i);
		printf(BLUE"Previusly guessed letters:"RESET);
		for (int j = 0; j < i + WordLen; j++) {
			printf(" %c", WrongLetters[j]);
		}

		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf(GREEN"____________\n\n"RESET);
		break;
	case 1:
		printf(BLUE"Amount of wrong letters: %d\n\n"RESET, i);
		printf(BLUE"Previusly guessed letters:"RESET);
		for (int j = 0; j < i + WordLen; j++) {
			printf(" %c", WrongLetters[j]);
		}
		printf("\n");
		printf("\n");
		printf(CYAN"  |\n");
		printf("  |\n");
		printf("  |\n");
		printf("  |\n");
		printf("  |\n"RESET);
		printf(GREEN"__"RESET);
		printf(CYAN"|"RESET);
		printf(GREEN"_________\n\n"RESET);
		break;
	case 2:
		printf(BLUE"Amount of wrong letters: %d\n\n"RESET, i);
		printf(BLUE"Previusly guessed letters:"RESET);
		for (int j = 0; j < i + WordLen; j++) {
			printf(" %c", WrongLetters[j]);
		}

		printf("\n");
		printf("\n");
		printf(YELLOW"  _______\n"RESET);
		printf(CYAN"  |\n");
		printf("  |\n");
		printf("  |\n");
		printf("  |\n");
		printf("  |\n"RESET);
		printf(GREEN"__"RESET);
		printf(CYAN"|"RESET);
		printf(GREEN"_________\n\n"RESET);
		break;
	case 3:
		printf(BLUE"Amount of wrong letters: %d\n\n"RESET, i);
		printf(BLUE"Previusly guessed letters:"RESET);
		for (int j = 0; j < i + WordLen; j++) {
			printf(" %c", WrongLetters[j]);
		}

		printf("\n");
		printf("\n");
		printf(YELLOW"  _______\n"RESET);
		printf(CYAN"  |/\n");
		printf("  |\n");
		printf("  |\n");
		printf("  |\n");
		printf("  |\n"RESET);
		printf(GREEN"__"RESET);
		printf(CYAN"|"RESET);
		printf(GREEN"_________\n\n"RESET);
		break;
	case 4:
		printf(BLUE"Amount of wrong letters: %d\n\n"RESET, i);
		printf(BLUE"Previusly guessed letters:"RESET);
		for (int j = 0; j < i + WordLen; j++) {
			printf(" %c", WrongLetters[j]);
		}

		printf("\n");
		printf("\n");
		printf(YELLOW"  _______\n"RESET);
		printf(CYAN"  |/   |\n");
		printf("  |    ");
		printf(YELLOW"O\n"RESET);
		printf(CYAN"  |\n");
		printf("  |\n");
		printf("  |\n"RESET);
		printf(GREEN"__"RESET);
		printf(CYAN"|"RESET);
		printf(GREEN"_________\n\n"RESET);
		break;
		//body is drawn
	case 5:
		printf(BLUE"Amount of wrong letters: %d\n\n"RESET, i);
		printf(BLUE"Previusly guessed letters:"RESET);
		for (int j = 0; j < i + WordLen; j++) {
			printf(" %c", WrongLetters[j]);
		}

		printf("\n");
		printf("\n");
		printf(YELLOW"  _______\n"RESET);
		printf(CYAN"  |/   |\n");
		printf("  |    ");
		printf(YELLOW"O\n"RESET);
		printf(CYAN"  |    ");
		printf(YELLOW"|\n"RESET);
		printf(CYAN"  |"RESET);
		printf(YELLOW"    |\n"RESET);
		printf(CYAN"  |\n"RESET);
		printf(GREEN"__"RESET);
		printf(CYAN"|"RESET);
		printf(GREEN"_________\n\n"RESET);
		break;
		//left arm
	case 6:
		printf(BLUE"Amount of wrong letters: %d\n\n"RESET, i);
		printf(BLUE"Previusly guessed letters:"RESET);
		for (int j = 0; j < i + WordLen; j++) {
			printf(" %c", WrongLetters[j]);
		}

		printf("\n");
		printf("\n");
		printf(YELLOW"  _______\n"RESET);
		printf(CYAN"  |/   |\n");
		printf("  |    ");
		printf(YELLOW"O\n"RESET);
		printf(CYAN"  |   ");
		printf(YELLOW"\\|\n"RESET);
		printf(CYAN"  |"RESET);
		printf(YELLOW"    |\n"RESET);
		printf(CYAN"  |\n"RESET);
		printf(GREEN"__"RESET);
		printf(CYAN"|"RESET);
		printf(GREEN"_________\n\n"RESET);
		break;
		//right arm
	case 7:
		printf(BLUE"Amount of wrong letters: %d\n\n"RESET, i);
		printf(BLUE"Previusly guessed letters:"RESET);
		for (int j = 0; j < i + WordLen; j++) {
			printf(" %c", WrongLetters[j]);
		}

		printf("\n");
		printf("\n");
		printf(YELLOW"  _______\n"RESET);
		printf(CYAN"  |/   |\n");
		printf("  |    ");
		printf(YELLOW"O\n"RESET);
		printf(CYAN"  |   ");
		printf(YELLOW"\\|/\n"RESET);
		printf(CYAN"  |"RESET);
		printf(YELLOW"    |\n"RESET);
		printf(CYAN"  |\n"RESET);
		printf(GREEN"__"RESET);
		printf(CYAN"|"RESET);
		printf(GREEN"_________\n\n"RESET);
		break;
		//left leg
	case 8:
		printf(BLUE"Amount of wrong letters: %d\n\n"RESET, i);
		printf(BLUE"Previusly guessed letters:"RESET);
		for (int j = 0; j < i + WordLen; j++) {
			printf(" %c", WrongLetters[j]);
		}

		printf("\n");
		printf("\n");
		printf(YELLOW"  _______\n"RESET);
		printf(CYAN"  |/   |\n");
		printf("  |    ");
		printf(YELLOW"O\n"RESET);
		printf(CYAN"  |   ");
		printf(YELLOW"\\|/\n"RESET);
		printf(CYAN"  |"RESET);
		printf(YELLOW"    |\n"RESET);
		printf(CYAN"  |"RESET);
		printf(YELLOW"   /\n"RESET);
		printf(GREEN"__"RESET);
		printf(CYAN"|"RESET);
		printf(GREEN"_________\n\n"RESET);
		break;
		//right leg
	case 9:
		printf(BLUE"Amount of wrong letters: %d\n\n"RESET, i);
		printf(BLUE"Previusly guessed letters:"RESET);
		for (int j = 0; j < i + WordLen; j++) {
			printf(" %c", WrongLetters[j]);
		}

		printf("\n");
		printf("\n");
		printf(YELLOW"  _______\n"RESET);
		printf(CYAN"  |/   |\n");
		printf("  |    ");
		printf(YELLOW"O\n"RESET);
		printf(CYAN"  |   ");
		printf(YELLOW"\\|/\n"RESET);
		printf(CYAN"  |"RESET);
		printf(YELLOW"    |\n"RESET);
		printf(CYAN"  |"RESET);
		printf(YELLOW"   / \\\n"RESET);
		printf(GREEN"__"RESET);
		printf(CYAN"|"RESET);
		printf(GREEN"_________\n\n"RESET);
		break;
		//dead
	case 10:
		printf(BLUE"Amount of wrong letters: %d\n\n"RESET, i);
		printf(BLUE"Previusly guessed letters:"RESET);
		for (int j = 0; j < i + WordLen; j++) {
			printf(" %c", WrongLetters[j]);
		}

		printf("\n");
		printf("\n");
		printf(YELLOW"  _______\n"RESET);
		printf(CYAN"  |/   |\n");
		printf("  |    ");
		printf(RED"X\n"RESET);
		printf(CYAN"  |   ");
		printf(RED"\\|/\n"RESET);
		printf(CYAN"  |"RESET);
		printf(RED"    |\n"RESET);
		printf(CYAN"  |"RESET);
		printf(RED"   / \\\n"RESET);
		printf(GREEN"__"RESET);
		printf(CYAN"|"RESET);
		printf(GREEN"_________\n\n"RESET);
		break;
	}
	printf("\n");
	return;
}