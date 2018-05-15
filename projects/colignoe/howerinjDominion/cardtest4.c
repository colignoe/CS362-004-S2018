/***************************
** Jake Howering
** CS 362 @ Oregon State U
** Spring 2018
** Filename: cardtest4.c
** Description: Card test 4 - 
**  test the Steward card
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
	printf("Card Test 1 - Steward Card\n");
	int choice1 = 0, choice2 = 0, choice3 = 0;
	int flag = G.coins;
	cardEffect(steward, choice1, choice2, choice3, &G, 0, NULL);
	choice1 = 2;
	if(G.coins == flag + 2)
		printf("Steward Card test passed\n");
	else {
		printf("Steward Card test failed\n");
		printf("The coins were not incremented correctly.\n");
	}

	return 0;
}
