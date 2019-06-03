
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
int myAssert(int boolNum, int card, char* message) {
    if (boolNum == 0) {
        printf ("card %d FAIL: %s", card, message);
        if (ASSERT_CRASH) {
          exit(1);
        }
    } else {
		printf ("card %d PASS: %s", card, message);
	}
}

int main ()	{
	struct gameState state;
	struct gameState testState;

	
	int currentPlayer=0;
	int currentPlayer2=1;
	int currentPlayer3=2;

	
	int numPlayers = 3; // only tested 3 players 
	
	int choice1 = 0;
	int choice2 = 1; 
	int choice3 = 2;
	
	int handPos=0;
	int bonus = 0;
	
	int randomSeed=999999;
	
	int kingdomCards[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};
	
	
	// initialize game state and make a testing copy
	initializeGame(numPlayers, kingdomCards, randomSeed, &state);
	
	memcpy(&testState, &state, sizeof(struct gameState));
	
	
	printf("**********Testing all cards in cardEffect function**********\n");
	printf("\n");
	printf("Testing to see if numBuys or numActions changes.\n\n");

	int i;

	
		
	// ----------- TEST 1: numBuys before and after card is played --------------;
	for(i = 0; i<20; i++) {
		cardEffect(i, choice1, choice2, choice3, &testState, handPos, &bonus);
		int numBuys1 = state.numBuys;
		int numBuys2 = testState.numBuys;
		myAssert((numBuys1 + 1) == numBuys2, i, "when using currentPlayer1.\n");
		
		memcpy(&testState, &state, sizeof(struct gameState));
	}
	
	
	// ----------- TEST 2: numActions before and after card is played --------------;
	 
	for(i = 0; i<20; i++) {
		cardEffect(i, choice1, choice2, choice3, &testState, handPos, &bonus);
		int numActions1 = state.numActions;
		int numActions2 = testState.numActions;
		myAssert(numActions1 == numActions2, i, "when using currentPlayer1.\n");
		
		
		memcpy(&testState, &state, sizeof(struct gameState));
	}
	
	
	return 0;
	
}
