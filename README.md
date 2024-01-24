# Automata

![Automata Header](docs/images/AutomataLogo.png)

Automata is an innovative game inspired by John Conway's Game of Life, utilizing a grid of cells as its primary structure. This game extends the classical cellular automaton concept by incorporating multiple rule sets, each offering a distinct layer of complexity and interaction dynamics. This was a collaborative project between Leif Huender, Aaron Froes, and Shaun Swant.

## Installation

Please refer to our [installation guide](docs/architecture/installation/installation.md) here for setting up and running Automata.

## For Collaborators

Please refer to our [style guide](docs/styleGuide/styleGuide.md) before making any changes to the repository.

## Rule Sets

The game features a variety of rule sets, allowing players to explore different aspects of cellular automaton theory:

1. **Conway's Original Rules**: This foundational rule set, established by John Conway, forms the core of cellular automaton mechanics. It stipulates the conditions for the survival, death, or birth of cells based on the number of adjacent active cells.

2. **High Life (Nathan Thompson, 1994)**: An extension of Conway's rules, High Life introduces an additional birth condition. In this rule set, a cell is born if it has exactly six neighbors, adding a novel complexity and resulting in unique evolutionary patterns.

3. **The Rainbow of Life (David Griffeath)**: This variant diversifies the cellular automaton concept by integrating a color dimension. The color of each cell results from an averaging of its progenitors' colors, adhering to the Nord color palette. This innovative approach illustrates the propagation of genetic-like traits within the automaton environment.

4. **Dynamic Life (Leif Huender, 2024)**: Dynamic Life represents a paradigm shift in cellular automaton gameplay. It employs a random algorithm to alter the rule set dynamically from an extensive array of possibilities. This mode is specially designed for the Reinforcement Learning (RL) Model incorporated into the game, trained to adeptly navigate and adapt to a range of environmental conditions, from the most benign to the most challenging.

## Research and Development

Automata is not solely a game; it is also a platform for research. A significant facet of Automata's design is the exploration of how advanced state of the art Convolutional Neural Networks (CNNs) learn and evolve through self-play. The game offers a unique setting for investigating the capacity of these networks to adapt, survive, and proliferate within a simulated cellular environment, marking the intersection of gaming and scientific research.

For those interested in the in-depth research and methodologies behind the development of Automata, particularly the integration and performance of the RL Model, you are encouraged to consult the paper [Adaptive Dynamics in Cellular Automata: Exploring the Intersection of Machine Learning and Self-Organizing Systems in Automata]("docs/papers/Adaptive Dynamics in Cellular Automata: Exploring the Intersection of Machine Learning and Self-Organizing Systems in Automata/Adaptive Dynamics in Cellular Automata: Exploring the Intersection of Machine Learning and Self-Organizing Systems in Automata.docx") by Leif Huender.

## Conclusion

Automata is an amalgamation of gaming and scientific inquiry. It invites players and researchers to delve into the complexities of cellular systems, machine learning, and the emergent behaviors arising from simple rules iterated over time.
