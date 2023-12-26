# This project duplicates a simulation of the Monty Hall problem in Python and C++, and compares the time taken for each program to execute.

Due to the purpose of the project, unnecessary lines of code have been implemented, such as shuffling the list / vector of what is behind the doors.

## Results

Python 3.11:
1. Execution time: 194.836 seconds.
2. The average number of cars obtained in 100 runs of the Monty Hall game if the player does not change choice, trialled 1000000 times is: 33.326323
3. The average number of cars obtained in 100 runs of the Monty Hall game if the player changes choice, trialled 1000000 times is: 66.677963

C++:
1. Execution time: 116.569 seconds.
2. The average number of cars obtained in 100 runs of the Monty Hall game if the player does not change choice, trialled 1000000 times is: 33.3296
3. The average number of cars obtained in 100 runs of the Monty Hall game if the player changes choice, trialled 1000000 times is: 66.6669

That is to say, the C++ program finished executing the task of getting the averages in 59.83% of the time it took the Python program to do so.

## Conclusion

Conventional wisdom is right, Python is kind of slow, assuming you're not actually using a Python library that uses C under the bonnet.
