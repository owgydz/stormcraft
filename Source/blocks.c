#include "blocks.h"
#include "item.h"
#include "player.h"

Block* get_block_at(int x, int y, int z) {
    // Implement logic to retrieve the block at the given coordinates
    return find_block_in_world(x, y, z);
}

void destroy_block(Block* block) {
    if (block && block->is_mineable) {
        drop_item(block->type, block->x, block->y, block->z);
        block->type = BLOCK_AIR;
    }
}

void dig_block(Block* block) {
    if (block && block->is_diggable) {
        drop_item(block->type, block->x, block->y, block->z);
        block->type = BLOCK_AIR;
    }
}

void chop_block(Block* block) {
    if (block && block->is_choppable) {
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
//                 destroy_block(target_block);
//             }