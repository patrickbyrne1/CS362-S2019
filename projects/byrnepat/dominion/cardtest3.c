
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
        printf ("Adventurer card FAIL: %s", message);
        if (ASSERT_CRASH) {
          exit(1);
        }
    } else {
		printf ("Adventurer card PASS: %s", message);
	}
}


int main() {
	struct gameState state;
	struct gameState testState;


	int currentPlayer1 = 0; 
	
	
	// testing handPos values
	int handPos0=0; // boundary test since position 0 is lowest handPos
	int handPos1=1; // positive test
	int handPos2=2; 
	
	int numPlayers = 3; // only tested 3 players 
	
	int choice1 = 0;
	int choice2 = 0;
	int choice3 = 0;
	
	int bonus = 0;

	int randomSeed=999999;
	
	int kingdomCards[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};
	
	
	// initialize game state and make a testing copy
	initializeGame(numPlayers, kingdomCards, randomSeed, &state);
	
	memcpy(&testState, &state, sizeof(struct gameState));
	
	
	printf("**********Testing adventurer card in cardEffect function**********\n");
	printf("\n");
	printf("Adventurer card should remove at least two cards from players deck.\n\n");
	
	
	// ----------- TEST 1: handPos0 = 0 = decksize reduced by at least 2 (Boundary Test)--------------
	cardEffect(adventurer, choice1, choice2, choice3, &testState, handPos0, &bonus);
	int deckSizeBefore = state.deckCount[currentPlayer1];
	int deckSizeAfter = testState.deckCount[currentPlayer1];
	
	myAssert(deckSizeBefore != deckSizeAfter, "when using handPos0.\n");

	memcpy(&testState, &state, sizeof(struct gameState));
	
	// ----------- TEST 2: handPos1 = 1 = decksize reduced by at least 2  --------------
	cardEffect(adventurer, choice1, choice2, choice3, &testState, handPos1, &bonus);
	deckSizeBefore = state.deckCount[currentPlayer1];
	deckSizeAfter = testState.deckCount[currentPlayer1];
	
	myAssert(deckSizeBefore != deckSizeAfter, "when using handPos1.\n");

	memcpy(&testState, &state, sizeof(struct gameState));


	// ----------- TEST 3: handPos2 = 2 = decksize reduced by at least 2  --------------
	cardEffect(adventurer, choice1, choice2, choice3, &testState, handPos2, &bonus);
	deckSizeBefore = state.deckCount[currentPlayer1];
	deckSizeAfter = testState.deckCount[currentPlayer1];
	
	myAssert(deckSizeBefore != deckSizeAfter, "when using handPos2.\n\n");

	memcpy(&testState, &state, sizeof(struct gameState));


	return 0;
}


