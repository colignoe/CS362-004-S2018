/*********************************************************************
** Filename: randomtestcard1.c
**   Author: Evin Colignon
**     Date: 5/13/18
** Overview: Generates and displays results of random tests of the
**           "great_hall" dominion card
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


int checkGreatHall(int p, struct gameState *post);

// Identify the interface to test - what should cardEffect do?
// great_hall
// draw card - drawCardFails
int drawCardFails = 0;
// state->numActions++ - numActionsFails
int numActionsFails = 0;
// discard - discardFails
int discardCardFails = 0;
// return 0 - cardEffectFails
int cardEffectFails = 0;
int totalFails;


int main()
{

  // Write code to generate random inputs: use code to randomly set
  // gamestate within reasonable boundaries (values code is expected to handle).
  // Hard code some boundary cases if needed
  printf("-----------testing randomtestcard2.c-----------\n");
  printf("--------------testing great_hall card-------------\n");

  int i, n, p;
  struct gameState G;

  // seed rand() function
  srand(time(NULL));

  for (n = 0; n < 2000; n++)
  {
    for (i = 0; i < sizeof(struct gameState); i++)
    {
      ((char*)&G)[i] = floor(Random() * 256);
    }

    // shift probability space: randomly select values within appropriate range
    p = floor(Random() * MAX_PLAYERS); // player
    G.deckCount[p] = floor(Random() * MAX_DECK); // deckCount
    G.discardCount[p] = floor(Random() * MAX_DECK); // discardCount
    G.handCount[p] = floor(Random() * MAX_HAND); // handcount
    G.playedCardCount = floor(Random() * MAX_DECK);
    G.whoseTurn = p;


    checkGreatHall(p, &G);
  }


  totalFails = drawCardFails + numActionsFails + discardCardFails + cardEffectFails;

  // if total fails == 0, all tests okay
  if (totalFails == 0)
  {
    printf("ALL TESTS OK\n");
  }

  // else print number of each failed test
  else
  {
    printf("draw card fails = %d\n", drawCardFails);
    printf("number of actions fails = %d\n", numActionsFails);
    printf("discard fails = %d\n", discardCardFails);
    printf("card effect fails = %d\n", cardEffectFails);
    printf("total fails = %d\n", totalFails);
  }



  return 0;

}


//
// Write code to check behavior on random inputs: use code to copy
// gamestate beforehand to "pre" variable, manually change the values as
// they are expected to change, then compare the values
int checkGreatHall(int p, struct gameState *post)
{
  struct gameState pre;
  memcpy (&pre, post, sizeof(struct gameState));

  int bonus = 0;
  int result = 0;
  int s;

  // call the card cardEffect
  result = cardEffect(great_hall,0,0,0,post,0, &bonus);

  if (result != 0)
  {
    cardEffectFails++;
  }

  // change pre manually
  // draw card
  s = drawCard(p, &pre);
  if (s != 0)
  {
    drawCardFails ++;
  }

  // increment actions
  pre.numActions++;
  if (pre.numActions != post->numActions)
  {
    numActionsFails ++;
  }

  // discard card from hand
  s = discardCard(0, p, &pre, 0);
  if (s != 0)
  {
    discardCardFails ++;
  }


  return 0;

}
