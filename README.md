My C Games Repository
Welcome to my repository of simple games written in C! This collection includes various games that showcase basic programming concepts and offer a fun way to practice coding in C.

Requirements
To compile and run these games, you will need:

GCC (GNU Compiler Collection) - a C compiler.
Command Prompt on Windows.
If you don’t already have GCC installed, follow the instructions below to set it up.

Installing GCC on Windows
Download and install MinGW, which provides GCC for Windows.
During installation, make sure to select gcc and g++ for installation in the MinGW Installation Manager.
Add the bin directory of your MinGW installation (usually C:\MinGW\bin) to your system’s PATH environment variable. This allows you to run gcc from any directory in the command prompt.
Cloning the Repository
To get started, clone this repository to your local machine. Run:

bash
Copiar código
git clone https://github.com/your-username/your-repository.git
cd your-repository
Replace your-username and your-repository with your GitHub username and repository name.

Compiling and Running a Game
To compile one of the games, navigate to the game’s directory and run the following command in your terminal:

bash
Copiar código
gcc -o game_name game_name.c
Replace game_name with the name of the specific game file (without the .c extension). This command will create an executable file called game_name.exe in the same directory.

To run the game, use:

bash
Copiar código
./game_name
Example
If you want to compile and run a game named tic_tac_toe.c, use:

bash
Copiar código
gcc -o tic_tac_toe tic_tac_toe.c
./tic_tac_toe
Additional Notes
If your game files have dependencies or libraries, ensure they are installed, and include any necessary #include directives in the code.
To compile multiple files, list them in the gcc command, e.g., gcc -o game main.c file1.c file2.c.
Feel free to report issues or suggest improvements!
