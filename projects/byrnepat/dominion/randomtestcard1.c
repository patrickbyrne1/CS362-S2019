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
void testVillage();


// cited source:  Assertion test function format taken from here:
// http://www.dillonbhuff.com/?p=439
int myAssert(int boolNum, char* message) {
    if (boolNum == 0) {
        printf ("villageCard test failed: %s", message);
        return 0;
    } else {
		return 1;
	}
}


// function to test the VillageCard
void testVillage() {

	struct gameState testState;
	
	clock_t start, total;
	
	int currentPlayer = 0;
	
	int randomSeed=999999;

	
	int kingdomCards[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};
	
	int numTestFails = 0;
	int numTestPasses = 0;
	int numPlayers = 4;

	printf("**********Testing villageCard function**********\n");
	printf("\n");
	printf("Village card should increase number of actions by 2.\n\n");

	int numActionsBefore;
	int numActionsAfter;
	int handPos = 0;
	
	int choice1 = 0;
	int choice2 = 0;
	int choice3 = 0;
	
	int bonus = 0;
	
	
	// cited source: ideas for timing the function come from here:
	// https://www.geeksforgeeks.org/how-to-measure-time-taken-by-a-program-in-c/
	start = clock();


	// randomize deckCount, discardCount, handCount
	// determine effect on number of actions before and after (should get two actions added)
	for(int i=0; i<2000; i++) {
		
		// initialize game
		initializeGame(numPlayers, kingdomCards, randomSeed, &testState);
		
		// randomize hand count
		testState.handCount[currentPlayer] = rand()%(MAX_HAND + 1);
		// randomize deck count
		testState.deckCount[currentPlayer] = rand()%(MAX_DECK + 1);
		// randomize discard count
		testState.discardCount[currentPlayer] = rand()%(MAX_DECK + 1);
		
		numActionsBefore = testState.numActions;
		cardEffect(village, choice1, choice2, choice3, &testState, handPos, &bonus);
		
		numActionsAfter = testState.numActions;
		
		if(!myAssert(numActionsBefore + 2 == numActionsAfter, "Incorrect number of actions after Village card played.\n")){
			numTestFails++;
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

// main function to call testVillage
int main() {
     
   srand(time(NULL));
   testVillage();

   
   return 0;
}
