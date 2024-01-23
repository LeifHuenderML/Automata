# Architecture

## Classes

### GameLoop

-Creates a game loop using sfml 
-creates a cell object
-runs the celuluar object in the game loop
-creates user interface object and implements the user interface functions in proper order during the loop 
### Cells
-creates a cell with multiple inherited sub classes of cells with different behaviors and utilites
-a base cell just uses the original conway logic

### RL ENGINE
-uses pytorch api to run possibly a convnext algorithm to learn spatial representations to survive and replicate the fastest in an environment
-training pipeline
### UserInterface
-menu page
-game page
-handle user inputs