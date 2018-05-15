/***************************
** Jake Howering
** CS 362 @ Oregon State U
** Spring 2018
** Filename: unittest4.c
** Description: Unit test 4 - 
**  getCost function test
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
	int cost = 0;
	// initialize game state
	initializeGame(numPlayers, k, seed, &G);

	printf ("Test getCost function.\n");
	cost = getCost(adventurer);
	// The adventurer should return 6
	if(cost == 6)
		printf("getCost function test passed\n");
	else	
		printf("getCost function test failed\n");
	//test with smithy - should return 4
	cost = getCost(smithy);
	if(cost == 4)
		printf("getCost function test passed\n");
	else
		printf("getCost function test failed\n");
	//test with embargo - should return 2
	cost = getCost(embargo);
	if(cost == 2)
		printf("getCost function test passed\n");
	else
		printf("getCost function test failed\n");
	//test with village- should return 3
	cost = getCost(village);
	if(cost == 3)
		printf("getCost function test passed\n");
	else
		printf("getCost function test failed\n");
	//test with minion - should return 5
	cost = getCost(minion);
	if(cost == 5)
		printf("getCost function test passed\n");
	else
		printf("getCost function test failed\n");
	//test with mine - should return 5
	cost = getCost(mine);
	if(cost == 5)
		printf("getCost function test passed\n");
	else
		printf("getCost function test failed\n");
	//test with cutpurse - should return 4
	cost = getCost(cutpurse);
	if(cost == 4)
		printf("getCost function test passed\n");
	else
		printf("getCost function test failed\n");
	//test with gardens - should return 4
	cost = getCost(gardens);
	if(cost == 4)
		printf("getCost function test passed\n");
	else
		printf("getCost function test failed\n");
	//test with tribute - should return 5
	cost = getCost(tribute);
	if(cost == 5)
		printf("getCost function test passed\n");
	else
		printf("getCost function test failed\n");
	//test with council_room - should return 5
	cost = getCost(council_room);
	if(cost == 5)
		printf("getCost function test passed\n");
	else
		printf("getCost function test failed\n");
	// test with invalid cost and should return -1
	int flag = 99;
	cost = getCost(flag);
	if(cost == -1)
		printf("getCost function test passed\n");
	else	
		printf("getCost function test failed\n");
	
	return 0;
}
