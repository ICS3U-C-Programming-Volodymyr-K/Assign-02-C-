
#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>

int main() {
    // Welcomes the user
    std::cout << "Hello, the user of this calculator. This calculator may be "
              << "useful for you in order to find the surface area and volume "
              << "of cylinder.\n";
    
    // Asks user about their next action
    std::string welcome_message;
    std::cout << "If you want to continue calculating, type yes and if not "
              << "then type no: ";
    std::cin >> welcome_message;
    
    // Convert to lowercase for case-insensitive comparison
    std::transform(welcome_message.begin(), welcome_message.end(), 
                  welcome_message.begin(), ::tolower);
    
    if (welcome_message == "no") {
        std::cout << "\033[1m \033[91m \033[41m "
                 << "I will delete your operation system.\033[0m\n";
    } else {
        // Gets the radius and height from the user
        double radius, height;
        std::cout << "Enter the radius value (cm): ";
        std::cin >> radius;
        std::cout << "Enter the height value (cm): ";
        std::cin >> height;
        
        // Calculate surface area and volume
        double surface_area = 2 * M_PI * radius * (height + radius);
        double volume = M_PI * radius * radius * height;
        
        // Display results
        std::cout.precision(2);
        std::cout << std::fixed;
        std::cout << "The surface area of the cylinder is " << surface_area 
                 << " cm^2\n";
        std::cout << "The volume of the cylinder is " << volume << " cm^3\n";
        
        // Ask about metric conversion
        std::string question_metrics;
        std::cout << "To what metrics do you want to convert your values? "
                 << "(m/mm/km), if you do not wish to have your values "
                 << "converted, say no: ";
        std::cin >> question_metrics;
        
        // Convert based on user's choice
        if (question_metrics == "m") {
            double metrical_surface_area = surface_area / 100;
            double metrical_volume = volume / 100;
            
            std::cout.precision(5);
            std::cout << "The surface area of cylinder is " 
                     << metrical_surface_area << " meters squared\n";
            std::cout << "The volume of cylinder is " << metrical_volume 
                     << " meters cubed\n";
        } else if (question_metrics == "mm") {
            double millimetrical_surface_area = surface_area * 10;
            double millimetrical_volume = volume * 10;
            
            std::cout.precision(5);
            std::cout << "The surface area of cylinder is " 
                     << millimetrical_surface_area << " millimeters squared\n";
            std::cout << "The volume of cylinder is " << millimetrical_volume 
                     << " millimeters cubed\n";
        } else if (question_metrics == "km") {
            double kilometrical_surface_area = surface_area / 100000;
            double kilometrical_volume = volume / 100000;
            
            std::cout << "The surface area of cylinder is " 
                     << kilometrical_surface_area << " kilometers squared\n";
            std::cout << "The volume of cylinder is " << kilometrical_volume 
                     << " kilometers cubed\n";
        } else if (question_metrics == "no") {
            std::cout << "Alright, thank you very much for the use of "
                     << "calculator.\n";
        }
    }
    
    return 0;
}
