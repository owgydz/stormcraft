from enum import Enum, auto

class BlockType(Enum):
    Air = auto()
    Grass = auto()
    Dirt = auto()
    Stone = auto()
    Water = auto()
    Sand = auto()
    Clay = auto()
    Coal = auto()
    Iron = auto()
    Gold = auto()
    Diamond = auto()
    Wood = auto()
    Leaves = auto()

    def is_solid(self):
        return self in {BlockType.Grass, BlockType.Dirt, BlockType.Stone}

# Example usage:
block_type = BlockType.Grass
print(block_type.is_solid())  
