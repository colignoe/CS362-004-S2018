/***************************
** Jake Howering
** CS 362 @ Oregon State U
** Spring 2018
** Filename: randomtestadventurer.c
** Description: randomize variables
** for adventurer function
*****************************/
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define NO_TESTS 1000

int main (int argc, char** argv) {
	
	int seed = rand();
	int preTotalCards = 0;
	int postTotalCards = 0;
	int passed = 0;
	int failed = 0;
	
	printf("Adventurer Card - Random Testing\n");

	for (int i = 0; i < NO_TESTS; i++) {
		int numPlayers = rand()%3 + 2;
		int player = rand() % (numPlayers + 1);
		int handPos = rand()%  4;
		int choice1 = rand()%2;
		int choice2 = rand()%2;
		int choice3 = rand()%2;
		struct gameState G;
		int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
				gardens, tribute, smithy, council_room};

		// initialize game state
		initializeGame(numPlayers, k, seed, &G);
		
		//Get card numbers
		G.deckCount[player] = rand() % MAX_DECK;
		G.discardCount[player] = rand() % MAX_DECK;
		G.handCount[player] = rand() % MAX_DECK;
		preTotalCards = G.deckCount[player] + G.discardCount[player] + G.handCount[player];

		int flag = cardEffect(adventurer, choice1, choice2, choice3, &G, handPos, NULL);
		if(flag == 0){
			// printf("Adventurer Card test passed\n");
			postTotalCards = G.deckCount[player] + G.discardCount[player] + G.handCount[player];
			if(preTotalCards == postTotalCards){
				//the card counts after calling adventurer card are good
				passed = passed + 1;
			}
		}
		else {
			// printf("Adventurer test passed\n");
			failed = failed + 1;
		}
	}
	printf("The Adventurer card is called and various card plays occur\n");
	printf("The overall card count should be the same after the Adventurer card is played. \n");
	printf("This test will check that we haven accurate overall card count\n");
	printf("The Adventurer card passed %d tests\n", passed);
	printf("The Adventurer card failed %d tests\n", failed);
	return 0;
}