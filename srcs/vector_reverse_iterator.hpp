#ifndef VECTOR_REVERSE_ITERATOR_HPP
#define VECTOR_REVERSE_ITERATOR_HPP

namespace ft {
    template<typename T>
    class vector_const_reverse_iterator;

    struct random_access_iterator_tag;

    template<typename T>
    class vector_reverse_iterator {

    public:
        typedef T                          *pointer;
        typedef T                          &reference;
        typedef std::ptrdiff_t             difference_type;
        typedef T                          value_type;
        typedef random_access_iterator_tag iterator_category;

        vector_reverse_iterator(pointer ptr = NULL) : _ptr(ptr) {}

        vector_reverse_iterator(vector_reverse_iterator const &src) {
            _ptr = src._ptr;
        }

        vector_reverse_iterator &operator=(vector_reverse_iterator const &rhs) {
            if (this == &rhs) {
                return *this;
            }
            _ptr = rhs._ptr;
            return *this;
        }

        ~vector_reverse_iterator() {}

        reference operator*() const throw() {
            return *_ptr;
        }

        pointer operator->() const throw() {
            return _ptr;
        }

        reference operator[](difference_type n) const throw() {
            vector_reverse_iterator newIter(*this);
            newIter._ptr = newIter._ptr - n;
            return *newIter;
        }

        vector_reverse_iterator operator++(int) throw() {
            vector_reverse_iterator old(*this);
            ++*this;
            return old;
        }

        vector_reverse_iterator operator--(int) throw() {
            vector_reverse_iterator oldIter(*this);
            --*this;
            return oldIter;
        }

        vector_reverse_iterator &operator++() throw() {
            --_ptr;
            return *this;
        }

        vector_reverse_iterator &operator--() throw() {
            ++_ptr;
            return *this;
        }

        vector_reverse_iterator operator+(difference_type n) const throw() {
            vector_reverse_iterator newIter(*this);
            newIter._ptr = newIter._ptr - n;
            return newIter;
        }

        vector_reverse_iterator operator-(difference_type n) const throw() {
            vector_reverse_iterator newIter(*this);
            newIter._ptr = newIter._ptr + n;
            return newIter;
        }

        vector_reverse_iterator operator+=(difference_type n) throw() {
            _ptr -= n;
            return *this;
        }

        vector_reverse_iterator operator-=(difference_type n) throw() {
            _ptr += n;
            return *this;
        }

        friend vector_reverse_iterator operator+(difference_type n, vector_reverse_iterator rhs) throw() {
            vector_reverse_iterator newIter(rhs);
            newIter._ptr = newIter._ptr - n;
            return newIter;
        }

        difference_type operator-(vector_reverse_iterator const &rhs) const throw() {
            return (rhs._ptr - this->_ptr);
        }

        friend bool operator==(vector_reverse_iterator const &lhs, vector_reverse_iterator const &rhs) throw() {
            return (lhs._ptr == rhs._ptr);
        }

        friend bool
        operator==(vector_reverse_iterator const &lhs, vector_const_reverse_iterator<T> const &rhs) throw() {
            return (lhs._ptr == rhs.operator->());
        }

        friend bool operator!=(vector_reverse_iterator const &lhs, vector_reverse_iterator const &rhs) throw() {
            return (lhs._ptr != rhs._ptr);
        }

        friend bool
        operator!=(vector_reverse_iterator const &lhs, vector_const_reverse_iterator<T> const &rhs) throw() {
            return (lhs._ptr != rhs.operator->());
        }

        friend bool operator>(vector_reverse_iterator const &lhs, vector_reverse_iterator const &rhs) throw() {
            return (lhs._ptr < rhs._ptr);
        }

        friend bool operator>(vector_reverse_iterator const &lhs, vector_const_reverse_iterator<T> const &rhs) throw() {
            return (lhs._ptr < rhs.operator->());
        }

        friend bool operator<(vector_reverse_iterator const &lhs, vector_reverse_iterator const &rhs) throw() {
            return (lhs._ptr > rhs._ptr);
        }

        friend bool operator<(vector_reverse_iterator const &lhs, vector_const_reverse_iterator<T> const &rhs) throw() {
            return (lhs._ptr > rhs.operator->());
        }

        friend bool operator>=(vector_reverse_iterator const &lhs, vector_reverse_iterator const &rhs) throw() {
            return (lhs._ptr <= rhs._ptr);
        }

        friend bool
        operator>=(vector_reverse_iterator const &lhs, vector_const_reverse_iterator<T> const &rhs) throw() {
            return (lhs._ptr <= rhs.operator->());
        }

        friend bool operator<=(vector_reverse_iterator const &lhs, vector_reverse_iterator const &rhs) throw() {
            return (lhs._ptr >= rhs._ptr);
        }

        friend bool
        operator<=(vector_reverse_iterator const &lhs, vector_const_reverse_iterator<T> const &rhs) throw() {
            return (lhs._ptr >= rhs.operator->());
        }

        pointer base() const throw() {
            return _ptr;
        }

    protected:
        pointer _ptr;

    };
}

#endif //VECTOR_REVERSE_ITERATOR_HPP
