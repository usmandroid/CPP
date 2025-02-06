#include <iostream>
#include <unordered_map>
#include <stdexcept>
#include <iomanip>

// Enum for unit types
enum class Unit {
    BIT, BYTE,
    KIB, MIB, GIB, TIB, // Binary units (1024-based)
    KB, MB, GB, TB // Decimal units (1000-based)
};

// Conversion factors
const std::unordered_map<Unit, double> conversionFactors = {
    {Unit::BIT, 1}, {Unit::BYTE, 8},
    {Unit::KIB, 8192}, {Unit::MIB, 8388608}, {Unit::GIB, 8589934592}, {Unit::TIB, 8796093022208},
    {Unit::KB, 8000}, {Unit::MB, 8000000}, {Unit::GB, 8000000000}, {Unit::TB, 8000000000000}
};

// Function to convert between units
double convert(double value, Unit from, Unit to) {
    if (conversionFactors.find(from) == conversionFactors.end() ||
        conversionFactors.find(to) == conversionFactors.end()) {
        throw std::invalid_argument("Invalid unit for conversion");
    }
    return value * (conversionFactors.at(from) / conversionFactors.at(to));
}

// Function to print conversion table
void printConversionTable() {
    std::cout << std::left << std::setw(10) << "Power of 2" << std::setw(20) << "Bits"
              << std::setw(10) << "Bytes" << std::setw(10) << "KiB" << std::setw(10) << "MiB"
              << std::setw(10) << "GiB" << std::setw(10) << "TiB" << std::endl;
    std::cout << std::string(80, '-') << std::endl;
    
    for (int i = 10; i <= 40; i += 10) {
        double value = static_cast<double>(1ULL << i);
        std::cout << std::left << std::setw(10) << i
                  << std::setw(20) << value
                  << std::setw(10) << convert(value, Unit::BIT, Unit::BYTE)
                  << std::setw(10) << convert(value, Unit::BIT, Unit::KIB)
                  << std::setw(10) << convert(value, Unit::BIT, Unit::MIB)
                  << std::setw(10) << convert(value, Unit::BIT, Unit::GIB)
                  << std::setw(10) << convert(value, Unit::BIT, Unit::TIB)
                  << std::endl;
    }
}

int main() {
    try {
        printConversionTable();
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}
