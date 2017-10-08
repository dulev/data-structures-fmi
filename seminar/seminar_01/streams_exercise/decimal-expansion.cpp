class DecimalExpansion {
private:
    int numer;
    int denom;
    int remainder;

public:
    DecimalExpansion(int numer, int denom) 
        : numer(numer), denom(denom), remainder(numer) {}

    DecimalExpansion& operator>>(int& digit) {
        digit = (10 * remainder) / denom;
        remainder = (10 * remainder) % denom;
        return *this;
    }    
};

