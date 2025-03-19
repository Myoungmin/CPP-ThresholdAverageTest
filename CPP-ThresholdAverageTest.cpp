#include <iostream>
#include <deque>
#include <cmath>
#include <numeric>

const size_t MAX_SIZE = 2;
std::deque<double> values;

void printValues() {
    std::cout << "Current values: ";
    for (double v : values) {
        std::cout << v << " ";
    }
    std::cout << std::endl;
    std::cout << "*********************" << std::endl;
}

void addValue(double value) {
    if (values.size() >= MAX_SIZE) {
        values.pop_front(); // 가장 오래된 값 제거
    }

    values.push_back(value);
    printValues();

    if (values.size() == 2) {
        double first = values.front();
        double second = values.back();

        double diff = std::abs(second - first);
        double threshold = std::min(first, second) * 0.2; // 더 작은 값 기준으로 threshold 계산

        if (diff > threshold) {
            std::cout << "Difference too large! first value pop." << std::endl;
            values.clear();
            values.push_back(second);
            printValues();
            return;
        }

        //double avg = (first + second) / 2.0;
        double avg = std::accumulate(values.begin(), values.end(), 0.0) / values.size();
        std::cout << "Average: " << avg << std::endl;

        values.clear();
        printValues();
    }
}

int main() {
    addValue(100);
    addValue(110);

    addValue(120);
    addValue(100);
    
    addValue(100);
    addValue(130);
    addValue(90);
    addValue(100);

    return 0;
}
