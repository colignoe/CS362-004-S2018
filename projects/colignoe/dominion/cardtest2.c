/*
** cardtest2.c
**
** tests implementation of smithy card
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
  int result; // stores return value of function during testing


  // init game
  initializeGame(numPlayers, k, seed, &G);

  printf("-----------TESTING smithy():---------------\n");


  int preNumCards = numHandCards(&G); // should increment by 2
  int preNumActions = G.numActions; // should decrememnt by 1

  // play smithy card
  G.hand[0][0] = smithy;
  result = playCard(0, 0, 0, 0, &G);

  // test that result = 0
  assertTrue(result, 0);

  assertTrue(numHandCards(&G), preNumCards + 2);
  assertTrue(G.numActions, preNumActions - 1);



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
