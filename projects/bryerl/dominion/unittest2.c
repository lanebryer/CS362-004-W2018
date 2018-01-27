#include "rngs.h"
#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//testing update coin function
int main()
{
    int seed = 1000;
    int numPlayer = 2;
    int bonus;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;

	initializeGame(numPlayer, k, seed, &G);
	
	printf("Test update coins with: copper, copper, copper, copper, copper\n");
	G.hand[0][0] = copper;
	G.hand[0][1] = copper;
	G.hand[0][2] = copper;
	G.hand[0][3] = copper;
	G.hand[0][4] = copper;
	updateCoins(0, &G, 0);
	printf("Player should have 5 coins.  Player has %d coins - ", G.coins);
	if (G.coins == 5)
	{
		printf("Test passed!\n");
	}
	else
	{
		printf("Test failed!\n");
	}
	
	printf("Test update coins with: silver, silver, silver, silver, silver\n");
	G.hand[0][0] = silver;
	G.hand[0][1] = silver;
	G.hand[0][2] = silver;
	G.hand[0][3] = silver;
	G.hand[0][4] = silver;
	updateCoins(0, &G, 0);
	printf("Player should have 10 coins.  Player has %d coins - ", G.coins);
	if (G.coins == 10)
	{
		printf("Test passed!\n");
	}
	else
	{
		printf("Test failed!\n");
	}
	
	printf("Test update coins with: gold, gold, gold, gold, gold\n");
	G.hand[0][0] = gold;
	G.hand[0][1] = gold;
	G.hand[0][2] = gold;
	G.hand[0][3] = gold;
	G.hand[0][4] = gold;
	updateCoins(0, &G, 0);
	printf("Player should have 15 coins.  Player has %d coins - ", G.coins);
	if (G.coins == 15)
	{
		printf("Test passed!\n");
	}
	else
	{
		printf("Test failed!\n");
	}
	
	printf("Test update coins with: gold, gold, gold, gold, gold + 2 bonus\n");
	bonus = 2;
	G.hand[0][0] = gold;
	G.hand[0][1] = gold;
	G.hand[0][2] = gold;
	G.hand[0][3] = gold;
	G.hand[0][4] = gold;
	updateCoins(0, &G, bonus);
	printf("Player should have 17 coins.  Player has %d coins - ", G.coins);
	if (G.coins == 17)
	{
		printf("Test passed!\n");
	}
	else
	{
		printf("Test failed!\n");
	}
	
	printf("Test update coins with: feast, adventurer, sea_hag, tribute, duchy\n");
	G.hand[0][0] = feast;
	G.hand[0][1] = adventurer;
	G.hand[0][2] = sea_hag;
	G.hand[0][3] = tribute;
	G.hand[0][4] = duchy;
	updateCoins(0, &G, 0);
	printf("Player should have 0 coins.  Player has %d coins - ", G.coins);
	if (G.coins == 0)
	{
		printf("Test passed!\n");
	}
	else
	{
		printf("Test failed!\n");
	}
	
}
	
	