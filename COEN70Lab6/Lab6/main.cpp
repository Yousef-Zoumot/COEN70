//  Yousef Zoumot Joseph Phan Lab 6
//  main.cpp
//  Lab6
//
//  Created by Yousef Zoumot on 2/9/16.
//  Copyright (c) 2016 Yousef Zoumot. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <time.h>

using namespace std;

class Player{
public:
    Player(){}
    virtual ~Player(){}
    virtual int getGuess()=0;
    // Returns the players next guess, an integer between
    // 0 and 99 (inclusive)
    virtual void lastWasTooHigh(bool tooHigh)=0;
    // Called to inform the player that their last guess
    // was too high (if the tooHigh argument is true) or
    // too low (if the tooHigh argument is false)
    virtual void opponentsGuess(int guess, bool tooHigh)=0;
    // Called to tell the player what the opponent's last
    // guess was, and whether it was too high or too low.
    virtual void reset()=0;
    // Called to reset the player at the end of the game.
    // Any stored state about the last guess should be
    // cleared

    
};

class HumanPlayer: public Player{
private:
    int current_guess;
public:
    HumanPlayer():Player(){}
    virtual ~HumanPlayer(){}
    virtual int getGuess();
    // Returns the players next guess, an integer between
    // 0 and 99 (inclusive)
    virtual void lastWasTooHigh(bool tooHigh);
    // Called to inform the player that their last guess
    // was too high (if the tooHigh argument is true) or
    // too low (if the tooHigh argument is false)
    virtual void opponentsGuess(int guess, bool tooHigh);
    // Called to tell the player what the opponent's last
    // guess was, and whether it was too high or too low.
    virtual void reset();
    // Called to reset the player at the end of the game.
    // Any stored state about the last guess should be
    // cleared.
};


void HumanPlayer::reset(){}

void HumanPlayer:: lastWasTooHigh(bool tooHigh){
    if(tooHigh){
        cout<<"Answer was too High"<<endl;
    }
    else
        cout<<"Answer was too Low"<<endl;
    
}

int HumanPlayer:: getGuess(){
    cout<<"Please enter your guess: ";
    int x;
    cin>>x;
    current_guess = x;
    return x;
}

void HumanPlayer::opponentsGuess(int guess, bool tooHigh){
    cout<<"opponent's guess: " << guess<< endl;
    if(tooHigh){
        cout<<"The guess was too high. "<<"\n";
    }
    else{
        cout<<"The guess was too Low. "<< "\n";
    }
}

class ComputerPlayer: public Player{
private:
    int min;
    int max;
    int current_guess;
public:
    ComputerPlayer():Player(){
        min = 0;
        max = 100;
    }
    virtual ~ComputerPlayer(){}
    virtual int getGuess();
    // Returns the players next guess, an integer between
    // 0 and 99 (inclusive)
    virtual void lastWasTooHigh(bool tooHigh);
    // Called to inform the player that their last guess
    // was too high (if the tooHigh argument is true) or
    // too low (if the tooHigh argument is false)
    virtual void opponentsGuess(int guess, bool tooHigh);
    // Called to tell the player what the opponent's last
    // guess was, and whether it was too high or too low.
    virtual void reset();
    // Called to reset the player at the end of the game.
    // Any stored state about the last guess should be
    // cleared.
    
};

void ComputerPlayer:: lastWasTooHigh(bool tooHigh){
    if(tooHigh)
        min = current_guess + 1;
    else
        max = current_guess - 1;
}

int ComputerPlayer:: getGuess(){
    int mid = (min + max)/2;
    current_guess = mid;
    return mid;
}

void ComputerPlayer::reset(){
    min = 0;
    max = 100;
}

void ComputerPlayer::opponentsGuess(int guess, bool tooHigh){
    if(tooHigh && (max>guess))
        max = guess-1;
    if(!tooHigh && (min<guess))
       min = guess+1;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    srand(time(NULL));
    HumanPlayer p1;
    ComputerPlayer p0;
    int num_players = 2;
    int answer= rand()%101;
    int player_guess;
    int play_again;
    int counter=0;
    bool wasHigh;
    bool end_game = false;
    while(true){
        counter++;
        for(int i=0; i<num_players; i++){
            //get guesses from human player
            player_guess = p1.getGuess();

            if(player_guess==answer){
                  cout<<"You win with" << counter << " guesses."<<endl;
                cout<<"would you like to play again? 0 for no, 1 for yes"<< endl;
                cin>>play_again;
                if(play_again==1){
                    p0.reset();
                    p1.reset();
                    counter = 0;
                    answer= rand() % 101;
                    break;
                }
                else{
                    end_game = true;
                    break;
                }
            }
            
            wasHigh = (player_guess > answer);
            p1.lastWasTooHigh(wasHigh);
            
            p0.opponentsGuess(player_guess, wasHigh);
            player_guess = p0.getGuess();
            if(player_guess==answer){
                cout<<"You lost opponent won in " << counter << " guesses."<<endl;
                cout<<"would you like to play again? 0 for no, 1 for yes"<< endl;
                cin>>play_again;
                if(play_again==1){
                    p0.reset();
                    p1.reset();
                    answer= rand()%101;
                    counter = 0;
                    break;
                }
                else{
                    end_game = true;
                    break;
                }
            }
            
            wasHigh = (player_guess > answer);
            p1.opponentsGuess(player_guess, wasHigh);
            
            
        }
        if(end_game)
            break;
    }
    return 0;
}
