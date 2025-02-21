#ifndef ITMM_H
#define ITMM_H

#define PICKAXE_DAMAGE 10
#define SHOVEL_DAMAGE 5
#define AXE_DAMAGE 8
#define DEFAULT_TOOL_DAMAGE 2

typedef struct {
    int type;
    int durability;
    int is_mineable;
    int is_diggable;
    int is_choppable;
    int x; 
    int y; 
    int z; 
} Block;

Block* get_block_at(int x, int y, int z);
void destroy_block(Block* block);
void dig_block(Block* block);
void chop_block(Block* block);
void weaken_block(Block* block);

#endif
