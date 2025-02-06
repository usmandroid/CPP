#include <iostream>
#include <unordered_map>
#include <stdexcept>

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

int main() {
    try {
        double value = 1; // 1 MiB
        Unit from = Unit::MIB;
        Unit to = Unit::KB;
        std::cout << value << " MiB = " << convert(value, from, to) << " KB" << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}
