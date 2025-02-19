#[derive(Clone, Copy, PartialEq, Eq, Debug)]
pub enum BlockType {
    Air,
    Grass,
    Dirt,
    Stone,
    Water,
    Wood, 
    Leaves,
    Sand,
    Glass,
}
// What a basic list of blocks. We'll update them.

impl BlockType {
    pub fn is_solid(&self) -> bool {
        matches!(self, BlockType::Grass | BlockType::Dirt | BlockType::Stone)
    }
}
