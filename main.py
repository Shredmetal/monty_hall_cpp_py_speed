import random
import matplotlib.pyplot as plt
import pandas as pd
import os

# Global variable, just change this number to change the number of trials to run.

NUM_TRIALS = 1000000

# Define a function to get open a door (get rid of the door)


def goat_door(choice):
    if player_choice == "car" or player_choice == "goat2":
        return "goat1"
    elif player_choice == "goat1":
        return "goat2"


# Initialise lists to store the number of times player gets a car out of 100 runs.

no_change_result_list = []
change_result_list = []

# Main program loop

for x in range(NUM_TRIALS):

    # Initialise the success counters

    no_change_counter = 0
    change_counter = 0

    # Count the number of successes in 100 rounds of playing the game without changing choice

    for n in range(100):

        my_list = ["car", "goat1", "goat2"]
        random.shuffle(my_list)
        player_choice = random.choice(my_list)
        door_remove = goat_door(choice=player_choice)
        my_list.remove(door_remove)

        if player_choice == "car":
            no_change_counter += 1
        else:
            pass

    # Count the number of successes in 100 rounds of playing the game with the player changing choice

    for n in range(100):

        my_list = ["car", "goat1", "goat2"]
        random.shuffle(my_list)
        player_choice = random.choice(my_list)
        door_remove = goat_door(choice=player_choice)
        my_list.remove(door_remove)

        if player_choice == my_list[0]:
            player_choice = my_list[1]
        elif player_choice == my_list[1]:
            player_choice = my_list[0]

        if player_choice == "car":
            change_counter += 1
        else:
            pass

    # Update the lists with the results

    no_change_result_list.append(no_change_counter)
    change_result_list.append(change_counter)

# Stick the results into a dataframe

no_change_df = pd.DataFrame(no_change_result_list)
change_df = pd.DataFrame(change_result_list)

# Describe the results to get mean, quartiles, and std dev and save them as variables to write into a file

no_change_description = no_change_df.describe()
change_description = change_df.describe()

# Check if directory exists, if not, create it, then write the results into a text file in the directory

if not os.path.exists("results"):
    os.makedirs("results")

with open("results/results.txt", mode="w") as data_file:
    data_file.write(f"{no_change_description}\n\n{change_description}")

# if you want to print to console, uncomment the following line

# print(f"{no_change_description}\n\n{change_description}")

# Plot the results into a single chart and save the figures

plt.hist(no_change_df, rwidth=0.7, density=True, bins=[n for n in range(101)])
plt.hist(change_df, rwidth=0.7, density=True, bins=[n for n in range(101)])
plt.savefig("results/distributions.png")
