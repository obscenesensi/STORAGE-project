/*Yu Gi Oh Card Game*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
/* prototypes */
void introduction();
void game();
void credit();
 
/*Card Structure Definition*/
struct monsterCard{
	const char *effect; //monster card effect
	const int attackPoint; //monster card attack point
	const int defensePoint; //monster card defense point
	
};

struct trapCard {
	const char *effect; //magic card effect
}; //

struct card {
	const char *monster; //monster card
	const char *trap; //trap card
	const char *magic; //magic card
	struct monsterCard monsterDetail; 
	struct trapCard trapCardDetail;
}; 

typedef struct card Card; //new type name for struct card
//to access it Card.monsterDetail.effect etc...
//to access it Card.trapCardDetail.effect


int main(void){
	system("clear");
	Card deck[10]; //define the deck size
	
	//Initialize the types of card
	const char *monster[] = {"Blue Eyes White Dragon","Red Eye Black Dragon","Dark Magican"};
	const char *trap[]= {"Gift of the Mystical Elf"};
	const char *magic[] = {"Monster Reborn"};
	
	printf("Welcome to the Yu Gi Oh Card Game\a\n\n");
	
	//seed random-number generator
	srand( time(NULL) );
	/*Initialize array of 3 pointers to functions that each take 
	 * an int argument and return void*/
	void (*selection[3]) = {introduction,game,credit};
	return 0;
}
void introduction() {
	printf("The game is a battle-based trading card game" 
	"in which players draw cards from their respective decks and take turns playing cards onto the field.\n"); 
}
void game() {
	printf("It's time to Duel\n");
}
void credit() {
	printf("Special thanks to nitrix, AndroidShoutapop,Luke-Jr, darkf for helping\n");
}
