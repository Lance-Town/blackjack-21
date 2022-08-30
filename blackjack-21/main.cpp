////
//  main.cpp
//  Blackjack
//
//  Created by Lance on 7/27/22.
//

#include "blackJackHelper.hpp"
#include <iostream>
#include <vector>

// keep track of player/computer score and cards
struct Hand {
    int score;
    std::vector<std::string> cards;
};

int main(int argc, const char * argv[]) {
    // create cards
    std::vector<std::vector<int>> cardDeck;
    populateDeck(cardDeck);
    
    // generate keys
    std::vector<std::string> keys = {"ace", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "jack", "queen", "king"};
    
    // set new seed
    srand(static_cast<unsigned int>(time(NULL)));
    
    // create player and computers hands
    Hand player{};
    Hand computer{};
    
    std::cout << "You are dealt: ";
    player.score = startGame(keys, cardDeck, player.cards, player.score, 2, 2);
    std::cout << "\nYour total is: " << player.score << "\nDealer has: ";
    computer.score = startGame(keys, cardDeck, computer.cards, computer.score, 2, 1);
    
    // allow player to keep hitting until they stand
    player.score = hitStand(keys, cardDeck, player.cards, player.score);
    
    // check to see if player bust, if they did then exit game
    if (is21(player.score, true)) return 0;
    
    // flip the dealers second card
    flipDealerCard(computer.cards[computer.cards.size()-1]);
    
    // dealer hits until they win or lose
    computer.score = dealerLogic(keys, cardDeck, computer.cards, computer.score, player.score);
    
    // check to see if computer bust, if they did then exit game
    if (is21(computer.score, false)) return 0;

    // see who won
    printWinner(player.score, computer.score);
    
    return 0;
}
