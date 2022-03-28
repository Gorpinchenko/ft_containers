#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <cstddef>
#include <limits>
#include "vector_base.hpp"
#include "vector_iterator.hpp"
#include "vector_const_iterator.hpp"
#include "vector_reverse_iterator.hpp"
#include "vector_const_reverse_iterator.hpp"
#include "utils.hpp"

namespace ft {
    template<class T, class Allocator = std::allocator<T> >
    class vector : private vector_base<T, Allocator> {
    public:
        typedef T                                             value_type;
        typedef Allocator                                     allocator_type;
        typedef typename allocator_type::reference            reference;
        typedef typename allocator_type::const_reference      const_reference;
        typedef typename ft::vector_iterator<T>               iterator;
        typedef typename ft::vector_const_iterator<T>         const_iterator;
        typedef typename allocator_type::size_type            size_type;
        typedef typename allocator_type::difference_type      difference_type;
        typedef typename allocator_type::pointer              pointer;
        typedef typename allocator_type::const_pointer        const_pointer;
        typedef typename ft::vector_reverse_iterator<T>       reverse_iterator;
        typedef typename ft::vector_const_reverse_iterator<T> const_reverse_iterator;

    private:
        template<class InputIterator>
        void move_to_left(InputIterator it_copied, size_type n) {
            iterator last = end();
            for (; it_copied != last; ++it_copied) {
                *(it_copied - n) = *it_copied;
            }
        }

        template<class InputIterator>
        void move_to_right(InputIterator left_copied, size_type n) {
            iterator       it = --end() + n;
            for (size_type i  = 0; it > left_copied; --it, ++i) {
                if (i < n) {
                    this->_alloc.construct(&*it, value_type(*(it - n)));
                } else {
                    *it = *(it - n);
                }
            }
        }

        template<class U1, class U2>
        struct is_same { static const bool value = false; };
        template<class U1>
        struct is_same<U1, U1> { static const bool value = true; };

        template<class, class Enable = void>
        struct is_random_access_iterator { static const bool value = false; };
        template<typename T2>
        struct is_random_access_iterator<T2, typename enable_if<
                is_same<typename T2::iterator_category, random_access_iterator_tag>::value
                || is_same<typename T2::iterator_category, std::random_access_iterator_tag>::value
        >::type> {
            static const bool value = true;
        };

        template<class, class Enable = void>
        struct is_bidirectional_iterator {
            static const bool value = false;
        };
        template<typename T2>
        struct is_bidirectional_iterator<T2, typename enable_if<
                is_same<typename T2::iterator_category, bidirectional_iterator_tag>::value
                || is_same<typename T2::iterator_category, std::bidirectional_iterator_tag>::value
        >::type> {
            static const bool value = true;
        };

        template<class, class Enable = void>
        struct is_forward_iterator {
            static const bool value = false;
        };
        template<typename T2>
        struct is_forward_iterator<T2, typename enable_if<
                is_same<typename T2::iterator_category, forward_iterator_tag>::value
                || is_same<typename T2::iterator_category, std::forward_iterator_tag>::value
        >::type> {
            static const bool value = true;
        };

        template<class, class Enable = void>
        struct is_input_iterator {
            static const bool value = false;
        };
        template<typename T2>
        struct is_input_iterator<T2, typename enable_if<
                is_same<typename T2::iterator_category, input_iterator_tag>::value
                || is_same<typename T2::iterator_category, std::input_iterator_tag>::value
        >::type> {
            static const bool value = true;
        };

    public:
        explicit vector(const Allocator &alloc = Allocator()) :
                vector_base<T, Allocator>(alloc) {
        }

        explicit vector(size_type n, const T &value = T(), const Allocator &alloc = Allocator()) :
                vector_base<T, Allocator>(n, alloc) {
            for (size_type i = 0; i < this->_capacity; ++i, ++this->_size) {
                this->_alloc.construct(&this->_begin[i], value);
            }
            this->_end = this->_begin + this->_size;
        }

        template<class InputIterator>
        vector(InputIterator first, InputIterator last, const Allocator &alloc = Allocator(),
               typename enable_if<
                       is_random_access_iterator<InputIterator>::value
                       || is_bidirectional_iterator<InputIterator>::value
                       || is_forward_iterator<InputIterator>::value
               >::type * = NULL):
                vector_base<T, Allocator>(first, last, alloc) {
            for (int i = 0; first != last; ++first, ++i, ++this->_size) {
                this->_alloc.construct(&this->_begin[i], *first);
            }
            this->_end = this->_begin + this->_size;
        }

        template<class InputIterator>
        vector(InputIterator first, InputIterator last, const Allocator &alloc = Allocator(),
               typename enable_if<is_input_iterator<InputIterator>::value>::type * = NULL) :
                vector_base<T, Allocator>(alloc) {
            for (; first != last; ++first) {
                push_back(*first);
            }
        }

        vector(vector const &src) :
                vector_base<T, Allocator>(src.begin(), src.end(), src._alloc) {
            const_iterator first(src.begin());
            const_iterator last(src.end());
            for (int       i = 0; first != last; ++first, ++i, ++this->_size) {
                this->_alloc.construct(&this->_begin[i], *first);
            }
            this->_end = this->_begin + this->_size;
        }

        ~vector() {
            for (size_type i = 0; i < this->_size; ++i) {
                this->_alloc.destroy(&this->_begin[i]);
            }
        }

        void assign(size_type n, const_reference val) {
            clear();
            insert(begin(), n, val);
        }

        template<class InputIterator>
        void assign(InputIterator first, InputIterator last,
                    typename enable_if<
                            is_random_access_iterator<InputIterator>::value
                            || is_bidirectional_iterator<InputIterator>::value
                            || is_forward_iterator<InputIterator>::value
                            || is_input_iterator<InputIterator>::value
                    >::type * = NULL) {
            clear();
            insert(begin(), first, last);
        }

        Allocator get_allocator() const throw() {
            return this->_alloc;
        }

        iterator begin() throw() {
            return iterator(this->_begin);
        }

        const_iterator begin() const throw() {
            return const_iterator(this->_begin);
        }

        iterator end() throw() {
            return iterator(this->_end);
        }

        const_iterator end() const throw() {
            return const_iterator(this->_end);
        }

        reverse_iterator rbegin() throw() {
            return reverse_iterator(this->_end - 1);
        }

        const_reverse_iterator rbegin() const throw() {
            return const_reverse_iterator(this->_end - 1);
        }

        reverse_iterator rend() throw() {
            return reverse_iterator(this->_begin - 1);
        }

        const_reverse_iterator rend() const throw() {
            return const_reverse_iterator(this->_begin - 1);
        }

        size_type size() const throw() {
            return this->_size;
        }

        size_type capacity() const throw() {
            return this->_capacity;
        }

        bool empty() const throw() {
            if (this->_size == 0) {
                return true;
            } else {
                return false;
            }
        }

        size_type max_size() const throw() {
            size_type limit1 = this->_alloc.max_size();
            size_type limit2 = std::numeric_limits<difference_type>::max();
            if (limit1 <= limit2) {
                return limit1;
            } else {
                return limit2;
            }
        }

        void reserve(size_type n) {
            if (n <= this->_capacity) {
                return;
            }
            if (this->_size + n >= max_size()) {
                throw std::length_error("vector");
            }
            this->_old_begin    = this->_begin;
            this->_old_capacity = this->_capacity;
            this->_old_size     = this->_size;
            this->_size         = 0;
            this->_begin        = NULL;
            this->_begin        = this->_alloc.allocate(n);
            this->_capacity     = n;
            for (size_type i    = 0; i < this->_old_size; ++i, ++this->_size) {
                this->_alloc.construct(&this->_begin[i], this->_old_begin[i]);
            }
            for (size_type i    = 0; i < this->_old_size; ++i) {
                this->_alloc.destroy(&this->_old_begin[i]);
            }
            this->_alloc.deallocate(this->_old_begin, this->_old_capacity);
            this->_old_begin    = NULL;
            this->_old_capacity = 0;
            this->_end          = this->_begin + this->_size;
        }

        reference at(size_type n) {
            if (n >= this->_capacity) {
                throw std::out_of_range("vector");
            }
            return this->_begin[n];
        }

        const_reference at(size_type n) const {
            if (n >= this->_capacity) {
                throw std::out_of_range("vector");
            }
            return this->_begin[n];
        }

        reference front() {
            return *(begin());
        }

        const_reference front() const {
            return *(begin());
        }

        reference back() {
            return *(end() - 1);
        }

        const_reference back() const {
            return *(end() - 1);
        }

        void push_back(const_reference val) {
            if (this->_size == 0) {
                reserve(1);
            } else if (this->_size >= this->_capacity) {
                reserve(this->_capacity * 2);
            }
            this->_alloc.construct(&this->_begin[this->_size], val);
            ++this->_size;
            ++this->_end;
        }

        void pop_back() {
            this->_alloc.destroy(&this->_begin[this->_size - 1]);
            --this->_size;
            --this->_end;
        }

        iterator insert(iterator position, const_reference val) {
            size_type diff_first = position - begin();
            iterator  new_first  = position;
            if (this->_size >= this->_capacity) {
                size_type new_capacity = this->_capacity * 2;
                reserve(new_capacity);
                new_first = begin() + diff_first;
            }
            move_to_right(new_first, 1);
            *new_first = val;
            ++this->_size;
            ++this->_end;
            return new_first;
        }

        void insert(iterator position, size_type n, const_reference val) {
            if (size() + n > max_size()) {
                throw std::length_error("vector");
            }
            size_type diff_first   = position - begin();
            iterator  new_first    = position;
            size_type new_capacity = this->_capacity;
            if (this->_size >= this->_capacity) {
                new_capacity = this->_capacity * 2;
            }
            if (this->_size + n > new_capacity) {
                new_capacity = this->_size + n;
            }
            if (new_capacity > this->_capacity) {
                reserve(new_capacity);
                new_first = begin() + diff_first;
            }
            if (diff_first < this->_size) {
                move_to_right(new_first, n);
                for (size_type i = 0; i < n; ++i) {
                    *(new_first + i) = val;
                }
            } else {
                for (size_type i = 0; i < n; ++i) {
                    this->_alloc.construct(&*(new_first + i), val);
                }
            }
            this->_size += n;
            this->_end += n;
        }

        template<class InputIterator>
        void insert(iterator position, InputIterator first, InputIterator last,
                    typename enable_if<
                            is_random_access_iterator<InputIterator>::value
                            || is_bidirectional_iterator<InputIterator>::value
                            || is_forward_iterator<InputIterator>::value
                    >::type * = NULL) {
            size_type          diff_first   = position - begin();
            iterator           new_first    = position;
            size_type          n            = 0;
            size_type          max_capacity = max_size();
            for (InputIterator temp         = first; temp != last && n < max_capacity;
                 ++temp, ++n) {}
            if (n >= max_capacity) {
                throw std::length_error("vector");
            }
            size_type new_capacity = this->_capacity;
            if (this->_size >= this->_capacity) {
                new_capacity = this->_capacity * 2;
            }
            if (this->_size + n > new_capacity) {
                new_capacity = this->_size + n;
            }
            if (new_capacity > this->_capacity) {
                reserve(new_capacity);
                new_first = begin() + diff_first;
            }
            if (diff_first < this->_size) {
                move_to_right(new_first, n);
                for (size_type i = 0; i < n; ++i) {
                    *(new_first + i) = *first;
                }
            } else {
                for (size_type i = 0; i < n; ++i) {
                    this->_alloc.construct(&*(new_first + i), *first);
                }
            }
            this->_size += n;
            this->_end += n;
        }

        template<class InputIterator>
        void insert(iterator position, InputIterator first, InputIterator last,
                    typename enable_if<is_input_iterator<InputIterator>::value>::type * = NULL) {
            for (; first != last; ++first, ++position) {
                insert(position, *first);
            }
        }

        template<class InputIterator>
        iterator erase(InputIterator it) {
            move_to_left(it + 1, 1);
            --this->_size;
            --this->_end;
            this->_alloc.destroy(&this->_base[this->_size]);
            return it;
        }

        template<class InputIterator>
        iterator erase(InputIterator first, InputIterator last) {
            size_type n = last - first;
            move_to_left(first + n, n);
            this->_size -= n;
            this->_end -= n;
            for (size_type i = 0; i < n; ++i) {
                this->_alloc.destroy(&this->_begin[this->_size + i]);
            }
            return first;
        }

        void clear() throw() {
            erase(begin(), end());
        }

        void resize(size_type n, value_type val = value_type()) {
            if (n == this->_size) {
                return;
            }
            if (n < this->_size) {
                for (size_type i = n; i < this->_size; ++i) {
                    this->_alloc.destroy(&this->_begin[i]);
                }
                this->_size = n;
            } else if (n > this->_size && n <= this->_capacity) {
                for (size_type i = this->_size; i < n; ++i, ++this->_size) {
                    this->_alloc.construct(&this->_begin[i], val);
                }
            } else {
                size_type new_size = this->_capacity * 2;
                if (n > new_size) {
                    new_size = n;
                }
                reserve(new_size);
                for (size_type i = this->_size; i < n; ++i, ++this->_size) {
                    this->_alloc.construct(&this->_begin[i], val);
                }
            }
            this->_end = this->_begin + this->_size;
        }

        void swap(vector &rhs) {
            if (this->_alloc == rhs._alloc) {
                pointer   temp_b = this->_begin;
                pointer   temp_e = this->_end;
                size_type temp_c = this->_capacity;
                size_type temp_s = this->_size;
                this->_begin    = rhs._begin;
                this->_end      = rhs._end;
                this->_capacity = rhs._capacity;
                this->_size     = rhs._size;
                rhs._begin      = temp_b;
                rhs._end        = temp_e;
                rhs._capacity   = temp_c;
                rhs._size       = temp_s;
            } else {
                vector<T, Allocator> temp_v = *this;
                *this = rhs;
                rhs = temp_v;
            }
        }

        vector &operator=(vector const &rhs) {
            if (this == &rhs) {}
            else if (rhs.size() == 0) {
                clear();
            } else {
                clear();
                insert(begin(), rhs.begin(), rhs.end());
            }
            return *this;
        }

        reference operator[](size_type n) {
            return this->_begin[n];
        }

        const_reference operator[](size_type n) const {
            return this->_begin[n];
        }

        friend bool operator==(const vector &lhs, const vector &rhs) throw() {
            if (&lhs == &rhs) {
                return true;
            }
            if (lhs.size() != rhs.size()) {
                return false;
            }
            const_iterator first_l(lhs.begin());
            const_iterator last(lhs.end());
            const_iterator first_r(rhs.begin());
            for (; first_l != last; ++first_l, ++first_r) {
                if (*first_l != *first_r) {
                    return false;
                }
            }
            return true;
        }

        friend bool operator>(const vector &lhs, const vector &rhs) throw() {
            if (&lhs == &rhs) {
                return true;
            }
            const_iterator first_l(lhs.begin());
            const_iterator last_l(lhs.end());
            const_iterator first_r(rhs.begin());
            const_iterator last_r(rhs.end());
            for (; first_l != last_l && first_r != last_r; ++first_l, ++first_r) {
                if (*first_l > *first_r) {
                    return true;
                } else if (*first_l < *first_r) {
                    return false;
                }
            }
            if (lhs.size() > rhs.size()) {
                return true;
            }
            return false;
        }
    };

    template<class T, class Alloc>
    void swap(vector<T, Alloc> &lhs, vector<T, Alloc> &rhs) {
        return lhs.swap(rhs);
    }

    template<class T, class Alloc>
    bool operator==(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) throw() {
        return (lhs == rhs);
    }

    template<class T, class Alloc>
    bool operator!=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) throw() {
        return !(lhs == rhs);
    }

    template<class T, class Alloc>
    bool operator>(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) throw() {
        return (lhs > rhs);
    }

    template<class T, class Alloc>
    bool operator<(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) throw() {
        return (rhs > lhs);
    }

    template<class T, class Alloc>
    bool operator<=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) throw() {
        return !(lhs > rhs);
    }

    template<class T, class Alloc>
    bool operator>=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) throw() {
        return !(lhs < rhs);
    }
}

#endif //VECTOR_HPP
