#ifndef BLOCKS_H
#define BLOCKS_H

#include "item.h"

enum BlockType {
    BLOCK_AIR = EMPTY,
    BLOCK_GRASS = GRASS,
    BLOCK_DIRT = DIRT,
    BLOCK_STONE = STONE,
    BLOCK_WOOD = WOOD,
    BLOCK_LEAVES = LEAVES,
    BLOCK_GLASS = GLASS,
};

#define BLOCK_IS_MINEABLE  (1 << 0) 
#define BLOCK_IS_DIGGABLE  (1 << 1) 
#define BLOCK_IS_CHOPPABLE (1 << 2) 

// Define the Block structure
struct Block {
    int x, y, z;          
    enum BlockType type;       
    int properties;       
    int durability;       
};

// Function prototypes
Block* get_block_at(int x, int y, int z);      
void destroy_block(Block* block);               
void dig_block(Block* block);                   
void chop_block(Block* block);                  
void weaken_block(Block* block);                


int is_mineable(Block* block);
int is_diggable(Block* block);
int is_choppable(Block* block);

#endif 
