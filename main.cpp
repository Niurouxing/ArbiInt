
#include "utils.h"
#include <cassert>
#include <sys/types.h>

// string multiplication, used to test the correctness of the multiplication
// operator
std::string string_multiply(const std::string &a, const std::string &b)
{
    bool is_negative = (a[0] == '-') ^ (b[0] == '-');
    std::string a_abs = (a[0] == '-') ? a.substr(1) : a;
    std::string b_abs = (b[0] == '-') ? b.substr(1) : b;

    std::string result;
    result.resize(a_abs.size() + b_abs.size(), '0');

    for (size_t i = 0; i < a_abs.size(); ++i)
    {
        int carry = 0;
        for (size_t j = 0; j < b_abs.size(); ++j)
        {
            int product = (a_abs[a_abs.size() - 1 - i] - '0') *
                              (b_abs[b_abs.size() - 1 - j] - '0') +
                          carry + (result[result.size() - 1 - i - j] - '0');
            result[result.size() - 1 - i - j] = product % 10 + '0';
            carry = product / 10;
        }
        result[result.size() - 1 - i - b_abs.size()] = carry + '0';
    }

    // Remove leading zeros
    size_t start = result.find_first_not_of('0');
    if (start == std::string::npos)
    {
        return "0";
    }
    else
    {
        result = result.substr(start);
    }

    return is_negative ? "-" + result : result;
}


bool isNegative(const std::string& num) {
    return num[0] == '-';
}

int absCompare(const std::string& lhs, const std::string& rhs) {
    if (lhs.size() > rhs.size()) return 1;
    if (lhs.size() < rhs.size()) return -1;
    for (size_t i = 0; i < lhs.size(); ++i) {
        if (lhs[i] > rhs[i]) return 1;
        if (lhs[i] < rhs[i]) return -1;
    }
    return 0;
}

bool lessThan(const std::string& lhs, const std::string& rhs) {
    bool negL = isNegative(lhs), negR = isNegative(rhs);
    if (negL && !negR) return true;
    if (!negL && negR) return false;

    int cmp = absCompare(negL ? lhs.substr(1) : lhs, 
                         negR ? rhs.substr(1) : rhs);

    return (negL) ? (cmp > 0) : (cmp < 0);
}

bool greaterThan(const std::string& lhs, const std::string& rhs) {
    return !lessThan(lhs, rhs) && lhs != rhs;
}

bool lessThanOrEqual(const std::string& lhs, const std::string& rhs) {
    return lessThan(lhs, rhs) || lhs == rhs;
}

bool greaterThanOrEqual(const std::string& lhs, const std::string& rhs) {
    return !lessThan(lhs, rhs);
}

int main()
{

 
    // {
    //     std::vector<std::string> test_case = {
    //         "0",
    //         "1",
    //         "-1",
    //         "123456789",
    //         "-123456789",
    //         "123456789123456789",
    //         "-123456789123456789",

    //     };

    //     for (const auto &a_str : test_case)
    //     {
    //         for (const auto &b_str : test_case)
    //         {
    //             ArbiInt<64> a = a_str;
    //             ArbiInt<184> b = b_str;

    //             auto c = a >= b;
          

    //             std::cout << a.toString() << " >= " << b.toString() << " = " << c <<  " Expected: " << (greaterThanOrEqual(a_str, b_str)) << std::endl;
    //             assert(c == (greaterThanOrEqual(a_str, b_str)));
                 
   
 
    //         }
    //     }
    // }

 
    ArbiInt<400> a;

    a.display();

    ArbiInt<200> b = -1;

    b.display();

    a = b;

    a.display();


    //   return 0;
}
