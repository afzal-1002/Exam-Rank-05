#include "bigint.hpp"
#include <sstream>

// ---------------------- Helper ----------------------
void bigint::trim() {
    while (digits.size() > 1 && digits[0] == 0)
        digits.erase(digits.begin());
}

// ---------------------- Constructors ----------------------
bigint::bigint() : digits(1, 0) {}

bigint::bigint(unsigned int n) {
    if (n == 0) {
        digits.push_back(0);
        return;
    }

    while (n > 0) {
        digits.insert(digits.begin(), n % 10);
        n /= 10;
    }
}

bigint::bigint(const bigint& other) : digits(other.digits) {}

// ---------------------- Assignment ----------------------
bigint& bigint::operator=(const bigint& other) {
    if (this != &other)
        digits = other.digits;
    return *this;
}

// ---------------------- Printing ----------------------
std::string bigint::toString() const {
    std::string s;
    for (int d : digits)
        s += std::to_string(d);
    return s;
}

std::ostream& operator<<(std::ostream& os, const bigint& n) {
    os << n.toString();
    return os;
}

// ---------------------- Addition ----------------------
bigint bigint::operator+(const bigint& other) const {
    bigint result;
    result.digits.clear();

    int carry = 0;
    int i = digits.size() - 1;
    int j = other.digits.size() - 1;

    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += digits[i--];
        if (j >= 0) sum += other.digits[j--];
        result.digits.insert(result.digits.begin(), sum % 10);
        carry = sum / 10;
    }

    return result;
}

bigint& bigint::operator+=(const bigint& other) {
    *this = *this + other;
    return *this;
}

// ---------------------- Increment ----------------------
bigint& bigint::operator++() {
    *this += bigint(1);
    return *this;
}

bigint bigint::operator++(int) {
    bigint temp = *this;
    ++(*this);
    return temp;
}

// ---------------------- Digit Shifts ----------------------
bigint bigint::operator<<(unsigned int n) const {
    if (*this == bigint(0)) return *this;
    bigint result = *this;
    for (unsigned int i = 0; i < n; ++i)
        result.digits.push_back(0);
    return result;
}

bigint bigint::operator>>(unsigned int n) const {
    if (n >= digits.size()) return bigint(0);
    bigint result = *this;
    result.digits.erase(result.digits.end() - n, result.digits.end());
    result.trim();
    return result;
}

bigint& bigint::operator<<=(unsigned int n) {
    *this = *this << n;
    return *this;
}

bigint& bigint::operator>>=(unsigned int n) {
    *this = *this >> n;
    return *this;
}

// ---------------------- Comparisons ----------------------
bool bigint::operator==(const bigint& other) const {
    return digits == other.digits;
}

bool bigint::operator!=(const bigint& other) const {
    return !(*this == other);
}

bool bigint::operator<(const bigint& other) const {
    if (digits.size() != other.digits.size())
        return digits.size() < other.digits.size();

    for (size_t i = 0; i < digits.size(); ++i) {
        if (digits[i] != other.digits[i])
            return digits[i] < other.digits[i];
    }
    return false;
}

bool bigint::operator>(const bigint& other) const {
    return other < *this;
}

bool bigint::operator<=(const bigint& other) const {
    return !(*this > other);
}

bool bigint::operator>=(const bigint& other) const {
    return !(*this < other);
}
