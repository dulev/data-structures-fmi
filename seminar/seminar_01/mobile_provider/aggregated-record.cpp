#include <iostream>

using std::string;
using std::ostream;

class AggregatedRecord {
private:
    string date;
    int amount;

public:
    AggregatedRecord(const string& date = "", int amount = 0)
        : date(date), amount(amount) {}

    string getDate() const {
        return date;
    }

    void addAmount(int seconds) {
        amount += seconds;
    }

    friend ostream& operator<<(ostream& os, const AggregatedRecord& ar) {
        return os << "On " << ar.date << " you talked for " << ar.amount;
    }
};