#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"
#include <math.h>
#include <stdlib.h>
#include <time.h>

//testing outpost card
int main()
{
	srand(time(NULL));
	int choice1, choice2, choice3, handPos, bonus, i, j, pass, fail, seed, numPlayers, player;
	choice1 = choice2 = choice3 = handPos = bonus = pass = fail = 0;
	struct gameState pre;
	struct gameState post;
	int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
	
	for(i = 0; i < 2000; i++)
	{
		memset(&pre, 0, sizeof(struct gameState));
		memset(&post, 0, sizeof(struct gameState));
		seed = rand() % 1000 + 1; //set seed to between 1-1000 inclusive
		numPlayers = rand() % 3 + 2; //set number of players to between 2-4 inclusive
		initializeGame(numPlayers, k, seed, &pre);
		pre.whoseTurn = rand() % numPlayers;
		player = whoseTurn(&pre);
		pre.handCount[player] = rand() % 30 + 1; //Set hand count to between 1-30 inclusive 
		pre.deckCount[player] = rand() % 30 + 1; //Set deck count to between 1-30 inclusive		
		pre.discardCount[player] = rand() % 30 + 1; //Set discard count to between 1-30 inclusive
		pre.playedCardCount = rand() % 11; //set played card count to between 1-10 inclusive
		
		for(j = 0; j < pre.deckCount[player]; j++)
		{
			pre.deck[player][j] = rand() % 28; //put random cards in the player's randomly sized deck
		}
		
		for(j = 0; j < pre.discardCount[player]; j++)
		{
			pre.discard[player][j] = rand() % 28; //put random cards in the player's randomly sized discard pile
		}			
		
		for(j = 0; j < pre.handCount[player]; j++)
		{
			pre.hand[player][j] = rand() % 28;
		}
		
		pre.outpostPlayed = rand() % 20; //give a random value for outpost played
		
		memcpy(&post, &pre, sizeof(struct gameState));
		cardEffect(outpost, choice1, choice2, choice3, &post, handPos, &bonus);
		
		if(post.outpostPlayed - pre.outpostPlayed == 1 && post.playedCardCount - pre.playedCardCount == 1)
		{
			pass++;
		}
		else{
			fail++;
			printf("Test %d failed.  Expected outposts played: %d, actual outposts: %d, Expected played pile addition: %d, actual: %d\n", i, 
			1, post.outpostPlayed - pre.outpostPlayed, 1, post.playedCardCount - pre.playedCardCount);
		}
	}
	printf("Tests passed: %d, tests failed: %d\n", pass, fail);
	
	return 0;
}
		
		
		
		
	
	