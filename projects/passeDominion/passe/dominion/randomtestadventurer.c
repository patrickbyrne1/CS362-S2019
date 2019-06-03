#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>


// function declarations
int myAssert(int boolNum, char* message);
void testAdventurer();


// cited source:  Assertion test function format taken from here:
// http://www.dillonbhuff.com/?p=439
int myAssert(int boolNum, char* message) {
    if (boolNum == 0) {
        printf ("adventureCard test failed: %s\n", message);
        return 0;
    } else {
		return 1;
	}
}

// function to test the adventurerCard
void testAdventurer() {

	struct gameState testState;
	
	clock_t start, total;
	
	
	int currentPlayer = 0;
	int randomSeed=999999;
	
	int kingdomCards[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};
	
	int numTestFails = 0;
	int numTestPasses = 0;
	int numPlayers;
	
	int handPos=0; 
	int choice1 = 0;
	int choice2 = 0;
	int choice3 = 0;
	
	int bonus = 0;
	
	printf("**********Testing adventureCard function**********\n");
	printf("\n");
	printf("Adventure card should add 2 treasure cards to player's hand.\n\n");
	
	// cited source: ideas for timing the function come from here:
	// https://www.geeksforgeeks.org/how-to-measure-time-taken-by-a-program-in-c/
	start = clock();
	
	// randomize number of players, whoseTurn, handCount
	// determine effect on number of cards before and after (should get two treasure cards added to deck)
	for(int i=0; i<100; i++) {
		
		// randomize the number of players between 2 and 4
		numPlayers = rand() % (MAX_PLAYERS-1) + 2;
		
		// initialize game
		initializeGame(numPlayers, kingdomCards, randomSeed, &testState);
		
		// randomize the hand count
		testState.handCount[currentPlayer] = rand()%(MAX_HAND + 1);
		
		// randomize whoseTurn
		testState.whoseTurn = rand()%(numPlayers);
	
		int handCountTest1 = testState.handCount[currentPlayer];
		
		cardEffect(adventurer, choice1, choice2, choice3, &testState, handPos, &bonus);
	
		int handCountTest2 = testState.handCount[currentPlayer];

		
		if(!myAssert((handCountTest1 + 2) == handCountTest2, "Incorrect number of cards in hand after Adventurer card played.\n")){
			numTestFails++;
			printf("Number of cards in hand before: %d\n", handCountTest1);
			printf("Number of cards in hand after: %d\n", handCountTest2);
		}
		else {
			numTestPasses++;
		}
	}	
	
	total = clock() - start;
	double time_taken = ((double)total)/CLOCKS_PER_SEC; // in seconds 
	
	
	printf("Test passed: %d\n", numTestPasses);
	printf("Test failed: %d\n", numTestFails);
	printf("Total time to do all tests: %f\n\n", time_taken); 
	
}

    
// main function to call testAdventurer
int main() {
	
   srand(time(NULL));
   testAdventurer();   

   
   return 0;
}
