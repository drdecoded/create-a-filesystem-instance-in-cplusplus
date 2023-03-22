# Create a filesystem instance (terminalprompt)

GitHub_Release.exe is a standalone executable to test the code.

Process of the .exe file:
1. Terminal opens and asks for a value.
2. Checks the value for repetition and existence.
3. Works with the value as described below.
4. Program is terminated.

Background:
User input is saved as a file. A folder named "folder" is created in the directory of the .exe file.
A .save file is created in the new folder and certain values are saved in this file.
Another .save file (metafile.save) will be created, recording all the .save files created in the past. 
The metafile remains and is only created once and expends by every new .save file created.
In case of misunderstandings: Both files are of course retained.

_________________________________________________________________

Functions @functions.cpp and @main.cpp:

gl_loadPath() # Loads disk locations and customizations into various external variables 
              # to call or override in other functions as needed.
              
getPath(string output) # Finds the current save path on disk (where the project is located). 
                       # The function can be called on a string argument.

creatDir() # Creates the required directory specified in the code. Directory on user request 
           # also possible, but more lumbering.
           # Functions checks if the needed folder has been created.
           # Note: "std::cout" in the if clause is unnecessary, and so the function is. Rewrite if necessary.

createFile() # Space-saving function. Creates the file with the user input as the name and 
             # stores specific values. These values can also be extended by user prompt.

clearT() # Clears the terminal.

_________________________________________________________________


You are free to use this code and rewrite/improve it if needed.

Task of the code: 
Store user input in general variables and make them callable via header files.

- Save inputs to files.
- Add more values in the files.

Availability:
Theoretically, use of the readable values for further use of memory instances and continuation by loading these memory instances.

NextToGo:
Read out created variables and call and change them.

+ Function call to retrieve all values stored at the moment and change them if necessary.

+ 'Save at any time' - function to save values on abrupt end.

_________________________________________________________________

NOTICE: Those files are written OS-dependent. A Windows operating system is required. If errors occur, please rewrite necessary functions.



good luck
