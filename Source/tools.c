#include "tools.h"
#include "blocks.h"
#include "players.h"

void use_tool(int tool_type, int x, int y, int z, Player* player) {
    switch (tool_type) {
        case TOOL_PICKAXE:
            // Implement pickaxe functionality
            Block* target_block = get_block_at(x, y, z);
            if (target_block && target_block->is_mineable) {
                target_block->durability -= PICKAXE_DAMAGE;
                if (target_block->durability <= 0) {
                    destroy_block(target_block);
                }
            }
            
            Player* target_player = get_player_at(x, y, z);
            if (target_player) {
                target_player->health -= PICKAXE_PLAYER_DAMAGE;
                if (target_player->health <= 0) {
                    eliminate_player(target_player);
                }
            }
            break;
        
        case TOOL_SHOVEL:
            // Implement shovel functionality
            target_block = get_block_at(x, y, z);
            if (target_block && target_block->is_diggable) {
                target_block->durability -= SHOVEL_DAMAGE;
                if (target_block->durability <= 0) {
                    dig_block(target_block);
                }
            }
            break;
        
        case TOOL_AXE:
            // Implement axe functionality
            target_block = get_block_at(x, y, z);
            if (target_block && target_block->is_choppable) {
                target_block->durability -= AXE_DAMAGE;
                if (target_block->durability <= 0) {
                    chop_block(target_block);
                }
            }
            
            target_player = get_player_at(x, y, z);
            if (target_player) {
                target_player->health -= AXE_PLAYER_DAMAGE;
                if (target_player->health <= 0) {
                    eliminate_player(target_player);
                }
            }
            break;
        
        default:
            // Default tool action
            target_block = get_block_at(x, y, z);
            if (target_block) {
                target_block->durability -= DEFAULT_TOOL_DAMAGE;
                if (target_block->durability <= 0) {
                    weaken_block(target_block);
                }
            }
            break;
    }
}
