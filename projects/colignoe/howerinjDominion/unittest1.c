/***************************
** Jake Howering
** CS 362 @ Oregon State U
** Spring 2018
** Filename: unittest1.c
** Description: Unit test 1 - 
**  testing the copper,gold,silver
**  supply count
*****************************/
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int main() {
	int seed = 1000;
	int numPlayers = 2;
	struct gameState G;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			gardens, tribute, smithy, council_room};
	int count = 0;

	// initialize game state
	initializeGame(numPlayers, k, seed, &G);

	printf ("Test Supply Count.\n");	
	
	// Copper supply count
	count = supplyCount(copper, &G);
	if (count == 46)
		printf("Copper supply test passed!\n");
	else 
		printf("Test Failed\n\n");

	// Silver supply count	
	count = supplyCount(silver, &G);
	if (count == 40)
		printf("Silver supply test passed!\n");
	else 
		printf("Test Failed\n\n");

	// Gold  supply count		
	count = supplyCount(gold, &G);
	if (count == 30)
		printf("Gold supply test passed!\n\n");
	else 
		printf("Test Failed\n\n");

	return 0;
}


