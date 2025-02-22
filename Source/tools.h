//
//
// 
#ifndef TOOLS_H
#define TOOLS_H

#define TOOL_PICKAXE 1
#define TOOL_SHOVEL  2
#define TOOL_AXE     3


#define PICKAXE_DAMAGE        5
#define PICKAXE_PLAYER_DAMAGE 5

#define SHOVEL_DAMAGE         3

#define AXE_DAMAGE            8
#define AXE_PLAYER_DAMAGE     6

#define DEFAULT_TOOL_DAMAGE   2


void use_tool(int tool_type, int x, int y, int z);

#endif
