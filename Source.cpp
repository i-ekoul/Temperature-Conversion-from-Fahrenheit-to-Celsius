#include <iostream>     // For input and output stream
#include <fstream>      // For file input and output
#include <string>       // For handling string data
#include <iomanip>      // For formatting output

using namespace std;

// Function to convert Fahrenheit to Celsius
double FahrenheitToCelsius(int fahrenheit) {
    // Apply the conversion formula: (Fahrenheit - 32) * 5/9
    return (fahrenheit - 32) * 5.0 / 9.0;
}

int main() {
    // Open the input file for reading
    ifstream inFile("FahrenheitTemperature.txt");
    // Open the output file for writing
    ofstream outFile("CelsiusTemperature.txt");

    // Check if the input file was successfully opened
    if (!inFile.is_open()) {
        cerr << "Error: Unable to open input file." << endl;
        return 1; // Exit with an error code
    }

    // Check if the output file was successfully opened
    if (!outFile.is_open()) {
        cerr << "Error: Unable to open output file." << endl;
        return 1; // Exit with an error code
    }

    string city; // Variable to store the city name
    int fahrenheit; // Variable to store the temperature in Fahrenheit

    // Read each city and its Fahrenheit temperature from the input file
    while (inFile >> city >> fahrenheit) {
        // Convert the temperature to Celsius
        double celsius = FahrenheitToCelsius(fahrenheit);
        // Write the city and its Celsius temperature to the output file
        outFile << city << " " << fixed << setprecision(2) << celsius << endl;
    }

    // Close the input file
    inFile.close();
    // Close the output file
    outFile.close();

    // Indicate that the conversion is complete
    cout << "Conversion completed. Check CelsiusTemperature.txt for results." << endl;

    return 0; // Exit with a success code
}
