#ifndef PLAYER_H
#define PLAYER_H
#define PLAYER_MAX_HEALTH 50


#include "itmm.h"
#include "item.h"

typedef struct {
    int x, y, z;
    int health;
    int inventory[35]; 
} Player;

// Function prototypes
void move_player(Player* player, int dx, int dy, int dz);
void damage_player(Player* player, int damage);
void heal_player(Player* player, int amount);
void eliminate_player(Player* player);
Player* get_player_at(int x, int y, int z);

#endif // PLAYER_H
