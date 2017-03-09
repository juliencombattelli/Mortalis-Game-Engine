
#### Audio module

#### Camera module

- [x] add a Player-Follow Camera class to manage the sf::View

#### Error handling module

- [ ] add ErrorWindow class, derived for each kind of error (resource missing, fatal error like out of range ...)

#### Input module

- [x] add an inputManager which use isActionSelected => user will use it instead of mge::Keyboard
- [ ] change DPad methods names

#### Internal Event module

- [ ] handle exceptions

#### Log module

- [ ] rewrite mul::Logger and integrate it to the MGE

#### Map module

- [x] remove mul::sfe::TileMap
- [ ] move tilesets data in an other struture and only leave tilesets id in MapData, to avoid data duplication
- [ ] load tilesets data from text file (maybe YAML or JSON)
- [ ] move maps data into a binary or text file (maybe YAML or JSON)

#### Miscellaneous

#### Phisics module

- [ ] add a tile movement for Player instead of a pixel movement
- [ ] add collision detection class

#### Render module

#### Resource module

- [x] add a text file resource

#### Scene module

#### Serialization module

#### Status module
