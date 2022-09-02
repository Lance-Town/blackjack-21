# Blackjack-21
Play blackjack against a computer!

<h2>
Installation
</h2>

```shell
git clone https://github.com/Lance-Town/Blackjack.git
```

<h2>
Overview
</h2>
Blackjack, or 21, is a very simple game. The objective is to get to 21, without going over 21. 
To start the game, each player draws two cards. The player can see both of thier own cards, but the dealer only shows one of the two cards they're dealt, leaving the second card face down. Then the player adds up the total thier cards, and decides whether to hit or stand. Hit means to draw another card, and stand means to end your turn and hold your total. After the player stands, the dealer, in this case the computer, flips their face down card and either 1) their total is greater than yours, and you lose 2) their total is less than yours, in which they will draw more cards until their total is less than 21 but greater than yours, or they bust and get a total greater than 21, which makes you the winner. For calculating the score, all face cards are 10, except ace which is either 1 or 11, and number cards = their number.

## Example game:
<ul>
<li> Player 1 is dealt a 9 and 6, total is 15.</li>
<li> Dealer is dealt a 2 and a facedown card.</li>
<li> Player 1 hits, and gets a 3, total is 18.</li>
<li> Player 1 stands.</li>
<li> Dealer flips their facedown card, and it is a queen, total is 12.</li>
<li> Dealer hits, and gets a king, total is 22.</li>
<li> Player 1 wins!</li>
</ul>
