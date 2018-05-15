/*************************** 
** Jake Howering 
** CS 362 @ Oregon State U 
** Spring 2018 
** Filename: randomtestcard2.c 
** Description: Steward card - 
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
	int passed1, passed2, passed3 = 0;
	int failed1 = 0;
	int failed2 = 0;
	int failed3 = 0;
	
	printf("Steward Card - Random Testing\n");
	
	for(int i = 0; i < NO_TESTS; i++){
		int numPlayers = rand()%3 + 2;
		int player = rand() % (numPlayers + 1);
		int handPos = rand()%4;
		int choice1 = rand()%3;
		int choice2 = rand()%2;
		int choice3 = rand()%2;
		struct gameState G;
		int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
				gardens, tribute, smithy, council_room};
		int flagCoins;
		int flagCount;
		
		// initialize game state
		initializeGame(numPlayers, k, seed, &G);

		flagCoins = G.coins;
		flagCount = numHandCards(&G);

		cardEffect(steward, choice1, choice2, choice3, &G, handPos, NULL);

		if(choice1 == 1){
			if(numHandCards(&G) == flagCount + 1){
				//printf("Steward Card draw test passed\n");
				passed1 = passed1 + 1;
			} else {
				//printf("Steward Card draw test failed\n");
				failed1 = failed1 + 1;
			}
		}
		else if(choice1 == 2){
			if(G.coins == flagCoins + 2){
				//printf("Steward Card coin test passed\n");
				passed2 = passed2 + 1;
			} else {
				//printf("Steward Card coin test failed\n");
				failed2 = failed2 + 1;
			}
		}
		else {
			if(numHandCards(&G) == flagCount - 3){
				//printf("Steward Card discard test passed\n");
				passed3 = passed3 + 1;
			} else {
				//printf("Steward Card discard test failed\n");
				failed3 = failed3 + 1;
			}
		}
	}
	printf("The Steward card passed %d card draw tests\n", passed1);
	printf("The Steward card failed %d card draw tests\n", failed1);
	
	printf("The Steward card passed %d coin count tests\n", passed2);
	printf("The Steward card failed %d coin count tests\n", failed2);
	
	printf("The Steward card passed %d card discard tests\n", passed3);
	printf("The Steward card failed %d card discard tests\n", failed3);
	return 0;
}


