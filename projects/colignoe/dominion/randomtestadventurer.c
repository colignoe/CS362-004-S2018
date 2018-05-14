/*********************************************************************
** Filename: randomtestadventurer.c
**   Author: Evin Colignon
**     Date: 5/13/18
** Overview:
**    Input:
**   Output:
*********************************************************************/



// include libraries
// include necessary dominion files
#include <time.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"


int checkAdventurer(int p, struct gameState *post);


// Identify the interface to test - what should cardEffect do?
// adventurer
// invoke cardEffect - cardEffectFails
int cardEffectFails = 0;
// if deck empty need to shuffle discard and add to deck - shuffleFails
int shuffleFails = 0;
// card needs to be drawn - drawCardFails
int drawCardFails = 0;
// drawn treasure increases if copper silver or gold - treasureFails
int treasureFails = 0;
// handCount decreases - handCountFails
int handCountFails = 0;
// total fails
int totalFails;





int main()
{
  // TODO Write code to generate random inputs: use code to randomly set
  // gamestate within reasonable boundaries (values code is expected to handle).
  // Hard code some boundary cases if needed
  printf("-----------testing randomtestadventurer.c-----------\n");
  printf("--------------testing adventurer card-------------\n");

  int i, n, p;
  int seed = 1000;
  int k[10] = {adventurer, council_room, feast, gardens, mine,
              remodel, smithy, village, baron, great_hall};
  struct gameState G;

  int numPlayers = floor(Random() * MAX_PLAYERS);

  // seed rand() function
  srand(time(NULL));

  for (n = 0; n < 2000; n++)
  {
    for (i = 0; i < sizeof(struct gameState); i++)
    {
      ((char*)&G)[i] = floor(Random() * 256);
    }

    // init game
    // initializeGame(numPlayers, k, seed, &G);


    // shift probability space: randomly select values within appropriate range
    p = floor(Random() * MAX_PLAYERS); // player
    G.numPlayers = floor(Random()* MAX_PLAYERS);
    G.deckCount[p] = floor(Random() * MAX_DECK); // deckCount
    G.discardCount[p] = floor(Random() * MAX_DECK); // discardCount
    G.handCount[p] = floor(Random() * MAX_HAND); // handcount
    G.playedCardCount = floor(Random() * MAX_DECK);
    G.whoseTurn = p;


    checkAdventurer(p, &G);
  }

  printf("ALL TESTS OK\n");



  return 0;

}




// TODO Write code to check behavior on random inputs: use code to copy
// gamestate beforehand to "pre" variable, manually change the values as
// they are expected to change, then compare the values
int checkAdventurer(int p, struct gameState *post)
{
  struct gameState pre;
  memcpy (&pre, post, sizeof(struct gameState));

  int bonus = 0;
  int result = 0;
  // int s;

  // call the card cardEffect
  result = cardEffect(adventurer,0,0,0,post,0, &bonus);

  if (result != 0)
  {
    cardEffectFails++;
  }


  // TODO change pre manually
  // TODO compare to post


  return 0;

}
