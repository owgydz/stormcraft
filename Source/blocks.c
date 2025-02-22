#include "blocks.h"
#include "item.h"
#include "player.h"

Block* get_block_at(int x, int y, int z) {
    return find_block_in_world(x, y, z);
}

void destroy_block(Block* block) {
    if (block && is_mineable(block)) {
        drop_item(block->type, block->x, block->y, block->z);
        block->type = BLOCK_AIR;
    }
}

void dig_block(Block* block) {
    if (block && is_diggable(block)) {
        drop_item(block->type, block->x, block->y, block->z);
        block->type = BLOCK_AIR;
    }
}

void chop_block(Block* block) {
    if (block && is_choppable(block)) {
        drop_item(block->type, block->x, block->y, block->z);
        block->type = BLOCK_AIR;
    }
}

void weaken_block(Block* block) {
    if (block) {
        block->durability -= DEFAULT_TOOL_DAMAGE;
        if (block->durability <= 0) {
            destroy_block(block);
        }
    }
}

int is_mineable(Block* block) {
    return block && (block->type == STONE || block->type == WOOD || block->type == BLOCK_DIRT);
}

int is_diggable(Block* block) {
    return block && (block->type == DIRT || block->type == SAND);
}

int is_choppable(Block* block) {
    return block && (block->type == WOOD);
}
