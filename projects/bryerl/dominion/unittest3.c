#include "rngs.h"
#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//testing scoreFor() function
int main()
{
	int result;
	int i;
    int seed = 1000;
    int numPlayer = 2;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;

	initializeGame(numPlayer, k, seed, &G);	
		
	for (i = 0; i < numPlayer; i++)
	{
		G.handCount[i] = 1;
		G.discardCount[i] = 1;
		G.deckCount[i] = 1;
	}
	
	G.hand[0][0] = curse;
	G.discard[0][0] = curse;
	G.deck[0][0] = curse;
	G.hand[1][0] = estate;
	G.discard[1][0] = estate;
	G.deck[1][0] = estate;

	printf("Testing - hand: curse, discard: curse, deck: curse\n");
	result = scoreFor(0, &G);
	printf("Expected score: -3, actual score: %d - ", result);
	if (result == -3)
	{
		printf("Test passed!\n\n");
	}
	else{
		printf("Test failed!\n\n");
	}
	
	printf("Testing - hand: estate, discard: estate, deck: estate\n");
	result = scoreFor(1, &G);
	printf("Expected score: 3, actual score: %d - ", result);
	if (result == 3)
	{
		printf("Test passed!\n\n");
	}
	else{
		printf("Test failed!\n\n");
	}	
	
	G.hand[0][0] = duchy;
	G.discard[0][0] = duchy;
	G.deck[0][0] = duchy;	
	G.hand[1][0] = province;
	G.discard[1][0] = province;
	G.deck[1][0] = province;	

	printf("Testing - hand: duchy, discard: duchy, deck: duchy\n");
	result = scoreFor(0, &G);
	printf("Expected score: 9, actual score: %d - ", result);
	if (result == 9)
	{
		printf("Test passed!\n\n");
	}
	else{
		printf("Test failed!\n\n");
	}	
	
	printf("Testing - hand: province, discard: province, deck: province\n");
	result = scoreFor(1, &G);
	printf("Expected score: 18, actual score: %d - ", result);
	if (result == 18)
	{
		printf("Test passed!\n\n");
	}
	else{
		printf("Test failed!\n\n");
	}
	
	G.hand[0][0] = great_hall;
	G.discard[0][0] = great_hall;
	G.deck[0][0] = great_hall;	
	G.hand[1][0] = gardens;
	G.discard[1][0] = gardens;
	G.deck[1][0] = gardens;
	
	printf("Testing - hand: great_hall, discard: great_hall, deck: great_hall\n");
	result = scoreFor(0, &G);
	printf("Expected score: 3, actual score: %d - ", result);
	if (result == 3)
	{
		printf("Test passed!\n\n");
	}
	else{
		printf("Test failed!\n\n");
	}
	
	printf("Testing - hand: gardens, discard: gardens, deck: gardens\n");
	result = scoreFor(1, &G);
	printf("Expected score: 0, actual score: %d - ", result);
	if (result == 0)
	{
		printf("Test passed!\n\n");
	}
	else{
		printf("Test failed!\n\n");
	}
}

	
	