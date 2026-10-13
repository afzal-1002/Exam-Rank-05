bigint bigint::operator+(const bigint &other) const
{
    int carry = 0;
    int i = static_cast<int>(_string.size()) - 1;
    int j = static_cast<int>(other._string.size()) - 1;

    std::string result;

    // Add digits from right to left
    while (i >= 0 || j >= 0 || carry > 0)
    {
        int x = 0;
        if (i >= 0)
        {
            x = _string[i] - '0';
            --i;
        }

        int y = 0;
        if (j >= 0)
        {
            y = other._string[j] - '0';
            --j;
        }

        int sum = x + y + carry;
        carry = sum / 10;
        result.push_back((sum % 10) + '0');
    }

    // Reverse to get correct order
    std::reverse(result.begin(), result.end());

    // Create a new bigint using default constructor
    bigint temp;
    temp._string = result;  // assign result directly to internal string

    return temp;  // returned by value
}