
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
        printf ("Smithy card FAIL: %s", message);
        if (ASSERT_CRASH) {
          exit(1);
        }
    } else {
		printf ("Smithy card PASS: %s", message);
	}
}


int main() {
	struct gameState state;
	struct gameState testState;


	int currentPlayer1 = 0; 
	
	
	// testing handPos values
	int handPos0=0; // boundary test since position 0 is lowest handPos
	int handPos1=1; // positive test
	int handPos2= -5; // negative test 
	
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
	
	
	printf("**********Testing smithy card in cardEffect function**********\n");
	printf("\n");
	printf("Smithy card should add three cards to the player's hand and remove one.\n\n");
	
	
	// ----------- TEST 1: handPos0 = 0 = +2 cards in hand (Boundary Test)--------------
	cardEffect(smithy, choice1, choice2, choice3, &testState, handPos0, &bonus);
	int hand1 = state.handCount[currentPlayer1];
	int hand2 = testState.handCount[currentPlayer1];
	
	myAssert((hand1+2)== hand2, "when using handPos0.\n");

	memcpy(&testState, &state, sizeof(struct gameState));
	
	
	// ----------- TEST 2: handPos1 = 1 = +2 cards in hand --------------
	cardEffect(smithy, choice1, choice2, choice3, &testState, handPos1, &bonus);
	hand1 = state.handCount[currentPlayer1];
	hand2 = testState.handCount[currentPlayer1];
	
	myAssert((hand1+2)== hand2, "when using handPos1.\n");

	memcpy(&testState, &state, sizeof(struct gameState));
	
	
	// ----------- TEST 3: handPos2 = -5 = + 1 outpostPlayed flag (Negative Test) --------------
	cardEffect(smithy, choice1, choice2, choice3, &testState, handPos2, &bonus);
	hand1 = state.handCount[currentPlayer1];
	hand2 = testState.handCount[currentPlayer1];
	
	myAssert((hand1+2)== hand2, "when using handPos2.\n\n");

	memcpy(&testState, &state, sizeof(struct gameState));

	return 0;
}

