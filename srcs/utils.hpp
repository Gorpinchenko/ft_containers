#ifndef ITERATORS_UTILS_HPP
#define ITERATORS_UTILS_HPP

namespace ft {
    struct input_iterator_tag {};
    struct output_iterator_tag {};
    struct forward_iterator_tag : public input_iterator_tag {};
    struct bidirectional_iterator_tag : public forward_iterator_tag {};
    struct random_access_iterator_tag : public bidirectional_iterator_tag {};

    template<class Iterator>
    struct iterator_traits {
        typedef typename Iterator::difference_type   difference_type;
        typedef typename Iterator::value_type        value_type;
        typedef typename Iterator::pointer           pointer;
        typedef typename Iterator::reference         reference;
        typedef typename Iterator::iterator_category iterator_category;
    };

    template<class T>
    struct iterator_traits<T *> {
        typedef ptrdiff_t                  difference_type;
        typedef T                          value_type;
        typedef T                          *pointer;
        typedef T                          &reference;
        typedef random_access_iterator_tag iterator_category;
    };

    template<class T>
    struct iterator_traits<const T *> {
        typedef std::ptrdiff_t             difference_type;
        typedef T                          value_type;
        typedef const T                    *pointer;
        typedef const T                    &reference;
        typedef random_access_iterator_tag iterator_category;
    };

    template<class T>
    struct is_integral { static const bool value = false; };
    template<>
    struct is_integral<bool> { static const bool value = true; };
    template<>
    struct is_integral<char> { static const bool value = true; };
    template<>
    struct is_integral<signed char> { static const bool value = true; };
    template<>
    struct is_integral<unsigned char> { static const bool value = true; };
    template<>
    struct is_integral<wchar_t> { static const bool value = true; };
    template<>
    struct is_integral<short> { static const bool value = true; };
    template<>
    struct is_integral<unsigned short> { static const bool value = true; };
    template<>
    struct is_integral<int> { static const bool value = true; };
    template<>
    struct is_integral<unsigned int> { static const bool value = true; };
    template<>
    struct is_integral<long> { static const bool value = true; };
    template<>
    struct is_integral<unsigned long> { static const bool value = true; };
    template<>
    struct is_integral<long long> { static const bool value = true; };
    template<>
    struct is_integral<unsigned long long> { static const bool value = true; };

    template<bool Cond, class T = void>
    struct enable_if {};
    template<class T>
    struct enable_if<true, T> {
        typedef T type;
    };

    template<class T1, class T2>
    struct pair {
        typedef T1 first_type;
        typedef T2 second_type;

        pair() : first(T1()), second(T2()) {}

        pair(const T1 &t1, const T2 &t2) : first(t1), second(t2) {}

        template<class U1, class U2>
        pair(const pair<U1, U2> &p) : first(p.first), second(p.second) {}

        pair &operator=(pair &rhs) {
            if (this == &rhs) {
                return *this;
            }
            first  = rhs.first;
            second = rhs.second;
            return *this;
        }

        pair &operator=(pair const &rhs) {
            if (this == &rhs) {
                return *this;
            }
            first  = rhs.first;
            second = rhs.second;
            return *this;
        }

        ~pair() {}

        void swap(pair &rhs) {
            T1 temp_f = this->first;
            T2 temp_s = this->second;
            this->first  = rhs.first;
            this->second = rhs.second;
            rhs.first    = temp_f;
            rhs.second   = temp_s;
        }

        T1 first;
        T2 second;
    };

    template<class T1, class T2>
    bool operator==(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) {
        return (lhs.first == rhs.first && lhs.second == rhs.second);
    }

    template<class T1, class T2>
    bool operator!=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) {
        return !(lhs == rhs);
    }

    template<class T1, class T2>
    bool operator<(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) {
        return lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second
                                                                     < rhs.second);
    }

    template<class T1, class T2>
    bool operator>(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) {
        return (rhs < lhs);
    }

    template<class T1, class T2>
    bool operator>=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) {
        return !(lhs < rhs);
    }

    template<class T1, class T2>
    bool operator<=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) {
        return !(rhs < lhs);
    }

    template<class T1, class T2>
    pair<T1, T2> make_pair(T1 lhs, T2 rhs) {
        return pair<T1, T2>(lhs, rhs);
    }

    template<class InputIterator1, class InputIterator2>
    bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2) {
        for (; first1 != last1; ++first1, (void) ++first2) {
            if (*first1 != *first2) {
                return false;
            }
        }
        return true;
    }

    template<class InputIterator1, class InputIterator2, class BinaryPredicate>
    bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred) {
        for (; first1 != last1; ++first1, (void) ++first2) {
            if (!pred(*first1, *first2)) {
                return false;
            }
        }
        return true;
    }

    template<class InputIterator1, class InputIterator2>
    bool
    lexicographical_compare(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2) {
        for (; first1 != last1 && first2 != last2; ++first1, ++first2) {
            if (*first1 < *first2) {
                return true;
            } else if (*first1 > *first2) {
                return false;
            }
            return (first1 == last1) && (first2 != last2);
        }
        return false;
    }

    template<class InputIterator1, class InputIterator2, class Compare>
    bool
    lexicographical_compare(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2,
                            Compare comp) {
        for (; first1 != last1 && first2 != last2; ++first1, ++first2) {
            if (*first1 == *first2 || comp(*first1, *first2)) {
                return true;
            } else if (comp(*first2, *first1)) {
                return false;
            }
            return (first1 == last1) && (first2 != last2);
        }
        return false;
    }

    template<class T>
    struct less {
        bool operator()(T &lhs, T &rhs) {
            return lhs < rhs;
        }

        bool operator()(const T &lhs, const T &rhs) const {
            return lhs < rhs;
        }
    };
}

#endif //ITERATORS_UTILS_HPP
