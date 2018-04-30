/*
** unittest3.c
**
** Tests function int handCard(int handPos, struct gameState *state)
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


int main(void)
{

  printf("-----------TESTING handCard():---------------\n");

  int seed = 1000;
  int numPlayers = 2;
  int k[10] = {adventurer, council_room, feast, gardens, mine,
              remodel, smithy, village, baron, great_hall};
  struct gameState G;
  // int result; // stores return value of function during testing
  int card;

  // init game
  initializeGame(numPlayers, k, seed, &G);

  // set to player 1's turn
  G.whoseTurn = 0;

  // assert that handCard return value == G.hand[currentPlayer][handPos]


  // player 1 1st card
  card = handCard(0, &G);
  assertTrue(card, G.hand[0][0]);


  // player 1 2nd card
  card = handCard(1, &G);
  assertTrue(card, G.hand[0][1]);


  // change players
  G.whoseTurn = 1;

  // player 2 1st card
  card = handCard(0, &G);
  assertTrue(card, G.hand[1][0]);

  // player 2 2nd card
  card = handCard(1, &G);
  assertTrue(card, G.hand[1][1]);


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
