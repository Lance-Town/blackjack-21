//
//  blackJackFunctions.hpp
//  Blackjack
//
//  Created by Lance on 7/28/22.
//

#ifndef blackJackFunctions_314159265359_hpp
#define blackJackFunctions_314159265359_hpp

#include <vector>

void populateDeck(std::vector<std::vector<int>> &cardDeck);

void checkAce(std::vector<std::vector<int>> &cardDeck, int &score);

void checkDeck(std::vector<std::string> &keys, std::vector<std::vector<int>> &cardDeck, int position);

void printCard(std::vector<std::string> &keys, int position, int numCardsToFlip);

int playRound(std::vector<std::string> &keys, std::vector<std::vector<int>> &cardDeck, std::vector<std::string> &playerCards, int &numCardsToFlip);

int startGame(std::vector<std::string> &keys, std::vector<std::vector<int>> &cardDeck, std::vector<std::string> &playerCards, int score, int timesToRun, int numCardsToFlip);

int hitStand(std::vector<std::string> &keys, std::vector<std::vector<int>> &cardDeck, std::vector<std::string> &playerCards, int score);

void flipDealerCard(std::string card);

int dealerLogic(std::vector<std::string> &keys, std::vector<std::vector<int>> &cardDeck, std::vector<std::string> &playerCards, int computerScore, int playerScore);

bool is21(int score, bool isHumanPlayer);

void printWinner(int playerScore, int computerScore);

#endif /* blackJackFunctions_hpp */
