#include "rngs.h"
#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//testing getCost()
int getCostTest(int card)
{
	int result;
	result = getCost(card);
	return result;
}

int main()
{
	int result;
	
	printf("Testing getCost() function\n\n");
	result = getCostTest(-1);
	printf("Testing out of bounds value: Expected result: -1, Actual result: %d - ", result);
	if (result == -1)
	{
		printf("Test Passed!\n");
	}
	else{
		printf("Test failed!\n");
	}
	
	result = getCostTest(0);
	printf("Testing curse: Expected result: 0, Actual result: %d - ", result);
	if (result == 0)
	{
		printf("Test Passed!\n");
	}
	else{
		printf("Test failed!\n");
	}
	
	result = getCostTest(1);
	printf("Testing Estate: Expected result: 2, Actual result: %d - ", result);
	if (result == 2)
	{
		printf("Test Passed!\n");
	}
	else{
		printf("Test failed!\n");
	}
	
	result = getCostTest(2);
	printf("Testing Duchy: Expected result: 5, Actual result: %d - ", result);
	if (result == 5)
	{
		printf("Test Passed!\n");
	}
	else{
		printf("Test failed!\n");
	}
	
	result = getCostTest(3);
	printf("Testing province: Expected result: 8, Actual result: %d - ", result);
	if (result == 8)
	{
		printf("Test Passed!\n");
	}
	else{
		printf("Test failed!\n");
	}
	
	result = getCostTest(4);
	printf("Testing Copper: Expected result: 0, Actual result: %d - ", result);
	if (result == 0)
	{
		printf("Test Passed!\n");
	}
	else{
		printf("Test failed!\n");
	}
	
		result = getCostTest(5);
	printf("Testing Silver: Expected result: 3, Actual result: %d - ", result);
	if (result == 3)
	{
		printf("Test Passed!\n");
	}
	else{
		printf("Test failed!\n");
	}
	
		result = getCostTest(6);
	printf("Testing Gold: Expected result: 6, Actual result: %d - ", result);
	if (result == 6)
	{
		printf("Test Passed!\n");
	}
	else{
		printf("Test failed!\n");
	}
	
		result = getCostTest(7);
	printf("Testing adventurer: Expected result: 6, Actual result: %d - ", result);
	if (result == 6)
	{
		printf("Test Passed!\n");
	}
	else{
		printf("Test failed!\n");
	}
	
		result = getCostTest(8);
	printf("Testing council room: Expected result: 5, Actual result: %d - ", result);
	if (result == 5)
	{
		printf("Test Passed!\n");
	}
	else{
		printf("Test failed!\n");
	}
	
			result = getCostTest(9);
	printf("Testing feast: Expected result: 4, Actual result: %d - ", result);
	if (result == 4)
	{
		printf("Test Passed!\n");
	}
	else{
		printf("Test failed!\n");
	}
	
			result = getCostTest(10);
	printf("Testing gardens: Expected result: 4, Actual result: %d - ", result);
	if (result == 4)
	{
		printf("Test Passed!\n");
	}
	else{
		printf("Test failed!\n");
	}
	
			result = getCostTest(11);
	printf("Testing mine: Expected result: 5, Actual result: %d - ", result);
	if (result == 5)
	{
		printf("Test Passed!\n");
	}
	else{
		printf("Test failed!\n");
	}
	
			result = getCostTest(12);
	printf("Testing remodel: Expected result: 4, Actual result: %d - ", result);
	if (result == 4)
	{
		printf("Test Passed!\n");
	}
	else{
		printf("Test failed!\n");
	}
	
			result = getCostTest(13);
	printf("Testing smithy: Expected result: 4, Actual result: %d - ", result);
	if (result == 4)
	{
		printf("Test Passed!\n");
	}
	else{
		printf("Test failed!\n");
	}
	
			result = getCostTest(14);
	printf("Testing village: Expected result: 3, Actual result: %d - ", result);
	if (result == 3)
	{
		printf("Test Passed!\n");
	}
	else{
		printf("Test failed!\n");
	}
	
			result = getCostTest(15);
	printf("Testing baron: Expected result: 4, Actual result: %d - ", result);
	if (result == 4)
	{
		printf("Test Passed!\n");
	}
	else{
		printf("Test failed!\n");
	}
	
			result = getCostTest(16);
	printf("Testing great hall: Expected result: 3, Actual result: %d - ", result);
	if (result == 3)
	{
		printf("Test Passed!\n");
	}
	else{
		printf("Test failed!\n");
	}
	
			result = getCostTest(17);
	printf("Testing minion: Expected result: 5, Actual result: %d - ", result);
	if (result == 5)
	{
		printf("Test Passed!\n");
	}
	else{
		printf("Test failed!\n");
	}
	
			result = getCostTest(18);
	printf("Testing steward: Expected result: 3, Actual result: %d - ", result);
	if (result == 3)
	{
		printf("Test Passed!\n");
	}
	else{
		printf("Test failed!\n");
	}
	
			result = getCostTest(19);
	printf("Testing tribute: Expected result: 5, Actual result: %d - ", result);
	if (result == 5)
	{
		printf("Test Passed!\n");
	}
	else{
		printf("Test failed!\n");
	}
	
				result = getCostTest(20);
	printf("Testing ambassador: Expected result: 3, Actual result: %d - ", result);
	if (result == 3)
	{
		printf("Test Passed!\n");
	}
	else{
		printf("Test failed!\n");
	}
	
				result = getCostTest(21);
	printf("Testing cutpurse: Expected result: 4, Actual result: %d - ", result);
	if (result == 4)
	{
		printf("Test Passed!\n");
	}
	else{
		printf("Test failed!\n");
	}
	
				result = getCostTest(22);
	printf("Testing embargo: Expected result: 2, Actual result: %d - ", result);
	if (result == 2)
	{
		printf("Test Passed!\n");
	}
	else{
		printf("Test failed!\n");
	}
	
				result = getCostTest(23);
	printf("Testing outpost: Expected result: 5, Actual result: %d - ", result);
	if (result == 5)
	{
		printf("Test Passed!\n");
	}
	else{
		printf("Test failed!\n");
	}
	
				result = getCostTest(24);
	printf("Testing salvager: Expected result: 4, Actual result: %d - ", result);
	if (result == 4)
	{
		printf("Test Passed!\n");
	}
	else{
		printf("Test failed!\n");
	}
	
					result = getCostTest(25);
	printf("Testing sea hag: Expected result: 4, Actual result: %d - ", result);
	if (result == 4)
	{
		printf("Test Passed!\n");
	}
	else{
		printf("Test failed!\n");
	}
	
					result = getCostTest(26);
	printf("Testing treasure map: Expected result: 4, Actual result: %d - ", result);
	if (result == 4)
	{
		printf("Test Passed!\n");
	}
	else{
		printf("Test failed!\n");
	}
}
	
	

	