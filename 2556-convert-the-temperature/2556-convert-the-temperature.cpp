class Solution {
public:
    vector<double> convertTemperature(double x) {
        double kel = x + 273.15;
        double f = x * 1.8 + 32.0;
        return {kel, f};
    }
};