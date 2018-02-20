#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int seed;	
	int pass,fail;
	pass = fail = 0;
	int i,j;	
	int numPlayers;
	int player;
	int totalTreasures;
	int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
	struct gameState pre;
	struct gameState post;
	int choice1, choice2, choice3, bonus, handPos;
	choice1 = choice2 = choice3 = bonus = handPos = 0;
	
	srand(time(NULL));
	
	printf("Random testing for adventurer card.....\n");
	
	for(i = 0; i < 5000; i++)
	{
		memset(&pre, 0, sizeof(struct gameState));
		memset(&post, 0, sizeof(struct gameState));
		seed = rand() % 1000 + 1; //random seed from 1 - 1000 (because 0 prompts for user seed entry)
		numPlayers = rand() % 3 + 2; //Sets player count to 2, 3, or 4 randomly
		initializeGame(numPlayers, k, seed, &pre); //initialize game state
		
		pre.whoseTurn = rand() % numPlayers;
		player = whoseTurn(&pre);
		pre.handCount[player] = rand() % 30 + 1; //Set hand count to between 1-30 inclusive (player must have a card in order to play an adventurer)
		pre.deckCount[player] = rand() % 30 + 1; //Set deck count to between 1-30 inclusive		
		pre.discardCount[player] = rand() % 30 + 1; //Set discard count to between 1-30 inclusive
		totalTreasures = 0;
		
		for(j = 0; j < pre.deckCount[player]; j++)
		{
			pre.deck[player][j] = rand() % 28; //put random cards in the player's randomly sized deck
			if(pre.deck[player][j] > 3 && pre.deck[player][j] < 7)
			{
				totalTreasures++;
			}
		}
		
		for(j = 0; j < pre.discardCount[player]; j++)
		{
			pre.discard[player][j] = rand() % 28; //put random cards in the player's randomly sized discard pile
			if(pre.discard[player][j] > 3 && pre.discard[player][j] < 7)
			{
				totalTreasures++;
			}
		}		
		
		for(j = 0; j < pre.handCount[player]; j++)
		{
			pre.hand[player][j] = rand() % 28;
		}
		
		memcpy(&post, &pre, sizeof(struct gameState)); //copy initialized game state to post struct for later comparison
		cardEffect(adventurer, choice1, choice2, choice3, &post, handPos, &bonus);
		
		if(totalTreasures > 2)
		{
			totalTreasures = 2;
		}
		
		if(post.handCount[player] == pre.handCount[player] + totalTreasures)
		{
			pass++;			
		}
		else{
			fail++;
			printf("Test %d failed.  Expected %d drawn cards.  Actually drew %d cards\n", i, totalTreasures, post.handCount[player] - pre.handCount[player]);
		}
	}
	
	printf ("Tests passed: %d, tests failed: %d\n", pass, fail);
	
	return 0;
}
		
		
		
		
		
		
		
		
		
		
	
	
	
	
	

	