#include <iostream>
#include <vector>
#include <iomanip>

// STRUCTS
struct monthlyElectricityStats
{
	uint32_t year;
	uint32_t month;
	float consumed;
	float produced;
	float priceKWH;
	float priceStorageKWH;

	// Auto Constructor
	monthlyElectricityStats(uint32_t year,
		uint32_t month,
		float consumed,
		float produced,
		float priceKwh,
		float priceStorageKwh)
		: year(year), month(month), consumed(consumed), produced(produced), priceKWH(priceKwh),
		  priceStorageKWH(priceStorageKwh)
	{
	}
};

// CONSTANTS
// All prices in eur
const float POWER_PLANT_POWER_IN_KW{ 1.5 };
const float POWER_PLANT_PER_KW_PRICE{ 920 };
const float STATE_REIMBURSEMENT_PERCENTAGE{ 0.3 };
const float ANNUAL_SERVICE_COST_PER_KW_IN_EUR{ 22.9 };
const float ANNUAL_REDUCTION_IN_ELECTRICITY_PRODUCTION{ 0.01 };

const std::string MONTHS[12]{ "January", "February", "March", "April",
							  "May", "June", "July", "August",
							  "September", "October", "November", "December" };

// GLOBAL VARS
std::vector<monthlyElectricityStats> data{};

// Utility functions
std::string mapIntToMonth(uint32_t month)
{
	return MONTHS[month];
}

std::vector<monthlyElectricityStats> findDataWithMonth(uint32_t m)
{
	std::vector<monthlyElectricityStats> output{};

	for (monthlyElectricityStats stats : data)
	{
		if (stats.month == m)
		{
			output.push_back(stats);
		}
	}

	return output;
}

float readFloat()
{
	float input{ 0 };
	bool valid{ false };

	do
	{
		std::cin >> input;
		if (std::cin.good())
		{
			valid = true;
		}
		else
		{
			std::cin.clear();
			std::cin.ignore();
			std::cout << "Invalid float, please try again.\n";
		}
	} while (!valid);

	return input;
}

void printHeader() {
	std::cout << std::setw(4) << "year" << "\t";
	std::cout << std::setw(10) << "month" << "\t";
	std::cout << std::setw(10) << "consumption" << "\t";
	std::cout << std::setw(10) << "production" << "\t";
	std::cout << std::setw(10) << "price" << "\t";
	std::cout << std::setw(10) << "storagePrice" << "\t";
	std::cout << std::setw(10) << "balance" << "\t";
	std::cout << std::setw(10) << "supported balance" << "\t";
	std::cout << std::endl;
}

void printStats(uint32_t year, uint32_t month, float consumption, float production, float price, float storagePrice, float balance, float balanceWithReimbursement) {
	std::cout << std::setw(4) << year << "\t";
	std::cout << std::setw(10) << mapIntToMonth(month) << "\t";
	std::cout << std::setw(10) << consumption << "\t";
	std::cout << std::setw(10) << production << "\t";
	std::cout << std::setw(10) << price << "\t";
	std::cout << std::setw(10) << storagePrice << "\t";
	std::cout << std::setw(10) << balance << "\t";
	std::cout << std::setw(10) << balanceWithReimbursement << "\t";
	std::cout << std::endl;
}

// Filling in preset data
void fillMonthlyData()
{
	data.emplace_back(2021, 0, 285, 7.83, 0.141, 0.05445);
	data.emplace_back(2021, 1, 242, 57.03, 0.141, 0.05445);
	data.emplace_back(2021, 2, 220, 114.29, 0.141, 0.05445);
	data.emplace_back(2021, 3, 153, 176.04, 0.141, 0.05445);
	data.emplace_back(2021, 4, 125, 221.95, 0.141, 0.05445);
	data.emplace_back(2021, 5, 104, 275.22, 0.141, 0.05445);
	data.emplace_back(2021, 6, 92, 247.78, 0.152, 0.05445);
	data.emplace_back(2021, 7, 109, 166.77, 0.152, 0.05445);
	data.emplace_back(2021, 8, 182, 149.32, 0.152, 0.05445);
	data.emplace_back(2021, 9, 174, 117.42, 0.152, 0.05445);
	data.emplace_back(2021, 10, 211, 35.66, 0.152, 0.05445);
	data.emplace_back(2021, 11, 176, 7.71, 0.152, 0.05445);
	data.emplace_back(2022, 0, 226, 19.21, 0.167, 0.04477);
	data.emplace_back(2022, 1, 228, 52.86, 0.167, 0.04477);
	data.emplace_back(2022, 2, 220, 207.2, 0.167, 0.04477);
	data.emplace_back(2022, 3, 136, 207.35, 0.167, 0.04477);
	data.emplace_back(2022, 4, 129, 218.31, 0.167, 0.04477);
	data.emplace_back(2022, 5, 121, 224.19, 0.167, 0.04477);
	data.emplace_back(2022, 6, 92, 220.31, 0.167, 0.04477);
	data.emplace_back(2022, 7, 108, 225.58, 0.1826, 0.04477);
	data.emplace_back(2022, 8, 160, 151.25, 0.1826, 0.04477);
	data.emplace_back(2022, 9, 167, 92.12, 0.1826, 0.04477);
	data.emplace_back(2022, 10, 202, 17.08, 0.1826, 0.04477);
	data.emplace_back(2022, 11, 225, 6, 0.1826, 0.04477);
}

int main()
{
	// Starting conditions
	fillMonthlyData();
	uint32_t currentYear{ 2023 };
	uint32_t currentMonth{ 0 };
	float currentElectricityPrice{ 0.1826 };
	float currentElectricityStoragePrice{ 0.04477 };
	float currentProduction{};
	float currentConsumption{};

	// Calculating the amount to repay
	float balance{ -(POWER_PLANT_POWER_IN_KW * POWER_PLANT_PER_KW_PRICE) };
	float balanceWithReimbursement{ balance * (1 - STATE_REIMBURSEMENT_PERCENTAGE) };
	float electricityStored{};

	// Fill in how much electricity is stored
	for (monthlyElectricityStats stats : data) {
		electricityStored += stats.produced;
		electricityStored -= stats.consumed;

		if (electricityStored < 0) {
			electricityStored = 0;
		}
	}

	bool isTargetReached{ false };
	bool isRepayTriggered{ false };

	printHeader();

	do
	{
		// Submit new data
		if (currentMonth == 0 || currentMonth == 6)
		{
			std::cout << "Enter new electricity price\n";
			currentElectricityPrice = readFloat();
			std::cout << "Enter new electricity storage price\n";
			currentElectricityStoragePrice = readFloat();
		}

		// Check if amount is repaid
		if (balance > 0)
		{
			isTargetReached = true;
			std::cout << "\n\nREPAID FULL COST AT YEAR:" << currentYear << " AND MONTH: " << mapIntToMonth(currentMonth) << "\n\n";
			break;
		}
		else if (balanceWithReimbursement > 0 && !isRepayTriggered)
		{
			isRepayTriggered = true;
			std::cout << "\n\nREPAID COST WITH REIMBURSEMENT AT YEAR:" << currentYear << " AND MONTH: " << mapIntToMonth(currentMonth) << "\n\n";
		}

		// Calculate data
		std::vector<monthlyElectricityStats> lastMonths{ findDataWithMonth(currentMonth) };

		float numMonths{};
		float lastProduced{};
		float lastConsumed{};

		for (monthlyElectricityStats stats : lastMonths)
		{
			numMonths++;
			lastProduced += stats.produced;
			lastConsumed += stats.consumed;
		}

		currentConsumption = lastConsumed / numMonths;
		currentProduction = (lastProduced / numMonths) * (1 - ANNUAL_REDUCTION_IN_ELECTRICITY_PRODUCTION);

		// Add estimate to data
		data.emplace_back(currentYear, currentMonth, currentConsumption, currentProduction,
			currentElectricityPrice, currentElectricityStoragePrice);

		// Update balance
		float changeInBalance{};
		float changeInProduction{currentProduction - currentConsumption + electricityStored};

		if (changeInProduction >= 0) {
			// If storage + production was more than consumption
			changeInBalance += currentConsumption * (currentElectricityPrice - currentElectricityStoragePrice);

			// Calculate change in electricity storage
			if (currentConsumption > currentProduction) {
				electricityStored -= currentConsumption - currentProduction;
			} else if (currentConsumption < currentProduction) {
				electricityStored += currentProduction - currentConsumption;
			}
		} else if (changeInProduction < 0) {
			// If storage + production was less than consumption
			changeInBalance += (currentProduction + electricityStored) * (currentElectricityPrice - currentElectricityStoragePrice);
			changeInBalance -= -(changeInProduction) * currentElectricityPrice;
			electricityStored = 0;
		}

		balance += changeInBalance;
		balanceWithReimbursement += changeInBalance;

		// Displaying data
		printStats(currentYear, currentMonth, currentConsumption,currentProduction,
			currentElectricityPrice,currentElectricityStoragePrice, balance, balanceWithReimbursement);

		// Increment month
		if (currentMonth == 11)
		{
			currentMonth = 0;
			currentYear++;
			balance -= ANNUAL_SERVICE_COST_PER_KW_IN_EUR;
			balanceWithReimbursement -= ANNUAL_SERVICE_COST_PER_KW_IN_EUR;
		}
		else
		{
			currentMonth++;
		}
	} while (!isTargetReached);
	return 0;
}
