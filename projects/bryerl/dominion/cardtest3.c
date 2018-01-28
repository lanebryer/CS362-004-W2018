#include "rngs.h"
#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

//Testing steward card
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
	
	choice1 = 1;
	cardEffect(steward, choice1, choice2, choice3, &testState, handPos, &bonus);
	printf("--------Testing steward----------\n");
	printf("Testing draw 2 cards...\n");
	result = testState.handCount[0] - G.handCount[0] + 1; //adds one to cover the discarded card
	printf("Expected draw: 2, Actual draw: %d - ", result);
	if (result == 2)
	{
		printf("Test passed!\n\n");
	}
	else{
		printf("Test failed!\n\n");
	}
	
	printf("Testing that discard works...\n");
	result = testState.playedCardCount;
	printf("Expected discard: 1, Actual discard: %d - ", result);
	if (result == 1)
	{
		printf("Test passed!\n\n");
	}
	else
	{
		printf("Test failed!\n\n");
	}
	
	memcpy(&testState, &G, sizeof(struct gameState));
	choice1 = 2;
	cardEffect(steward, choice1, choice2, choice3, &testState, handPos, &bonus);
	printf("Testing adding 2 coins...\n");
	result = testState.coins - G.coins;
	printf("Coins expected: 2, Actual coins: %d - ", result);
	if (result == 2)
	{
		printf("Test passed!\n\n");
	}
	else{
		printf("Test failed!\n\n");
	}
	
	memcpy(&testState, &G, sizeof(struct gameState));
	choice1 = 3;
	cardEffect(steward, choice1, choice2, choice3, &testState, handPos, &bonus);
	printf("Testing trashing two cards...\n");
	result = G.handCount[0] - testState.handCount[0] - 1; //subtract 1 to cover for the card that was played and discarded
	printf("Expected discard: 2, Actual discard: %d - ", result);
	if (result == 2)
	{
		printf("Test passed!\n\n");
	}
	else{
		printf("Test failed!\n\n");
	}
	return 0;
	
}