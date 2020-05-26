
#include <string>

using namespace std;


/* nfunc.cpp */
int RNUM( int min, int max );

/* nstring.cpp */
string cap_args( string text );


#ifndef DECK_H
#define DECK_H



#define DECKL 52

#define ALLOC_SIZE 65


struct card
{
 int value;
 /*
 Type
 1 hearts
 2 diamonds
 3 spades
 4 clubs
 */
 int type;
 string name;
 string abv_name;
 int index;
};

// Functions in this file
string color_abv_name( string abv_name );
char conv_suite_char_to_symbol( char x );
card get_card_with_abv( string abv_name );

 
enum card_value
{
 V_JOKER = 1,  V_TWO = 2,V_THREE = 3,V_FOUR = 4,V_FIVE = 5,
 V_SIX = 6,V_SEVEN = 7,V_EIGHT = 8,V_NINE = 9, V_TEN = 10, V_JACK = 10,
 V_QUEEN = 10, V_KING = 10 , V_ACE = 11
};

/* standard 52 card deck 
    2 special cards 
	10 bonus cards
  */
const card card_list[ALLOC_SIZE] =
{
 { V_ACE, 1, "Ace of hearts" ,  "AH"  , 0},
 { V_ACE, 2, "Ace of diamonds", "AD"  , 1 },
 { V_ACE, 3, "Ace of spades", "AS"  , 2 },
 { V_ACE, 4, "Ace of clubs", "AC"  , 3 },
 { V_TWO, 1, "2 of hearts", "2H" , 4 },
 { V_TWO, 2, "2 of diamonds", "2D" , 5 },
 { V_TWO, 3, "2 of spades", "2S" , 6 },
 { V_TWO, 4, "2 of clubs", "2C" , 7 },       
 { V_THREE, 1, "3 of hearts", "3H" , 8 },
 { V_THREE, 2, "3 of diamonds", "3D" , 9 },
 { V_THREE, 3, "3 of spades", "3S" , 10 },
 { V_THREE, 4, "3 of clubs", "3C" , 11 },
 { V_FOUR, 1, "4 of hearts", "4H" , 12 },
 { V_FOUR, 2, "4 of diamonds", "4D" , 13 },
 { V_FOUR, 3, "4 of spades", "4S" , 14 },
 { V_FOUR, 4, "4 of clubs", "4C" , 15 },
 { V_FIVE, 1, "5 of hearts", "5H" , 16 },
 { V_FIVE, 2, "5 of diamonds", "5D" , 17 },
 { V_FIVE, 3, "5 of spades", "5S" , 18 },
 { V_FIVE, 4, "5 of clubs", "5C" , 19 },
 { V_SIX, 1, "6 of hearts", "6H" , 20 },
 { V_SIX, 2, "6 of diamonds", "6D" , 21 },
 { V_SIX, 3, "6 of spades", "6S" , 22 },
 { V_SIX, 4, "6 of clubs", "6C" , 23 },
 { V_SEVEN, 1, "7 of hearts", "7H" , 24 },
 { V_SEVEN, 2, "7 of diamonds", "7D" , 25 },
 { V_SEVEN, 3, "7 of spades", "7S" , 26 },
 { V_SEVEN, 4, "7 of clubs", "7C" , 27 },
 { V_EIGHT, 1, "8 of hearts", "8H" , 28 },
 { V_EIGHT, 2, "8 of diamonds", "8D" , 29 },
 { V_EIGHT, 3, "8 of spades", "8S" , 30 },
 { V_EIGHT, 4, "8 of clubs", "8C" , 31 },
 { V_NINE, 1, "9 of hearts", "9H" , 32 },
 { V_NINE, 2, "9 of diamonds", "9D" , 33 },
 { V_NINE, 3, "9 of spades", "9S" , 34 },
 { V_NINE, 4, "9 of clubs", "9C" , 35 },
 { V_TEN, 1, "10 of hearts", "TH" , 36 },
 { V_TEN, 2, "10 of diamonds", "TD" , 37 },
 { V_TEN, 3, "10 of spades", "TS" , 38 },
 { V_TEN, 4, "10 of clubs", "TC" , 39 },
 { V_JACK, 1, "Jack of hearts", "JH" , 40 },
 { V_JACK, 2, "Jack of diamonds", "JD" , 41 },
 { V_JACK, 3, "Jack of spades", "JS" , 42 },
 { V_JACK, 4, "Jack of clubs", "JC" , 43 },
 { V_QUEEN, 1, "Queen of hearts", "QH" , 44 },
 { V_QUEEN, 2, "Queen of diamonds", "QD" , 45 },
 { V_QUEEN, 3, "Queen of spades", "QS" , 46 },
 { V_QUEEN, 4, "Queen of clubs", "QC" , 47 },
 { V_KING, 1, "King of hearts", "KH" , 48 },
 { V_KING, 2, "King of diamonds", "KD" , 49 },
 { V_KING, 3, "King of spades", "KS" , 50 },
 { V_KING, 4, "King of clubs", "KC" , 51 },
 { V_JOKER,  1, "Joker Wild 1", "JO" , 52 },
 { V_JOKER,  1, "Joker Wild 2", "JT" , 53 },    
	{ 1,  1, "Bonus Plus 1", "+1" , 55 }, // 54 reserved for back of deck
	{ -1, 1, "Bonus Minus 1", "-1", 56 },
	{ 2,  2, "Bonus Plus 2", "+2", 57 },
	{ -2, 2, "Bonus Minus 2", "-2", 58 },
	{ 3,  3, "Bonus Plus 3", "+3", 59 },
	{ -3, 3, "Bonus Minus 3", "-3", 60 },
	{ 4,  4, "Bonus Plus 4", "+4", 61 },
	{ -4, 4, "Bonus Minus 4", "-4", 62 },
	{ 5,  5, "Bonus Plus 5", "+5", 63 },
	{ -5, 5, "Bonus Minus 5", "-5", 64 },
        {  0, 0, " "           , " "  , 65 }
};
     


#ifndef CLASS_DECK
#define CLASS_DECK


 class deck
 {
   private:
     int length;
     card* data;
   public:
     deck();
     ~deck();
     string get_hand_text();
     void shuffle();
     card draw();
     bool is_empty();
     int get_length();
     void add_card_front( card x );
     void add_card_back( card x );
 };

// private functions

 // public functions
 deck::deck()
 {
   data = new card [ALLOC_SIZE];
   length = 0;
 }

 deck::~deck()
 {
   delete [] data;
 }

 string deck::get_hand_text()
 {
  string temp;

  
  if( length <= 0 )
  {
    temp += "&REmpty!!!";
  }
  else
  for( int i=0; i < length; ++i )
  {
    temp += color_abv_name( data[i].abv_name );
    temp += " ";
  }

  return temp;
 }

 void deck::shuffle(   )
 {
  int pos = 0;
  int key[DECKL] = {0};

  // this function also resets our deck
  length = 0;

  // we sequentialy go through the card array finding random cards in the master 
  // deck marking the card and inserting it into our deck
  for( int i= 0;  i < DECKL;   ++i  ) // random cards chosen for sequential positions
  {
    pos = RNUM(0,DECKL - 1); // we find a random position
    if( key[pos] == 0 ) // we found a position not already taken
    {
      data[i] = card_list[pos]; // put a random card into the next position
      key[pos] = 1; // mark our key that we have used that card
      ++length;
    }
    else
    {
      while( key[pos] == 1 )
      {
        pos = RNUM(0,DECKL - 1); // find a new position in the master deck
      }
      // now we have the position of our new card so lets insert it
      data[i] = card_list[pos];
      key[pos] = 1;
      ++length;
    }
  }
 }


 /*
 Draw
 returns a random card from the deck sent to the function
 decklength should be checked before being sent to this function
 */
 card deck::draw()
 {
  card temp = data[ 0 ]; // take the first card of an shuffled deck
 
  // now that we have our card we are going to remove it
  for( int i=0; i < length; ++i )
  {
     // this shifts data backward 1 element position
    data[i] = data[i+1];  
  }
  
   --length;
   
  return temp;
 } 


 bool deck::is_empty()
 {
   if( length <= 0 ) return true;
   else return false;
 }

 int deck::get_length()
 {
   return length;
 }

 void deck::add_card_front( card x )
 {
   // our pos is going to be 0
   for( int i=0; i < length; ++i )
   {
     // this shifts data forward 1 element position
     data[i+1] = data[i];
   }
   data[0] = x; // now that all our data has been shifted forward 1 we can set pos 0 to be x
   // after adjusting we incriment length
   ++length;
 }

 void deck::add_card_back( card x )
 {
   // check size of deck
   if( length >= ALLOC_SIZE - 1 )
   {
      throw "Extream Error !!! Duplicate Cards exsist in Main Deck";
   }
   // our pos is going to be length 
   data[ length ] = x;
    
   // after adjusting we incriment length
   ++length;
 }

#endif



///////////////////////////////////////////////////  OTHER GLOBAL CARD FUNCTIONS //////////////////////////////////////////////
  /*
    char_change
	receives a char and changes it to
	a symbol using a code
	Only used in the console based version of this program
	This function is mostly hear for historical reasons
   */
 char conv_suite_char_to_symbol( char x )
 { 
   char temp;
   switch( x ) 
   {
     case 'H': temp = (char)259; break;
     case 'D': temp = (char)260; break;
     case 'C': temp = (char)261; break;
     case 'S': temp = (char)262; break;
     case 'O': temp = (char)257; break;
     case 'T': temp = (char)258; break;
     default: temp = x; break;
   }
   return temp;
 }

 /*
  Colorizes the abint determine_suite_with_highest_count();reviated name of the cards
 */
 string color_abv_name( string abv_name )
 {
   string new_abv;
   char type = abv_name.at(0); // 3
   char suite = abv_name.at(1); // S
   // from these pieces of information we can now colorize our abreviation
   
   // if we have unicode we can also do this
   char symbol_suite = conv_suite_char_to_symbol( suite );

   switch( type )
   {
     case 'A': new_abv += "&r"; break;
     case 'K': 
     case 'Q':
     case 'J':
        if( suite == '0' || suite == '1' )
           new_abv += "&P";
        else
        new_abv += "&C"; break;
     case '8': new_abv += "&G"; break;
     default: new_abv += "&c"; break;
   }
   new_abv += type;
   
   switch( suite )
   {
     case 'H': 
     case 'D': new_abv += "&R"; break; // red
     case 'S':
     case 'C': new_abv += "&w"; break; // black
     case '0':
     case '1':
           new_abv += "&Y";  break;
     default: break; // don't want any coloring right now on special cards
   } 
   new_abv += suite;
     

   return new_abv;
 }

 /*
  Returns card that matches the abv_name supplied
   The card is copied from the Card list 
   If the card is not found A card with
     -1 as the type is returned
 */
 card get_card_with_abv( string abv_name )
 {
  card temp;

   temp.type = -1; // used if card is not found

  for( int i=0; i < ALLOC_SIZE; ++i )
  {
    if( card_list[i].abv_name == cap_args( abv_name ) )
    {
      temp = card_list[i];
      break; // breaks out of the for loop
    }
  }
  
  return temp;
 }








 
#endif   








