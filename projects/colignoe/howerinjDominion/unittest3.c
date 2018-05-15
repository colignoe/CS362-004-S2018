/***************************
** Jake Howering
** CS 362 @ Oregon State U
** Spring 2018
** Filename: unittest3.c
** Description: Unit test 3 - 
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
	int flag = 0;
	// initialize a game state
	initializeGame(numPlayers, k, seed, &G);
	for (int i = 0; i < 99; i++){
		G.whoseTurn = count;
		flag = whoseTurn(&G);
		if(flag != count)
			printf("Test whoseTurn function failed\n");
		count++;
	}
	printf("Test whoseTurn function passed\n");
	return 0;
}


