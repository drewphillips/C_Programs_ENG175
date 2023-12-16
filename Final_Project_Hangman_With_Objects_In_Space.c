/*
ENG175 Final Project, Code improvements by Drew Phillips.

Additional improvements, The loop again options was changed to include a Cheet Sheet to see all the words.
It crossed my mind that people will have a hard time with some of the words,
The menu won't actually let people quit, the only way to end the program is to hit the "C" option,
and call the cheat sheet function, This was intentional, I'll be sending this to friends and family.

FIXME Don't add the correct letter to wrongLetter array.

FIXME Capitalize the first letter of the word once displayed.
            if (gword[0] != '_') {
                gword[0] = toupper(gword[0]);
                }
This was the code I wrote to try to do this by it was conflicting with the display of the challenge word.
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
#include <ctype.h>

#define MAXLEN 20            // maximum word length
#define MAXGUESS 10            // maximum number of guesses allowed
#define NUMWORDS 26            // number of words in hangman's dictionary

void CheetSheet();

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
        "opportunity", "pluto", "quasar", "rhea", "sylvia", "tesla", "uranus", "venus",
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
    char loopAgain = 'y';

    srand(time(NULL));            //sends a "seed" for random number generation

    do {

        //Clear the wrong letter array for each new game
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

            //Custom Fix, Capitalize the first letter once guessed. 
           // if (gword[0] != '_') {
             //   gword[0] = toupper(gword[0]);
               // }

            for (loop = 0; loop < wordLen; loop++)

                printf("%c ", gword[loop]);

            printf("\n");

            guess = getguess();

            if (!processguess(challenge, gword, wordLen, guess))
                wrongs++;
            
            //(4 pts) update the wrong letter count to also display a list of wrong letters that the user incorrectly guessed

           // for (k = 0; k < wordLen; k ++) {

             //   if (guess == gword[k]) {
               // k = wordLen; 

                //}
               // else { 
                //wrongLetters[j] = guess;
                //k = wordLen;
                //j++;
               // }
          //  }

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

        //(2 pts) loop the game until the user wants to quit
        printf("\tDo you want to play again? [y/n]: ");
        scanf(" %c", &loopAgain);
        loopAgain = tolower(loopAgain);

        if (loopAgain == 'c') {
            CheetSheet();
        }

        else if (loopAgain != 'y') {
            printf("\n\tThe words used in this program are hard to guess,\n");
            printf("\tTry again and when asked if you want to play again, press the letter 'C'\n");
            printf("\tThis will show a list of the words used in this porgram.\n");
            printf("\n\tAre you really sure you want to quit? Y/N"); //this is meant to be a trick question
            scanf(" %c", &loopAgain);
        }

    } while (loopAgain == 'y' || loopAgain == 'n'); // end of outer do while loop

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

void initguess(char g[]) {
    int i;
    for (i = 0; i < MAXLEN; ++i)
        g[i] = '_';
    return;
}

char getguess(void) {
    char g;
    //(4 pts) add color to make your game more readable
    printf(CYAN"\tYour guess: "RESET);
    g = getchar();
    getchar();
    return g;
}

/*this is the code to understand, and maybe use to fix the wrong letter array from adding correct letters. 

prototype:  int processguess(char[], char[], int, char);     compares guessed letter with word to be guessed
                                                --if guess is correct, letter is placed in user's word array;
                                                otherwise, wrong guesses are counted
Call:  if (!processguess(challenge, gword, wordLen, guess))  // why !not(processguess(challange....
                wrongs++;
*/

int processguess(char c[], char g[], int l, char gl) {
    int i, hits = 0;
    for (i = 0; i <= l; i++) //run through the challenge word array
    {
        if (c[i] == gl)  //if index of challenge word compares to the guessed letter, 
        {
            g[i] = gl;  //set the correct letters array to the letter guessed.
            hits++;   // What does hits do? it returns to what?
        }
    }

    return hits;
}

int checkwin(char c[], char g[], int l) {
    int i, matches = 0;
    for (i = 0; i < l; i++)
        if (c[i] == g[i])
            matches++;
    if (matches == l)
        return 1;
    else
        return 0;
}

//(2 pts) have a creative opening banner, check out ideas from ASCII Art Generator
void showLogo() {
    printf("\t**************************************************************\n");
    printf(YELLOW"\t         *               *                         \\      ");
    printf(CYAN"O    \n"RESET);
    printf(YELLOW"\t     *          "RESET);
    printf(CYAN"()      ");
    printf(YELLOW"/          "RESET);
    printf(MAGENTA"^"RESET);
    printf(YELLOW "                *          \n"RESET);
    printf(MAGENTA"\t  ^"RESET);
    printf(YELLOW"                                     *                     \n"RESET);
    printf("\t     000000000");
    printf(YELLOW"     *"RESET);
    printf("      IIIIIIII          SSSSSSSSSSSSSSSS  \n");
    printf("\t   00::"RESET);
    printf(YELLOW"*"RESET);
    printf("::::::00          I::::::I        SS::::::::::::::::S \n");
    printf("\t 00:::");
    printf(RED"/"RESET);
    printf(":::::::::00        I:::");
    printf(MAGENTA"O"RESET);
    printf("::I       S:::::SSSSSSS::::::S \n");
    printf("\t0::::");
    printf(RED"/"RESET);
    printf("::000:::::::0       II::::II       S::");
    printf(YELLOW"*"RESET);
    printf("::S      SSSSSSS \n");
    printf("\t0::::::0   0::::::0        I::::I        S:::::S     ");
    printf(RED"\\       \n"RESET);
    printf("\t0:::::0     0:::::0    ");
    printf(YELLOW"*"RESET);
    printf("   I::::I        S:::::S      ");
    printf(RED"\\       "RESET);
    printf("       \n");
    printf("\t0:::::0     0:::::0   ");
    printf(RED"/"RESET);
    printf("    I::::I         S::::SSSS    ");
    printf(YELLOW"*       \n"RESET);
    printf("\t0:::::0     0:::::0  ");
    printf(RED"/"RESET);
    printf("     I::::I          SS::::::SSSSS      \n");
    printf("\t0::");
    printf(MAGENTA"O"RESET);
    printf("::0     0:::::0        I::::I    ");
    printf(RED"\\"RESET);
    printf("      SSS::::::::SS    \n");
    printf("\t0:::::0     0:::::0        I::::I     ");
    printf(RED"\\"RESET);
    printf("        SSSSSSS::::S   \n");
    printf("\t0::");
    printf(YELLOW"*"RESET);
    printf("::0     0:::::0        I::::I      ");
    printf(YELLOW"*"RESET);
    printf("             S::");
    printf(MAGENTA"O"RESET);
    printf("::S  \n");
    printf("\t0::::::0   0::::::0        I::::I                    S:::::S  \n");
    printf("\t0:::::::000::::::0    ");
    printf(CYAN"()"RESET);
    printf("   I::::I         SSSSSSS    S:::::S  \n");
    printf("\t 00::::::::::::00         II::::II       S::::::SSSSSS:::::S  \n");
    printf("\t   00::::::::00     ");
    printf(YELLOW"*"RESET);
    printf("     I::::::I       S:::::");
    printf(MAGENTA"O"RESET);
    printf(":::::::::SS   \n");
    printf("\t     00000000             IIIIIIII        SSSSSSSSSSSSSSS     \n");
    printf("\t                   \n");
    printf(CYAN"\t      OBJECTS                ");
    printf(BLUE"IN                "RESET);
    printf(MAGENTA"SPACE\n"RESET);
    printf(YELLOW "\t\t\t*                        *\n" RESET);
    puts(CYAN"\n\t\t ()\t     Welcome to Hangman!\n");
    printf(YELLOW "\t\t*"RESET);
    printf(MAGENTA "\t    Coded by Drew Phillips         "RESET);
    printf(CYAN"()\n" RESET);
    printf("\t************************************************************\n\n");
    return;
}

//(2 pts) update wording in directions so the player knows how to play, what theme words to guess, etc.
void printInstructions() {
    //puts(MAGENTA"\t\tWelcome to Hangman!");
    puts(CYAN"\tTry to guess my secret word one letter at a time.");
    puts("\tThe theme of this game is OBJECTS IN SPACE!\n\tPlanets would be a good guess but what other objects are in space?\n\tMan made obects are inclueded and also things that just pass by...");
    puts("\tYou can enter uppercase or lowercase letters.");
    puts("\tYou get a total of 10 wrong guesses ... Ready set go!!!\n\n"RESET);
    return;
}

//(4 pts) update the hangman noose to a more creative one
void drawfig(const int i, char WrongLetters[21], int WordLen) {
    showLogo();
    printInstructions();
  
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

void CheetSheet() {
    showLogo();
    printf(CYAN"\t-----------------Cheet Sheet-----------------\n\n");
        printf("A) Akatsuki - A Japan Aerospace Exploration Agency (JAXA) space probe\n\t\t       tasked with studying the atmosphere of Venus.\n\n");
        printf("B) Blackhole - A black hole is a region of spacetime where gravity is so strong that nothing, including light and other electromagnetic waves, has enough energy to escape it.\n");
        printf("C) Curiosity - A car-sized Mars rover exploring Gale crater and Mount Sharp on Mars as part of NASA's Mars Science Laboratory (MSL) mission.\n");
        printf("D) Dscovr - Deep Space Climate Observatory is a National Oceanic and Atmospheric Administration space weather, space climate, and Earth observation satellite. It was launched by SpaceX on a Falcon 9 v1.1 launch vehicle on 11 February 2015, from Cape Canaveral\n\n");
        printf("E) Earth - You are here.\n\n");
        printf("F) Fortuna - One of the largest main-belt asteroids. It has a composition similar to 1 Ceres: a darkly colored surface that is heavily space-weathered with the composition of primitive organic compounds, including tholins.\n");
        printf("G) Ganymed - the largest and most massive natural satellite of Jupiter as well as in the Solar System, being a planetary-mass moon. It is the largest Solar System object without an atmosphere, despite being the only moon in the Solar System with a substantial magnetic field. Like Titan, it is larger than the planet Mercury, but has somewhat less surface gravity than Mercury, Io or the Moon.\n");
        printf("H) Hayabusa - Japan's Hayabusa was the first spacecraft to take samples from an asteroid, and was also the first mission to successfully land and take off from an asteroid. It brought samples from asteroid 25143 Itokawa to Earth on June 13, 2010.\n\n");
        printf("I) Iris - a large main-belt asteroid and possible remnant planetesimal orbiting the Sun between Mars and Jupiter. It is the fourth-brightest object in the asteroid belt. 7 Iris is classified as an S-type asteroid, meaning that it has a stony composition.\n\n");
        printf("J) Jupiter - the fifth planet from the Sun and the largest in the Solar System. It is a gas giant with a mass more than two and a half times that of all the other planets in the Solar System combined, and slightly less than one one-thousandth the mass of the Sun.\n\n");
        printf("K) Kepdler - Sometimes quoted to be an Earth 2.0 or Earth's Cousin based on its characteristics is a super-Earth exoplanet orbiting within the inner edge of the habitable zone of the sun-like star Kepler-452. It is located about 1,800 light-years from Earth in the constellation of Cygnus.\n\n");
        printf("L) Leda - known as Jupiter XIII, is a prograde irregular satellite of Jupiter. It was discovered by Charles T. Kowal at the Mount Palomar Observatory on September 14, 1974, after three nights' worth of photographic plates had been taken. It was named after Leda, who was raped by Zeus, the Greek equivalent of Jupiter.\n\n");
        printf("M) Mars - the fourth planet and the furthest terrestrial planet from the Sun. The reddish color of its surface is due to finely grained iron(III) oxide dust in the soil, giving it the nickname 'The Red Planet'.\n\n");
        printf("N) Neptune - the eighth and farthest planet from the Sun. It is the fourth-largest planet in the Solar System by diameter, the third-most-massive planet, and the densest giant planet. It is 17 times the mass of Earth, and slightly more massive than its near-twin Uranus. Neptune is denser and physically smaller than Uranus because its greater mass causes more gravitational compression of its atmosphere.\n\n");
        printf("O) Opportunity - a robotic rover that was active on Mars from 2004 until 2018.[2] Opportunity was operational on Mars for 5111 sols (14 years, 138 days on Earth). Launched on July 7, 2003, as part of NASA's Mars Exploration Rover program, it landed in Meridiani Planum on January 25, 2004, three weeks after its twin, Spirit, touched down on the other side of the planet.\n\n");
        printf("P) Pluto - a dwarf planet in the Kuiper belt, a ring of bodies beyond the orbit of Neptune. It is the ninth-largest and tenth-most-massive known object to directly orbit the Sun. It is the largest known trans-Neptunian object by volume, by a small margin, but is slightly less massive than Eris. Like other Kuiper belt objects, Pluto is made primarily of ice and rock and is much smaller than the inner planets. Pluto has only one sixth the mass of Earth's moon, and one third its volume. Pluto was recognized as a planet until 2006.\n\n");
        printf("Q) Quasar - An extremely luminous active galactic nucleus (AGN). It is sometimes known as a quasi-stellar object, abbreviated QSO. The emission from an AGN is powered by a supermassive black hole with a mass ranging from millions to tens of billions of solar masses, surrounded by a gaseous accretion disc. Gas in the disc falling towards the black hole heats up and releases energy in the form of electromagnetic radiation.\n\n");
        printf("R) Rhea - The second-largest moon of Saturn and the ninth-largest moon in the Solar System, with a surface area that is comparable to the area of Australia. It is the smallest body in the Solar System for which precise measurements have confirmed a shape consistent with hydrostatic equilibrium. It was discovered in 1672 by Giovanni Domenico Cassini.\n\n");
        printf("S) Sylvia - One of the largest asteroids. It is the parent body of the Sylvia family and member of Cybele group located beyond the main asteroid belt. Sylvia was the first asteroid known to possess more than one moon.\n\n");
        printf("T) Tesla - Elon Musk's Tesla Roadster is an electric sports car that served as the dummy payload for the February 2018 Falcon Heavy test flight and became an artificial satellite of the Sun. A mannequin in a spacesuit, dubbed 'Starman', occupies the driver's seat. The car and rocket are products of Tesla and SpaceX, respectively, both companies headed by Elon Musk. The 2010 Roadster is personally owned by and previously used by Musk for commuting to work. It is the first production car launched into space.\n\n");
        printf("U) Uranus - the seventh planet from the Sun. It is a gaseous cyan-coloured ice giant. Most of the planet is made of water, ammonia, and methane in a supercritical phase of matter, which in astronomy is called 'ice' or volatiles. The planet's atmosphere has a complex layered cloud structure and has the lowest minimum temperature of 49 K (−224 °C; −371 °F) out of all the Solar System's planets. It has a marked axial tilt of 97.8° with a retrograde rotation rate of 17 hours. This means that in an 84-Earth-year orbital period around the Sun, its poles get around 42 years of continuous sunlight, followed by 42 years of continuous darkness.\n\n");
        printf("V) Venus - the second planet from the Sun. It is a rocky planet with the densest atmosphere of all the rocky bodies in the Solar System, and the only one with a mass and size that is close to that of its orbital neighbour Earth. Orbiting inferiorly (inside of Earth's orbit), it appears in Earth's sky always close to the Sun, as either a 'morning star' or an 'evening star'. While this is also true for Mercury, Venus appears much more prominently, since it is the third brightest object in Earth's sky after the Moon and the Sun,[20][21] appearing brighter than any other star-like classical planet or any fixed star. With such prominence in Earth's sky, Venus has historically been a common and important object for humans, in both their cultures and astronomy.\n\n");
        printf("W) Wells - The crater is named after the author H. G. Wells whose works include the 1901 novel The First Men in the Moon. This large formation is most notable for the extremely battered state of its outer rim. Little or nothing remains of the original rim, so completely has it been eroded and incised by smaller craters.\n\n");
        printf("X) Xanadu - A highly reflective area on the leading hemisphere of Saturn's moon Titan. Its name comes from an alternate transcription of Shangdu, the summer capital of the Yuan dynasty established by Kublai Khan and made famous by Samuel Taylor Coleridge.\n\n");
        printf("Y) Ymir - the second-largest retrograde irregular moon of Saturn. It was discovered by Brett J. Gladman, et al. in 2000, and given the temporary designation S/2000 S 1. It was named in August 2003 after Ymir, who in Norse mythology is the ancestor of all the Jotuns or frost giants. It takes 3.6 Earth years to complete an orbit around Saturn. Of the moons that take more than 3 Earth years to orbit Saturn, Ymir is the largest, at about 18 kilometres (11 miles) in diameter; Ymir is also the second largest member of the Norse group, after Phoebe.\n\n");
        printf("Z) Zhurong - A Chinese rover on Mars, the country's first to land on another planet after it previously landed two rovers on the Moon. The rover is part of the Tianwen-1 mission to Mars conducted by the China National Space Administration (CNSA). The spacecraft was launched on 23 July 2020 and inserted into Martian orbit on 10 February 2021. The lander, carrying the rover, performed a soft-landing on Mars on 14 May 2021, making China the third country to successfully soft-land a spacecraft on Mars and the second one to deploy a rover on Mars, after the United States. Zhurong was deployed on 22 May 2021\n\n");
        printf("\n\n");
        printf(YELLOW"\tScroll up ^ to see all the words. Otherwise run the porgram again to keep playing.\n");
        printf(RED"\tCheating was the only way to end the program... God job cheater."RESET);
        
        return;
}
//(2 pts) game should compile and run smoothly without delay or interruption