/*
** unittest4.c
**
** Tests function int supplyCount(int card, struct gameState *state)
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>


int faults = 0; // track number of faults

void assertTrue(int a, int b)
{
  if (a == b)
  {
    printf("TEST PASSED\n");
  }
  else
  {
    printf("TEST FAILURE\n");
    faults++;
  }

}


int main()
{
  int seed = 1000;
  int numPlayers = 2;
  int k[10] = {adventurer, council_room, feast, gardens, mine,
              remodel, smithy, village, baron, great_hall};
  struct gameState G;
  // int result; // stores return value of function during testing

  // init game
  initializeGame(numPlayers, k, seed, &G);

printf("-----------TESTING supplyCount():---------------\n");


  // set supply of each card to 0
  int i;
  for (i = 0; i < treasure_map; i++)
  {
    G.supplyCount[i] = 0;
  }

  // pick 3 cards and assert they are 0
  assertTrue(supplyCount(gold, &G), 0);
  assertTrue(supplyCount(embargo, &G), 0);
  assertTrue(supplyCount(outpost, &G), 0);

  // set supply of each card to 10
  for (i = 0; i < treasure_map; i++)
  {
    G.supplyCount[i] = 10;
  }

  // assert they all return 10
  assertTrue(supplyCount(gold, &G), 10);
  assertTrue(supplyCount(embargo, &G), 10);
  assertTrue(supplyCount(outpost, &G), 10);


  // Test complete
  if (faults > 0)
  {
    printf("\nTEST FAILED\n");
  }
  else
  {
    printf("\nTEST SUCCESSFULLY COMPLETED\n");
  }

}
