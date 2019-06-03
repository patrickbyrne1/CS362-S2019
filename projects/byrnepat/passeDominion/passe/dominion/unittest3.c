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
        printf ("seaHagCard() FAIL: %s", message);
        if (ASSERT_CRASH) {
          exit(1);
        }
    } else {
		printf ("seaHagCard() PASS: %s", message);
	}
}

// main runs all tests
int main ()	{
	struct gameState state;
	struct gameState testState;

	
	int currentPlayer1=0;
	int currentPlayer2=1;
	int currentPlayer3=2;
	int choice1 = 0;
	int choice2 = 0;
	int choice3 = 0;
	
	int bonus = 0;
	
	int handPos=0;
	
	int numPlayers = 3; // only tested 3 players 
	

	int randomSeed=999999;
	
	int kingdomCards[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};
	
	// initialize game state and make a testing copy
	initializeGame(numPlayers, kingdomCards, randomSeed, &state);
	
	memcpy(&testState, &state, sizeof(struct gameState));
	
	
	printf("**********Testing seaHagCard function**********\n");
	printf("\n");
	printf("Sea hag card should add a curse to top of player's deck.\n\n");

	// ----------- TEST 1: currentPlayer1 plays Sea Hag Card = curse card added to other players --------------
	cardEffect(sea_hag, choice1, choice2, choice3, &testState, handPos, &bonus);
	int player2TopCard1 = state.deck[currentPlayer2][state.deckCount[currentPlayer2]--];
	int player2TopCard2 = testState.deck[currentPlayer2][testState.deckCount[currentPlayer2]--];
	int player3TopCard1 = state.deck[currentPlayer3][state.deckCount[currentPlayer3]--];
	int player3TopCard2 = testState.deck[currentPlayer3][testState.deckCount[currentPlayer3]--];
	
	// Test the top card.  If it is 0, then it is a curse card (curse 0 in enum CARD)
	myAssert(player2TopCard1 == 0, "for player 2 curse card when using currentPlayer1.\n");
	myAssert(player3TopCard1 == 0, "for player 3 curse card when using currentPlayer1.\n");

	
	memcpy(&testState, &state, sizeof(struct gameState));
	
	
	// ----------- TEST 2: currentPlayer2 plays Sea Hag Card = curse card added to other players --------------
	cardEffect(sea_hag, choice1, choice2, choice3, &testState, handPos, &bonus);
	int player1TopCard1 = state.deck[currentPlayer1][state.deckCount[currentPlayer1]--];
	int player1TopCard2 = testState.deck[currentPlayer1][testState.deckCount[currentPlayer1]--];
	player3TopCard1 = state.deck[currentPlayer3][state.deckCount[currentPlayer3]--];
	player3TopCard2 = testState.deck[currentPlayer3][testState.deckCount[currentPlayer3]--];
	
	myAssert(player1TopCard1 != 0, "player 1 curse card when using currentPlayer2.\n");
	myAssert(player3TopCard1 != 0, "player 3 curse card when using currentPlayer2.\n");
	
	
	memcpy(&testState, &state, sizeof(struct gameState));
	
	// ----------- TEST 3: currentPlayer3 plays Sea Hag Card = curse card added to other players --------------
	cardEffect(sea_hag, choice1, choice2, choice3, &testState, handPos, &bonus);
	player1TopCard1 = state.deck[currentPlayer1][state.deckCount[currentPlayer1]--];
	player1TopCard2 = testState.deck[currentPlayer1][testState.deckCount[currentPlayer1]--];
	player2TopCard1 = state.deck[currentPlayer2][state.deckCount[currentPlayer2]--];
	player2TopCard2 = testState.deck[currentPlayer2][testState.deckCount[currentPlayer2]--];
	
	myAssert(player1TopCard1 != 0, "player 1 curse card when using currentPlayer3.\n");
	myAssert(player2TopCard1 != 0, "player 2 curse card when using currentPlayer3.\n\n");
	
	
	memcpy(&testState, &state, sizeof(struct gameState));
	

	return 0;
	
}
