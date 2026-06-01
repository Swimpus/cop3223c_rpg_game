# include <stdio.h> // Mainstay since we need standard input and output.
# include <stdlib.h> // Helps us generate random numbers
# include "combat.c"

// Prototypes
void print_hero_stats(void);
void print_monster_stats(void);
void print_stats(char *name,int bravery, double health, int attack, int defense);



void print_stats(char *name, int bravery, double health, int attack, int defense){
    printf("=======================\n");
    printf("|%-22s|\n",name);
    printf("|HP: %.2lf             |\n",health);
    printf("|ATTACK: %d  DEF: %d   |\n",attack,defense); // Match the order
    if (bravery) {
        printf("|Bravery: %d           |\n",bravery); // Hero exclusive print.
    }
}

int main(void){

    // Constants
    const int potion_strength = 50;

    // Hero's Profile
    int hero_bravery = 10;
    int hero_attack = 10;
    int hero_defense = 10;
    double hero_health = 10;
    char hero_name[50] = "Hubert";

    // Monster Profile
    int monster_bravery;
    int monster_attack = 12;
    int monster_defense = 10;
    double monster_health = 10;
    char monster_name[50]= "Lil Carmine";


    printf("=======================\n");
    printf("|  Electric Bogaloo   |\n");
    printf("|      The Third      |\n");
    printf("=======================\n");

    printf("Enter your hero's name: ");
    fscanf(stdin,"%s",hero_name);

    do {
        printf("%s Attacks!\n",hero_name);
        monster_health -= calculate_damage(hero_name,hero_bravery, hero_attack,monster_defense);
        if (monster_health < 0) monster_health= 0;

        printf("%s Counter-Attacks!\n",monster_name);
        hero_health -= calculate_damage(monster_name,0,monster_attack,hero_defense);
        if (hero_health < 0) hero_health = 0;

        print_stats(hero_name, hero_bravery, hero_health, hero_attack, hero_defense);
        print_stats(monster_name, 0, monster_health, monster_attack, monster_defense);

        printf("Press ENTER to continue\n");
        char enter; // Dummy value
        fscanf(stdin," %c", &enter); // Mind the space before the %c. Eats any newlines.

    } while(hero_health > 0 && monster_health >0); // && == and
                                                   
    if (hero_health == 0 && monster_health ==0 ){
        printf("Draw\n");
    }
    else if (hero_health == 0 && monster_health > 0){
        printf("%s WINS!\n",monster_name);
    }
    else{
        printf("%s WINS!\n",hero_name);
    }

    return 0;
}