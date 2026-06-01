#include "combat.h"
#include <stdio.h>
# include <stdlib.h>

double calculate_damage(char *name, int bravery, int attack, int defense){ // Two Parameters, two integers

    double adjusted_attack = attack * (1 + (bravery/100.0f));
    printf("Adjusted Damage:%.2lf\n",adjusted_attack);
    double damage = adjusted_attack - defense;
    printf("Damage after defense:%.2lf\n",damage);
    if (damage < 0) return 0;
    return damage;
}

void heal(double *health, int *potions, const int potion_strength){

}
