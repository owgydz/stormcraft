
#include "item.h"
#include "player.h"

Block* get_block_at(int x, int y, int z) {
    return find_block_in_world(x, y, z);
}

void destroy_block(Block* block) {
    if (block && is_mineable(block)) {
        drop_item(block->type, block->x, block->y, block->z);
        block->type = EMPTY;
    }
}

void dig_block(Block* block) {
    if (block && is_diggable(block)) {
        drop_item(block->type, block->x, block->y, block->z);
        block->type = EMPTY;
    }
}

void chop_block(Block* block) {
    if (block && is_choppable(block)) {
        drop_item(block->type, block->x, block->y, block->z);
        block->type = EMPTY;
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
    return block && (block->type == STONE || block->type == WOOD || block->type == DIRT || block->type == COBBLE || block->type == IRON_ORE || block->type == GOLD_ORE || block->type == DIA_ORE);
}

int is_diggable(Block* block) {
    return block && (block->type == DIRT || block->type == SAND || block->type == SNOW || block->type == GLASS || block->type == LEAVES || block->type == CLOUD || block->type == TALL_GRASS || block->type == YELLOW_FLOWER || block->type == RED_FLOWER || block->type == PURPLE_FLOWER || block->type == SUN_FLOWER || block->type == WHITE_FLOWER || block->type == BLUE_FLOWER || block->type == ORANGE_FLOWER || block->type == PINK_FLOWER || block->type == CYAN_FLOWER);
}

int is_choppable(Block* block) {
    return block && (block->type == WOOD || block->type == LEAVES);
}
