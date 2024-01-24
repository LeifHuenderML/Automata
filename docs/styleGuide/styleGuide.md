# Repository Style Guide

This style guide is intended to maintain consistency, readability, and maintainability within this C++ repository. All contributors are expected to adhere to these guidelines.

## 1. Language

- The primary language for this repository is C++ 17.

## 2. Code Style

### Naming Conventions

- **Variables and Functions**: Use `camelCase`. Start with a lowercase letter. For multi-word names, capitalize the first letter of each subsequent word. Example: `myVariable`, `calculateTotal`.
- **Classes and Structures**: Start with a capital letter and use `camelCase`. Example: `MyClass`, `DataStructure`.
- **Constants and Enumerators**: Use all uppercase letters with underscores separating words. Example: `MAX_SIZE`, `COLOR_RED`.

### Formatting

- **Indentation**: Use spaces, preferring 4 spaces per level of indentation.
- **Braces**: Opening brace on the same line as the statement; closing brace on its own line.

    ```cpp
    if (condition) {
        doSomething();
    }
    ```

- **Line Length**: Prefer lines under 80 characters. Break longer lines for readability.
- **Whitespace**: Use whitespace to improve readability, like after commas and around operators.

### Comments

- **Inline Comments**: Use sparingly for explaining complex code.
- **Documentation Comments**: Use for functions, classes, and modules. Suitable for tools like Doxygen.

## 3. Directory Structure

Organize the project into folders where there is a main idea or component. Each folder should encapsulate all the necessary files for that component. Avoid placing unrelated files in the same folder. Here's an example of a structured project:

```cpp
├── environment
│ └── main.cpp
│ └── enviormnent.cpp
│ └── enviromnment.hpp
├── gameController
│ └── main.cpp
│ └── gameController.cpp
│ └── gameController.hpp 
```

## 4. Git Practices

### Branches

- **Working in Branches**: Always work in branches. `main` is for stable, tested code. Create a new branch for features, fixes, or experiments.
- **Naming Branches**: Descriptive, prefixed with the work type, e.g., `feature/add-login`, `bugfix/address-crash`.
- **Pull Requests**: Create a pull request to merge into `main`. Ensure code adheres to the style guide and is tested.

### Commit Messages

- Write clear, concise commit messages. First line: short description (max 50 characters), followed by a blank line and a more detailed explanation if needed.

## 5. Testing

- **Unit Testing**: Write unit tests for new code. Ensure existing tests pass before pull requests.
- **Continuous Integration**: Use CI tools to automate testing. Keep `main` branch in a releasable state.

Contributions not adhering to these guidelines may be subject to revision. Happy coding!
