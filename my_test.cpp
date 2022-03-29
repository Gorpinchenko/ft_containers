#include <vector.hpp>
#include <stack.hpp>
#include <map.hpp>
#include <set.hpp>
#include <iostream>

#include <vector>
#include <list>
#include <stack>
#include <map>
#include <set>

#define red "\033[0;31m"
#define green "\033[0;32m"
#define blue "\033[0;34m"
#define magenta "\033[0;35m"
#define back_red "\033[0;41m"
#define back_green "\033[0;42m"
#define back_blue "\033[0;44m"
#define back_white "\033[0;47m"
#define reset "\033[0m"


class testClass {

public:

    testClass() {
        _val = 0;
        ptr  = new int(1);
    }

    testClass(int size) {
        _val = size;
        ptr  = new int(1);
    }

    ~testClass() {
        delete ptr;
    }

    testClass(testClass const &src) {
        _val = src._val;
        ptr  = new int(1);
    }

    testClass &operator=(testClass const &rhs) {
        if (this == &rhs) {
            return *this;
        }
        _val = rhs._val;
        return *this;
    }

    friend bool operator<(testClass const &lhs, testClass const &rhs) {
        return (lhs._val < rhs._val);
    }

    friend bool operator>(testClass const &lhs, testClass const &rhs) {
        return (lhs._val > rhs._val);
    }

    friend bool operator<=(testClass const &lhs, testClass const &rhs) {
        return (lhs._val <= rhs._val);
    }

    friend bool operator>=(testClass const &lhs, testClass const &rhs) {
        return (lhs._val >= rhs._val);
    }

    friend bool operator==(testClass const &lhs, testClass const &rhs) {
        return (lhs._val == rhs._val);
    }

    friend bool operator!=(testClass const &lhs, testClass const &rhs) {
        return (lhs._val != rhs._val);
    }

    int getVal() const { return _val; }

private:

    int _val;
    int *ptr;

};

std::ostream &operator<<(std::ostream &os, testClass const &rhs) {
    os << "t_" << rhs.getVal();
    return os;
}


int main() {

    std::cout << std::boolalpha;
    std::cout << std::endl;

    std::cout << red << "VECTOR" << reset << std::endl << std::endl;

    std::cout << "01_____________________________________________" << std::endl;

    std::cout << blue << "parameter constructor, begin(), end(), [], iterator arithmetics:" << reset << std::endl;
    std::cout << "creating ft::vector<double>=(6, 3)" << std::endl;
    ft::vector<double> f_vec_a1(6, 3);
    std::cout << "assighing f_vec_a1[0] - f_vec_a1[5] values: 5, 6, 7, 8, 9" << std::endl;
    f_vec_a1[1] = 5;
    f_vec_a1[2] = 6;
    f_vec_a1[3] = 7;
    f_vec_a1[4] = 8;
    f_vec_a1[5] = 9;
    std::cout << "printing ft::vector<double> f_vec_a1: from begin() to end():" << std::endl;
    int i = 0;

    for (ft::vector<double>::iterator    it           = f_vec_a1.begin(); it != f_vec_a1.end(); ++it, ++i) {
        std::cout << "[" << i << "]=" << f_vec_a1[i] << std::endl;
    }
    ft::vector<double>::iterator         it_f_vec_01  = f_vec_a1.begin();
    ft::vector<double>::iterator         it_f_vec_02  = f_vec_a1.end();
    ft::vector<double>::reverse_iterator it_f_vec_r01 = f_vec_a1.rbegin();
    ft::vector<double>::reverse_iterator it_f_vec_r02 = f_vec_a1.rend();

    std::cout << std::endl << "ft::vector<double> iterator arithmetic:" << std::endl;
    std::cout << "0. f_vec_a1.begin() => *it_f_vec_01 = " << *it_f_vec_01 << std::endl;
    std::cout << "1. f_vec_a1.end() => *(--it_f_vec_02) = " << *(--it_f_vec_02) << std::endl;
    std::cout << "2. *(++it_f_vec_01) = " << *(++it_f_vec_01) << std::endl;
    std::cout << "3. *it_f_vec_01 = " << *it_f_vec_01 << std::endl;
    std::cout << "4. *(it_f_vec_01++) = " << *(it_f_vec_01++) << std::endl;
    std::cout << "5. *it_f_vec_01 = " << *it_f_vec_01 << std::endl;
    std::cout << "6. *(it_f_vec_01 - 1) = " << *(it_f_vec_01 - 1) << std::endl;
    std::cout << "7. *it_f_vec_01 = " << *it_f_vec_01 << std::endl;
    it_f_vec_01 += 1;
    std::cout << "8. *(it_f_vec_01 += 1) = " << *(it_f_vec_01) << std::endl;
    std::cout << "9. (it_f_vec_01 - it_f_vec_02) = " << (it_f_vec_01 - it_f_vec_02) << std::endl;
    std::cout << "10. it_f_vec_01[1] = " << it_f_vec_01[1] << std::endl;
    std::cout << "11. *it_f_vec_01 = " << *it_f_vec_01 << std::endl;
    it_f_vec_01 = 2 + it_f_vec_01;
    std::cout << "12. *(it_f_vec_01 = 2 + it_f_vec_01) = " << *it_f_vec_01 << std::endl;

    std::cout << std::endl << "ft::vector<double> reverse iterator arithmetic:" << std::endl;
    std::cout << "0. f_vec_a1.begin() => *it_f_vec_r01 = " << *it_f_vec_r01 << std::endl;
    std::cout << "1. f_vec_ra1.end() => *(--it_f_vec_r02) = " << *(--it_f_vec_r02) << std::endl;
    std::cout << "2. *(++it_f_vec_r01) = " << *(++it_f_vec_r01) << std::endl;
    std::cout << "3. *it_f_vec_r01 = " << *it_f_vec_r01 << std::endl;
    std::cout << "4. *(it_f_vec_r01++) = " << *(it_f_vec_r01++) << std::endl;
    std::cout << "5. *it_f_vec_r01 = " << *it_f_vec_r01 << std::endl;
    std::cout << "6. *(it_f_vec_r01 - 1) = " << *(it_f_vec_r01 - 1) << std::endl;
    std::cout << "7. *it_f_vec_r01 = " << *it_f_vec_r01 << std::endl;
    it_f_vec_r01 += 1;
    std::cout << "8. *(it_f_vec_r01 += 1) = " << *(it_f_vec_r01) << std::endl;
    std::cout << "9. (it_f_vec_r01 - it_f_vec_r02) = " << (it_f_vec_r01 - it_f_vec_r02) << std::endl;
    std::cout << "10. it_f_vec_r01[1] = " << it_f_vec_r01[1] << std::endl;
    std::cout << "11. *it_f_vec_r01 = " << *it_f_vec_r01 << std::endl;
    it_f_vec_r01 = 2 + it_f_vec_r01;
    std::cout << "12. *(it_f_vec_r01 = 2 + it_f_vec_r01) = " << *it_f_vec_r01 << std::endl;
    std::cout << std::endl;


    std::cout << "02_____________________________________________" << std::endl;
    std::cout << blue << "ft::vector<testClass> vec_b1(3, testClass(2)):" << reset << std::endl;

    ft::vector <testClass>          f_vec_b1(3, testClass(2));
    ft::vector<testClass>::iterator it_f_vec_03;
    it_f_vec_03                                   = f_vec_b1.begin();
    while (it_f_vec_03 != f_vec_b1.end()) {
        std::cout << "*(it_f_vec_03++)=" << *it_f_vec_03 << std::endl;
        it_f_vec_03++;
    }
    std::cout << std::endl;

    std::cout << "03_____________________________________________" << std::endl;
    std::cout << blue << "constant and nonconst vector iterators comparison" << reset << std::endl;

    std::cout << "ft and std vector<int> (4, 1)" << std::endl;
    ft::vector<int>                 f_vec_c1(4, 1);
    ft::vector<int>::iterator       it_f_vec_04   = f_vec_c1.begin();
    ft::vector<int>::const_iterator it_fc_vec_04  = f_vec_c1.begin();

    std::vector<int>                 s_vec_c1(4, 1);
    std::vector<int>::iterator       it_s_vec_04  = s_vec_c1.begin();
    std::vector<int>::const_iterator it_sc_vec_04 = s_vec_c1.begin();

    std::cout << "std iterators: nonconst iterator == const iterator: " << (it_s_vec_04 == it_sc_vec_04) << std::endl;
    std::cout << "ft  iterators: nonconst iterator == const iterator: " << (it_f_vec_04 == it_fc_vec_04) << std::endl;

    ft::vector<int>::reverse_iterator       it_fr_vec_05  = f_vec_c1.rbegin();
    ft::vector<int>::const_reverse_iterator it_frc_vec_05 = f_vec_c1.rbegin();

    std::vector<int>::reverse_iterator       it_sr_vec_05  = s_vec_c1.rbegin();
    std::vector<int>::const_reverse_iterator it_src_vec_05 = s_vec_c1.rbegin();

    std::cout << "std reverse iterators: nonconst iterator == const iterator: " << (it_sr_vec_05 == it_src_vec_05)
              << std::endl;
    std::cout << "ft  reverse iterators: nonconst iterator == const iterator: " << (it_fr_vec_05 == it_frc_vec_05)
              << std::endl;
    std::cout << std::endl;

    std::cout << "04_____________________________________________" << std::endl;
    std::cout << blue << "ft::vector constructor from iterators:" << reset << std::endl;
    std::cout << "std::vector<int> s_vec_d1(5, 3)" << std::endl;
    std::vector<int> s_vec_d1(5, 3);
    std::cout << "constructing ft vector with iterators from std vector s_vec_d1" << std::endl;
    std::cout << "new ft vector f_vec_d1:" << std::endl;
    ft::vector<int>                f_vec_d1(s_vec_d1.begin(), s_vec_d1.end());
    for (ft::vector<int>::iterator i                       = f_vec_d1.begin(); i != f_vec_d1.end(); ++i) {
        std::cout << "*i=" << *i << std::endl;
    }
    std::cout << "std vector capacity=" << s_vec_d1.capacity() << std::endl;
    std::cout << "ft vector capacity=" << f_vec_d1.capacity() << std::endl;
    std::cout << std::endl;

    std::cout << blue << "ft::vector copy constructor:" << reset << std::endl;
    std::cout << "constructing ft vector with copy constructor from ft vector f_vec_d1" << std::endl;
    ft::vector<int> ft_vec_copy(f_vec_d1);
    std::cout << "new ft vector ft_vec_copy:" << std::endl;
    for (ft::vector<int>::iterator i = ft_vec_copy.begin(); i != ft_vec_copy.end(); ++i) {
        std::cout << "*i=" << *i << std::endl;
    }
    std::cout << "ft_vec_copy.capacity=" << ft_vec_copy.capacity() << std::endl;
    std::cout << std::endl;

    std::cout << "05_____________________________________________" << std::endl;
    std::cout << blue << "assignment overload" << reset << std::endl;

    std::cout << "std s_vec_e1(2, testClass(1)) and s_vec_e2(3, testClass(2))" << std::endl;
    std::vector<testClass> s_vec_e1(2, testClass(1));
    std::vector<testClass> s_vec_e2(3, testClass(2));
    std::cout << "s_vec_e1:" << std::endl;
    for (std::vector<testClass>::iterator i = s_vec_e1.begin(); i != s_vec_e1.end(); ++i) {
        std::cout << "*(i++)=" << *i << std::endl;
    }
    std::cout << "s_vec_e1.capacity=" << s_vec_e1.capacity() << std::endl;
    std::cout << "s_vec_e1.size=" << s_vec_e1.size() << std::endl;
    std::cout << "s_vec_e1 after s_vec_e1 = s_vec_e2:" << std::endl;
    s_vec_e1 = s_vec_e2;
    for (std::vector<testClass>::iterator i = s_vec_e1.begin(); i != s_vec_e1.end(); ++i) {
        std::cout << "*(i++)=" << *i << std::endl;
    }
    std::cout << "s_vec_e1.capacity=" << s_vec_e1.capacity() << std::endl;
    std::cout << "s_vec_e1.size=" << s_vec_e1.size() << std::endl;
    std::cout << std::endl;

    std::cout << "ft f_vec_e1(2, testClass(1)) and f_vec_e2(3, testClass(2))" << std::endl;
    ft::vector <testClass> f_vec_e1(2, testClass(1));
    ft::vector <testClass> f_vec_e2(3, testClass(2));
    std::cout << "f_vec_e1:" << std::endl;
    for (ft::vector<testClass>::iterator i = f_vec_e1.begin(); i != f_vec_e1.end(); ++i) {
        std::cout << "*(i++)=" << *i << std::endl;
    }
    std::cout << "f_vec_e1.capacity=" << f_vec_e1.capacity() << std::endl;
    std::cout << "f_vec_e1.size=" << f_vec_e1.size() << std::endl;
    std::cout << "f_vec_e1 after f_vec_e1 = f_vec_e2:" << std::endl;
    f_vec_e1 = f_vec_e2;
    for (ft::vector<testClass>::iterator i  = f_vec_e1.begin(); i != f_vec_e1.end(); ++i) {
        std::cout << "*(i++)=" << *i << std::endl;
    }
    std::cout << "f_vec_e1.capacity=" << f_vec_e1.capacity() << std::endl;
    std::cout << "f_vec_e1.size=" << f_vec_e1.size() << std::endl;
    std::cout << std::endl;

    std::cout << "06_____________________________________________" << std::endl;
    std::cout << blue << "vector comprising operators: ==/!=/>/>=/</<=  " << reset << std::endl;

    std::cout << "std vector s_vec_f1(2, 10):" << std::endl;
    std::vector<int>                s_vec_f1(2, 10);
    for (std::vector<int>::iterator i       = s_vec_f1.begin(); i != s_vec_f1.end(); ++i) {
        std::cout << "*(s_vec_f1++) = " << *i << std::endl;
    }
    std::cout << std::endl;
    std::cout << "std vector const s_vec_f2(2, 10):" << std::endl;
    const std::vector<int>                s_vec_f2(2, 10);
    for (std::vector<int>::const_iterator i = s_vec_f2.begin(); i != s_vec_f2.end(); ++i) {
        std::cout << "*(s_vec_f2++) = " << *i << std::endl;
    }
    std::cout << std::endl;
    std::cout << "s_vec_f1 == s_vec_f2: " << (s_vec_f1 == s_vec_f2) << std::endl;
    std::cout << "s_vec_f1 >= s_vec_f2: " << (s_vec_f1 >= s_vec_f2) << std::endl;
    std::cout << "s_vec_f1 <= s_vec_f2: " << (s_vec_f1 <= s_vec_f2) << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "ft vector f_vec_f1(2, 10):" << std::endl;
    ft::vector<int>                f_vec_f1(2, 10);
    for (ft::vector<int>::iterator i        = f_vec_f1.begin(); i != f_vec_f1.end(); ++i) {
        std::cout << "*(f_vec_f1++) = " << *i << std::endl;
    }
    std::cout << std::endl;
    std::cout << "ft vector const f_vec_f2(2, 10):" << std::endl;
    const ft::vector<int>                f_vec_f2(2, 10);
    for (ft::vector<int>::const_iterator i  = f_vec_f2.begin(); i != f_vec_f2.end(); ++i) {
        std::cout << "*(f_vec_f2++) = " << *i << std::endl;
    }
    std::cout << std::endl;
    std::cout << "f_vec_f1 == f_vec_f2: " << (f_vec_f1 == f_vec_f2) << std::endl;
    std::cout << "f_vec_f1 >= f_vec_f2: " << (f_vec_f1 >= f_vec_f2) << std::endl;
    std::cout << "f_vec_f1 <= f_vec_f2: " << (f_vec_f1 <= f_vec_f2) << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "std vector s_vec_f3(3, 111):" << std::endl;
    std::vector<int>                s_vec_f3(3, 11);
    for (std::vector<int>::iterator i       = s_vec_f3.begin(); i != s_vec_f3.end(); ++i) {
        std::cout << "*(s_vec_f3++) = " << *i << std::endl;
    }
    std::cout << std::endl;
    std::cout << "std vector const s_vec_f4(2, 11):" << std::endl;
    const std::vector<int>                s_vec_f4(2, 11);
    for (std::vector<int>::const_iterator i = s_vec_f4.begin(); i != s_vec_f4.end(); ++i) {
        std::cout << "*(s_vec_f4++) = " << *i << std::endl;
    }
    std::cout << std::endl;
    std::cout << "s_vec_f3 == s_vec_f4: " << (s_vec_f3 == s_vec_f4) << std::endl;
    std::cout << "s_vec_f3 > s_vec_f4: " << (s_vec_f3 > s_vec_f4) << std::endl;
    std::cout << "s_vec_f3 < s_vec_f4: " << (s_vec_f3 < s_vec_f4) << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "ft vector f_vec_f3(3, 11):" << std::endl;
    ft::vector<int>                f_vec_f3(3, 11);
    for (ft::vector<int>::iterator i        = f_vec_f3.begin(); i != f_vec_f3.end(); ++i) {
        std::cout << "*(f_vec_f3++) = " << *i << std::endl;
    }
    std::cout << std::endl;
    std::cout << "ft vector const f_vec_f4(2, 11):" << std::endl;
    const ft::vector<int>                f_vec_f4(2, 11);
    for (ft::vector<int>::const_iterator i  = f_vec_f4.begin(); i != f_vec_f4.end(); ++i) {
        std::cout << "*(f_vec_f4++) = " << *i << std::endl;
    }
    std::cout << std::endl;
    std::cout << "f_vec_f3 == f_vec_f4: " << (f_vec_f3 == f_vec_f4) << std::endl;
    std::cout << "f_vec_f3 > f_vec_f4: " << (f_vec_f3 > f_vec_f4) << std::endl;
    std::cout << "f_vec_f3 < f_vec_f4: " << (f_vec_f3 < f_vec_f4) << std::endl;
    std::cout << std::endl;

    std::cout << "07_____________________________________________" << std::endl;
    std::cout << blue << "erase()" << reset << std::endl;

    std::cout << "std::vector<testClass> s_vec_g1 = {0, 1, 2, 3, 4}" << std::endl;
    std::vector<testClass> s_vec_g1(5, testClass(0));
    s_vec_g1[1] = 1;
    s_vec_g1[2] = 2;
    s_vec_g1[3] = 3;
    s_vec_g1[4] = 4;
    std::cout << "after s_vec_g1.erase(s_vec_g1.begin() + 1, s_vec_g1.begin() + 3):" << std::endl;
    s_vec_g1.erase(s_vec_g1.begin() + 1, s_vec_g1.begin() + 3);
    for (std::vector<testClass>::iterator i = s_vec_g1.begin(); i != s_vec_g1.end(); ++i) {
        std::cout << "*(i++)=" << *i << std::endl;
    }
    std::cout << "s_vec_g1.capacity=" << s_vec_g1.capacity() << std::endl;
    std::cout << "s_vec_g1.size=" << s_vec_g1.size() << std::endl;
    std::cout << std::endl;

    std::cout << "ft::vector<testClass> f_vec_g1 = {0, 1, 2, 3, 4}" << std::endl;
    ft::vector <testClass> f_vec_g1(5, testClass(0));
    f_vec_g1[1] = 1;
    f_vec_g1[2] = 2;
    f_vec_g1[3] = 3;
    f_vec_g1[4] = 4;
    std::cout << "after f_vec_g1.erase(f_vec_g1.begin() + 1, f_vec_g1.begin() + 3):" << std::endl;
    f_vec_g1.erase(f_vec_g1.begin() + 1, f_vec_g1.begin() + 3);
    for (ft::vector<testClass>::iterator i = f_vec_g1.begin(); i != f_vec_g1.end(); ++i) {
        std::cout << "*(i++)=" << *i << std::endl;
    }
    std::cout << "f_vec_g1.capacity=" << f_vec_g1.capacity() << std::endl;
    std::cout << "f_vec_g1.size=" << f_vec_g1.size() << std::endl;
    std::cout << std::endl;

    std::cout << "08_____________________________________________" << std::endl;
    std::cout << blue << "clear()" << reset << std::endl;

    std::cout << "after clear(s_vec_g1):" << std::endl;
    s_vec_g1.clear();
    for (std::vector<testClass>::iterator i = s_vec_g1.begin(); i != s_vec_g1.end(); ++i) {
        std::cout << "*(i++)=" << *i << std::endl;
    }
    std::cout << "s_vec_g1.capacity=" << s_vec_g1.capacity() << std::endl;
    std::cout << "s_vec_g1.size=" << s_vec_g1.size() << std::endl;
    std::cout << std::endl;

    std::cout << "after clear(f_vec_g1):" << std::endl;
    f_vec_g1.clear();
    for (ft::vector<testClass>::iterator i = f_vec_g1.begin(); i != f_vec_g1.end(); ++i) {
        std::cout << "*(i++)=" << *i << std::endl;
    }
    std::cout << "f_vec_g1.capacity=" << f_vec_g1.capacity() << std::endl;
    std::cout << "f_vec_g1.size=" << f_vec_g1.size() << std::endl;
    std::cout << std::endl;

    std::cout << "09_____________________________________________" << std::endl;
    std::cout << blue << "empty()" << reset << std::endl;

    std::cout << "s_vec_g1.empty():" << s_vec_g1.empty() << std::endl;
    std::cout << "f_vec_g1.empty():" << f_vec_g1.empty() << std::endl;
    std::cout << std::endl;

    std::cout << "10_____________________________________________" << std::endl;
    std::cout << blue << "max_size()" << reset << std::endl;

    std::cout << "s_vec_g1.max_size():" << s_vec_g1.max_size() << std::endl;
    std::cout << "f_vec_g1.max_size():" << f_vec_g1.max_size() << std::endl;
    std::cout << std::endl;

    std::cout << "11_____________________________________________" << std::endl;
    std::cout << blue << "reserve()" << reset << std::endl;

    std::cout << "s_vec_h1(5, testClass(1)):" << std::endl;
    std::vector<testClass> s_vec_h1(5, testClass(1));
    std::cout << "s_vec_h1.capacity=" << s_vec_h1.capacity() << std::endl;
    std::cout << "s_vec_h1.size=" << s_vec_h1.size() << std::endl;
    std::cout << std::endl;

    std::cout << "after s_vec_h1.reserve(8):" << std::endl;
    s_vec_h1.reserve(8);
    for (std::vector<testClass>::iterator i = s_vec_h1.begin(); i != s_vec_h1.end(); ++i) {
        std::cout << "*(i++)=" << *i << std::endl;
    }
    std::cout << "s_vec_h1.capacity=" << s_vec_h1.capacity() << std::endl;
    std::cout << "s_vec_h1.size=" << s_vec_h1.size() << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "f_vec_h1(5, testClass(1)):" << std::endl;
    ft::vector <testClass> f_vec_h1(5, testClass(1));
    std::cout << "f_vec_h1.capacity=" << f_vec_h1.capacity() << std::endl;
    std::cout << "f_vec_h1.size=" << f_vec_h1.size() << std::endl;
    std::cout << std::endl;

    std::cout << "after f_vec_h1.reserve(8):" << std::endl;
    f_vec_h1.reserve(8);
    for (ft::vector<testClass>::iterator i = f_vec_h1.begin();
         i != f_vec_h1.end(); ++i) {
        std::cout << "*(i++)=" << *i << std::endl;
    }
    std::cout << "f_vec_h1.capacity=" << f_vec_h1.capacity() << std::endl;
    std::cout << "f_vec_h1.size=" << f_vec_h1.size() << std::endl;
    std::cout << std::endl;

    std::cout << "12_____________________________________________" << std::endl;
    std::cout << blue << "resize()" << reset << std::endl;

    std::cout << "after s_vec_h1.resize(9):" << std::endl;
    s_vec_h1.resize(9);
    for (std::vector<testClass>::iterator i = s_vec_h1.begin();
         i != s_vec_h1.end(); ++i) {
        std::cout << "*(i++)=" << *i << std::endl;
    }
    std::cout << "s_vec_h1.capacity=" << s_vec_h1.capacity() << std::endl;
    std::cout << "s_vec_h1.size=" << s_vec_h1.size() << std::endl;
    std::cout << std::endl;

    std::cout << "after f_vec_h1.resize(9):" << std::endl;
    f_vec_h1.resize(9);
    for (ft::vector<testClass>::iterator i  = f_vec_h1.begin();
         i != f_vec_h1.end(); ++i) {
        std::cout << "*(i++)=" << *i << std::endl;
    }
    std::cout << "f_vec_h1.capacity=" << f_vec_h1.capacity() << std::endl;
    std::cout << "f_vec_h1.size=" << f_vec_h1.size() << std::endl;
    std::cout << std::endl;

    std::cout << "13_____________________________________________" << std::endl;
    std::cout << blue << "front()" << reset << std::endl;

    std::cout << "std vector s_vec_i1(1, testClass(1)) and ft vector f_vec_i1(1, testClass(1))" << std::endl;
    const std::vector<testClass> s_vec_i1(1, testClass(1));
    const ft::vector <testClass> f_vec_i1(1, testClass(1));
    std::cout << "s_vec_i1.front(): " << s_vec_i1.front() << std::endl;
    std::cout << "f_vec_i1.front(): " << f_vec_i1.front() << std::endl;
    std::cout << std::endl;

    std::cout << "14_____________________________________________" << std::endl;
    std::cout << blue << "pop_back()" << reset << std::endl;

    std::cout << "std vector s_vec_j1(2, testClass(1)):" << std::endl;
    std::vector<testClass>                s_vec_j1(2, testClass(1));
    for (std::vector<testClass>::iterator i = s_vec_j1.begin(); i != s_vec_j1.end(); ++i) {
        std::cout << "*(i++)=" << *i << std::endl;
    }
    std::cout << "s_vec_j1.capacity=" << s_vec_j1.capacity() << std::endl;
    std::cout << "s_vec_j1.size=" << s_vec_j1.size() << std::endl;
    std::cout << std::endl;
    std::cout << "after s_vec_j1.pop_back():" << std::endl;
    s_vec_j1.pop_back();
    for (std::vector<testClass>::iterator i = s_vec_j1.begin(); i != s_vec_j1.end(); ++i) {
        std::cout << "*(i++)=" << *i << std::endl;
    }
    std::cout << "s_vec_j1.capacity=" << s_vec_j1.capacity() << std::endl;
    std::cout << "s_vec_j1.size=" << s_vec_j1.size() << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "ft vector f_vec_j1(2, testClass(1)):" << std::endl;
    ft::vector <testClass>               f_vec_j1(2, testClass(1));
    for (ft::vector<testClass>::iterator i  = f_vec_j1.begin(); i != f_vec_j1.end(); ++i) {
        std::cout << "*(i++)=" << *i << std::endl;
    }
    std::cout << "f_vec_j1.capacity=" << f_vec_j1.capacity() << std::endl;
    std::cout << "f_vec_j1.size=" << f_vec_j1.size() << std::endl;
    std::cout << std::endl;
    std::cout << "after f_vec_j1.pop_back():" << std::endl;
    f_vec_j1.pop_back();
    for (ft::vector<testClass>::iterator i = f_vec_j1.begin(); i != f_vec_j1.end(); ++i) {
        std::cout << "*(i++)=" << *i << std::endl;
    }
    std::cout << "f_vec_j1.capacity=" << f_vec_j1.capacity() << std::endl;
    std::cout << "f_vec_j1.size=" << f_vec_j1.size() << std::endl;
    std::cout << std::endl;

    std::cout << "15_____________________________________________" << std::endl;
    std::cout << blue << "push_back()" << reset << std::endl;

    std::cout << "after s_vec_j1.push_back(5):" << std::endl;
    s_vec_j1.push_back(5);
    for (std::vector<testClass>::iterator i = s_vec_j1.begin(); i != s_vec_j1.end(); ++i) {
        std::cout << "*(i++)=" << *i << std::endl;
    }
    std::cout << "s_vec_j1.capacity=" << s_vec_j1.capacity() << std::endl;
    std::cout << "s_vec_j1.size=" << s_vec_j1.size() << std::endl;
    std::cout << "after s_vec_j1.push_back(5):" << std::endl;
    s_vec_j1.push_back(5);
    for (std::vector<testClass>::iterator i = s_vec_j1.begin(); i != s_vec_j1.end(); ++i) {
        std::cout << "*(i++)=" << *i << std::endl;
    }
    std::cout << "s_vec_j1.capacity=" << s_vec_j1.capacity() << std::endl;
    std::cout << "s_vec_j1.size=" << s_vec_j1.size() << std::endl;
    std::cout << std::endl;

    std::cout << "after f_vec_j1.push_back(5):" << std::endl;
    f_vec_j1.push_back(5);
    for (ft::vector<testClass>::iterator i = f_vec_j1.begin(); i != f_vec_j1.end(); ++i) {
        std::cout << "*(i++)=" << *i << std::endl;
    }
    std::cout << "f_vec_j1.capacity=" << f_vec_j1.capacity() << std::endl;
    std::cout << "f_vec_j1.size=" << f_vec_j1.size() << std::endl;
    std::cout << "after f_vec_j1.push_back(5):" << std::endl;
    f_vec_j1.push_back(5);
    for (ft::vector<testClass>::iterator i  = f_vec_j1.begin(); i != f_vec_j1.end(); ++i) {
        std::cout << "*(i++)=" << *i << std::endl;
    }
    std::cout << "f_vec_j1.capacity=" << f_vec_j1.capacity() << std::endl;
    std::cout << "f_vec_j1.size=" << f_vec_j1.size() << std::endl;
    std::cout << std::endl;

    std::cout << "16_____________________________________________" << std::endl;
    std::cout << blue << "back()" << reset << std::endl;

    std::cout << "s_vec_j1.back(): " << s_vec_j1.back() << std::endl;
    std::cout << "f_vec_j1.back(): " << f_vec_j1.back() << std::endl;
    std::cout << "std vector s_vec_k1(1, testClass(1)) and ft vector f_vec_k1(1, testClass(1))" << std::endl;
    const std::vector<testClass> s_vec_k1(1, testClass(1));
    const ft::vector <testClass> f_vec_k1(1, testClass(1));
    std::cout << "s_vec_k1.back(): " << s_vec_k1.back() << std::endl;
    std::cout << "f_vec_k1.back(): " << f_vec_k1.back() << std::endl;
    std::cout << std::endl;

    std::cout << "17_____________________________________________" << std::endl;
    std::cout << blue << "insert(position, val)" << reset << std::endl;

    std::cout << "std vector s_vec_l1(2, testClass(1)):" << std::endl;
    std::vector<testClass>                s_vec_l1(2, testClass(1));
    for (std::vector<testClass>::iterator i = s_vec_l1.begin(); i != s_vec_l1.end(); ++i) {
        std::cout << "*(i++)=" << *i << std::endl;
    }
    std::cout << "s_vec_l1.capacity=" << s_vec_l1.capacity() << std::endl;
    std::cout << "s_vec_l1.size=" << s_vec_l1.size() << std::endl;
    std::cout << "after s_vec_l1.insert(1, 3):" << std::endl;
    s_vec_l1.insert(s_vec_l1.begin() + 1, 3);
    for (std::vector<testClass>::iterator i = s_vec_l1.begin(); i != s_vec_l1.end(); ++i) {
        std::cout << "*(i++)=" << *i << std::endl;
    }
    std::cout << "s_vec_l1.capacity=" << s_vec_l1.capacity() << std::endl;
    std::cout << "s_vec_l1.size=" << s_vec_l1.size() << std::endl;
    std::cout << std::endl;

    std::cout << "ft vector f_vec_l1(2, testClass(1)):" << std::endl;
    ft::vector <testClass>               f_vec_l1(2, testClass(1));
    for (ft::vector<testClass>::iterator i  = f_vec_l1.begin(); i != f_vec_l1.end(); ++i) {
        std::cout << "*(i++)=" << *i << std::endl;
    }
    std::cout << "f_vec_l1.capacity=" << f_vec_l1.capacity() << std::endl;
    std::cout << "f_vec_l1.size=" << f_vec_l1.size() << std::endl;
    std::cout << "after f_vec_l1.insert(1, 3):" << std::endl;
    f_vec_l1.insert(f_vec_l1.begin() + 1, 3);
    for (ft::vector<testClass>::iterator i  = f_vec_l1.begin(); i != f_vec_l1.end(); ++i) {
        std::cout << "*(i++)=" << *i << std::endl;
    }
    std::cout << "f_vec_l1.capacity=" << f_vec_l1.capacity() << std::endl;
    std::cout << "f_vec_l1.size=" << f_vec_l1.size() << std::endl;
    std::cout << std::endl;

    std::cout << "18_____________________________________________" << std::endl;
    std::cout << blue << "insert(position, n, val)" << reset << std::endl;

    std::cout << "std vector s_vec_m1(2, testClass(1)):" << std::endl;
    std::vector<testClass>                s_vec_m1(2, testClass(1));
    for (std::vector<testClass>::iterator i = s_vec_m1.begin(); i != s_vec_m1.end(); ++i) {
        std::cout << "*(i++)=" << *i << std::endl;
    }
    std::cout << "s_vec_m1.capacity=" << s_vec_m1.capacity() << std::endl;
    std::cout << "s_vec_m1.size=" << s_vec_m1.size() << std::endl;
    std::cout << "after s_vec_m1.insert(1, 5, 3):" << std::endl;
    s_vec_m1.insert(s_vec_m1.begin() + 1, 5, 3);
    for (std::vector<testClass>::iterator i = s_vec_m1.begin(); i != s_vec_m1.end(); ++i) {
        std::cout << "*(i++)=" << *i << std::endl;
    }
    std::cout << "s_vec_m1.capacity=" << s_vec_m1.capacity() << std::endl;
    std::cout << "s_vec_m1.size=" << s_vec_m1.size() << std::endl;
    std::cout << std::endl;

    std::cout << "ft vector f_vec_m1(2, testClass(1)):" << std::endl;
    ft::vector <testClass>               f_vec_m1(2, testClass(1));
    for (ft::vector<testClass>::iterator i  = f_vec_m1.begin(); i != f_vec_m1.end(); ++i) {
        std::cout << "*(i++)=" << *i << std::endl;
    }
    std::cout << "f_vec_m1.capacity=" << f_vec_m1.capacity() << std::endl;
    std::cout << "f_vec_m1.size=" << f_vec_m1.size() << std::endl;
    std::cout << "after f_vec_m1.insert(1, 5, 3):" << std::endl;
    f_vec_m1.insert(f_vec_m1.begin() + 1, 5, 3);
    for (ft::vector<testClass>::iterator i  = f_vec_m1.begin(); i != f_vec_m1.end(); ++i) {
        std::cout << "*(i++)=" << *i << std::endl;
    }
    std::cout << "f_vec_m1.capacity=" << f_vec_m1.capacity() << std::endl;
    std::cout << "f_vec_m1.size=" << f_vec_m1.size() << std::endl;
    std::cout << std::endl;

    std::cout << "19_____________________________________________" << std::endl;
    std::cout << blue << "insert(position, first, last)" << reset << std::endl;

    std::cout << "s_vec_n0 - inserted vector:" << std::endl;
    std::vector<testClass>                s_vec_n0(3, testClass(3));
    for (std::vector<testClass>::iterator i = s_vec_n0.begin(); i != s_vec_n0.end(); ++i) {
        std::cout << "*(i++)=" << *i << std::endl;
    }
    std::cout << "s_vec_n0.capacity=" << s_vec_n0.capacity() << std::endl;
    std::cout << "s_vec_n0.size=" << s_vec_n0.size() << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "std vector s_vec_n1(2, testClass(1)):" << std::endl;
    std::vector<testClass>                s_vec_n1(2, testClass(1));
    for (std::vector<testClass>::iterator i = s_vec_n1.begin(); i != s_vec_n1.end(); ++i) {
        std::cout << "*(i++)=" << *i << std::endl;
    }
    std::cout << "s_vec_n1.capacity=" << s_vec_n1.capacity() << std::endl;
    std::cout << "s_vec_n1.size=" << s_vec_n1.size() << std::endl;
    std::cout << std::endl;
    std::cout << "after s_vec_n1.insert(1, s_vec_n0.begin, s_vec_n0.last):" << std::endl;
    s_vec_n1.insert(s_vec_n1.begin() + 1, s_vec_n0.begin(), s_vec_n0.end());
    for (std::vector<testClass>::iterator i = s_vec_n1.begin(); i != s_vec_n1.end(); ++i) {
        std::cout << "*(i++)=" << *i << std::endl;
    }
    std::cout << "s_vec_n1.capacity=" << s_vec_n1.capacity() << std::endl;
    std::cout << "s_vec_n1.size=" << s_vec_n1.size() << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "ft vector f_vec_n1(2, testClass(1)):" << std::endl;
    ft::vector <testClass>               f_vec_n1(2, testClass(1));
    for (ft::vector<testClass>::iterator i  = f_vec_n1.begin(); i != f_vec_n1.end(); ++i) {
        std::cout << "*(i++)=" << *i << std::endl;
    }
    std::cout << "f_vec_n1.capacity=" << f_vec_n1.capacity() << std::endl;
    std::cout << "f_vec_n1.size=" << f_vec_n1.size() << std::endl;
    std::cout << std::endl;
    std::cout << "after f_vec_n1.insert(1, s_vec_n0.begin, s_vec_n0.last):" << std::endl;
    f_vec_n1.insert(f_vec_n1.begin() + 1, s_vec_n0.begin(), s_vec_n0.end());
    for (ft::vector<testClass>::iterator i  = f_vec_n1.begin(); i != f_vec_n1.end(); ++i) {
        std::cout << "*(i++)=" << *i << std::endl;
    }
    std::cout << "f_vec_n1.capacity=" << f_vec_n1.capacity() << std::endl;
    std::cout << "f_vec_n1.size=" << f_vec_n1.size() << std::endl;
    std::cout << std::endl;

    std::cout << "20_____________________________________________" << std::endl;
    std::cout << blue << "assign(n, val)" << reset << std::endl;

    std::cout << "std vector s_vec_o1(2, testClass(1)):" << std::endl;
    std::vector<testClass>                s_vec_o1(2, testClass(1));
    for (std::vector<testClass>::iterator i = s_vec_o1.begin(); i != s_vec_o1.end(); ++i) {
        std::cout << "*(i++)=" << *i << std::endl;
    }
    std::cout << "s_vec_o1.capacity=" << s_vec_o1.capacity() << std::endl;
    std::cout << "s_vec_o1.size=" << s_vec_o1.size() << std::endl;
    std::cout << std::endl;
    std::cout << "after s_vec_o1.assign(1, 2):" << std::endl;
    s_vec_o1.assign(1, 2);
    for (std::vector<testClass>::iterator i = s_vec_o1.begin(); i != s_vec_o1.end(); ++i) {
        std::cout << "*(i++)=" << *i << std::endl;
    }
    std::cout << "s_vec_o1.capacity=" << s_vec_o1.capacity() << std::endl;
    std::cout << "s_vec_o1.size=" << s_vec_o1.size() << std::endl;
    std::cout << std::endl;
    std::cout << "after s_vec_o1.assign(5, 3):" << std::endl;
    s_vec_o1.assign(5, 3);
    for (std::vector<testClass>::iterator i = s_vec_o1.begin(); i != s_vec_o1.end(); ++i) {
        std::cout << "*(i++)=" << *i << std::endl;
    }
    std::cout << "s_vec_o1.capacity=" << s_vec_o1.capacity() << std::endl;
    std::cout << "s_vec_o1.size=" << s_vec_o1.size() << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "ft vector f_vec_o1(2, testClass(1)):" << std::endl;
    ft::vector <testClass>               f_vec_o1(2, testClass(1));
    for (ft::vector<testClass>::iterator i  = f_vec_o1.begin(); i != f_vec_o1.end(); ++i) {
        std::cout << "*(i++)=" << *i << std::endl;
    }
    std::cout << "f_vec_o1.capacity=" << f_vec_o1.capacity() << std::endl;
    std::cout << "f_vec_o1.size=" << f_vec_o1.size() << std::endl;
    std::cout << std::endl;
    std::cout << "after f_vec_o1.assign(1, 2):" << std::endl;
    f_vec_o1.assign(1, 2);
    for (ft::vector<testClass>::iterator i = f_vec_o1.begin(); i != f_vec_o1.end(); ++i) {
        std::cout << "*(i++)=" << *i << std::endl;
    }
    std::cout << "f_vec_o1.capacity=" << f_vec_o1.capacity() << std::endl;
    std::cout << "f_vec_o1.size=" << f_vec_o1.size() << std::endl;
    std::cout << std::endl;
    std::cout << "after f_vec_o1.assign(5, 3):" << std::endl;
    f_vec_o1.assign(5, 3);
    for (ft::vector<testClass>::iterator i = f_vec_o1.begin(); i != f_vec_o1.end(); ++i) {
        std::cout << "*(i++)=" << *i << std::endl;
    }
    std::cout << "f_vec_o1.capacity=" << f_vec_o1.capacity() << std::endl;
    std::cout << "f_vec_o1.size=" << f_vec_o1.size() << std::endl;
    std::cout << std::endl;

    std::cout << "21_____________________________________________" << std::endl;
    std::cout << blue << "assign() from list" << reset << std::endl;

    std::cout << "inserted list:" << std::endl;
    std::list<int>           list_a(5, 5);
    std::list<int>::iterator list_a_it     = list_a.begin();
    for (; list_a_it != list_a.end(); ++list_a_it) {
        std::cout << "*(i++)=" << *list_a_it << std::endl;
    }

    std::cout << "std vector s_vec_p1(4, 1)" << std::endl;
    std::vector<int> s_vec_p1(4, 1);
    std::cout << "after s_vec_p1.assign(list_a.begin(), list_a.end()):"
              << std::endl;
    s_vec_p1.assign(list_a.begin(), list_a.end());
    for (std::vector<int>::iterator i = s_vec_p1.begin();
         i != s_vec_p1.end(); ++i) {
        std::cout << "*(i++)=" << *i << std::endl;
    }
    std::cout << "s_vec_p1.capacity=" << s_vec_p1.capacity() << std::endl;
    std::cout << "s_vec_p1.size=" << s_vec_p1.size() << std::endl;
    std::cout << std::endl;

    std::cout << "ft vector f_vec_p1(4, 1)" << std::endl;
    ft::vector<int> f_vec_p1(4, 1);
    std::cout << "after f_vec_p1.assign(list_a.begin(), list_a.end()):" << std::endl;
    f_vec_p1.assign(list_a.begin(), list_a.end());
    for (ft::vector<int>::iterator i        = f_vec_p1.begin(); i != f_vec_p1.end(); ++i) {
        std::cout << "*(i++)=" << *i << std::endl;
    }
    std::cout << "f_vec_p1.capacity=" << f_vec_p1.capacity() << std::endl;
    std::cout << "f_vec_p1.size=" << f_vec_p1.size() << std::endl;
    std::cout << std::endl;

    std::cout << "22_____________________________________________" << std::endl;
    std::cout << blue << "swap()" << reset << std::endl;

    std::cout << blue << "std: swap" << reset << std::endl;

    std::cout << "std vector s_vec_r1(4, 1)" << std::endl;
    std::vector<testClass>                s_vec_r1(4, 1);
    for (std::vector<testClass>::iterator i = s_vec_r1.begin(); i != s_vec_r1.end(); ++i) {
        std::cout << *i << ", ";
    }
    std::cout << std::endl;
    std::cout << "s_vec_r1.capacity=" << s_vec_r1.capacity() << std::endl;
    std::cout << "s_vec_r1.size=" << s_vec_r1.size() << std::endl;
    std::vector<testClass>::iterator s_vec_r1_it = s_vec_r1.begin();
    std::cout << "std::vector<testClass>::iterator s_vec_r1_it = s_vec_r1.begin()=" << *s_vec_r1_it << std::endl;
    std::cout << std::endl;

    std::cout << "std vector s_vec_r2(5, 3)" << std::endl;
    std::vector<testClass>                s_vec_r2(5, 3);
    for (std::vector<testClass>::iterator i      = s_vec_r2.begin(); i != s_vec_r2.end(); ++i) {
        std::cout << *i << ", ";
    }
    std::cout << std::endl;
    std::cout << "s_vec_r2.capacity=" << s_vec_r2.capacity() << std::endl;
    std::cout << "s_vec_r2.size=" << s_vec_r2.size() << std::endl;
    std::vector<testClass>::iterator s_vec_r2_it = s_vec_r2.begin();
    std::cout << "std::vector<testClass>::iterator s_vec_r2_it = s_vec_r2.begin()=" << *s_vec_r2_it << std::endl;
    std::cout << std::endl;

    std::cout << "after swap: s_vec_r1 and s_vec_r2:" << std::endl;
    std::cout << std::endl;
    std::swap(s_vec_r1, s_vec_r2);

    std::cout << "s_vec_r1:" << std::endl;
    for (std::vector<testClass>::iterator i = s_vec_r1.begin(); i != s_vec_r1.end(); ++i) {
        std::cout << *i << ", ";
    }
    std::cout << std::endl;
    std::cout << "s_vec_r1.capacity=" << s_vec_r1.capacity() << std::endl;
    std::cout << "s_vec_r1.size=" << s_vec_r1.size() << std::endl;
    std::cout << "iterator s_vec_r1_it = " << *s_vec_r1_it << std::endl;
    std::cout << std::endl;

    std::cout << "s_vec_r2:" << std::endl;
    for (std::vector<testClass>::iterator i = s_vec_r2.begin(); i != s_vec_r2.end(); ++i) {
        std::cout << *i << ", ";
    }
    std::cout << std::endl;
    std::cout << "s_vec_r2.capacity=" << s_vec_r2.capacity() << std::endl;
    std::cout << "s_vec_r2.size=" << s_vec_r2.size() << std::endl;
    std::cout << "iterator s_vec_r2_it = " << *s_vec_r2_it << std::endl;
    std::cout << std::endl;

    std::cout << blue << "ft: swap" << reset << std::endl;

    std::cout << "ft vector f_vec_r1(4, 1)" << std::endl;
    ft::vector <testClass>               f_vec_r1(4, 1);
    for (ft::vector<testClass>::iterator i  = f_vec_r1.begin(); i != f_vec_r1.end(); ++i) {
        std::cout << *i << ", ";
    }
    std::cout << std::endl;
    std::cout << "f_vec_r1.capacity=" << f_vec_r1.capacity() << std::endl;
    std::cout << "f_vec_r1.size=" << f_vec_r1.size() << std::endl;
    ft::vector<testClass>::iterator f_vec_r1_it = f_vec_r1.begin();
    std::cout << "ft::vector<testClass>::iterator f_vec_r1_it = f_vec_r1.begin()=" << *f_vec_r1_it << std::endl;
    std::cout << std::endl;

    std::cout << "ft vector f_vec_r2(5, 3)" << std::endl;
    ft::vector <testClass>               f_vec_r2(5, 3);
    for (ft::vector<testClass>::iterator i      = f_vec_r2.begin(); i != f_vec_r2.end(); ++i) {
        std::cout << *i << ", ";
    }
    std::cout << std::endl;
    std::cout << "f_vec_r2.capacity=" << f_vec_r2.capacity() << std::endl;
    std::cout << "f_vec_r2.size=" << f_vec_r2.size() << std::endl;
    ft::vector<testClass>::iterator f_vec_r2_it = f_vec_r2.begin();
    std::cout << "ft::vector<testClass>::iterator f_vec_r2_it = f_vec_r2.begin()=" << *f_vec_r2_it << std::endl;
    std::cout << std::endl;

    std::cout << "after swap: f_vec_r1 and f_vec_r2:" << std::endl;
    std::cout << std::endl;
    ft::swap(f_vec_r1, f_vec_r2);

    std::cout << "f_vec_r1:" << std::endl;
    for (ft::vector<testClass>::iterator i = f_vec_r1.begin(); i != f_vec_r1.end(); ++i) {
        std::cout << *i << ", ";
    }
    std::cout << std::endl;
    std::cout << "f_vec_r1.capacity=" << f_vec_r1.capacity() << std::endl;
    std::cout << "f_vec_r1.size=" << f_vec_r1.size() << std::endl;
    std::cout << "iterator f_vec_r1_it = " << *f_vec_r1_it << std::endl;
    std::cout << std::endl;

    std::cout << "f_vec_r2:" << std::endl;
    for (ft::vector<testClass>::iterator i = f_vec_r2.begin(); i != f_vec_r2.end(); ++i) {
        std::cout << *i << ", ";
    }
    std::cout << std::endl;
    std::cout << "f_vec_r2.capacity=" << f_vec_r2.capacity() << std::endl;
    std::cout << "f_vec_r2.size=" << f_vec_r2.size() << std::endl;
    std::cout << "iterator f_vec_r2_it = " << *f_vec_r2_it << std::endl;
    std::cout << std::endl;

    std::cout << "23_____________________________________________" << std::endl;
    std::cout << blue << "at()" << reset << std::endl;

    std::cout << "std vector: s_vec_r2.at(2): " << s_vec_r2.at(2) << std::endl;
    std::cout << "ft vector: f_vec_r2.at(2): " << f_vec_r2.at(2) << std::endl;
    std::cout << std::endl;

    std::cout << "24_____________________________________________" << std::endl;
    std::cout << blue << "get_allocator()" << reset << std::endl;

    std::cout << "std vector: s_vec_r2.get_allocator().max_size(): " << s_vec_r2.get_allocator().max_size()
              << std::endl;
    std::cout << "ft  vector: f_vec_r2.get_allocator().max_size(): " << f_vec_r2.get_allocator().max_size()
              << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << red << "Utils" << reset << std::endl << std::endl;

    std::cout << "1.01___________________________________________" << std::endl;

    std::cout << blue << "pair, make_pair():" << reset << std::endl;
    std::cout << blue << "std::pair" << reset << std::endl;
    std::pair<int, int> s_pair_1(10, 20);
    std::cout << "std::pair s_pair_1 = (" << s_pair_1.first << ", " << s_pair_1.second << ")" << std::endl;
    std::pair<int, int> s_pair_2 = std::make_pair(3, 6);
    std::cout << "std::make_pair s_pair_2 = (" << s_pair_2.first << ", " << s_pair_2.second << ")" << std::endl;
    std::cout << "s_pair_1 == s_pair_2: " << (s_pair_1 == s_pair_2) << std::endl;
    std::cout << "s_pair_1 != s_pair_2: " << (s_pair_1 != s_pair_2) << std::endl;
    std::cout << "s_pair_1 == s_pair_1: " << (s_pair_1 == s_pair_1) << std::endl;
    std::cout << "s_pair_1 > s_pair_2: " << (s_pair_1 > s_pair_2) << std::endl;
    std::cout << "std::pair.swap" << std::endl;
    s_pair_1.swap(s_pair_2);
    std::cout << "std::pair s_pair_1 = (" << s_pair_1.first << ", " << s_pair_1.second << ")" << std::endl;
    std::cout << "std::pair s_pair_2 = (" << s_pair_2.first << ", " << s_pair_2.second << ")" << std::endl;
    std::cout << "s_pair_1 > s_pair_2: " << (s_pair_1 > s_pair_2) << std::endl;
    std::cout << std::endl;

    std::cout << blue << "ft::pair" << reset << std::endl;
    ft::pair<int, int> f_pair_1(10, 20);
    std::cout << "ft::pair f_pair_1 = (" << f_pair_1.first << ", " << f_pair_1.second << ")" << std::endl;
    ft::pair<int, int> f_pair_2               = ft::make_pair(3, 6);
    std::cout << "ft::make_pair f_pair_2 = (" << f_pair_2.first << ", " << f_pair_2.second << ")" << std::endl;
    std::cout << "f_pair_1 == s_pair_2: " << (f_pair_1 == f_pair_2) << std::endl;
    std::cout << "f_pair_1 != s_pair_2: " << (f_pair_1 != f_pair_2) << std::endl;
    std::cout << "f_pair_1 == s_pair_1: " << (f_pair_1 == f_pair_1) << std::endl;
    std::cout << "f_pair_1 > s_pair_2: " << (f_pair_1 > f_pair_2) << std::endl;
    std::cout << "ft::pair.swap" << std::endl;
    f_pair_1.swap(f_pair_2);
    std::cout << "std::pair f_pair_1 = (" << f_pair_1.first << ", " << f_pair_1.second << ")" << std::endl;
    std::cout << "std::pair f_pair_2 = (" << f_pair_2.first << ", " << f_pair_2.second << ")" << std::endl;
    std::cout << "f_pair_1 > s_pair_2: " << (f_pair_1 > f_pair_2) << std::endl;
    std::cout << std::endl;

    std::cout << "1.02___________________________________________" << std::endl;
    std::cout << blue << "std::is_integral:" << reset << std::endl;
    std::cout << "char: " << std::is_integral<char>::value << std::endl;
    std::cout << "int: " << std::is_integral<int>::value << std::endl;
    std::cout << "float: " << std::is_integral<float>::value << std::endl;
    std::cout << std::endl;

    std::cout << "1.03___________________________________________" << std::endl;
    std::cout << blue << "ft::is_integral:" << reset << std::endl;
    std::cout << "char: " << ft::is_integral<char>::value << std::endl;
    std::cout << "int: " << ft::is_integral<int>::value << std::endl;
    std::cout << "float: " << ft::is_integral<float>::value << std::endl;
    std::cout << std::endl;

    std::cout << "1.04___________________________________________" << std::endl;
    std::cout << blue << "equal/lexicographical compare:" << reset << std::endl;
    std::cout << "std vectors s_comp1(2, 3) and s_comp2(2, 4)" << std::endl;
    std::vector<int> s_comp1(2, 3);
    std::vector<int> s_comp2(2, 4);
    std::cout << "std: lexicographical compare: "
              << std::lexicographical_compare(s_comp1.begin(), s_comp1.end(), s_comp2.begin(), s_comp2.end())
              << std::endl;
    std::cout << "std: equal: " << std::equal(s_comp1.begin(), s_comp1.end(), s_comp2.begin()) << std::endl;

    std::cout << "ft vectors f_comp1(2, 3) and f_comp2(2, 4)" << std::endl;
    std::vector<int> f_comp1(2, 3);
    std::vector<int> f_comp2(2, 4);
    std::cout << "ft: lexicographical compare: "
              << std::lexicographical_compare(f_comp1.begin(), f_comp1.end(), f_comp2.begin(), f_comp2.end())
              << std::endl;
    std::cout << "ft: equal: " << std::equal(f_comp1.begin(), f_comp1.end(), f_comp2.begin()) << std::endl;
    std::cout << std::endl;

    std::cout << "std vectors s_comp3(3, 4) and s_comp4(2, 4)" << std::endl;
    std::vector<int> s_comp3(3, 4);
    std::vector<int> s_comp4(2, 4);
    std::cout << "std: lexicographical compare: "
              << std::lexicographical_compare(s_comp3.begin(), s_comp3.end(), s_comp4.begin(), s_comp4.end())
              << std::endl;
    std::cout << "std: equal: " << std::equal(s_comp3.begin(), s_comp3.end(), s_comp4.begin()) << std::endl;

    std::cout << "ft vectors f_comp3(3, 4) and f_comp4(2, 4)" << std::endl;
    std::vector<int> f_comp3(3, 4);
    std::vector<int> f_comp4(2, 4);
    std::cout << "ft: lexicographical compare: "
              << std::lexicographical_compare(f_comp3.begin(), f_comp3.end(), f_comp4.begin(), f_comp4.end())
              << std::endl;
    std::cout << "ft: equal: " << std::equal(f_comp3.begin(), f_comp3.end(), f_comp4.begin()) << std::endl;
    std::cout << std::endl;

    std::cout << "std vectors s_comp5(3, 4) and s_comp6(3, 4)" << std::endl;
    std::vector<int> s_comp5(3, 4);
    std::vector<int> s_comp6(3, 4);
    std::cout << "std: lexicographical compare: "
              << std::lexicographical_compare(s_comp5.begin(), s_comp5.end(), s_comp6.begin(), s_comp6.end())
              << std::endl;
    std::cout << "std: equal: " << std::equal(s_comp5.begin(), s_comp5.end(), s_comp6.begin()) << std::endl;

    std::cout << "ft vectors f_comp5(3, 4) and f_comp6(3, 4)" << std::endl;
    std::vector<int> f_comp5(3, 4);
    std::vector<int> f_comp6(3, 4);
    std::cout << "ft: lexicographical compare: "
              << std::lexicographical_compare(f_comp5.begin(), f_comp5.end(), f_comp6.begin(), f_comp6.end())
              << std::endl;
    std::cout << "ft: equal: " << std::equal(f_comp5.begin(), f_comp5.end(), f_comp6.begin()) << std::endl;
    std::cout << std::endl;


    std::cout << "1.05___________________________________________" << std::endl;
    std::cout << blue << "iterator traits" << reset << std::endl;

    std::vector<int>                 s_tr(4, 1);
    std::vector<int>::iterator       it_s_tr  = s_tr.begin();
    std::vector<int>::const_iterator itc_s_tr = s_tr.begin();

    ft::vector<int>                 f_tr(4, 1);
    ft::vector<int>::iterator       it_f_tr   = f_tr.begin();
    ft::vector<int>::const_iterator itc_f_tr  = f_tr.begin();

    typedef std::iterator_traits<std::vector<int>::iterator>::difference_type
            new_type1;
    typedef ft::iterator_traits<ft::vector<int>::iterator>::difference_type
            new_type2;

    std::cout << "n1 type = std::iterator_traits<ft::vector<int>::iterator >::difference_type" << std::endl;
    std::cout << "std::vector<int>::iterator it_s_tr = s_tr.begin()" << std::endl;
    std::cout << "std::vector<int>::const_iterator itc_s_tr = s_tr.begin()" << std::endl;
    std::cout << "n1 = it_s_tr - itc_s_tr" << std::endl;
    new_type1 n1 = it_s_tr - itc_s_tr;
    std::cout << "n1 = " << n1 << std::endl;
    std::cout << std::endl;

    std::cout << "n2 type = ft::iterator_traits<ft::vector<int>::iterator >::difference_type" << std::endl;
    std::cout << "ft::vector<int>::iterator it_f_tr = f_tr.begin()" << std::endl;
    std::cout << "ft::vector<int>::const_iterator itc_f_tr = f_tr.begin()" << std::endl;
    std::cout << "n2 = it_f_tr - itc_f_tr" << std::endl;
    new_type2 n2 = it_f_tr - itc_f_tr;
    std::cout << "n2 = " << n2 << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;


    std::cout << red << "STACK" << reset << std::endl << std::endl;

    std::cout << "2.01___________________________________________" << std::endl;

    std::cout << blue << "creating stacks with default container: std::stack "
                         "stack<double> s_st_01 and ft::stack f_st_01.size(), size():" << reset << std::endl;

    std::stack<double> s_st_01;
    ft::stack<double>  f_st_01;

    std::cout << "s_st_01.size() = " << s_st_01.size() << std::endl;
    std::cout << "f_st_01.size() = " << f_st_01.size() << std::endl;
    std::cout << std::endl;

    std::cout << blue << "push(), top()" << reset << std::endl;
    std::cout << "after push(3.4), push(5.7):" << std::endl;
    s_st_01.push(3.4);
    s_st_01.push(5.7);
    f_st_01.push(3.4);
    f_st_01.push(5.7);

    std::cout << "s_st_01.top() = " << s_st_01.top() << std::endl;
    std::cout << "s_st_01.size() = " << s_st_01.size() << std::endl;
    std::cout << std::endl;
    std::cout << "f_st_01.top() = " << f_st_01.top() << std::endl;
    std::cout << "f_st_01.size() = " << f_st_01.size() << std::endl;
    std::cout << std::endl;

    std::cout << blue << "pop()" << reset << std::endl;
    std::cout << "after pop():" << std::endl;
    s_st_01.pop();
    f_st_01.pop();
    std::cout << "s_st_01.top() = " << s_st_01.top() << std::endl;
    std::cout << "s_st_01.size() = " << s_st_01.size() << std::endl;
    std::cout << std::endl;
    std::cout << "f_st_01.top() = " << f_st_01.top() << std::endl;
    std::cout << "f_st_01.size() = " << f_st_01.size() << std::endl;
    std::cout << std::endl;

    std::cout << blue << "empty()" << reset << std::endl;
    std::cout << "s_st_01.empty() = " << s_st_01.empty() << std::endl;
    std::cout << "f_st_01.empty() = " << f_st_01.empty() << std::endl;
    std::cout << std::endl;
    std::cout << "after pop():" << std::endl;
    s_st_01.pop();
    f_st_01.pop();
    std::cout << "s_st_01.empty() = " << s_st_01.empty() << std::endl;
    std::cout << "f_st_01.empty() = " << f_st_01.empty() << std::endl;
    std::cout << std::endl;

    std::cout << "2.02___________________________________________" << std::endl;
    std::cout << blue << "compirising operators" << reset << std::endl;

    std::stack<double> s_st_01_copy(s_st_01);
    ft::stack<double>  f_st_01_copy(f_st_01);

    std::cout << "(s_st_01 == s_st_01_copy)=" << (s_st_01 == s_st_01_copy) << std::endl;
    std::cout << "(f_st_01 == f_st_01_copy)=" << (f_st_01 == f_st_01_copy) << std::endl;
    std::cout << std::endl;

    std::cout << "(s_st_01 > s_st_01_copy)=" << (s_st_01 > s_st_01_copy) << std::endl;
    std::cout << "(f_st_01 > f_st_01_copy)=" << (f_st_01 > f_st_01_copy) << std::endl;
    std::cout << std::endl;

    std::cout << "(s_st_01 < s_st_01_copy)=" << (s_st_01 < s_st_01_copy) << std::endl;
    std::cout << "(f_st_01 < f_st_01_copy)=" << (f_st_01 < f_st_01_copy) << std::endl;
    std::cout << std::endl;


    std::cout << "2.03___________________________________________" << std::endl;
    std::cout << blue << "creating ft::stack with std::vector:" << reset
              << std::endl;
    std::cout << std::endl;
    ft::stack<double, std::vector<double> > f_st_02;

    std::cout << "f_st_02.size() = " << f_st_02.size() << std::endl;
    std::cout << std::endl;

    std::cout << "after push(3.4), push(5.7):" << std::endl;
    f_st_02.push(3.4);
    f_st_02.push(5.7);

    std::cout << "f_st_02.top() = " << f_st_02.top() << std::endl;
    std::cout << "f_st_02.size() = " << f_st_02.size() << std::endl;
    std::cout << std::endl;

    std::cout << "after pop:" << std::endl;
    f_st_02.pop();
    std::cout << "f_st_02.top() = " << f_st_02.top() << std::endl;
    std::cout << "f_st_02.size() = " << f_st_02.size() << std::endl;
    std::cout << std::endl;

    std::cout << "empty:" << std::endl;
    std::cout << "f_st_02.empty() = " << f_st_02.empty() << std::endl;
    std::cout << std::endl;

    std::cout << "2.04___________________________________________" << std::endl;
    std::cout << blue << "creating ft::stack with std::deque:" << reset
              << std::endl;
    std::cout << std::endl;
    ft::stack<double, std::deque<double> > f_st_03;

    std::cout << "f_st_03.size() = " << f_st_03.size() << std::endl;
    std::cout << std::endl;

    std::cout << "after push(3.4), push(5.7):" << std::endl;
    f_st_03.push(3.4);
    f_st_03.push(5.7);

    std::cout << "f_st_03.top() = " << f_st_03.top() << std::endl;
    std::cout << "f_st_03.size() = " << f_st_03.size() << std::endl;
    std::cout << std::endl;

    std::cout << "after pop:" << std::endl;
    f_st_03.pop();
    std::cout << "f_st_03.top() = " << f_st_03.top() << std::endl;
    std::cout << "f_st_03.size() = " << f_st_03.size() << std::endl;
    std::cout << std::endl;

    std::cout << "empty:" << std::endl;
    std::cout << "f_st_03.empty() = " << f_st_03.empty() << std::endl;
    std::cout << std::endl;

    std::cout << "2.05___________________________________________" << std::endl;
    std::cout << blue << "creating ft::stack with std::list:" << reset << std::endl;
    std::cout << std::endl;
    ft::stack<double, std::list<double> > f_st_04;

    std::cout << "f_st_04.size() = " << f_st_04.size() << std::endl;
    std::cout << std::endl;

    std::cout << "after push(3.4), push(5.7):" << std::endl;
    f_st_04.push(3.4);
    f_st_04.push(5.7);

    std::cout << "f_st_04.top() = " << f_st_04.top() << std::endl;
    std::cout << "f_st_04.size() = " << f_st_04.size() << std::endl;
    std::cout << std::endl;

    std::cout << "after pop:" << std::endl;
    f_st_04.pop();
    std::cout << "f_st_04.top() = " << f_st_04.top() << std::endl;
    std::cout << "f_st_04.size() = " << f_st_04.size() << std::endl;
    std::cout << std::endl;

    std::cout << "empty:" << std::endl;
    std::cout << "f_st_04.empty() = " << f_st_04.empty() << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;


    std::cout << red << "MAP" << reset << std::endl << std::endl;

    testClass tc2(2);
    testClass tc3(3);
    testClass tc1(1);
    testClass tc4(4);
    testClass tc5(5);
    testClass tc6(6);
    testClass tc7(7);
    testClass tc8(8);
    testClass tc100(100);
    testClass tc50(50);
    testClass tc9(9);
    testClass tc0(0);
    testClass tc101(101);
    testClass tc49(49);

    std::cout << "3.01___________________________________________" << std::endl;
    std::cout << blue << "creating ft::map<int, testClass>, size(), max_size()" << reset << std::endl;

    std::cout << "creating ft::map<int, testClass> f_map_01 and std::map<int, testClass> s_map_01" << std::endl;
    ft::map<int, testClass>  f_map_01;
    std::map<int, testClass> s_map_01;
    std::cout << "f_map_01.size()=" << f_map_01.size() << std::endl;
    std::cout << "f_map_01.max_size()=" << f_map_01.max_size() << std::endl;
    std::cout << std::endl;
    std::cout << "s_map_01.size()=" << s_map_01.size() << std::endl;
    std::cout << "s_map_01.max_size()=" << s_map_01.max_size() << std::endl;
    std::cout << std::endl;


    std::cout << "3.02___________________________________________" << std::endl;
    std::cout << blue << "insert(val), operator[]" << reset << std::endl;
    std::cout << "insert(2, tc2)" << std::endl;
    std::cout << "f_map_01.insert(2, tc2)=" << std::endl;
    ft::pair<ft::map<int, testClass>::iterator, bool> f_pair_map
                                                              = f_map_01.insert(ft::make_pair(2, tc2));
    std::cout << "ft: pair.first.first = " << (*(f_pair_map.first)).first << ", pair.second = "
              << (bool) f_pair_map.second << std::endl;
    std::cout << "f_map_01.insert(2, tc2)=" << std::endl;
    f_pair_map = f_map_01.insert(ft::make_pair(2, tc2));
    std::cout << "ft: pair.first.first = " << (*(f_pair_map.first)).first << ", pair.second = "
              << (bool) f_pair_map.second << std::endl;
    std::cout << "f_map_01.size=" << f_map_01.size() << std::endl;
    std::cout << std::endl;

    std::cout << "s_map_01.insert(2, tc2)" << std::endl;
    std::pair<std::map<int, testClass>::iterator, bool> s_pair_map
                                                                = s_map_01.insert(std::make_pair(2, tc2));
    std::cout << "std: pair.first.first = " << (*(s_pair_map.first)).first << ", pair.second = "
              << (bool) s_pair_map.second << std::endl;
    std::cout << "s_map_01.insert(2, tc2)" << std::endl;
    s_pair_map = s_map_01.insert(std::make_pair(2, tc2));
    std::cout << "std: pair.first.first = " << (*(s_pair_map.first)).first << ", pair.second = "
              << (bool) s_pair_map.second << std::endl;
    std::cout << "s_map_01.size=" << s_map_01.size() << std::endl;
    std::cout << std::endl;

    std::cout << "[3] = tc3" << std::endl;
    f_map_01[3] = tc3;
    s_map_01[3] = tc3;

    std::cout << "[1] = tc1" << std::endl;
    f_map_01[1] = tc1;
    s_map_01[1] = tc1;

    std::cout << "[4] = tc3" << std::endl;
    f_map_01[4] = tc3;
    s_map_01[4] = tc3;
    std::cout << "f_map_01[4]=" << f_map_01[4] << std::endl;
    std::cout << "s_map_01[4]=" << s_map_01[4] << std::endl;

    std::cout << "[4] = tc4" << std::endl;
    f_map_01[4] = tc4;
    s_map_01[4] = tc4;
    std::cout << "f_map_01[4]=" << f_map_01[4] << std::endl;
    std::cout << "s_map_01[4]=" << s_map_01[4] << std::endl;

    std::cout << "insert(5, tc5)" << std::endl;
    f_map_01.insert(ft::make_pair(5, tc5));
    s_map_01.insert(std::make_pair(5, tc5));

    std::cout << "insert(6, tc6)" << std::endl;
    f_map_01.insert(ft::make_pair(6, tc6));
    s_map_01.insert(std::make_pair(6, tc6));

    std::cout << "insert(7, tc7)" << std::endl;
    f_map_01.insert(ft::make_pair(7, tc7));
    s_map_01.insert(std::make_pair(7, tc7));

    std::cout << "insert(8, tc8)" << std::endl;
    f_map_01.insert(ft::make_pair(8, tc8));
    s_map_01.insert(std::make_pair(8, tc8));

    std::cout << "insert(100, tc100)" << std::endl;
    f_map_01.insert(ft::make_pair(100, tc100));
    s_map_01.insert(std::make_pair(100, tc100));

    std::cout << "insert(50, tc50)" << std::endl;
    f_map_01.insert(ft::make_pair(50, tc50));
    s_map_01.insert(std::make_pair(50, tc50));

    std::cout << "insert(9, tc9)" << std::endl;
    f_map_01.insert(ft::make_pair(9, tc9));
    s_map_01.insert(std::make_pair(9, tc9));
    std::cout << "f_map_01.size=" << f_map_01.size() << std::endl;
    std::cout << "s_map_01.size=" << s_map_01.size() << std::endl;
    std::cout << std::endl;

    std::cout << blue << "insert(iterator position, val), find()" << reset << std::endl;
    std::cout << "insert (begin(), (0, tc0))" << std::endl;
    f_map_01.insert(f_map_01.begin(), ft::make_pair(0, tc0));
    std::cout << "f_map_01.size=" << f_map_01.size() << std::endl;
    s_map_01.insert(s_map_01.begin(), std::make_pair(0, tc0));
    std::cout << "s_map_01.size=" << s_map_01.size() << std::endl;
    std::cout << std::endl;

    std::cout << "insert(end(), (101, tc101))" << std::endl;
    f_map_01.insert(f_map_01.end(), ft::make_pair(101, tc101));
    std::cout << "f_map_01.size=" << f_map_01.size() << std::endl;
    s_map_01.insert(s_map_01.end(), std::make_pair(101, tc101));
    std::cout << "s_map_01.size=" << s_map_01.size() << std::endl;
    std::cout << std::endl;

    std::cout << "insert(find(9), (49, tc49))" << reset << std::endl;
    f_map_01.insert(f_map_01.find(9), ft::make_pair(49, tc49));
    std::cout << "f_map_01.size=" << f_map_01.size() << std::endl;
    s_map_01.insert(s_map_01.find(9), std::make_pair(49, tc49));
    std::cout << "s_map_01.size=" << s_map_01.size() << std::endl;
    std::cout << std::endl;

    std::cout << blue << "insert(iterator first, iterator last)" << reset << std::endl;
    std::cout << "creating list<(int, testClass)> s_map_list: list((88, tc88), (89, tc89))" << std::endl;
    std::list<std::pair<int, testClass> > s_map_list;
    s_map_list.push_back(std::make_pair(88, testClass(88)));
    s_map_list.push_back(std::make_pair(89, testClass(89)));
    std::list<ft::pair < int, testClass> > f_map_list;
    f_map_list.push_back(ft::make_pair(88, testClass(88)));
    f_map_list.push_back(ft::make_pair(89, testClass(89)));

    std::cout << "insert(s_map_list.begin(), s_map_list.end())" << reset << std::endl;
    f_map_01.insert(f_map_list.begin(), f_map_list.end());
    std::cout << "f_map_01.size=" << f_map_01.size() << std::endl;
    s_map_01.insert(s_map_list.begin(), s_map_list.end());
    std::cout << "s_map_01.size=" << s_map_01.size() << std::endl;
    std::cout << std::endl;

    std::cout << "3.02___________________________________________" << std::endl;
    std::cout << blue << "erase(val)" << reset << std::endl;
    std::cout << "erase(49)" << std::endl;
    f_map_01.erase(49);
    s_map_01.erase(49);
    std::cout << "f_map_01.size=" << f_map_01.size() << std::endl;
    std::cout << "s_map_01.size=" << s_map_01.size() << std::endl;
    std::cout << std::endl;
    std::cout << "erase(100)" << std::endl;
    f_map_01.erase(100);
    s_map_01.erase(100);
    std::cout << "erase(101)" << std::endl;
    f_map_01.erase(101);
    s_map_01.erase(101);
    std::cout << std::endl;

    std::cout << blue << "begin(), rbegin()" << reset << std::endl;
    std::cout << "*f_map_01.begin().first=" << (*f_map_01.begin()).first << std::endl;
    std::cout << "*f_map_01.rbegin().first=" << (*f_map_01.rbegin()).first << std::endl;
    std::cout << "*s_map_01.begin().first=" << (*s_map_01.begin()).first << std::endl;
    std::cout << "*s_map_01.rbegin().first=" << (*s_map_01.rbegin()).first << std::endl;
    std::cout << std::endl;

    std::cout << blue << "erase(iterator position)" << reset << std::endl;

    std::cout << "erase(begin())" << std::endl;
    f_map_01.erase(f_map_01.begin());
    s_map_01.erase(s_map_01.begin());
    std::cout << "f_map_01.size=" << f_map_01.size() << std::endl;
    std::cout << "s_map_01.size=" << s_map_01.size() << std::endl;
    std::cout << std::endl;

    std::cout << "erase(0)" << std::endl;
    f_map_01.erase(0);
    s_map_01.erase(0);
    std::cout << "f_map_01.size=" << f_map_01.size() << std::endl;
    std::cout << "s_map_01.size=" << s_map_01.size() << std::endl;
    std::cout << std::endl;

    std::cout << "3.03___________________________________________" << std::endl;
    std::cout << blue << "find(val), count(), equal_range()" << reset << std::endl;

    std::cout << "f_map_01.count(89)=" << f_map_01.count(89) << std::endl;
    std::cout << "s_map_01.count(89)=" << s_map_01.count(89) << std::endl;
    std::cout << std::endl;

    std::cout << "printing f_map_01.equal_range(89):" << std::endl;
    ft::pair <ft::map<int, testClass>::iterator, ft::map<int,
            testClass>::iterator> f_map_pair_it;
    f_map_pair_it = f_map_01.equal_range(89);
    for (ft::map<int, testClass>::iterator it = f_map_pair_it.first; it != f_map_pair_it.second; ++it) {
        std::cout << (*it).first << ", ";
    }
    std::cout << std::endl;

    std::cout << "printing s_map_01.equal_range(89):" << std::endl;
    std::pair<std::map<int, testClass>::iterator, std::map<int,
            testClass>::iterator> s_map_pair_it;
    s_map_pair_it = s_map_01.equal_range(89);
    for (std::map<int, testClass>::iterator it = s_map_pair_it.first; it != s_map_pair_it.second; ++it) {
        std::cout << (*it).first << ", ";
    }
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "erase(find(*rbegin()).first)" << std::endl;
    f_map_01.erase(f_map_01.find((*f_map_01.rbegin()).first));
    s_map_01.erase(s_map_01.find((*s_map_01.rbegin()).first));
    std::cout << "f_map_01.size=" << f_map_01.size() << std::endl;
    std::cout << "s_map_01.size=" << s_map_01.size() << std::endl;
    std::cout << std::endl;

    std::cout << "*f_map_01.begin().first=" << (*f_map_01.begin()).first << std::endl;
    std::cout << "*f_map_01.rbegin().first=" << (*f_map_01.rbegin()).first << std::endl;
    std::cout << "*s_map_01.begin().first=" << (*s_map_01.begin()).first << std::endl;
    std::cout << "*s_map_01.rbegin().first=" << (*s_map_01.rbegin()).first << std::endl;
    std::cout << std::endl;

    std::cout << "f_map_01.count(89)=" << f_map_01.count(89) << std::endl;
    std::cout << "s_map_01.count(89)=" << s_map_01.count(89) << std::endl;
    std::cout << std::endl;

    std::cout << "3.04___________________________________________" << std::endl;
    std::cout << blue << "erase(iterator first, iterator last), lower_bound(), upper_bound" << reset << std::endl;

    std::cout << "*f_map_01.lower_bound(50).first=" << (*f_map_01.lower_bound(50)).first << std::endl;
    std::cout << "*s_map_01.lower_bound(50).first=" << (*s_map_01.lower_bound(50)).first << std::endl;

    std::cout << "*(++f_map_01.lower_bound(50)).first=" << (*(++f_map_01.lower_bound(50))).first << std::endl;
    std::cout << "*(++s_map_01.lower_bound(50)).first=" << (*(++s_map_01.lower_bound(50))).first << std::endl;

    std::cout << "*f_map_01.upper_bound(50).first=" << (*f_map_01.upper_bound(50)).first << std::endl;
    std::cout << "*s_map_01.upper_bound(50).first=" << (*s_map_01.upper_bound(50)).first << std::endl;
    std::cout << std::endl;

    std::cout << "erase(lower_bound(50), upper_bound(50)" << std::endl;
    f_map_01.erase(f_map_01.lower_bound(50), f_map_01.upper_bound(50));
    s_map_01.erase(s_map_01.lower_bound(50), s_map_01.upper_bound(50));
    std::cout << "f_map_01.size=" << f_map_01.size() << std::endl;
    std::cout << "s_map_01.size=" << s_map_01.size() << std::endl;
    std::cout << std::endl;


    std::cout << "3.05___________________________________________" << std::endl;
    std::cout << blue << "iterator arithmetics, end(), rend()" << reset << std::endl;

    std::cout << "ft::map<int, testClass>::iterator f_map_01_it" << std::endl;
    std::cout << "std::map<int, testClass>::iterator s_map_01_it" << std::endl;
    ft::map<int, testClass>::iterator  f_map_01_it;
    std::map<int, testClass>::iterator s_map_01_it;
    std::cout << "f_map_01_it = f_map_01.begin()" << std::endl;
    std::cout << "s_map_01_it = s_map_01.begin()" << std::endl;
    f_map_01_it = f_map_01.begin();
    s_map_01_it = s_map_01.begin();
    std::cout << std::endl;
    std::cout << "*f_map_01_it.first=" << (*f_map_01_it).first << std::endl;
    std::cout << "*s_map_01_it.first=" << (*s_map_01_it).first << std::endl;
    std::cout << std::endl;
    std::cout << "*(++f_map_01_it).first=" << (*(++f_map_01_it)).first << std::endl;
    std::cout << "*(++s_map_01_it).first=" << (*(++s_map_01_it)).first << std::endl;
    std::cout << std::endl;
    std::cout << "*(++f_map_01_it).first=" << (*(++f_map_01_it)).first << std::endl;
    std::cout << "*(++s_map_01_it).first=" << (*(++s_map_01_it)).first << std::endl;
    std::cout << std::endl;
    std::cout << "*(f_map_01_it++).first=" << (*(f_map_01_it++)).first << std::endl;
    std::cout << "*(s_map_01_it++).first=" << (*(s_map_01_it++)).first << std::endl;
    std::cout << std::endl;
    std::cout << "*f_map_01_it.first=" << (*f_map_01_it).first << std::endl;
    std::cout << "*s_map_01_it.first=" << (*s_map_01_it).first << std::endl;
    std::cout << std::endl;
    std::cout << "*(--f_map_01_it).first=" << (*(--f_map_01_it)).first << std::endl;
    std::cout << "*(--s_map_01_it).first=" << (*(--s_map_01_it)).first << std::endl;
    std::cout << std::endl;
    std::cout << "*(f_map_01_it--).first=" << (*(f_map_01_it--)).first << std::endl;
    std::cout << "*(s_map_01_it--).first=" << (*(s_map_01_it--)).first << std::endl;
    std::cout << std::endl;
    std::cout << "*f_map_01_it.first=" << (*f_map_01_it).first << std::endl;
    std::cout << "*s_map_01_it.first=" << (*s_map_01_it).first << std::endl;
    std::cout << std::endl;

    std::cout << "ft::map<int, testClass>::reverse_iterator f_map_01_rit" << std::endl;
    std::cout << "std::map<int, testClass>::reverse_iterator s_map_01_rit" << std::endl;
    ft::map<int, testClass>::reverse_iterator  f_map_01_rit;
    std::map<int, testClass>::reverse_iterator s_map_01_rit;
    std::cout << "f_map_01_rit = f_map_01.rbegin()" << std::endl;
    std::cout << "s_map_01_rit = s_map_01.rbegin()" << std::endl;
    f_map_01_rit = f_map_01.rbegin();
    s_map_01_rit = s_map_01.rbegin();
    std::cout << std::endl;
    std::cout << "*f_map_01_rit.first=" << (*f_map_01_rit).first << std::endl;
    std::cout << "*s_map_01_rit.first=" << (*s_map_01_rit).first << std::endl;
    std::cout << std::endl;
    std::cout << "*(++f_map_01_rit)=" << (*(++f_map_01_rit)).first << std::endl;
    std::cout << "*(++s_map_01_rit)=" << (*(++s_map_01_rit)).first << std::endl;
    std::cout << std::endl;

    std::cout << "printing f_map_01 from begin() to end()" << std::endl;
    for (ft::map<int, testClass>::iterator it = f_map_01.begin(); it != f_map_01.end(); ++it) {
        std::cout << "k=" << (*it).first << " v=" << (*it).second << ";  ";
    }
    std::cout << std::endl;
    std::cout << "printing s_map_01 from begin() to end()" << std::endl;
    for (std::map<int, testClass>::iterator it = s_map_01.begin(); it != s_map_01.end(); ++it) {
        std::cout << "k=" << (*it).first << " v=" << (*it).second << ";  ";
    }
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "printing f_map_01 from rbegin() to rend()" << std::endl;
    for (ft::map<int, testClass>::reverse_iterator it = f_map_01.rbegin(); it != f_map_01.rend(); ++it) {
        std::cout << "k=" << (*it).first << " v=" << (*it).second << ";  ";
    }
    std::cout << std::endl;
    std::cout << "printing s_map_01 from rbegin() to rend()" << std::endl;
    for (std::map<int, testClass>::reverse_iterator it = s_map_01.rbegin(); it != s_map_01.rend(); ++it) {
        std::cout << "k=" << (*it).first << " v=" << (*it).second << ";  ";
    }
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "3.06___________________________________________" << std::endl;
    std::cout << blue << "iterators compirising" << reset << std::endl;

    std::cout << "ft::map<int, testClass>::iterator f_map_02_it" << std::endl;
    ft::map<int, testClass>::iterator f_map_02_it;
    std::cout << "f_map_01_it and f_map_01_it = f_map_01.begin()" << std::endl;
    f_map_01_it = f_map_01.begin();
    f_map_02_it = f_map_01.begin();
    std::cout << "(f_map_01_it == f_map_02_it)=" << (f_map_01_it == f_map_02_it) << std::endl;
    std::cout << std::endl;

    std::cout << "ft::map<int, testClass>::const_iterator f_map_01_itc" << std::endl;
    ft::map<int, testClass>::const_iterator f_map_01_itc;
    std::cout << "f_map_01_itc = f_map_01.begin()" << std::endl;
    f_map_01_itc = f_map_01.begin();
    std::cout << "(f_map_01_it == f_map_01_itc)=" << (f_map_01_it == f_map_01_itc) << std::endl;
    std::cout << std::endl;

    std::cout << "3.07___________________________________________" << std::endl;
    std::cout << blue << "copy constructor" << reset << std::endl;

    std::cout << "constructing const f_map_01_copy and s_map_01_copy from f_map_01 and s_map_01" << std::endl;
    ft::map<int, testClass>  f_map_01_copy(f_map_01);
    std::map<int, testClass> s_map_01_copy(s_map_01);

    std::cout << "printing f_map_01_copy from begin() to end()" << std::endl;
    for (ft::map<int, testClass>::iterator it = f_map_01_copy.begin(); it != f_map_01_copy.end(); ++it) {
        std::cout << "k=" << (*it).first << " v=" << (*it).second << ";  ";
    }
    std::cout << std::endl;
    std::cout << "printing s_map_01_copy from begin() to end()" << std::endl;
    for (std::map<int, testClass>::iterator it = s_map_01_copy.begin(); it != s_map_01_copy.end(); ++it) {
        std::cout << "k=" << (*it).first << " v=" << (*it).second << ";  ";
    }
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "f_map_01_copy.size=" << f_map_01_copy.size() << std::endl;
    std::cout << "s_map_01_copy.size=" << s_map_01_copy.size() << std::endl;
    std::cout << std::endl;

    std::cout << "3.08___________________________________________" << std::endl;
    std::cout << blue << "assignment overload" << reset << std::endl;

    std::cout << "f_map_01_ao and s_map_01_ao" << std::endl;
    ft::map<int, testClass>  f_map_01_ao;
    std::map<int, testClass> s_map_01_ao;
    std::cout << "f_map_01_ao = f_map_01 and s_map_01_ao = s_map_01" << std::endl;
    f_map_01_ao = f_map_01;
    s_map_01_ao = s_map_01;

    std::cout << "printing f_map_01_ao from begin() to end()" << std::endl;
    for (ft::map<int, testClass>::iterator it = f_map_01_ao.begin(); it != f_map_01_ao.end(); ++it) {
        std::cout << "k=" << (*it).first << " v=" << (*it).second << ";  ";
    }
    std::cout << std::endl;
    std::cout << "printing s_map_01_ao from begin() to end()" << std::endl;
    for (std::map<int, testClass>::iterator it = s_map_01_ao.begin(); it != s_map_01_ao.end(); ++it) {
        std::cout << "k=" << (*it).first << " v=" << (*it).second << ";  ";
    }
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "f_map_01_ao.size=" << f_map_01_ao.size() << std::endl;
    std::cout << "s_map_01_ao.size=" << s_map_01_ao.size() << std::endl;
    std::cout << std::endl;

    std::cout << "3.09___________________________________________" << std::endl;
    std::cout << blue << "swap" << reset << std::endl;

    std::cout << "creating f_map_02 and s_map_02, both = {5, 6, 7}" << std::endl;
    ft::map<int, testClass> f_map_02;
    f_map_02.insert(ft::make_pair(5, tc5));
    f_map_02.insert(ft::make_pair(6, tc6));
    f_map_02.insert(ft::make_pair(7, tc7));
    std::map<int, testClass> s_map_02;
    s_map_02.insert(std::make_pair(5, tc5));
    s_map_02.insert(std::make_pair(6, tc6));
    s_map_02.insert(std::make_pair(7, tc7));
    std::cout << std::endl;

    ft::map<int, testClass>::iterator f_map_01_i = f_map_01.begin();
    std::cout << "ft::map<int, testClass>::iterator f_map_01_i = f_map_01.begin()=>first=" << (*f_map_01_i).first
              << std::endl;
    std::map<int, testClass>::iterator s_map_01_i = s_map_01.begin();
    std::cout << "std::map<int, testClass>::iterator s_map_01_i = s_map_01.begin()=>first=" << (*s_map_01_i).first
              << std::endl;
    ft::map<int, testClass>::iterator f_map_02_i = f_map_02.begin();
    std::cout << "ft::map<int, testClass>::iterator f_map_02_i = f_map_02.begin()=>first=" << (*f_map_02_i).first
              << std::endl;
    std::map<int, testClass>::iterator s_map_02_i = s_map_02.begin();
    std::cout << "std::map<int, testClass>::iterator s_map_02_i = s_map_02.begin()=>first=" << (*s_map_02_i).first
              << std::endl;
    std::cout << std::endl;
    std::cout << "after swap f_map_01 and f_map_02:" << std::endl;
    ft::swap(f_map_01, f_map_02);
    std::cout << "printing f_map_01" << std::endl;
    for (ft::map<int, testClass>::iterator it = f_map_01.begin();
         it != f_map_01.end(); ++it) {
        std::cout << "k=" << (*it).first << " v=" << (*it).second << ";  ";
    }
    std::cout << std::endl;
    std::cout << "iterator f_map_01_i=>first = " << (*f_map_01_i).first << std::endl;
    std::cout << "printing f_map_02" << std::endl;
    for (ft::map<int, testClass>::iterator it = f_map_02.begin(); it != f_map_02.end(); ++it) {
        std::cout << "k=" << (*it).first << " v=" << (*it).second << ";  ";
    }
    std::cout << std::endl;
    std::cout << "iterator f_map_02_i=>first = " << (*f_map_02_i).first << std::endl;
    std::cout << std::endl;

    std::cout << "after swap s_map_01 and s_map_02:" << std::endl;
    std::swap(s_map_01, s_map_02);
    std::cout << "printing s_map_01" << std::endl;
    for (std::map<int, testClass>::iterator it = s_map_01.begin(); it != s_map_01.end(); ++it) {
        std::cout << "k=" << (*it).first << " v=" << (*it).second << ";  ";
    }
    std::cout << std::endl;
    std::cout << "iterator s_map_01_i=>first = " << (*s_map_01_i).first << std::endl;
    std::cout << "printing s_map_02" << std::endl;
    for (std::map<int, testClass>::iterator it = s_map_02.begin(); it != s_map_02.end(); ++it) {
        std::cout << "k=" << (*it).first << " v=" << (*it).second << ";  ";
    }
    std::cout << std::endl;
    std::cout << "iterator s_map_02_i=>first = " << (*s_map_02_i).first << std::endl;
    std::cout << std::endl;

    std::cout << "3.10___________________________________________" << std::endl;
    std::cout << blue << "compirising operators" << reset << std::endl;

    std::cout << "(f_map_01 == f_map_02)=" << (f_map_01 == f_map_02) << std::endl;
    std::cout << "(s_map_01 == s_map_02)=" << (s_map_01 == s_map_02) << std::endl;
    std::cout << std::endl;

    std::cout << "(f_map_01 > f_map_02)=" << (f_map_01 > f_map_02) << std::endl;
    std::cout << "(s_map_01 > s_map_02)=" << (s_map_01 > s_map_02) << std::endl;
    std::cout << std::endl;

    std::cout << "(f_map_01 < f_map_02)=" << (f_map_01 < f_map_02) << std::endl;
    std::cout << "(s_map_01 < s_map_02)=" << (s_map_01 < s_map_02) << std::endl;
    std::cout << std::endl;

    std::cout << "3.11___________________________________________" << std::endl;
    std::cout << blue << "clear(), empty()" << reset << std::endl;

    std::cout << "after clear()" << std::endl;
    f_map_01.clear();
    s_map_01.clear();
    std::cout << "f_map_01.size=" << f_map_01.size() << std::endl;
    std::cout << "s_map_01.size=" << s_map_01.size() << std::endl;
    std::cout << std::endl;
    std::cout << "f_map_01.empty()=" << f_map_01.empty() << std::endl;
    std::cout << "s_map_01.empty()=" << s_map_01.empty() << std::endl;
    std::cout << std::endl;

    std::cout << "3.12___________________________________________" << std::endl;
    std::cout << blue << "get_allocator(), key_comp(), value_comp()" << reset << std::endl;
    std::cout << "f_map_01.get_allocator().max_size(): " << f_map_01.get_allocator().max_size() << std::endl;
    std::cout << "s_map_01.get_allocator().max_size(): " << s_map_01.get_allocator().max_size() << std::endl;
    std::cout << std::endl;

    std::cout << "f_map_01.key_comp()(1, 2)=" << f_map_01.key_comp()(1, 2) << std::endl;
    std::cout << "s_map_01.key_comp()(1, 2)=" << s_map_01.key_comp()(1, 2) << std::endl;
    std::cout << std::endl;

    std::cout << "f_map_01.value_comp()((1, tc1), (2, tc2))="
              << f_map_01.value_comp()(ft::make_pair(1, tc1), ft::make_pair(2, tc2)) << std::endl;
    std::cout << "s_map_01.value_comp()((1, tc1), (2, tc2))="
              << s_map_01.value_comp()(std::make_pair(1, tc1), std::make_pair(2, tc2)) << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;


    std::cout << red << "SET" << reset << std::endl << std::endl;

    std::cout << "4.01___________________________________________" << std::endl;

    std::cout << blue << "creating ft::set<testClass>, size(), max_size()" << reset << std::endl;
    std::cout << "creating ft::set<testClass> f_set_01 and std::set<testClass> s_set_01" << std::endl;
    ft::set <testClass> f_set_01;
    std::set<testClass> s_set_01;
    std::cout << "f_set_01.size()=" << f_set_01.size() << std::endl;
    std::cout << "f_set_01.max_size()=" << f_set_01.max_size() << std::endl;
    std::cout << std::endl;
    std::cout << "s_set_01.size()=" << s_set_01.size() << std::endl;
    std::cout << "s_set_01.max_size()=" << s_set_01.max_size() << std::endl;
    std::cout << std::endl;


    std::cout << "4.02___________________________________________" << std::endl;
    std::cout << blue << "insert(val)" << reset << std::endl;
    std::cout << "insert(2)" << std::endl;
    std::cout << "f_set_01.insert(2)=" << std::endl;
    ft::pair<ft::set<testClass>::iterator, bool> f_pair_set
                                                         = f_set_01.insert(tc2);
    std::cout << "ft: pair.first = " << *(f_pair_set.first) << ", pair.second = " << (bool) f_pair_set.second
              << std::endl;
    std::cout << "f_set_01.insert(2)=" << std::endl;
    f_pair_set = f_set_01.insert(tc2);
    std::cout << "ft: pair.first = " << *(f_pair_set.first) << ", pair.second = " << (bool) f_pair_set.second
              << std::endl;
    std::cout << "f_set_01.size=" << f_set_01.size() << std::endl;
    std::cout << std::endl;

    std::cout << "s_set_01.insert(2)" << std::endl;
    std::pair<std::set<testClass>::iterator, bool> s_pair_set
                                                           = s_set_01.insert(tc2);
    std::cout << "std: pair.first = " << *(s_pair_set.first) << ", pair.second = " << (bool) s_pair_set.second
              << std::endl;
    std::cout << "s_set_01.insert(2)" << std::endl;
    s_pair_set = s_set_01.insert(tc2);
    std::cout << "std: pair.first = " << *(s_pair_set.first) << ", pair.second = " << (bool) s_pair_set.second
              << std::endl;
    std::cout << "s_set_01.size=" << s_set_01.size() << std::endl;
    std::cout << std::endl;

    std::cout << "insert(3)" << std::endl;
    f_set_01.insert(tc3);
    s_set_01.insert(tc3);

    std::cout << "insert(1)" << std::endl;
    f_set_01.insert(tc1);
    s_set_01.insert(tc1);

    std::cout << "insert(4)" << std::endl;
    f_set_01.insert(tc4);
    s_set_01.insert(tc4);

    std::cout << "insert(5)" << std::endl;
    f_set_01.insert(tc5);
    s_set_01.insert(tc5);

    std::cout << "insert(6)" << std::endl;
    f_set_01.insert(tc6);
    s_set_01.insert(tc6);

    std::cout << "insert(7)" << std::endl;
    f_set_01.insert(tc7);
    s_set_01.insert(tc7);

    std::cout << "insert(8)" << std::endl;
    f_set_01.insert(tc8);
    s_set_01.insert(tc8);

    std::cout << "insert(100)" << std::endl;
    f_set_01.insert(tc100);
    s_set_01.insert(tc100);

    std::cout << "insert(50)" << std::endl;
    f_set_01.insert(tc50);
    s_set_01.insert(tc50);

    std::cout << "insert(9)" << std::endl;
    f_set_01.insert(tc9);
    s_set_01.insert(tc9);
    std::cout << "f_set_01.size=" << f_set_01.size() << std::endl;
    std::cout << "s_set_01.size=" << s_set_01.size() << std::endl;
    std::cout << std::endl;

    std::cout << blue << "insert(iterator position, val), find()" << reset << std::endl;
    std::cout << "insert (begin(), 0)" << std::endl;
    f_set_01.insert(f_set_01.begin(), tc0);
    std::cout << "f_set_01.size=" << f_set_01.size() << std::endl;
    s_set_01.insert(s_set_01.begin(), tc0);
    std::cout << "s_set_01.size=" << s_set_01.size() << std::endl;
    std::cout << std::endl;

    std::cout << "insert(end(), 101)" << std::endl;
    f_set_01.insert(f_set_01.end(), tc101);
    std::cout << "f_set_01.size=" << f_set_01.size() << std::endl;
    s_set_01.insert(s_set_01.end(), tc101);
    std::cout << "s_set_01.size=" << s_set_01.size() << std::endl;
    std::cout << std::endl;

    std::cout << "insert(find(9), 49)" << reset << std::endl;
    f_set_01.insert(f_set_01.find(9), tc49);
    std::cout << "f_set_01.size=" << f_set_01.size() << std::endl;
    s_set_01.insert(s_set_01.find(9), tc49);
    std::cout << "s_set_01.size=" << s_set_01.size() << std::endl;
    std::cout << std::endl;

    std::cout << blue << "insert(iterator first, iterator last)" << reset << std::endl;
    std::cout << "creating std::list<testClass> s_set_list: list(88, 89)" << std::endl;
    std::list<testClass> s_set_list;
    s_set_list.push_back(testClass(88));
    s_set_list.push_back(testClass(89));

    std::cout << "insert(s_set_list.begin(), s_set_list.end())" << reset << std::endl;
    f_set_01.insert(s_set_list.begin(), s_set_list.end());
    std::cout << "f_set_01.size=" << f_set_01.size() << std::endl;
    s_set_01.insert(s_set_list.begin(), s_set_list.end());
    std::cout << "s_set_01.size=" << s_set_01.size() << std::endl;
    std::cout << std::endl;

    std::cout << "4.02___________________________________________" << std::endl;
    std::cout << blue << "erase(val)" << reset << std::endl;
    std::cout << "erase(49)" << std::endl;
    f_set_01.erase(tc49);
    s_set_01.erase(tc49);
    std::cout << "f_set_01.size=" << f_set_01.size() << std::endl;
    std::cout << "s_set_01.size=" << s_set_01.size() << std::endl;
    std::cout << std::endl;
    std::cout << "erase(100)" << std::endl;
    f_set_01.erase(tc100);
    s_set_01.erase(tc100);
    std::cout << "erase(101)" << std::endl;
    f_set_01.erase(tc101);
    s_set_01.erase(tc101);
    std::cout << std::endl;

    std::cout << blue << "begin(), rbegin()" << reset << std::endl;
    std::cout << "*f_set_01.begin()=" << *f_set_01.begin() << std::endl;
    std::cout << "*f_set_01.rbegin()=" << *f_set_01.rbegin() << std::endl;
    std::cout << "*s_set_01.begin()=" << *s_set_01.begin() << std::endl;
    std::cout << "*s_set_01.rbegin()=" << *s_set_01.rbegin() << std::endl;
    std::cout << std::endl;

    std::cout << blue << "erase(iterator position)" << reset << std::endl;

    std::cout << "erase(begin())" << std::endl;
    f_set_01.erase(f_set_01.begin());
    s_set_01.erase(s_set_01.begin());
    std::cout << "f_set_01.size=" << f_set_01.size() << std::endl;
    std::cout << "s_set_01.size=" << s_set_01.size() << std::endl;
    std::cout << std::endl;

    std::cout << "erase(0)" << std::endl;
    f_set_01.erase(tc0);
    s_set_01.erase(tc0);
    std::cout << "f_set_01.size=" << f_set_01.size() << std::endl;
    std::cout << "s_set_01.size=" << s_set_01.size() << std::endl;
    std::cout << std::endl;

    std::cout << "4.03___________________________________________" << std::endl;
    std::cout << blue << "find(val), count(), equal_range()" << reset << std::endl;

    std::cout << "f_set_01.count(89)=" << f_set_01.count(testClass(89)) << std::endl;
    std::cout << "s_set_01.count(89)=" << s_set_01.count(testClass(89)) << std::endl;
    std::cout << std::endl;

    std::cout << "printing f_set_01.equal_range(89):" << std::endl;
    ft::pair <ft::set<testClass>::iterator, ft::set<testClass>::iterator> f_set_pair_it;
    f_set_pair_it = f_set_01.equal_range(testClass(89));
    for (ft::set<testClass>::iterator it = f_set_pair_it.first; it != f_set_pair_it.second; ++it) {
        std::cout << *it << ", ";
    }
    std::cout << std::endl;

    std::cout << "printing s_set_01.equal_range(89):" << std::endl;
    std::pair<std::set<testClass>::iterator, std::set<testClass>::iterator> s_set_pair_it;
    s_set_pair_it = s_set_01.equal_range(testClass(89));
    for (std::set<testClass>::iterator it = s_set_pair_it.first; it != s_set_pair_it.second; ++it) {
        std::cout << *it << ", ";
    }
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "erase(find(*rbegin()))" << std::endl;
    f_set_01.erase(f_set_01.find(*f_set_01.rbegin()));
    s_set_01.erase(s_set_01.find(*s_set_01.rbegin()));
    std::cout << "f_set_01.size=" << f_set_01.size() << std::endl;
    std::cout << "s_set_01.size=" << s_set_01.size() << std::endl;
    std::cout << std::endl;

    std::cout << "*f_set_01.begin()=" << *f_set_01.begin() << std::endl;
    std::cout << "*f_set_01.rbegin()=" << *f_set_01.rbegin() << std::endl;
    std::cout << "*s_set_01.begin()=" << *s_set_01.begin() << std::endl;
    std::cout << "*s_set_01.rbegin()=" << *s_set_01.rbegin() << std::endl;
    std::cout << std::endl;

    std::cout << "f_set_01.count(89)=" << f_set_01.count(testClass(89)) << std::endl;
    std::cout << "s_set_01.count(89)=" << s_set_01.count(testClass(89)) << std::endl;
    std::cout << std::endl;

    std::cout << "4.04___________________________________________" << std::endl;
    std::cout << blue << "erase(iterator first, iterator last), lower_bound(), upper_bound" << reset << std::endl;

    std::cout << "*f_set_01.lower_bound(50)=" << *f_set_01.lower_bound(50)
              << std::endl;
    std::cout << "*s_set_01.lower_bound(50)=" << *s_set_01.lower_bound(50) << std::endl;

    std::cout << "*(++f_set_01.lower_bound(50))=" << *(++f_set_01.lower_bound(50)) << std::endl;
    std::cout << "*(++s_set_01.lower_bound(50))=" << *(++s_set_01.lower_bound(50)) << std::endl;

    std::cout << "*f_set_01.upper_bound(50)=" << *f_set_01.upper_bound(50) << std::endl;
    std::cout << "*s_set_01.upper_bound(50)=" << *s_set_01.upper_bound(50) << std::endl;
    std::cout << std::endl;

    std::cout << "erase(lower_bound(50), upper_bound(50)" << std::endl;
    f_set_01.erase(f_set_01.lower_bound(50), f_set_01.upper_bound(50));
    s_set_01.erase(s_set_01.lower_bound(50), s_set_01.upper_bound(50));
    std::cout << "f_set_01.size=" << f_set_01.size() << std::endl;
    std::cout << "s_set_01.size=" << s_set_01.size() << std::endl;
    std::cout << std::endl;


    std::cout << "4.05___________________________________________" << std::endl;
    std::cout << blue << "iterator arithmetics, end(), rend()" << reset << std::endl;

    std::cout << "ft::set<testClass>::iterator f_set_01_it" << std::endl;
    std::cout << "std::set<testClass>::iterator s_set_01_it" << std::endl;
    ft::set<testClass>::iterator  f_set_01_it;
    std::set<testClass>::iterator s_set_01_it;
    std::cout << "f_set_01_it = f_set_01.begin()" << std::endl;
    std::cout << "s_set_01_it = s_set_01.begin()" << std::endl;
    f_set_01_it = f_set_01.begin();
    s_set_01_it = s_set_01.begin();
    std::cout << std::endl;
    std::cout << "*f_set_01_it=" << *f_set_01_it << std::endl;
    std::cout << "*s_set_01_it=" << *s_set_01_it << std::endl;
    std::cout << std::endl;
    std::cout << "*(++f_set_01_it)=" << *(++f_set_01_it) << std::endl;
    std::cout << "*(++s_set_01_it)=" << *(++s_set_01_it) << std::endl;
    std::cout << std::endl;
    std::cout << "*(++f_set_01_it)=" << *(++f_set_01_it) << std::endl;
    std::cout << "*(++s_set_01_it)=" << *(++s_set_01_it) << std::endl;
    std::cout << std::endl;
    std::cout << "*(f_set_01_it++)=" << *(f_set_01_it++) << std::endl;
    std::cout << "*(s_set_01_it++)=" << *(s_set_01_it++) << std::endl;
    std::cout << std::endl;
    std::cout << "*f_set_01_it=" << *f_set_01_it << std::endl;
    std::cout << "*s_set_01_it=" << *s_set_01_it << std::endl;
    std::cout << std::endl;
    std::cout << "*(--f_set_01_it)=" << *(--f_set_01_it) << std::endl;
    std::cout << "*(--s_set_01_it)=" << *(--s_set_01_it) << std::endl;
    std::cout << std::endl;
    std::cout << "*(f_set_01_it--)=" << *(f_set_01_it--) << std::endl;
    std::cout << "*(s_set_01_it--)=" << *(s_set_01_it--) << std::endl;
    std::cout << std::endl;
    std::cout << "*f_set_01_it=" << *f_set_01_it << std::endl;
    std::cout << "*s_set_01_it=" << *s_set_01_it << std::endl;
    std::cout << std::endl;

    std::cout << "ft::set<testClass>::reverse_iterator f_set_01_rit" << std::endl;
    std::cout << "std::set<testClass>::reverse_iterator s_set_01_rit" << std::endl;
    ft::set<testClass>::reverse_iterator  f_set_01_rit;
    std::set<testClass>::reverse_iterator s_set_01_rit;
    std::cout << "f_set_01_rit = f_set_01.rbegin()" << std::endl;
    std::cout << "s_set_01_rit = s_set_01.rbegin()" << std::endl;
    f_set_01_rit = f_set_01.rbegin();
    s_set_01_rit = s_set_01.rbegin();
    std::cout << std::endl;
    std::cout << "*f_set_01_rit=" << *f_set_01_rit << std::endl;
    std::cout << "*s_set_01_rit=" << *s_set_01_rit << std::endl;
    std::cout << std::endl;
    std::cout << "*(++f_set_01_rit)=" << *(++f_set_01_rit) << std::endl;
    std::cout << "*(++s_set_01_rit)=" << *(++s_set_01_rit) << std::endl;
    std::cout << std::endl;

    std::cout << "printing f_set_01 from begin() to end()" << std::endl;
    for (ft::set<testClass>::iterator it = f_set_01.begin(); it != f_set_01.end(); ++it) {
        std::cout << *it << ", ";
    }
    std::cout << std::endl;
    std::cout << "printing s_set_01 from begin() to end()" << std::endl;
    for (std::set<testClass>::iterator it = s_set_01.begin(); it != s_set_01.end(); ++it) {
        std::cout << *it << ", ";
    }
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "printing f_set_01 from rbegin() to rend()" << std::endl;
    for (ft::set<testClass>::reverse_iterator it = f_set_01.rbegin(); it != f_set_01.rend(); ++it) {
        std::cout << *it << ", ";
    }
    std::cout << std::endl;
    std::cout << "printing s_set_01 from rbegin() to rend()" << std::endl;
    for (std::set<testClass>::reverse_iterator it = s_set_01.rbegin(); it != s_set_01.rend(); ++it) {
        std::cout << *it << ", ";
    }
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "4.06___________________________________________" << std::endl;
    std::cout << blue << "iterators compirising" << reset << std::endl;

    std::cout << "ft::set<testClass>::iterator f_set_02_it" << std::endl;
    ft::set<testClass>::iterator f_set_02_it;
    std::cout << "f_set_01_it and f_set_01_it = f_set_01.begin()" << std::endl;
    f_set_01_it = f_set_01.begin();
    f_set_02_it = f_set_01.begin();
    std::cout << "(f_set_01_it == f_set_02_it)=" << (f_set_01_it == f_set_02_it) << std::endl;
    std::cout << std::endl;

    std::cout << "ft::set<testClass>::const_iterator f_set_01_itc" << std::endl;
    ft::set<testClass>::const_iterator f_set_01_itc;
    std::cout << "f_set_01_itc = f_set_01.begin()" << std::endl;
    f_set_01_itc = f_set_01.begin();
    std::cout << "(f_set_01_it == f_set_01_itc)=" << (f_set_01_it == f_set_01_itc) << std::endl;
    std::cout << std::endl;

    std::cout << "4.07___________________________________________" << std::endl;
    std::cout << blue << "copy constructor" << reset << std::endl;

    std::cout << "constructing const f_set_01_copy and s_set_01_copy from f_set_01 and s_set_01" << std::endl;
    ft::set <testClass> f_set_01_copy(f_set_01);
    std::set<testClass> s_set_01_copy(s_set_01);

    std::cout << "printing f_set_01_copy from begin() to end()" << std::endl;
    for (ft::set<testClass>::iterator it = f_set_01_copy.begin(); it != f_set_01_copy.end(); ++it) {
        std::cout << *it << ", ";
    }
    std::cout << std::endl;
    std::cout << "printing s_set_01_copy from begin() to end()" << std::endl;
    for (std::set<testClass>::iterator it = s_set_01_copy.begin(); it != s_set_01_copy.end(); ++it) {
        std::cout << *it << ", ";
    }
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "f_set_01_copy.size=" << f_set_01_copy.size() << std::endl;
    std::cout << "s_set_01_copy.size=" << s_set_01_copy.size() << std::endl;
    std::cout << std::endl;

    std::cout << "4.08___________________________________________" << std::endl;
    std::cout << blue << "assignment overload" << reset << std::endl;

    std::cout << "f_set_01_ao and s_set_01_ao" << std::endl;
    ft::set <testClass> f_set_01_ao;
    std::set<testClass> s_set_01_ao;
    std::cout << "f_set_01_ao = f_set_01 and s_set_01_ao = s_set_01" << std::endl;
    f_set_01_ao = f_set_01;
    s_set_01_ao = s_set_01;

    std::cout << "printing f_set_01_ao from begin() to end()" << std::endl;
    for (ft::set<testClass>::iterator it = f_set_01_ao.begin(); it != f_set_01_ao.end(); ++it) {
        std::cout << *it << ", ";
    }
    std::cout << std::endl;
    std::cout << "printing s_set_01_ao from begin() to end()" << std::endl;
    for (std::set<testClass>::iterator it = s_set_01_ao.begin(); it != s_set_01_ao.end(); ++it) {
        std::cout << *it << ", ";
    }
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "f_set_01_ao.size=" << f_set_01_ao.size() << std::endl;
    std::cout << "s_set_01_ao.size=" << s_set_01_ao.size() << std::endl;
    std::cout << std::endl;

    std::cout << "4.09___________________________________________" << std::endl;
    std::cout << blue << "swap" << reset << std::endl;

    std::cout << "creating f_set_02 and s_set_02, both = {5, 6, 7}" << std::endl;
    ft::set <testClass> f_set_02;
    f_set_02.insert(tc5);
    f_set_02.insert(tc6);
    f_set_02.insert(tc7);
    std::set<testClass> s_set_02;
    s_set_02.insert(tc5);
    s_set_02.insert(tc6);
    s_set_02.insert(tc7);
    std::cout << std::endl;

    ft::set<testClass>::iterator f_set_01_i = f_set_01.begin();
    std::cout << "ft::set<testClass>::iterator f_set_01_i = f_set_01.begin()=" << *f_set_01_i << std::endl;
    ft::set<testClass>::iterator f_set_02_i = f_set_02.begin();
    std::cout << "ft::set<testClass>::iterator f_set_02_i = f_set_02.begin()=" << *f_set_02_i << std::endl;
    std::set<testClass>::iterator s_set_01_i = s_set_01.begin();
    std::cout << "std::set<testClass>::iterator s_set_01_i = s_set_01.begin()=" << *s_set_01_i << std::endl;
    std::set<testClass>::iterator s_set_02_i = s_set_02.begin();
    std::cout << "std::set<testClass>::iterator s_set_02_i = s_set_02.begin()=" << *s_set_02_i << std::endl;
    std::cout << std::endl;
    std::cout << "after swap f_set_01 and f_set_02:" << std::endl;
    ft::swap(f_set_01, f_set_02);
    std::cout << "printing f_set_01" << std::endl;
    for (ft::set<testClass>::iterator it = f_set_01.begin(); it != f_set_01.end(); ++it) {
        std::cout << *it << ", ";
    }
    std::cout << std::endl;
    std::cout << "iterator f_set_01_i = " << *f_set_01_i << std::endl;
    std::cout << "printing f_set_02" << std::endl;
    for (ft::set<testClass>::iterator it = f_set_02.begin(); it != f_set_02.end(); ++it) {
        std::cout << *it << ", ";
    }
    std::cout << std::endl;
    std::cout << "iterator f_set_02_i = " << *f_set_02_i << std::endl;
    std::cout << std::endl;

    std::cout << "after swap s_set_01 and s_set_02:" << std::endl;
    std::swap(s_set_01, s_set_02);
    std::cout << "printing s_set_01" << std::endl;
    for (std::set<testClass>::iterator it = s_set_01.begin(); it != s_set_01.end(); ++it) {
        std::cout << *it << ", ";
    }
    std::cout << std::endl;
    std::cout << "iterator s_set_01_i = " << *s_set_01_i << std::endl;
    std::cout << "printing s_set_02" << std::endl;
    for (std::set<testClass>::iterator it = s_set_02.begin(); it != s_set_02.end(); ++it) {
        std::cout << *it << ", ";
    }
    std::cout << std::endl;
    std::cout << "iterator s_set_02_i = " << *s_set_02_i << std::endl;
    std::cout << std::endl;

    std::cout << "4.10___________________________________________" << std::endl;
    std::cout << blue << "compirising operators" << reset << std::endl;

    std::cout << "(f_set_01 == f_set_02)=" << (f_set_01 == f_set_02) << std::endl;
    std::cout << "(s_set_01 == s_set_02)=" << (s_set_01 == s_set_02) << std::endl;
    std::cout << std::endl;

    std::cout << "(f_set_01 > f_set_02)=" << (f_set_01 > f_set_02) << std::endl;
    std::cout << "(s_set_01 > s_set_02)=" << (s_set_01 > s_set_02) << std::endl;
    std::cout << std::endl;

    std::cout << "(f_set_01 < f_set_02)=" << (f_set_01 < f_set_02) << std::endl;
    std::cout << "(s_set_01 < s_set_02)=" << (s_set_01 < s_set_02) << std::endl;
    std::cout << std::endl;

    std::cout << "4.11___________________________________________" << std::endl;
    std::cout << blue << "clear(), empty()" << reset << std::endl;

    std::cout << "after clear()" << std::endl;
    f_set_01.clear();
    s_set_01.clear();
    std::cout << "f_set_01.size=" << f_set_01.size() << std::endl;
    std::cout << "s_set_01.size=" << s_set_01.size() << std::endl;
    std::cout << std::endl;
    std::cout << "f_set_01.empty()=" << f_set_01.empty() << std::endl;
    std::cout << "s_set_01.empty()=" << s_set_01.empty() << std::endl;
    std::cout << std::endl;

    std::cout << "4.12___________________________________________" << std::endl;
    std::cout << blue << "get_allocator(), key_comp(), value_comp()" << reset << std::endl;
    std::cout << "f_set_01.get_allocator().max_size(): " << f_set_01.get_allocator().max_size() << std::endl;
    std::cout << "s_set_01.get_allocator().max_size(): " << s_set_01.get_allocator().max_size() << std::endl;
    std::cout << std::endl;

    std::cout << "f_set_01.key_comp()(1, 2)=" << f_set_01.key_comp()(1, 2) << std::endl;
    std::cout << "s_set_01.key_comp()(1, 2)=" << s_set_01.key_comp()(1, 2) << std::endl;
    std::cout << std::endl;

    std::cout << "f_set_01.value_comp()(1, 2)=" << f_set_01.value_comp()(1, 2) << std::endl;
    std::cout << "s_set_01.value_comp()(1, 2)=" << s_set_01.value_comp()(1, 2) << std::endl;

    return (0);
}
