/*
** unittest2.c
**
** Tests function isGameOver(struct gameState *state)
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
// #include <assert.h>


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



int main(void)
{

  int seed = 1000;
  int numPlayers = 2;
  int k[10] = {adventurer, council_room, feast, gardens, mine,
              remodel, smithy, village, baron, great_hall};
  struct gameState G;
  int result; // stores return value of function during testing

  // init game
  initializeGame(numPlayers, k, seed, &G);

  printf("-----------TESTING isGameOver():---------------\n");

  // TODO choose input data
  // TODO expected outcome:
  // TODO run function against input
  // TODO examine results



  // input: set stack of province cards to empty (game ends - should return 1)
  printf("Test: stack of province cards is empty -> ");
  G.supplyCount[province] = 0;
  result = isGameOver(&G);
  assertTrue(result, 1);


  // input: stack of province cards not empty (should return 0)
  printf("Test: stack of province cards is not empty -> ");
  G.supplyCount[province] = 1;
  result = isGameOver(&G);
  assertTrue(result, 0);

  // input: set 3 supply piles to empty (game ends - should return 1)
  printf("Test: 3 supply piles are empty -> ");
  G.supplyCount[0] = 0;
  G.supplyCount[1] = 0;
  G.supplyCount[2] = 0;
  result = isGameOver(&G);
  assertTrue(result, 1);

  // input: all supply piles are not empty (should return 0)
  printf("Test: all supply piles have cards -> ");
  int i;
  for (i = 0; i < 25; i++)
  {
    G.supplyCount[i] = 1;
  }
  result = isGameOver(&G);
  assertTrue(result, 0);


  if (faults > 0)
  {
    printf("\nTEST FAILED\n");
  }
  else
  {
    printf("\nTEST SUCCESSFULLY COMPLETED\n");
  }






}
