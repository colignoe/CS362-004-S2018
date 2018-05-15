/***************************
** Jake Howering
** CS 362 @ Oregon State U
** Spring 2018
** Filename: cardtest3.c
** Description: Card test 2 - 
**  test the village card
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
	printf("Card test 3 - Village Card\n");
	// initialize game state
	initializeGame(numPlayers, k, seed, &G);
	flag = G.numActions;
	cardEffect(village, choice1, choice2, choice3, &G, 0, NULL);
	//make sure 2 actions are incremented
	if(G.numActions == flag + 2)
		printf("Village Card test passed\n");
	else {
		printf("Village Card test failed\n");
		printf("The number of actions incremented is incorrect\n");
	}

	return 0;
}
