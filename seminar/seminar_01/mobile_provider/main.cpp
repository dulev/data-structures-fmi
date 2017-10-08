#include <iostream>
#include <string>

#include "./statement-aggregator.cpp"
#include "./aggregated-record.cpp"

using std::cout;
using std::string;

int main() {
    string filename = "./call-data.csv"
    StatementAggregator sa = StatementAggregator(filename);
    AggregatedRecord ar;
    sa >> ar;

    while (sa) {
        cout << ar;
        sa >> ar;
    }

    return 0;
}