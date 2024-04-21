    # Installation Guide for Automata

    This guide will walk you through the steps required to set up your environment for Automata. Follow these instructions to install Python, set up the necessary executable permissions, and build the game.

    ## Prerequisites

    Ensure that you have administrative access to your computer and an internet connection to download the required software.

    ## Step 1: Install Python

    ### Windows

    1. Visit the official Python website at [python.org](https://www.python.org/downloads/).
    2. Download the latest version of Python for Windows by clicking on the "Download Python" button.
    3. Run the downloaded installer. Ensure to check the box that says "Add Python to PATH" at the beginning of the installation process.
    4. Follow the on-screen instructions to install Python.

    ## Step 2: Download the Repository

    Clone the repository to your local machine using the following command:

    ```bash
    git clone https://github.com/LeifHuenderML/Automata.git
    cd Automata
    ```

    ## Step 3: Grant Executable Permissions to `build.sh`

    Before running the build script, you need to make sure it has executable permissions:

    ```bash
    chmod +x build.sh
    ```

    ## Step 4: Build the Game

    Now that everything is set up, you can build the game by running:

    ```bash
    ./build.sh
    ```

    This script will compile and build the game based on the instructions defined within it.

    ## Troubleshooting

    If you encounter any issues during the installation or build process, please check the following:
    - Ensure that Python is correctly installed and in your PATH.
    - Confirm that you have the correct permissions to execute the `build.sh` script.
    - Verify that all dependencies specified in the build script are correctly installed.

    ## Conclusion

    You should now have Automata installed and ready to run.