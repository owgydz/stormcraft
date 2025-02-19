from enum import Enum, auto

class BlockType(Enum):
    Grass = auto()
    Dirt = auto()
    Sand = auto()
    Wood = auto()
    Stone = auto()
    Water = auto() # It's called an Ocean.
    Air = auto()

class BiomeType(Enum):
    Grassland = auto()
    Desert = auto()
    Forest = auto()
    Mountain = auto()
    Water = auto()

    def get_block_type(self, y):
        if self == BiomeType.Grassland:
            return BlockType.Grass if y == 0 else BlockType.Dirt
        elif self == BiomeType.Desert:
            return BlockType.Sand if y == 0 else BlockType.Dirt
        elif self == BiomeType.Forest:
            return BlockType.Wood if y == 0 else BlockType.Dirt
        elif self == BiomeType.Mountain:
            return BlockType.Stone if y == 0 else BlockType.Dirt
        elif self == BiomeType.Water:
            return BlockType.Water if y == 0 else BlockType.Air

# Example usage:
biome = BiomeType.Grassland
block_type = biome.get_block_type(0)
print(block_type)  # Output: BlockType.Grass
