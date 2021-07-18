# my_mastermind
#
**SPECIFICATIONS**

Write a program called mastermind; it will be an implementation of the famous game.
#
**NAME**

my_mastermind
#
**SYNOPSIS**

my_mastermind [-ct]
#

**DESCRIPTION**

Mastermind is a game composed of 8 pieces of different colors.
A secret code is then composed of 4 distinct pieces.

The player has 10 attempts to find the secret code.
After each input, the game indicates to the player the number of well placed pieces and the number of misplaced pieces.

Pieces will be '0' '1' '2' '3' '4' '5' '6' '7'.

If the player finds the code, he wins, and the game stops.
A misplaced piece is a piece that is present in the secret code butthat is not in a good position.

You must read the player's input from the standard input.

Your program will also receive the following parameters:

-c [CODE]: specifies the secret code. If no code is specified, a random code will be generated.

-t [ATTEMPTS]: specifies the number of attempts; by default, the playerhas 10 attempts.

-p [PIECES]: specifies and changes pieces; by default '0' '1' '2' '3' '4' '5' '6' '7'
 
 #
 Example 00
```
PROMPT>./my_mastermind -c "0123"
Will you find the secret code?
---
Round 0
>1456
Well placed pieces: 0
Misplaced pieces: 1
---
Round 1
>tata
Wrong input!
>4132
Well placed pieces: 1
Misplaced pieces: 2
---
Round 2
>0123
Congratz! You did it!
```
#

**AUTHORIZED FUNCTIONS**

printf(3)

write(2)

read(2)

rand() (/ srand())

time()

atoi()
