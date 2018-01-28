#include "rngs.h"
#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

//Testing outpost card
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
	
	cardEffect(outpost, choice1, choice2, choice3, &testState, handPos, &bonus);
	printf("--------Testing outpost card----------\n"); 
	printf("Testing that outpost was incremented...\n");
	result = testState.outpostPlayed - G.outpostPlayed;
	printf("Expected result: 1, Actual result: %d - ", result);
	if(result == 1)
	{
		printf("Test passed!\n\n");
	}
	else
	{
		printf("Test failed!\n\n");
	}
	
	printf("Testing that card was discarded...\n");
	result = testState.playedCardCount;
	printf("Expected played: 1, Actual played: %d - ", result);
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
