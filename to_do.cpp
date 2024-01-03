#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <thread>

struct Task {
    std::string name;
    std::chrono::system_clock::time_point deadline;
};

int main() {
    std::vector<Task> tasks;
    
    while (true) {
        // Print the menu options
        std::cout << "1. Add task\n";
        std::cout << "2. List tasks\n";
        std::cout << "3. Quit\n";
        
        // Get the user's choice
        std::string choice_str;
        std::getline(std::cin, choice_str);
        int choice = std::stoi(choice_str);
        
        if (choice == 1) {
            // Get the task name
            std::cout << "Enter task name: ";
            std::string task_name;
            std::getline(std::cin, task_name);
            
            // Get the deadline date and time
            std::cout << "Enter deadline date (YYYY-MM-DD): ";
            std::string date_str;
            std::getline(std::cin, date_str);
            
            std::cout << "Enter deadline time (HH:MM): ";
            std::string time_str;
            std::getline(std::cin, time_str);
            
            // Parse the deadline date and time
            std::string datetime_str = date_str + " " + time_str;
            std::tm datetime_tm = {};
            std::istringstream datetime_ss(datetime_str);
            datetime_ss >> std::get_time(&datetime_tm, "%Y-%m-%d %H:%M");
            std::time_t datetime_tt = std::mktime(&datetime_tm);
            std::chrono::system_clock::time_point deadline = std::chrono::system_clock::from_time_t(datetime_tt);
            
            // Add the task to the list
            tasks.push_back({task_name, deadline});
            
            // Set a reminder for the task
            std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
            std::chrono::duration<int> time_left_duration = std::chrono::duration_cast<std::chrono::duration<int>>(deadline - now);
            int time_left_ms = time_left_duration.count() * 1000;
            std::this_thread::sleep_for(std::chrono::milliseconds(time_left_ms));
            std::cout << "Reminder: " << task_name << std::endl;
        }
        else if (choice == 2) {
            // List the tasks
            std::cout << "Tasks:\n";
            for (const Task& task : tasks) {
                std::time_t deadline_tt = std::chrono::system_clock::to_time_t(task.deadline);
                std::cout << "- " << task.name << " (deadline: " << std::ctime(&deadline_tt) << ")";
            }
        }
        else if (choice == 3) {
            // Quit
            break;
        }
        else {
            // Invalid choice
            std::cout << "Invalid choice. Please try again.\n";
        }
        
        // Print a separator
        std::cout << std::endl;
    }
    
    return 0;
}
