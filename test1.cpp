#include <iostream>
#include <vector>

std::vector<int> chocolatesSold(const std::vector<std::pair<int, int>>& operations) {
    std::vector<int> result;
    std::vector<int> stack;

    for (const auto& operation : operations) {
        if (operation.first == 1) {
            // Sell a box of chocolates
            if (!stack.empty()) {
                result.push_back(stack.back());
                stack.pop_back();
            } else {
                result.push_back(-1); // Indicates no chocolates to sell
            }
        } else if (operation.first == 2) {
            // Receive a box of chocolates
            stack.push_back(operation.second);
        }
    }

    return result;
}

int main() {
    // Example usage:
    std::vector<std::pair<int, int>> operations = {{2, 5}, {2, 3}, {1, 0}, {2, 7}, {1, 0}};
    std::vector<int> result = chocolatesSold(operations);

    for (int soldChocolates : result) {
        if (soldChocolates == -1) {
            std::cout << "No chocolates to sell\n";
        } else {
            std::cout << "Sold box with " << soldChocolates << " chocolates\n";
        }
    }

    return 0;
}
