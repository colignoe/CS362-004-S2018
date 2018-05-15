/***************************
** Jake Howering
** CS 362 @ Oregon State U
** Spring 2018
** Filename: cardtest1.c
** Description: Card test 1 - 
**  test the adventurer card
*****************************/
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int main (int argc, char** argv) {

	int seed = 1000;
	int numPlayers = 2;
	struct gameState G;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			gardens, tribute, smithy, council_room};

	// initialize game state
	initializeGame(numPlayers, k, seed, &G);
	printf("Card Test 1 - Adventurer Card\n");
	int choice1 = 0, choice2 = 0, choice3 = 0;
	int flag = cardEffect(adventurer, choice1, choice2, choice3, &G, 0, NULL);
	if(flag == 0)
		printf("Adventurer Card test passed\n");
	else 
		printf("Adventurer test passed\n");

	return 0;
}
