# Maintenance

><p>
    +----------------------------------------------------------+<br>
    |               Command Line Quadratic Solver              |<br>
    |        TEAM: Ali Itani, Nathan Hleman, Xavier Gray       |<br>
    |                Kapenga Inc., LICENSE: GPL 2.0            |<br>
    |                            v1.0                          |<br>
    +----------------------------------------------------------+<br>
</p>

To be able to use program make sure you follow these steps accordingly.


## Step 1 - Compile Quad Solver

To Compile the project - since its a Command Line Program, simply go to the root of the project **./quad-solver** and make sure you are able to see a **makefile** file in the directory alongside /build, /doc, /spikes, etc...

>**Note:** makefile is a special file, containing shell commands, that our team implemented.

To Compile the program. 
```sh
    $ make program
```

after executing this command, you should be able to see the **object** files in the **/build** directory and the **executables** in the **/src** directory

## Step 2 - Run Quad Solver

To run the project - make sure you have followed step 1 and executed the steps with no errors. 

Again, in the root directory of the project, use the **make** file to run the program.

```sh
    $ make run
```

## Final Step - Using the program

To use the program after running the executable. 
by using the command

```sh
    $ make run
```
By executing this command, you will be able to run the **executable** file which is **./quad_solver** in the **/src** directory, and then you should be able to see the program running were you will be prompted to insert the values for the coefficients.


## To Deploy:
To deploy the program, our team have worked on an option to deploy the project and its necessary requirements into a tar file.

Again, in the root directory of the project, use the **make** file to run the program.

```sh
    $ make deploy
```

# Unit Testing
To unit test the program, we have several methods and source files provided for unit testing, key methods are 
    - qsolve: Function that implements the quadratic equation. Takes floats a, b, and c from user input and uses them in the equation.
    - validate_line: which validates the input provided by the user.
    - read_Line: which is able to read a stream of unbuffered characters from the user.
    - format_line: Takes arguments from main and formats a string to be passed to outline

unit testing for these methods are done to check whether they are fit for use.

Again, in the root directory of the project, make sure the program has exited use the **make** file to to run a certain command for each function to test, 

1 - to unit test qsolve run:
```sh
    $ make test_qsolve
```
2 - to unit test validate run:
```sh
    $ make test_validate
```
3 - to unit test readline run:
```sh
    $ make test_readline
```
3 - to unit test formatline run:
```sh
    $ make test_formatline
```
4 - to unit test outline run:
```sh
    $ make test_outline
```

# HELP

if you ran into any problems while running or executing commands in the program, 
go to the root directory and use the command **make help** which will provide you with sufficient information to guide you through the process.
- Instructions:
Again, in the root directory of the project, use the **make** file to run the program.
```sh
    $ make help
```


# Finally
We hope you enjoy our Command Line Quadratic Solver - The Team!
