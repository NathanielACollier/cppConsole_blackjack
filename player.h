/*
Nathaniel Collier
7/17/2006
  Origional Crazy8 Player Class
9/2/2006
  Modification for Blackjack Game
Player Class for Blackjack Card Game
*/

#ifndef PLAYER_CLASS
#define PLAYER_CLASS

#include "deck.h"


class player
{
 private:
  card* pdeck; 
  int deck_length;
  int total_score;
  int games_won;
  int games_lost;
  int games_played;
  int points;
  bool stay;
  bool iscomputer;
  string player_name;
  // functions
  int count_card_points();
  void reset_game_stats();
 public:
  // functions
  player(bool x);
  ~player();
  void new_game();
  void insert_card( card temp );
  string get_hand_text();
  int hit( card x );
  int get_points(  );
  int get_total_score();
  int get_games_won();
  int get_games_lost();
  int get_games_played();

  int hand_length();
  void set_playername( string name );
  string get_playername();
  void end_game( bool winner, int points );
  void set_stay(bool value);
  bool get_stay();

  void remove_card( card x );

  int computer_turn();

  
};


////////////////////////////////////////////// private functions  ///////////////////////////////////////////////////

 
 /*
 Goes through the deck adding up the points
 */
 int player::count_card_points()
 {
  int temp = 0;
   for( int i=0; i < deck_length; ++i )
   {
    temp += pdeck[i].value;
   }
  return temp;
 }

 void player::reset_game_stats()
 {
  deck_length = 0;
  points = 0;
  stay = false;
 }

////////////////////////////////////////// public functions  ///////////////////////////////////////////////

player::player(bool x)
{
  pdeck = new card[64]; // the deck could not be any larger than this
  total_score = 0;
  games_won = 0;
  games_lost = 0;
  games_played = 0;
  reset_game_stats(); // sets current game stats to beginning values
  iscomputer = x;
}

player::~player()
{
  delete [] pdeck;
}

/*
 Returns a status message via an integer
  0 - error
  1 - success
  2 - All the Ace cards changed to joker with value of 1
*/
int player::hit( card x )
{
  int status = 1;
  insert_card( x );

  if( points > 21 )
  {
    for( int i=0; i < deck_length; ++i )
    {
      if( pdeck[i].value == 11 )
      {
         pdeck[i] = card_list[52];
         points = count_card_points();
         status = 2;
      }
    }
  }
  return status;
}

/*
 Sends an int back to the caller
  telling what the computer will do
   -1 - error
   0 - stay
   1 - hit
  
*/
int player::computer_turn()
{
  int status = -1;

  if( stay == true )
    status = 0;

  if( points <= 15 )
    status = 1;

  if( points > 15 )
  {
    int chance = 0;

    if( points >= 19 )
    {
      chance = RNUM( 1, 100 );
      if( chance != 50 )
      {
        status = 0;
      }
      else
      {
        status = 1;
      }
    }
    else
    {
      chance = RNUM( 1, 10 );
      if( chance != 5 )
      {
        status = 0;
      }
      else
      {
        status = 1;
      }
    }
      
  }

 return status;
}



void player::end_game( bool winner, int points )
{
  if( winner == true )
  {
    total_score += points;
    ++games_played;
    ++games_won;
  }
  else
  {
    ++games_played;
    ++games_lost;
  }
 return;
}


void player::new_game()
{
  reset_game_stats(); // sets current game stats to beginning values
}

void player::insert_card( card temp )
{
  // update our card count
  pdeck[deck_length] = temp;
  ++deck_length;
  points = count_card_points();
}


string player::get_hand_text()
{
  string temp;

  
  if( deck_length <= 0 )
  {
    temp += "&REmpty!!!";
  }
  else
  for( int i=0; i < deck_length; ++i )
  {
    temp += color_abv_name( pdeck[i].abv_name );
    temp += " ";
  }

 return temp;
}



/*
Returns the number of points a player has in their hand
*/
int player::get_points(  )
{
  return points;
}

int player::get_total_score() 
{
  return total_score;
}

 int player::get_games_won() 
 {
  return games_won;
 }

 int player::get_games_lost() 
 {
  return games_lost;
 }

 int player::get_games_played() 
 {
  return games_played;
 }

 int player::hand_length() 
 {
   return deck_length;
 }


 void player::set_playername( string name )
 {
   player_name = name;
 }
 
 string player::get_playername() 
 {
   return player_name;
 }

 bool player::get_stay()
 {
   return stay;
 }

 void player::set_stay(bool value)
 {
   stay = value;
 }


 void player::remove_card( card x )
 {
  // find the card
  for( int i=0; i < deck_length; ++i )
  {
    if( x.abv_name == pdeck[i].abv_name )
    {
      --deck_length;
       // remove the card from the deck by shifting
      for( int j=i; j < deck_length; ++j )
      {
        pdeck[j] = pdeck[j+1];
      }
    }
  }
  points = count_card_points();
  return;
}





#endif






