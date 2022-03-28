#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
#include "vector.hpp"

namespace ft {
    template<class T, class Container = ft::vector<T> >
    class stack {
    public:
        typedef typename Container::value_type value_type;
        typedef typename Container::size_type  size_type;
        typedef Container                      container_type;

    protected:
        Container c;

    public:
        explicit stack(Container const &cont = Container()) throw(): c(cont) {}

        stack(const stack &rhs) : c(rhs.c) {}

        stack &operator=(stack const &rhs) {
            if (this == &rhs) {
                return *this;
            }
            c = rhs.c;
            return *this;
        }

        ~stack() {}

        bool empty() const {
            return c.empty();
        }

        size_type size() const {
            return c.size();
        }

        value_type &top() {
            return c.back();
        }

        const value_type &top() const {
            return c.back();
        }

        void push(const value_type &x) {
            c.push_back(x);
        }

        void pop() {
            c.pop_back();
        }

        friend bool operator==(const stack &lhs, const stack &rhs) {
            return lhs.c == rhs.c;
        }

        friend bool operator!=(const stack &lhs, const stack &rhs) {
            return lhs.c != rhs.c;
        }

        friend bool operator>(const stack &lhs, const stack &rhs) {
            return lhs.c > rhs.c;
        }

        friend bool operator<(const stack &lhs, const stack &rhs) {
            return lhs.c < rhs.c;
        }

        friend bool operator>=(const stack &lhs, const stack &rhs) {
            return lhs.c >= rhs.c;
        }

        friend bool operator<=(const stack &lhs, const stack &rhs) {
            return lhs.c <= rhs.c;
        }
    };

    template<class T, class Container>
    bool operator==(const stack<T, Container> &lhs, const stack<T, Container> &rhs) {
        return lhs == rhs;
    }

    template<class T, class Container>
    bool operator!=(const stack<T, Container> &lhs, const stack<T, Container> &rhs) {
        return lhs != rhs;
    }

    template<class T, class Container>
    bool operator>(const stack<T, Container> &lhs, const stack<T, Container> &rhs) {
        return lhs > rhs;
    }

    template<class T, class Container>
    bool operator<(const stack<T, Container> &lhs, const stack<T, Container> &rhs) {
        return lhs < rhs;
    }

    template<class T, class Container>
    bool operator>=(const stack<T, Container> &lhs, const stack<T, Container> &rhs) {
        return lhs >= rhs;
    }

    template<class T, class Container>
    bool operator<=(const stack<T, Container> &lhs, const stack<T, Container> &rhs) {
        return lhs <= rhs;
    }
}

#endif //STACK_HPP
