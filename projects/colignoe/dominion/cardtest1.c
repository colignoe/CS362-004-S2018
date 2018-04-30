/*
** cardtest1.c
**
** tests play of adventurer card
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


  printf("-----------TESTING adventurer:---------------\n");


  // play adventurer card
  G.hand[0][0] = adventurer;
  result = playCard(0, 0, 0, 0, &G);






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
