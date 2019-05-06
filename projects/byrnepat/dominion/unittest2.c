
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>


#define ASSERT_CRASH 0

// cited source:  Assertion test function format taken from here:
// http://www.dillonbhuff.com/?p=439
int myAssert(int boolNum, char* message) {
    if (boolNum == 0) {
        printf ("villageCard() FAIL: %s", message);
        if (ASSERT_CRASH) {
          exit(1);
        }
    } else {
		printf ("villageCard() PASS: %s", message);
	}
}

// main runs all tests
int main ()	{
	struct gameState state;
	struct gameState testState;
	
	int currentPlayer=0;
	
	int currentPlayer1=0;
	int currentPlayer2=1;
	int currentPlayer3=2;
	int currentPlayer4=3;
	
	int handPos=0;
	
	int numPlayers = 4;
	

	int randomSeed=999999;
	
	int kingdomCards[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};
	
	
	// initialize game state and make a testing copy
	initializeGame(numPlayers, kingdomCards, randomSeed, &state);
	
	memcpy(&testState, &state, sizeof(struct gameState));
	
	
	printf("**********Testing villageCard function**********\n");
	printf("\n");
	printf("Village card should increase number of actions by 2.\n\n");

	// ----------- TEST 1: currentPlayer1 = 0 = +2 actions --------------;
	villageCard(currentPlayer1, &testState, handPos);
	int numActions1 = state.numActions;
	int numActions2 = testState.numActions;
	
	myAssert(numActions1 != numActions2, "when using currentPlayer1.\n");
	
	memcpy(&testState, &state, sizeof(struct gameState));
	
	
	// ----------- TEST 2: currentPlayer2 = 1 = +2 actions --------------
	villageCard(currentPlayer2, &testState, handPos);
	numActions1 = state.numActions;
	numActions2 = testState.numActions;
	
	myAssert(numActions1 != numActions2, "when using currentPlayer2.\n");
	
	
	memcpy(&testState, &state, sizeof(struct gameState));
	
	
	// ----------- TEST 3: currentPlayer3 = 2 = +2 actions --------------
	villageCard(currentPlayer3, &testState, handPos);
	numActions1 = state.numActions;
	numActions2 = testState.numActions;
	
	myAssert(numActions1 != numActions2, "when using currentPlayer3.\n");
	
	memcpy(&testState, &state, sizeof(struct gameState));


	// ----------- TEST 4: currentPlayer4 = 3 = +2 actions --------------
	villageCard(currentPlayer4, &testState, handPos);
	numActions1 = state.numActions;
	numActions2 = testState.numActions;
	
	myAssert(numActions1 != numActions2, "when using currentPlayer4.\n\n");
	
	memcpy(&testState, &state, sizeof(struct gameState));

	return 0;
	
}
