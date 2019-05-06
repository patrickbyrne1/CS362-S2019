
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
        printf ("adventureCard() FAIL: %s", message);
        if (ASSERT_CRASH) {
          exit(1);
        }
    } else {
		printf ("adventureCard() PASS: %s", message);
	}
}

// main runs all tests
int main ()	{
	struct gameState state;
	struct gameState testState;
	
	int currentPlayer1=0;
	int currentPlayer2=1;
	int currentPlayer3=2;
	int currentPlayer4=3;
	
	int numPlayers = 4;
	int randomSeed=999999;
	
	int kingdomCards[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};
	
	

	// initialize game state and make a testing copy
	initializeGame(numPlayers, kingdomCards, randomSeed, &state);
	
	memcpy(&testState, &state, sizeof(struct gameState));
	
	printf("**********Testing adventureCard function**********\n");
	printf("\n");
	printf("Adventure card should add 2 treasure cards to player's hand.\n\n");
	int temphand[MAX_HAND];
	
	// ----------- TEST 1: currentPlayer1 = 0 = +2 cards --------------
	adventurerCard(currentPlayer1, &testState, &temphand);
	int handCountTest1 = state.handCount[currentPlayer1];
	int handCountTest2 = testState.handCount[currentPlayer1];
	
	myAssert(handCountTest1 != handCountTest2, "when using currentPlayer1\n");
	
	memcpy(&testState, &state, sizeof(struct gameState));
	
	// ----------- TEST 2: currentPlayer2 = 1 = +2 cards --------------
	adventurerCard(currentPlayer2, &testState, &temphand);
	handCountTest1 = state.handCount[currentPlayer2];
	handCountTest2 = testState.handCount[currentPlayer2];
	
	myAssert(handCountTest1 != handCountTest2, "when using currentPlayer2\n");
	
	memcpy(&testState, &state, sizeof(struct gameState));
	
	// ----------- TEST 3: currentPlayer3 = 2 = +2 cards --------------
	adventurerCard(currentPlayer3, &testState, &temphand);
	handCountTest1 = state.handCount[currentPlayer3];
	handCountTest2 = testState.handCount[currentPlayer3];
	
	myAssert(handCountTest1 != handCountTest2, "when using currentPlayer3\n");
	
	memcpy(&testState, &state, sizeof(struct gameState));
	
	// ----------- TEST 4: currentPlayer4 = 3 = +2 cards --------------
	adventurerCard(currentPlayer4, &testState, &temphand);
	handCountTest1 = state.handCount[currentPlayer4];
	handCountTest2 = testState.handCount[currentPlayer4];
	
	myAssert(handCountTest1 != handCountTest2, "when using currentPlayer4\n\n");
	
	
	
	return 0;
	
}
