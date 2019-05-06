
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
        printf ("embargoCard() FAIL: %s", message);
        if (ASSERT_CRASH) {
          exit(1);
        }
    } else {
		printf ("embargoCard() PASS: %s", message);
	}
}

int main ()	{
	struct gameState state;
	struct gameState testState;

	
	int currentPlayer1=0;
	int currentPlayer2=1;
	int currentPlayer3=2;
	
	int handPos=0;
	
	int numPlayers = 3; // only tested 3 players 
	
	int choice1 = 1;

	int randomSeed=999999;
	
	int kingdomCards[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};
	
	
	// initialize game state and make a testing copy
	initializeGame(numPlayers, kingdomCards, randomSeed, &state);
	
	memcpy(&testState, &state, sizeof(struct gameState));
	
	
	printf("**********Testing embargoCard function**********\n");
	printf("\n");
	printf("Embargo card should add two coins to currentPlayer.\n\n");

	// ----------- TEST 1: currentPlayer1 = 0 = +2 coins --------------;
	embargoCard(currentPlayer1, &testState, handPos, choice1);
	int coins1 = state.coins;
	int coins2 = testState.coins;
	
	myAssert((coins1 +2) == coins2, "when using currentPlayer1.\n");
	
	memcpy(&testState, &state, sizeof(struct gameState));
	
	// ----------- TEST 2: currentPlayer2 = 1 = +2 coins --------------;
	embargoCard(currentPlayer2, &testState, handPos, choice1);
	coins1 = state.coins;
	coins2 = testState.coins;
	
	myAssert((coins1 +2) == coins2, "when using currentPlayer2.\n");
	
	memcpy(&testState, &state, sizeof(struct gameState));
	
	// ----------- TEST 3: currentPlayer3 = 2 = +2 coins --------------;
	embargoCard(currentPlayer3, &testState, handPos, choice1);
	coins1 = state.coins;
	coins2 = testState.coins;
	
	myAssert((coins1 +2) == coins2, "when using currentPlayer3.\n\n");
	
	memcpy(&testState, &state, sizeof(struct gameState));
	
	
	return 0;
	
}
