/*************************** 
** Jake Howering 
** CS 362 @ Oregon State U 
** Spring 2018 
** Filename: randomtestcard1.c 
** Description: Smithy Card - 
** random testing 
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
	int passed = 0;
	int failed = 0;
	
	printf("Smith Card - Random Testing\n");
	
	for(int i = 0; i < NO_TESTS; i++){
		
		int numPlayers = rand()%3 + 2;
		int handPos = rand()%4;
		int choice1 = rand()%2;
		int choice2 = rand()%2;
		int choice3 = rand()%2;
		struct gameState G;
		int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
				gardens, tribute, smithy, council_room};
		int flag;
		// initialize game state
		initializeGame(numPlayers, k, seed, &G);
		flag = numHandCards(&G);
		cardEffect(smithy, choice1, choice2, choice3, &G, handPos, NULL);
		//make sure 3 cards were drawn
		if(numHandCards(&G) == flag + 2)
			//printf("Smith Card test passed\n");
			passed = passed + 1;
		else {
			//printf("Smithy Card test failed\n");
			failed = failed + 1;
		}
	}
	printf("The Smith card is supposed to draw 3 cards and discard 1\n");
	printf("The test is to check if the player hand count increases by two\n");
	printf("The Smithy card passed %d tests\n", passed);
	printf("The Smithy card failed %d tests\n", failed);
	return 0;
}
