#ifndef VECTOR_CONST_ITERATOR_HPP
#define VECTOR_CONST_ITERATOR_HPP

namespace ft {
    template<typename T>
    class vector_iterator;

    struct random_access_iterator_tag;

    template<typename T>
    class vector_const_iterator {

    public:
        typedef const T                    *pointer;
        typedef const T                    &reference;
        typedef std::ptrdiff_t             difference_type;
        typedef T                          value_type;
        typedef random_access_iterator_tag iterator_category;

        vector_const_iterator(pointer ptr = NULL) : _ptr(ptr) {}

        vector_const_iterator(vector_const_iterator const &src) {
            _ptr = src._ptr;
        }

        vector_const_iterator(vector_iterator<T> const &src) {
            _ptr = src.operator->();
        }

        vector_const_iterator &operator=(vector_const_iterator const &rhs) {
            if (this == &rhs) {
                return *this;
            }
            _ptr = rhs._ptr;
            return *this;
        }

        ~vector_const_iterator() {}

        reference operator*() const throw() {
            return *_ptr;
        }

        pointer operator->() const throw() {
            return _ptr;
        }

        reference operator[](difference_type n) const throw() {
            vector_const_iterator newIter(*this);
            newIter._ptr = newIter._ptr + n;
            return *newIter;
        }

        vector_const_iterator operator++(int) throw() {
            vector_const_iterator old(*this);
            ++*this;
            return old;
        }

        vector_const_iterator operator--(int) throw() {
            vector_const_iterator old(*this);
            --*this;
            return old;
        }

        vector_const_iterator &operator++() throw() {
            ++_ptr;
            return *this;
        }

        vector_const_iterator &operator--() throw() {
            --_ptr;
            return *this;
        }

        vector_const_iterator operator+(difference_type n) const throw() {
            vector_const_iterator newIter(*this);
            newIter._ptr = newIter._ptr + n;
            return newIter;
        }

        vector_const_iterator operator-(difference_type n) const throw() {
            vector_const_iterator newIter(*this);
            newIter._ptr = newIter._ptr - n;
            return newIter;
        }

        vector_const_iterator operator+=(difference_type n) throw() {
            _ptr += n;
            return *this;
        }

        vector_const_iterator operator-=(difference_type n) throw() {
            _ptr -= n;
            return *this;
        }

        friend vector_const_iterator operator+(difference_type n, vector_const_iterator rhs) throw() {
            vector_const_iterator newIter(rhs);
            newIter._ptr = newIter._ptr + n;
            return newIter;
        }

        difference_type operator-(vector_const_iterator const &rhs) const throw() {
            return (this->_ptr - rhs._ptr);
        }

        friend bool operator==(vector_const_iterator const &lhs, vector_const_iterator const &rhs) throw() {
            return (lhs._ptr == rhs._ptr);
        }

        friend bool operator!=(vector_const_iterator const &lhs, vector_const_iterator const &rhs) throw() {
            return (lhs._ptr != rhs._ptr);
        }

        friend bool operator>(vector_const_iterator const &lhs, vector_const_iterator const &rhs) throw() {
            return (lhs._ptr > rhs._ptr);
        }

        friend bool operator<(vector_const_iterator const &lhs, vector_const_iterator const &rhs) throw() {
            return (lhs._ptr < rhs._ptr);
        }

        friend bool operator>=(vector_const_iterator const &lhs, vector_const_iterator const &rhs) throw() {
            return (lhs._ptr >= rhs._ptr);
        }

        friend bool operator<=(vector_const_iterator const &lhs, vector_const_iterator const &rhs) throw() {
            return (lhs._ptr <= rhs._ptr);
        }

        pointer base() const throw() {
            return _ptr;
        }

    protected:
        pointer _ptr;

    };
}

#endif //VECTOR_CONST_ITERATOR_HPP
