/*
Nathaniel Collier
  9/2/2006
   Game Redone to be class based
   Still alot of work needs to be done
   but it is now playable using classes
*/

#include <iostream>
#include <string>
#include <ctime>
using namespace std;


#include "deck.h"
#include "player.h"

#define VERSION ".6"


/* ncolor.cpp */
void cprintf( const char* text, ... );
 
/* nstring.cpp */
char* string_date();
string format_time( double seconds );

string get_first_arg( string& text );
string get_line_kyb();




deck card_deck;
player pc(false);
player cpu(true);

int start = 0;

void start_game( );
void cc_display();
void pc_display();
void calc_winner(  );
void computer_turn(  );
int menu(int type);
void calc_score(  int winner );
void new_game();
void pc_hit();
void title();

int main()
{
		
 int choice = 0;

 
  srand( (unsigned int) time(0) ); // seed the random number generator

 title();
  choice = menu(1);
 
  switch( choice )
  {
   case 1:
     start_game( );
    break;
   case 0:
     exit(0);
    break;
   default:
    exit(0);
    break;
  }
 
 
return 0;
} 



void title()
{
  cprintf(
       "\n&W+&R-&r-&R-&r-&R-&r-&R-&r-&R-&r-&R-&r-&R-&r-&R-&r-&R-&r-&R-&r-&R-&r-&R-&r-&R-&r-&R-&r-&R-&r-&R-&r-&R-&r-&R-&W+"
       "\n&R|                                   &R|"
       "\n&r|                                   &r|"
       "\n&R|          &YBlack&BJack                &R|"
       "\n&r|                                   &r|"
       "\n&R|                                   &R|"
       "\n&W+&R-&r-&R-&r-&R-&r-&R-&r-&R-&r-&R-&r-&R-&r-&R-&r-&R-&r-&R-&r-&R-&r-&R-&r-&R-&r-&R-&r-&R-&r-&R-&r-&R-&r-&R-&W+"
         );
}


void new_game()
{
  // resset all current game stats
  start = 1;
   cprintf( "\n&G#########&Y-&R=&Y< &BNEW GAME &Y>&R=&Y-&G#########" );
   card_deck.shuffle();

    pc.new_game();
    cpu.new_game();

   cpu.hit( card_deck.draw() );
   pc.hit( card_deck.draw() );

   pc_display();

   computer_turn();
}

 
void calc_score(  int winner )
{
  int points = 0;
  int cpu_stat = ( cpu.get_games_won() - cpu.get_games_lost() );
  int pc_stat = ( pc.get_games_won() - pc.get_games_lost() );
  

  switch( winner )
  {
    case 0:
        // No one won
         cpu.end_game( false, 0 );
         pc.end_game( false, 0 );
         cprintf( 
              "\n&g---------------------"
              "\n&G%s &RHas Won &Y!!!!"
              "\n&WWinning Hand&R: %s"
              "\n&WWinning Score&R: %d"
              "\n&g---------------------"
              , "NoOne", "Empty!!", 0 
                );
        break;
    case 1:
        //  Pc won
         points = pc_stat - cpu_stat;

         if( points <= 0 ) points = 21;
           else points *= 21;
         
         cpu.end_game( false, 0 );
         pc.end_game( true, points );
         cprintf( 
              "\n&g---------------------"
              "\n&G%s &RHas Won &Y!!!!"
              "\n&WWinning Hand&R: %s"
              "\n&WWinning Score&R: %d"
              "\n   &YAward Amnt&R:  &W%d"
              "\n&g---------------------"
              , "PC", pc.get_hand_text().c_str(), pc.get_points(), points 
                );
        break;
    case 2:
        //  cpu won
         points = cpu_stat - pc_stat;

         if( points <= 0 ) points = 21;
           else points *= 21;
         cpu.end_game( true, points );
         pc.end_game( false, 0 );
         cprintf( 
              "\n&g---------------------"
              "\n&G%s &RHas Won &Y!!!!"
              "\n&WWinning Hand&R: %s"
              "\n&WWinning Score&R: %d"
              "\n   &YAward Amnt&R:  &W%d"
              "\n&g---------------------"
              , "CPU", cpu.get_hand_text().c_str(), cpu.get_points(), points 
                );
        break;
  }
}
 


/*
 Computer will need to draw cards based on rules
 
 */
void computer_turn( )
{
 
 switch( cpu.computer_turn() )
 {
   case 0:
      // we stay
       cpu.set_stay( true );
     break;
   case 1:
      // we hit
       cpu.hit( card_deck.draw() );
     break;
 }

}



int menu(int type)
{
 int x(0);
 switch( type )
 {
  case 1: 
       cprintf("\n&YBlack&PJack &Rv &g%s  &B(&W1&B) &RPlay &B(&W0&B) &RQuit\n", VERSION );
       break;
  case 2:
   if( start == 0 ) return 1;
    cprintf("\n&WMenu&R: &B(&W1&B)&GNew Game &R[&w2&R]&WHit &R[&w3&R]&WStay &B(&W0&B)&GQuit\n" );
   break;
 }    
 cin>>x;
 return x;
}




/*
 0 - no one
 1 - pc
 2 - computer
*/
void calc_winner( )
{
  int player_score = pc.get_points();
  int computer_score = cpu.get_points();
  int winner = -1;
 
  
   if( player_score == computer_score )
     winner = 0;
   else
   if( player_score > computer_score && player_score <= 21 )
     winner = 1;
   else
   if( computer_score > player_score && computer_score <= 21 )
     winner = 2;
   else
   if( computer_score > 21 && player_score > 21 )
     winner = 0;
   else
   if( computer_score < 21 && player_score > 21 )
     winner = 2;
   else
   if( player_score < 21 && computer_score > 21 )
     winner = 1;
  
  calc_score(  winner );
   
}




void pc_display()
{
  cprintf( "\n&WPC &Rhand&W: %s", pc.get_hand_text().c_str() );
  cprintf( "\n&RPoints&W: %d", pc.get_points() );
}
	
void cc_display(  )
{
  cprintf( "\n&WCPU &Rhand&W: %s", cpu.get_hand_text().c_str() );
  cprintf( "\n&WCPU &RPoints&W: %d", cpu.get_points() );
}



void pc_hit()
{
  card temp = card_deck.draw();
  switch( pc.hit( temp ) )
  {
    case 0:
       // some kind of error happened
       break;
    case 1:
       // success
       break;
    case 2:
       // aces have become jokers
        cprintf( "\n&RYour score &G%d &Ris over 21 so now all your &WAce &Rbecome &WJoker&R.", pc.get_points() );
       break;
  }
}
 

void start_game()
{
 int choice = menu(2);

 
 /*
 This for loop is refered to as the Game Loop
 almost every game has an infinite loop that it runs under since many conditions may end the loop
 */
 for(;;) // Main Game Loop
 {
	 
 switch( choice ) 
 {
  case 1:
   // Deal - new game
   new_game();
   choice = menu(2); 
   break;
  case 2:
   // Hit - add a new random card to the player's or computer hand
    /*
      We need to check to see if the card deck is empty
       if it is we need to end the game
    */

    if( card_deck.is_empty() == true )
    {
      // end game
    }
    pc_hit();
    pc_display();
    if( card_deck.is_empty() == true )
    {
      // end game
    }
   computer_turn();
   choice = menu(2);
   break;
  case 3:
   // Stay - calculate player's hand and the computers hand
   while( cpu.get_stay() == false )
   {
	computer_turn(  );
   }

   cprintf( "\n&G#########&Y-&R=&Y< &BEND OF GAME &Y>&R=&Y-&G#########" );
   pc_display();
   cc_display();
   calc_winner(  );

   new_game();
   
   choice = menu(2);
   break;
  case 0:
   // quit
   exit(0);
   break;
  default:
   exit(0);
   break;
 }
}
 
}




