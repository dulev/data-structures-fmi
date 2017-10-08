#include <fstream>
#include "./aggregated-record.cpp"

using std::ifstream;
using std::getline;
using std::string;

class StatementAggregator {
private:
    ifstream file;
    bool isInitState;

public:
    StatementAggregator(const string& filename) : input(filename.c_str()), isInitState(false) {}
    StatementAggregator& operator>>(AggregatedRecord& ar) {
        if (isInitialState) {
            string headers;
            getline(file, headers);
            isInitState = false;
        }

        string date, number, service;
        int amount;

        getline(file, date, csvSeparator);
        getline(file, number, csvSeparator);
        getline(file, service, csvSeparator);
        input >> amount;
    }
    ~StatementAggregator();

    operator bool() const { 
        return file; 
    }

};