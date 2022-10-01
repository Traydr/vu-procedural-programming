#include <iostream>

/* Task description
 * AVG electricity bill for each flat per month. Electricity used to light the building entrance during the nighttime.
 * Electricity price 0.24 EUR / kWh
 * LED lamp 20w
 * Lamps num = 3
 * Num flats = 45
 * Light work time per day:
 *  Jan - 16 h
 *  Feb - 14 h
 *  Mar - 12 h
 *  Apr - 10 h
 *  May - 8 h
 *  Jun - 6 h
 *  Jul - 7 h
 *  Aug - 9 h
 *  Sep - 11 h
 *  Oct - 13 h
 *  Nov - 15 h
 *  Dec - 16 h
 * Each month has 30 days
 */

int main() {
    const float electricityPrice{0.24}; // eur per kwh
    const int lampConsumption{20}; // watts
    const int numLamps{3};
    const int numFlats{45};
    const int nightHours[12]{16, 14, 12, 10, 8, 6, 7,
                             9, 11, 13, 15, 16}; // hours
    const std::string months[12]{"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul",
                                 "Aug", "Sep", "Oct", "Nov", "Dec"};
    const int daysPerMonth{30};

    int totalConsumption{numLamps * lampConsumption};
    float sumOfPrices{0};

    for (int i = 0; i < 12; i++) {
        float wattHours = (nightHours[i] * daysPerMonth) * totalConsumption;
        float electricityPricePerFlat = ((wattHours / 1000) * electricityPrice) / numFlats;
        sumOfPrices += electricityPricePerFlat;
        std::cout << "Electricity price per flat For month " << months[i] << " is " << electricityPricePerFlat
                  << " eur\n";
    }

    float avgPrice = sumOfPrices / 12;
    std::cout << "Avg price of electricity per month per flat is " << avgPrice << " eur";

    return 0;
}
