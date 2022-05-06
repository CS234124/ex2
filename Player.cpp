#include "Player.h"
#include "utilities.h"
#include <string>
#include <stdbool.h>
#include <assert.h>

const int LEVEL1 = 1 ;
const unsigned int ZERO_COINS = 0 ;
const int ZERO = 0 ;

//note to self- add defolt values in h 
Player::Player (std::string name , int maxHP , int force) 
{
    this -> name = name ;
    this -> level = LEVEL1 ;
    this -> force = force ;
    this -> maxHP = maxHP ;
    this -> HP = this.maxHP ;
    this -> coins = ZERO_COINS ;
}

void Player::printInfo ()
{
    printPlayerInfo( this -> name , this -> level , this -> force , this -> HP , this -> coins ) ;
}

int Player::getLevel ()
{
    return this -> level ;
}

void Player::heal (int HP)
{
    this -> HP += HP ;
    if (this -> HP > this -> maxHP)
    {
        this -> HP = this -> maxHP;
    }
}

bool Player::isKnockedOut ()
{
    if( this -> HP <= ZERO )
    {
        return true ; 
    }
    return false ;
}

bool Player::pay ( unsigned int coins)
{
    assert(coins) ;
    if(coins < this -> coins)
    {
        return false ;
    }
    this -> coins -= coins ;
    assert ( this -> coins >= ZERO) ;
    return true;
}

