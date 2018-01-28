#include "rngs.h"
#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

//Testing adventurer card
int main()
{
	int result;
    int seed = 1000;
    int numPlayer = 2;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
	struct gameState testState;
	int choice1, choice2, choice3, bonus, handPos;
	choice1 = choice2 = choice3 = bonus = handPos = 0;
	

	initializeGame(numPlayer, k, seed, &G);	
	G.whoseTurn = 0;
	memcpy(&testState, &G, sizeof(struct gameState));
   	
	printf("--------Testing adventurer card----------\n");
	cardEffect(adventurer, choice1, choice2, choice3, &testState, handPos, &bonus);
	printf("Testing that two cards were added to hand...\n");
	result = testState.handCount[0] - G.handCount[0];
	printf("Expected result: 2, Actual result: %d - ", result);
	if (result == 2)
	{
		printf("Test passed!\n\n");
	}
	else{
		printf("Test failed!\n\n");
	}
	
	G.discard[0][0] = copper;
	G.discard[0][1] = smithy;
	G.discardCount[0] = 2;
	G.deckCount[0] = 2;
	G.deck[0][0] = smithy;
	G.deck [0][1] = adventurer;
	memcpy(&testState, &G, sizeof(struct gameState));
	
	cardEffect(adventurer, choice1, choice2, choice3, &testState, handPos, &bonus);
	printf("Testing with no treasures in deck, 1 in discard pile...\n");
	result = testState.handCount[0] - G.handCount[0];
	printf("Expected drawn treasures: 1, Actual result: %d - ", result);
	if (result == 1)
	{
		printf("Test passed!\n\n");
	}
	else
	{
		printf("Test failed!\n\n");
}
return 0;
}
	
	