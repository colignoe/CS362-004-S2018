/***************************
** Jake Howering
** CS 362 @ Oregon State U
** Spring 2018
** Filename: cardtest2.c
** Description: Card test 2 - 
**  test the smithy card
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
	int flag;
	int choice1 = 0, choice2 = 0, choice3 = 0;
	printf("Card Test 2 - Smithy Card\n");
	// initialize game state
	initializeGame(numPlayers, k, seed, &G);
	flag = numHandCards(&G);
	cardEffect(smithy, choice1, choice2, choice3, &G, 0, NULL);
	//make sure 3 cards were drawn
	if(numHandCards(&G) == flag + 2)
		printf("Smith Card test passed\n");
	else {
		printf("Smithy Card test failed\n");
		printf("The number of cards drawn is incorrect\n");
	}

	return 0;
}
