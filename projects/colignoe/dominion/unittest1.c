/*
** unittest.1.c
**
** Tests function buyCard(int supplyPos, struct gameState *state)
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

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

printf("-----------TESTING buyCard():---------------\n");

  // buy gold for all tests, costs 6
  // if numBuys is 0, should return -1
  printf("Test: numBuys is 0 -> ");
  G.numBuys = 0;
  result = buyCard(gold, &G);
  assertTrue(-1, result);


  // if supply of card is empty, should return -1
  printf("Test: supply of card is empty -> ");
  G.supplyCount[gold] = 0;
  result = buyCard(gold, &G);
  assertTrue(-1, result);


  // if not enough money, should return - 1
  printf("Test: not enough coins to buy card -> ");
  G.coins = 3;
  result = buyCard(gold, &G);
  assertTrue(-1, result);



  // gameState changes correctly if enough of everything:
  G.coins = 10;
  G.numBuys = 2;
  G.supplyCount[gold] = 5;

  result = buyCard(gold, &G); // result should return 0

  // phase should be set to 1
  printf("Test: phase set to 1 -> ");
  assertTrue(G.phase, 1);
  // coins should decrement by amount of card
  printf("Test: coins decremented by card cost -> ");
  assertTrue(G.coins, 4);
  // numbuys should decrement by 1
  printf("Test: numBuy decremented -> ");
  assertTrue(G.numBuys, 1);
  // supply of gold should decrement by 1
  printf("Test: supply of gold decrements -> ");
  assertTrue(G.supplyCount[gold], 4);


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
