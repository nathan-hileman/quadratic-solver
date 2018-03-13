#Unit Testing
Each module of the quadratic solver program was unit tested using a simplified version of the CUnit testing framework provided by Dr. Kapenga for us to use for this project. These modules include the read_line function for reading input from users, validate_line to validate the line read from the read_line function, the actual quadratic solver which is q_solve which basically holds the entire program together calling functions when needed, out_line which outputs a line to users, and finally, format_line which formats the line given from output function. 

## read_line:
For read_line, our test cases will be based around reading the input from the user. This will involve determining whether the user input data or not. The second test case will determine if the user inputed more than what was allocated in memory for the input buffer. 

## validate_line:
Validation will have the most test cases for user inputs. The most important thing to test will be that it accepts any non-empty string of characters from read_line. Furthermore, it must be determined whether the input can be tokenized into real numbers or not. If the user inputs NaN, characters, etc., then validate should report it back to the user. The second most important test case would be that the input string can be tokenized into three numbers. For example, we do not want the user to input only two values or two values and a character. Lastly, we will want to test if we can validate input that is written in scientific notation. 

##q_solve:
For the actual solver of the quadratic equation we intend to test several cases. First, we must test for incorrect input from the user. This includes NaNs, characters, and anything that is not a real number. Ideally handling incorrect input will be unnecessary, however, we are testing this independently from validate_line. Second, we must test the three types of solutions that q_solve provides: two real roots, one real double root, or complex roots. For each of these solutions, the input variables will be different values. For complex roots, we will return to the user a message saying that the roots are complex and not compute the solution. After that we will test several other cases including negative inputs, irrational numbers, and numbers that are, in size, larger than

##out_line
The out_line function is a specific source code used for a specific reason in the entire quadratic solver program. Its main purpose is to output a certain line to the user. 

##format_line:
The format_line function is a specific source code used for a specific reason in the entire quadratic solver program. Its main purpose is to format the line given which will then be printed alongside the out_line function 

##log_output
The log_output function is a specifc source code used for a specifc reason in the entire quadratic solver program. Its main purpose of this function is to take a message from the program and logs the message to a file.  