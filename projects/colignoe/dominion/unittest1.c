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


int main()
{
  int seed = 1000;
  struct gameState G;
  int k[10] = {adventurer, council_room, feast, gardens, mine,
              remodel, smithy, village, baron, great_hall};

  printf("TESTING buyCard():\n");
}
