/********************
** Jake Howering
** CS 362 @ Oregon State U
** Spring 2018
** Filename: unittest2.c
** Description: Unit test 2-
**  isGameOver function test
*********************/
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int main(int argc, char** argv){
	int seed=1000;
	int numPlayers = 2;
	struct gameState G;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, gardens, tribute, smithy, council_room};
	int count = 0;
	// initialize game state
	initializeGame(numPlayers, k, seed, &G);

	printf("Test isGameOver function\n");
	// the game is over if the province card supply count is zero
	G.supplyCount[province] = 0;
	count = isGameOver(&G);
	if(count == 1)
		printf("The Game is over - test 1 passed\n");
	else 
		printf("The game is not over -- test 1 failed\n");

	// the game is over if 3 supply counts are zero so we'll set three supply counts to zero
	G.supplyCount[1] = 0;
	G.supplyCount[2] = 0;
	G.supplyCount[3] = 0;
	count = isGameOver(&G);
	if(count == 1)
		printf("The game is over - test 2 passed\n");
	else
		printf("The game is not over - test 2 failed\n");

	return 0;
}
