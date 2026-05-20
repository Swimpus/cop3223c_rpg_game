# include <stdio.h> // Mainstay since we need standard input and output.
# include <stdlib.h> // Helps us generate random numbers

// Hero's Profile
int hero_bravery = 10;
int hero_attack = 10;
int hero_defense = 10;
double hero_health = 10;
char hero_name[50] = "Hubert";

// Monster Profile
int monster_attack = 12;
int monster_defense = 10;
double monster_health = 10;
char monster_name[50]= "Lil Carmine";

// Print Hero Stats Function
void print_hero_stats(void){
    printf("=======================\n");
    printf("|%-22s|\n",hero_name);
    printf("|HP: %.2lf                |\n",hero_health);
    printf("|ATTACK: %d  DEF: %d   |\n",hero_attack,hero_defense); // Match the order
    printf("|Bravery: %d           |\n",hero_bravery);             // In which the variables are summoned.
    printf("=======================\n");
}

void print_monster_stats(void){
    printf("=======================\n");
    printf("|%-22s|\n",monster_name);
    printf("|HP: %.2lf                |\n",monster_health);
    printf("|ATTACK: %d  DEF: %d   |\n",monster_attack,monster_defense); // Match the order here too.           // In which the variables are summoned.
    printf("=======================\n");
}

double calculate_damage(int bravery,int attack,int defense){ // Two Parameters, two integers
    //float defense_modifier = 0.0;
    //srand(0);
    //defense_modifier = 1 + rand()%20;

    double adjusted_attack = attack * (1 + (bravery/100.0f));
    printf("Adjusted Damage:%.2lf\n",adjusted_attack);
    double damage = adjusted_attack - defense;
    printf("Damage after defense:%.2lf\n",damage);


    if (damage < 0) return 0;
    return damage;


}

int main(void){
    printf("=======================\n");
    printf("|  Electric Bogaloo   |\n");
    printf("|      The Third      |\n");
    printf("=======================\n");

    printf("Enter your hero's name: ");
    fscanf(stdin,"%s",hero_name);

    do {
        printf("%s Attacks!\n",hero_name);
        monster_health -= calculate_damage(hero_bravery,hero_attack,monster_defense);
        if (monster_health < 0) monster_health= 0;

        printf("%s Counter-Attacks!\n",monster_name);
        hero_health -= calculate_damage(0,monster_attack,hero_defense);
        if (hero_health < 0) hero_health = 0;

        print_hero_stats();
        print_monster_stats();

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
