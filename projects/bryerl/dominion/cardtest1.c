#include "rngs.h"
#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

//Testing smithy card
int main()
{
	int result;
	int i;
    int seed = 1000;
    int numPlayer = 2;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
	struct gameState testState;
	int choice1, choice2, choice3, bonus, handPos;
	choice1 = choice2 = choice3 = bonus = handPos = 0;
	

	initializeGame(numPlayer, k, seed, &G);	
	G.hand[0][0] = smithy;
	G.whoseTurn = 0;
	memcpy(&testState, &G, sizeof(struct gameState));
   	
	printf("--------Testing smithy card----------\n");
	cardEffect(smithy, choice1, choice2, choice3, &testState, handPos, &bonus);
	result = testState.handCount[0] - G.handCount[0];
	printf("Checking for 3 cards drawn and 1 discarded...\n");
	printf("Net card gain expected: 2, Actual card gain: %d - ", result);
	if(result == 2)
	{
		printf("Test passed!\n\n");
	}
	else
	{
		printf("Test failed!\n\n");
	}
	
	printf("Test for 1 card played...\n");	
	result = testState.playedCardCount;
	printf("Expected played: 1, Actual played: %d - ", result);
	if (result == 1)
	{
		printf("Test passed!\n\n");
	}
	else{
		printf("Test failed!\n\n");
	}
	
	printf("Test for deck count decrement...\n");
	result = G.deckCount[0] - testState.deckCount[0];
	printf("Expected deck count decrease: 3, actual: %d - ", result);
	if(result == 3)
	{
		printf("Test passed!\n\n");
	}
	else{
		printf("Test failed!\n\n");
	}
	
	printf("Test for smithy removal...\n");
	result = 0;
	for (i = 0; i < testState.handCount[0]; i++)
	{
		if (testState.hand[0][i] == smithy)
		{
			result = 1;
		}
	}
	printf("Expected result: 0 (not found), actual result: %d - ", result);
	if(result == 0)
	{
		printf("Test passed!\n\n");
	}
	else
	{
		printf("Test failed!\n\n");
	}
	return 0;
}
	