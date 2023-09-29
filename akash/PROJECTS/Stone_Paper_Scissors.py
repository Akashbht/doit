from random import randint
print('5 Rounds of Rock, Paper, Scissors will be played. ')
print('Ties would be counted as a round.')
print('Score will be counted and winner will be declared at the end.')
print('May the best player win!')
t = ["rock", "paper", "scissors"]
computer_score= 0
player_score = 0
for i in range(5):
    computer = t[randint(0, 2)]

    player = input("Rock, Paper, Scissors?").lower()
    print(computer.lower())
    if player == computer:
        print("Tie!")
    elif player == "rock":
        if computer == "paper":
            computer_score +=1
            print("You lose!", computer, "covers", player)
            print('Computer- ',computer_score,'. Your Score- ',player_score)
        else:
            print("You win!", player, "smashes", computer)
            player_score += 1
            print('Computer- ', computer_score, '. Your Score- ', player_score)
    elif player == "paper":
        if computer == "scissors":
            computer_score += 1
            print("You lose!", computer, "cut", player)
            print('Computer- ', computer_score, '. Your Score- ', player_score)
        else:
            player_score += 1
            print("You win!", player, "covers", computer)
            print('Computer- ', computer_score, '. Your Score- ', player_score)
    elif player == "scissors":
        if computer == "rock":
            computer_score += 1
            print("You lose...", computer, "smashes", player)
            print('Computer- ', computer_score, '. Your Score- ', player_score)
        else:
            player_score += 1
            print("You win!", player, "cut", computer)
            print('Computer- ', computer_score, '. Your Score- ', player_score)
    else:
        print("That's not a valid play. Check your spelling!")

if computer_score > player_score:
    print('Computer score -', computer_score)
    print('Your score - ', player_score)
    print('YOU LOSER!!')

elif computer_score == player_score:
    print("That's a tie. Play better next time.")
else:
    print('Computer score -', computer_score)
    print('Your score - ', player_score)
    print('YOU WINNER!!!')