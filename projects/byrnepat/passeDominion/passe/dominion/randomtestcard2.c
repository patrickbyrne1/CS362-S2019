#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>

//#define ASSERT_CRASH 0

// function declarations
int myAssert(int boolNum, char* message);
void testVillage();


// cited source:  Assertion test function format taken from here:
// http://www.dillonbhuff.com/?p=439
int myAssert(int boolNum, char* message) {
    if (boolNum == 0) {
        printf ("embargoCard test failed: %s", message);
        return 0;
    } else {
		return 1;
	}
}

// function to test the embargoCard
void testEmbargo() {

	struct gameState testState;
	
	clock_t start, total;

	int randomSeed=999999;

	int kingdomCards[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

	// initialize game state and make a testing copy
	//initializeGame(numPlayers, kingdomCards, randomSeed, &state);
	
	int numTestFails = 0;
	int numTestPasses = 0;
	int numPlayers;
	// Test for hand count increasing by 2 -> any more/less fail
	// Test for discard pile having treasure cards -> fail
	
	
	int choice1 = 0;
	int choice2 = 0;
	int choice3 = 0;
	
	int bonus = 0;
	
	printf("**********Testing embargo card in cardEffect function**********\n\n");
	printf("Embargo card should increase the number of coins by two.\n\n");

	int handPos;

	// cited source: ideas for timing the function come from here:
	// https://www.geeksforgeeks.org/how-to-measure-time-taken-by-a-program-in-c/
	start = clock();

	// randomize numPlayers, handPos, whether supply card is in deck
	// determine effect on number of actions before and after (should get two actions added)
	for(int i=0; i<2000; i++) {
		
		// randomize the number of player
		numPlayers = rand() % (MAX_PLAYERS-1) + 2;
		
		initializeGame(numPlayers, kingdomCards, randomSeed, &testState);
		
		testState.supplyCount[choice1] = (rand()%100)-1;
		
		// randomize handPos
		handPos = rand()%(10);
		
		int coins1 = testState.coins;
		//embargoCard(currentPlayer, &testState, handPos0, choice1);
		cardEffect(embargo, choice1, choice2, choice3, &testState, handPos, &bonus);
		int coins2 = testState.coins;
		
		
		//numActions2 = testState.numActions;
		if(!myAssert(coins1 + 2 == coins2, "Number of coins should be 2 greater after the embargo card is played.\n")){
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

// main function to call testEmbargo
int main() {
    
   srand(time(NULL));
   testEmbargo();
   
   return 0;
}
