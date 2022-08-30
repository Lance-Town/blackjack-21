//
//  blackJackFunctions.cpp
//  Blackjack
//
//  Created by Lance on 7/28/22.
//

#include <iostream>
#include <vector>

// populate the card deck with its value
// and times its been used (for max of 4)
void populateDeck(std::vector<std::vector<int>> &cardDeck) {
    cardDeck = {
        {1, 0, 0}, // ace (2nd position value used to tell to add 1 or 11, evaluates to true/false)
        {2, 0},
        {3, 0},
        {4, 0},
        {5, 0},
        {6, 0},
        {7, 0},
        {8, 0},
        {9, 0},
        {10, 0}, // ten
        {10, 0}, // jack
        {10, 0}, // queen
        {10, 0}  // king
    };
}

// logic to determine whether to add 1 or 11 when an ace is pulled
void checkAce(std::vector<std::vector<int>> &cardDeck, int &score) {
    // reset ace back to 0
    cardDeck[0][2] = 0;
    
    if (score <= 11) {
        score += 10;
    }
    
    return;
}

// erase a card if its been used 4 times
void checkDeck(std::vector<std::string> &keys, std::vector<std::vector<int>> &cardDeck, int position) {
    if (cardDeck[position][1] > 3) {
        cardDeck.erase(cardDeck.begin() + position);
        keys.erase(keys.begin() + position);
    }
}

// print the name of the card the player was dealt
void printCard(std::vector<std::string> &keys, int position, int &numCardsToFlip) {
    if (numCardsToFlip) {
        std::cout << keys[position] << " ";
        --numCardsToFlip;
    }
    return;
}

// dole out one card to player/computer
int playRound(std::vector<std::string> &keys, std::vector<std::vector<int>> &cardDeck, std::vector<std::string> &playerCards, int &numCardsToFlip) {
    // generate random number from 0 to vector size
    int position{};
    position = rand() % cardDeck.size();
    
    // increment the times that number has been used
    cardDeck[position][1]++;
    playerCards.push_back(keys[position]);
    
    // print the players card
    printCard(keys, position, numCardsToFlip);
    
    // check if ace was pulled, turn on to notify ace was pulled
    if (cardDeck[position][0] == 1) {
        cardDeck[0][2] = 1;
    }
    
    checkDeck(keys, cardDeck, position);
    
    return cardDeck[position][0];
}

// start game by giving player two cards
int startGame(std::vector<std::string> &keys, std::vector<std::vector<int>> &cardDeck, std::vector<std::string> &playerCards, int score, int timesToRun, int numCardsToFlip) {
    if (timesToRun == 0) {
        // check to see if an Ace was pulled in first two cards
        if (cardDeck[0][2]) {
            checkAce(cardDeck, score);            
        }
        return score;
    }
    --timesToRun;
    
    // re-assign players new score
    score += playRound(keys, cardDeck, playerCards, numCardsToFlip);
    
    return startGame(keys, cardDeck, playerCards, score, timesToRun, numCardsToFlip);
}

// get user input
std::string getUserInput(std::string answer) {
    std::cout << "\nEnter 'hit' or 'stand' to Hit or Stand\nEnter: ";
    std::cin >> answer;
    
    if (answer == "hit" || answer == "stand") {
        return answer;
    }
    return getUserInput(answer);
}

// recursively hit until either user stands, hits 21, or busts
int hitStand(std::vector<std::string> &keys, std::vector<std::vector<int>> &cardDeck, std::vector<std::string> &playerCards, int score) {
    // base case
    if (score >= 21) {
        return score;
    }
    
    // get user input
    std::string answer{};
    answer = getUserInput(answer);
    
    // player doesn't want to hit
    if (answer != "hit") {
        return score;
    }
    
    std::cout << "You hit: ";
    int numCardsToFlip{1};
    score += playRound(keys, cardDeck, playerCards, numCardsToFlip);
    
    std::cout << "\nYour total now is: "<< score << '\n';
    
    return hitStand(keys, cardDeck, playerCards, score);
}

// flip the dealers second card
void flipDealerCard(std::string card) {
    std::cout << "Dealer has: " << card << ' ';
}

// have dealer keep hitting until they win, lose, or tie
int dealerLogic(std::vector<std::string> &keys, std::vector<std::vector<int>> &cardDeck, std::vector<std::string> &playerCards, int computerScore, int playerScore) {
    // if dealer beats player, hits 21, or busts, return
    if ((computerScore > playerScore) || (computerScore >= 21)) {
        return computerScore;
    }
    
    // keep hitting until win or lose
    int numCardsToFlip{1};
    computerScore += playRound(keys, cardDeck, playerCards, numCardsToFlip);
    
    return dealerLogic(keys, cardDeck, playerCards, computerScore, playerScore);
}

// terminate the program if player/computer bust
bool is21(int score, bool isHumanPlayer) {
    // if not greater than 21, return
    if (score <= 21) return false;
    
    // else terminate and declare winner
    if (isHumanPlayer) {
        std::cout << "\nYou bust :(" << std::endl;
    } else {
        std::cout << "\nYou win, the computer bust!" << std::endl;
    }
    return true;
}

// print the winner
void printWinner(int playerScore, int computerScore) {
    if (playerScore > computerScore) {
        std::cout << "\nYou win!" << std::endl;
    } else if (playerScore < computerScore) {
        std::cout << "\nYou lose :(" << std::endl;
    } else {
        std::cout << "\nA tie?" << std::endl;
    }
    
    return;
}
