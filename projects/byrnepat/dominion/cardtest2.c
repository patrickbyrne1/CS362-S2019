
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
        printf ("Outpost card FAIL: %s", message);
        if (ASSERT_CRASH) {
          exit(1);
        }
    } else {
		printf ("Outpost card PASS: %s", message);
	}
}


int main() {
	struct gameState state;
	struct gameState testState;

	
	// testing handPos values
	int handPos0=0; // boundary test since position 0 is lowest handPos
	int handPos1=0;
	int handPos2=0;
	
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
	
	
	printf("**********Testing outpost card in cardEffect function**********\n\n");
	printf("Outpost card should increase the outpostPlayed flag by one regardless of hand position.\n\n");

	// ----------- TEST 1: handPos0 = 0 = + 1 outpostPlayed flag (Boundary Test)--------------
	cardEffect(outpost, choice1, choice2, choice3, &testState, handPos0, &bonus);
	int outpostBefore = state.outpostPlayed;
	int outpostAfter = testState.outpostPlayed;
	
	myAssert((outpostBefore + 1) == outpostAfter, "when using handPos0.\n");
	
	memcpy(&testState, &state, sizeof(struct gameState));


	// ----------- TEST 2: handPos1 = 1 = + 1 outpostPlayed flag --------------
	cardEffect(outpost, choice1, choice2, choice3, &testState, handPos1, &bonus);
	outpostBefore = state.outpostPlayed;
	outpostAfter = testState.outpostPlayed;
	
	myAssert((outpostBefore + 1) == outpostAfter, "when using handPos1.\n");
	
	memcpy(&testState, &state, sizeof(struct gameState));
	
	// ----------- TEST 3: outpostPlayed starts with value of 1 = + 1 outpostPlayed flag --------------
	testState.outpostPlayed++;
	
	cardEffect(outpost, choice1, choice2, choice3, &testState, handPos1, &bonus);
	outpostBefore = state.outpostPlayed;
	outpostAfter = testState.outpostPlayed;
	
	myAssert(outpostBefore != outpostAfter, "when outpostPlayed starts with value of 1.\n\n");
	memcpy(&testState, &state, sizeof(struct gameState));



	return 0;
}

