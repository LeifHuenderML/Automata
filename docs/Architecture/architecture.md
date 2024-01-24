<img src="../images/Architecture_Logo.png" alt="Architecture Header" width="1300" height="300"/>

# Automata Architecture Documentation

## 1. GameController

### Responsibilities:
- Orchestrates the game loop using the Simple and Fast Multimedia Library (SFML), a multimedia C++ API. This involves initializing the rendering window, handling frame updates, and managing event polling for user interactions.
- Manages transitions between different game states (such as: menu, in-game, game over) by maintaining a state machine. Each state encapsulates specific behaviors and can trigger transitions based on events or conditions.
- Handles high-level interactions between major components (CellManager, UIManager, RLEngine) by serving as a mediator, ensuring that each component's state and data are synchronized with the overall game state.

### Technical Details:
- Utilizes the SFML event system to process user inputs (keyboard, mouse) and window events (close, resize).
- Implements a game loop that calculates the delta time between frames to ensure consistent updates and rendering regardless of performance fluctuations.
- Manages a stack of game states, allowing for flexible control over the flow of the game, such as pausing and resuming.

## 2. CellManager

### Responsibilities:
- Manages the cell grid and its state, which involves storing and updating a two-dimensional array of cells.
- Updates the cells based on cellular automata rules, which determine the state of each cell in the grid based on the states of its neighbors.
- Can handle different types of cells through polymorphism. A base class `Cell` can be extended to create various specialized cells, allowing for a versatile system capable of simulating different scenarios.

### Technical Details:
- Implements efficient data structures (e.g., arrays, matrices) to store the state of each cell and to perform batch updates on the grid.
- Employs optimized algorithms for updating cells based on cellular automata rules, minimizing unnecessary calculations.
- Facilitates the extension of cell behavior through a well-defined inheritance hierarchy, where each subclass of `Cell` can override specific methods to alter its behavior.

#### Subclasses of Cell:
- `BaseCell`: Implements the basic Conway's Game of Life logic. It includes methods for calculating the next state based on the traditional rules (e.g., underpopulation, overpopulation, reproduction).
- `CustomCell`: Implements variations of the basic logic or entirely new rules for more complex behavior. This can include cells with different survival rules, reproduction rates, or interactions with other types of cells.

## 3. RLEngine

### Responsibilities:
- Manages the reinforcement learning aspect using the PyTorch API, a powerful library for machine learning and neural network computation.
- Trains models to learn optimal strategies under different conditions by interacting with the game environment, receiving feedback, and adjusting strategies based on the rewards received.
- Interfaces with CellManager to apply learned strategies to the cell grid and observe the results, effectively allowing the AI to control aspects of the game or simulate intelligent behavior.

### Technical Details:
- Implements reinforcement learning algorithms (e.g., Q-learning, policy gradients) that can operate on the state representations provided by the CellManager.
- Uses PyTorch's automatic differentiation and neural network modules to build and train models that can predict the value of actions or directly output optimal actions.
- Integrates with the game loop, allowing the AI to periodically receive state updates, perform actions, and receive feedback in the form of rewards.

## 4. UIManager

### Responsibilities:
- Manages all user interface elements, including buttons, menus, and status displays. This involves rendering text, handling layout, and responding to user interactions.
- Handles user inputs (e.g., button clicks, menu selections) and translates them into actions within the game, such as starting a new game, pausing, or adjusting settings.

### Technical Details:
- Utilizes SFML's graphics and window modules to render UI elements and handle input events.
- Implements a UI event system that allows components to communicate and react to user actions.
- Employs a layout system to automatically arrange UI elements, ensuring a consistent and responsive design across different screen sizes and resolutions.

#### Subcomponents:
- `MenuPage`: Displays the main menu and options. It handles navigation between different menu screens (e.g., main menu, options, credits) and triggers actions like starting the game or exiting the application.
- `GamePage`: Displays the game grid, status information (e.g., score, level), and in-game menus (e.g., pause menu). It updates in real-time based on the game state and user interactions.

## 5. Environment

### Responsibilities:
- Represents the environment in which cells exist. This can include factors like resource availability, predation, or climate conditions, which can affect cell behavior and survival.
- Can be used to introduce varying conditions that affect cell behavior, adding an additional layer of complexity and realism to the simulation.
- Interacts with CellManager to impose environmental effects on cells, such as altering their growth rate, lifespan, or reproductive success based on environmental factors.

### Technical Details:
- Encapsulates environmental factors in a modular way, allowing for easy extension or modification of environmental effects.
- Provides an API for CellManager to query environmental conditions at specific grid locations or times, ensuring that cell behavior can be dynamically adjusted based on the environment.
- Implements algorithms to simulate environmental dynamics, such as resource depletion, spread of hazards, or changes in climate conditions.

## Interactions:

- `GameController <-> UIManager`: GameController receives user inputs from UIManager (e.g., menu selections, in-game commands) and updates the game state accordingly. It also sends state updates to UIManager to reflect changes in the game, such as transitioning between menus and the game scene.
- `GameController <-> CellManager`: GameController triggers updates in CellManager based on game state (e.g., starting a new simulation, pausing) and user inputs (e.g., modifying cell states, changing simulation parameters).
- `CellManager <-> RLEngine`: CellManager provides cell grid states to RLEngine for training and strategy application. RLEngine, in turn, sends back actions or policy updates that CellManager uses to adjust cell behavior or simulation parameters.
- `CellManager <-> Environment`: The Environment imposes conditions on the cell grid, such as altering resource availability or introducing hazards. CellManager updates cell states based on these conditions, ensuring that the simulation reflects the dynamic interplay between cells and their environment.
