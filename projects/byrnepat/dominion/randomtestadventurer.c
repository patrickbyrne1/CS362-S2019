#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>

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

void testAdventurer() {

	struct gameState state;
	
	int currentPlayer1=0;
	int currentPlayer2=1;
	int currentPlayer3=2;
	int currentPlayer4=3;
	
	int numPlayers = 4;
	int randomSeed=999999;
	
	int kingdomCards[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};
	
	int count = 0;
	
	while(count < 2000)  {

		// initialize game state and make a testing copy
		initializeGame(numPlayers, kingdomCards, randomSeed, &state);
	
		cardEffect(adventurer, 0, 0, 0, &G, 2, 0);
	
	}
}

int main() {
    
    
    
    
   srand(time(NULL));
   
   return 0;
}
