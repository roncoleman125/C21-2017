/*
Copyright (c) Ron Coleman
Permission is hereby granted, free of charge, to any person obtaining
a copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to
the following conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/
#pragma once
#include "Strategy.h"
#include "Player.h"

/*! \def Blackjack (natural) payoff */
#define PAYOFF_BLACKJACK (1.5f)

/*! \def Charlie payoff */
#define PAYOFF_CHARLIE (2.0f)

/*! \def Push payoff */
#define PAYOFF_PUSH (0.0f)

// Count indices of Game 
#define WINS 0
#define BLACKJACKS 1
#define CHARLIES 2
#define LOSSES 3
#define BUSTS 4
#define DEALER_BLACKJACKS 5
#define PUSHES 6

/*!
  \struct Game
  \brief  Defines statistics to collect from one or more games.
*/
typedef struct {
	int count[7];  /**< Frequency counts */
	int nohands;   /**< Number of hands played in game, could be >= number of games depending on splits */
	float pl;      /**< P&L for games */
} Game;

/*! \brief Game constructor */
Game Game_(void);

/*!
  \brief Starts a game.
  \param strategy Strategy to use
  \param ngames Number of games to play
  \param seed Random seed
  \return Game statistics for n games
*/
Game start(Strategy* strategy, int ngames, int seed);

/*!
  \brief Plays one complete game, with player going first then if necessary, the dealer.
  \param strategy Strategy pointer
  \param statistics Game statistics pointer
*/
void play(Strategy* strategy, Game* statistics);

/*!
  \brief Plays all plays of the player, including splits.
  \param player Player pointer
  \param upcard Dealer's upcard pointer
*/
void play(Player* player, Card* upcard);

/*!
  \brief Plays out player hand, recusively in case of split, if necessary.
  \param hand Player hand pointer
  \param upcard Dealer's upcard pointer
*/
void playout(Hand* hand, Card* upcard);

/*!
  \brief Closes out game with dealer's hand.
  \param dealer Dealer's hand pointer
  \param player Player with all its hands pointer
  \param statistics Game statistics
*/
void play(Hand* dealer, Player* player, Game* stats);

/*!
  \brief Outputs the game statistics.
  \param method Output method
*/
void output(Game* stats, int method);
