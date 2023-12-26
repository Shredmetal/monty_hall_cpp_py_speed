#include <iostream>
#include <random>
#include <chrono>
#include <string>
#include <vector>
#include <algorithm>


std::string door_remove(std::string choice) {
    if(choice == "car" || choice == "goat2") {
        return "goat1";
    }
    else if(choice == "goat1") {
        return "goat2";
    }
}


int main() {
    // start timer
    auto start = std::chrono::high_resolution_clock::now();
 
    // number of trials to run 
    const int num_trials {1000000};

    // initialise vectors to store trial results

    std::vector<int> no_change_result_vec {};
    std::vector<int> change_result_vec {};

    // initialise rngesus

    std::random_device random_device;
    std::mt19937 gen(random_device());
    std::uniform_int_distribution<int> dist(0, 2);

    // main program loop

    for(int i{0}; i < num_trials; ++i) {

        int no_change_counter {0};
        int change_counter {0};
        
        // count the number of successes in 100 rounds of playing the game without changing choice

        for (int j{0}; j < 100; ++j) {

            std::vector<std::string> choice_vec {"car", "goat1", "goat2"};

            std::string choice = choice_vec[dist(gen)];

            std::random_shuffle (choice_vec.begin(), choice_vec.end());
            std::string door_to_remove = door_remove(choice); 
            choice_vec.erase(std::remove(choice_vec.begin(), choice_vec.end(), door_to_remove), choice_vec.end());

            if(choice == "car") {
                no_change_counter++;
            }

        }

        no_change_result_vec.push_back(no_change_counter);

        // count the number of successes in 100 rounds of playing the game changing choice

        for (int j{0}; j < 100; ++j) {

            std::vector<std::string> choice_vec {"car", "goat1", "goat2"};

            std::string choice = choice_vec[dist(gen)];

            std::random_shuffle (choice_vec.begin(), choice_vec.end());
            std::string door_to_remove = door_remove(choice); 
            choice_vec.erase(std::remove(choice_vec.begin(), choice_vec.end(), door_to_remove), choice_vec.end());

            if(choice == choice_vec[0]) {
                choice = choice_vec[1];
            }
            else if(choice == choice_vec[1]) {
                choice = choice_vec[0];
            }

            if(choice == "car") {
                change_counter++;
            }
        }

        change_result_vec.push_back(change_counter);
    }

    double change_avg {0};
    double no_change_avg {0};

    for(auto i:no_change_result_vec) {
        no_change_avg += i;
    }

    for(auto i:change_result_vec) {
        change_avg += i;
    }

    no_change_avg = (no_change_avg / no_change_result_vec.size());
    change_avg = (change_avg / change_result_vec.size());

    std::cout << "The average number of cars obtained in 100 runs of the Monty Hall game if the player does not change choice, trialled " << num_trials << " times is: " << no_change_avg << std::endl;
    std::cout << "The average number of cars obtained in 100 runs of the Monty Hall game if the player changes choice, trialled " << num_trials << " times is: " << change_avg << std::endl;

    // end timer
    auto end = std::chrono::high_resolution_clock::now();

    // calculate duration
    std::chrono::duration<double> duration = end - start;
    std::cout << "Execution time: " << duration.count() << " seconds. " << std::endl;

    return 0;
}
