#include <iostream>
#include <limits> 
#include <fstream> 
#include <string>  
#include <cstdlib>
#include <ctime>

int main() {
    const std::string high_scores_filename = "high_scores.txt";
    std::cout << "Hi! Enter your name, please:" << std::endl;
    std::string user_name;
    std::cin >> user_name;

    const int max_value = 100;
    std::srand(std::time(nullptr));
    int random_value = std::rand() % max_value + 1; // Генерация случайного числа от 1 до 100

    int current_value = 0;
    int attempts = 0; 

    std::cout << "Welcome, " << user_name << "! Try to guess the number (between 1 and 100):" << std::endl;

    do {
        std::cout << "Enter your guess:" << std::endl;

        // Проверка на корректность ввода
        while (!(std::cin >> current_value)) {
            std::cout << "Invalid input. Please enter a number." << std::endl;
            std::cin.clear(); // Сброс состояния потока
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Игнорируем неверный ввод
        }

        attempts++; // Увеличиваем счетчик попыток

        if (current_value < random_value) {
            std::cout << "Less." << std::endl; 
        } else if (current_value > random_value) {
            std::cout << "Greater." << std::endl; 
        }

    } while (current_value != random_value); // Продолжаем, пока число не угадано

    std::cout << "Congratulations, " << user_name << "! You win!" << std::endl;
    std::cout << "You guessed the number in " << attempts << " attempts." << std::endl; // Вывод количества попыток

    // Запись в файл high_scores.txt
    {
        std::ofstream out_file(high_scores_filename, std::ios::app); // Открываем файл для добавления
        if (!out_file.is_open()) {
            std::cerr << "Failed to open file for write: " << high_scores_filename << "!" << std::endl;
            return -1;
        }
        out_file << user_name << "\t" << attempts << std::endl; 
    }

    return 0; 
}