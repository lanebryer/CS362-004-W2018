#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"
#include <math.h>
#include <stdlib.h>
#include <time.h>

//testing steward card
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
		pre.handCount[player] = rand() % 28 + 3; //Set hand count to between 3-30 inclusive (player must have at least 3 cards in order to play steward and trash 2 additional)
		pre.deckCount[player] = rand() % 30 + 1; //Set deck count to between 1-30 inclusive		
		pre.discardCount[player] = rand() % 30 + 1; //Set discard count to between 1-30 inclusive
		pre.playedCardCount = rand() % 11; //set played card count to between 1-10 inclusive
		choice1 = rand() % 3;  //set choice1 to either 0, 1, or 2 - tests all choices equally (1/3 chance of picking any choice)
		do{
			choice2 = rand() % pre.handCount[player];
		} while (choice2 == 0); //pick random card that cannot be 0 (handPos)
		
		do{
		choice3 = rand() % pre.handCount[player];
		} while (choice3 == choice2 || choice3 == 0); //pick random card that isn't card already chosen as choice2 or handPos		
			
		
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
		
		memcpy(&post, &pre, sizeof(struct gameState));
		cardEffect(steward, choice1, choice2, choice3, &post, handPos, &bonus);
		
		if(choice1 == 0)
		{
			if(post.handCount[player] - pre.handCount[player] == -3)
			{
				pass++;
			}
			else{
				fail++;
				printf("Test %d: Choice1: %d, Expected hand count: %d, actual hand count: %d\nExpected discard count: 1, Actual discard count: %d\n", i, choice1, pre.handCount[player] - 3,
					pre.discardCount[player] + 1, post.discardCount[player]);
			}
		}
		else if (choice1 == 1)
		{
			if(post.handCount[player] - pre.handCount[player] == 1)
			{
				pass++;
			}
			else
			{
				fail++;
				printf("Test %d: Choice1: %d, Expected hand count: %d, actual hand count: %d\nExpected discard count: %d, Actual discard count: %d\n", i, choice1, pre.handCount[player]+1,
				post.handCount[player], pre.discardCount[player] + 1, post.discardCount[player] - pre.discardCount[player]);
			}
		}
		else{
			if(post.coins - pre.coins == 2)
			{
				pass++;
			}
			else
			{
				fail++;
				printf("Test %d: Choice1: %d, Expected coin count: %d, actual coin count: %d\nExpected discard count: %d, Actual discard count: %d\n", i, choice1, pre.coins + 2, post.coins,
				pre.discardCount[player] + 1, post.discardCount[player]);
			}
		}
	}
	
	printf("Tests passed: %d, tests failed: %d\n", pass, fail);
	
	return 0;
}
			
		
		
		
		