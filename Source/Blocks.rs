#[derive(Clone, Copy, PartialEq, Eq, Debug)]
pub enum BlockType {
    Air,
    Grass,
    Dirt,
    Stone,
    Water,
    Sand,
    Clay,
    Coal,
    Iron,
    Gold, // WOAH! 
    Diamond, // WOAHHHH!
    Wood,
    Leaves,
}


impl BlockType {
    pub fn is_solid(&self) -> bool {
        matches!(self, BlockType::Grass | BlockType::Dirt | BlockType::Stone)
    }
}
