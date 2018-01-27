#include "rngs.h"
#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//testing supplyCount() function
int main()
{
	int result;
    int seed = 1000;
    int numPlayer = 2;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;

	initializeGame(numPlayer, k, seed, &G);	
	
	G.supplyCount[gold] = 2;
	G.supplyCount[silver] = 3;
	G.supplyCount[duchy] = 0;
	G.supplyCount[curse] = 7;
	
	result = supplyCount(gold, &G);
	printf("Testing supply count of gold...\n");
	printf("Expected value: 2, Actual value: %d - ", result);
	if (result == 2)
	{
		printf("Test passed!\n\n");
	}
	else{
		printf("Test failed!\n\n");
	}
	
	result = supplyCount(silver, &G);
	printf("Testing supply count of silver...\n");
	printf("Expected value: 3, Actual value: %d - ", result);
	if (result == 3)
	{
		printf("Test passed!\n\n");
	}
	else{
		printf("Test failed!\n\n");
	}
	
	result = supplyCount(duchy, &G);
	printf("Testing supply count of duchy...\n");
	printf("Expected value: 0, Actual value: %d - ", result);
	if (result == 0)
	{
		printf("Test passed!\n\n");
	}
	else{
		printf("Test failed!\n\n");
	}
	
	result = supplyCount(curse, &G);
	printf("Testing supply count of curse...\n");
	printf("Expected value: 7, Actual value: %d - ", result);
	if (result == 7)
	{
		printf("Test passed!\n\n");
	}
	else{
		printf("Test failed!\n\n");
	}
	
}