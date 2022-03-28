#ifndef VECTOR_BASE_HPP
#define VECTOR_BASE_HPP

namespace ft {
    template<class T, class Alloc>
    class vector_base {
    protected:
        typedef T              *pointer;
        typedef size_t         size_type;
        typedef std::ptrdiff_t difference_type;

        size_type _capacity;
        Alloc     _alloc;
        size_type _size;
        pointer   _begin;
        pointer   _end;
        size_type _old_capacity;
        size_type _old_size;
        pointer   _old_begin;

        vector_base(Alloc const &alloc) :
                _capacity(0), _alloc(alloc), _size(0), _begin(NULL), _end(NULL), _old_capacity(0), _old_size(0),
                _old_begin(NULL) {
        }

        vector_base(size_type capacity, Alloc const &alloc) :
                _capacity(capacity), _alloc(alloc), _size(0), _end(NULL), _old_capacity(0), _old_size(0),
                _old_begin(NULL) {
            if (capacity > max_size_base()) {
                _capacity = 0;
                throw std::length_error("ft::vector");
            }
            if (capacity != 0) {
                _begin = _alloc.allocate(capacity);
            } else {
                _begin = NULL;
            }
        }

        template<class InputIterator>
        vector_base(InputIterator first, InputIterator last, Alloc const &alloc):
                _capacity(0), _alloc(alloc), _size(0), _end(NULL), _old_capacity(0), _old_size(0), _old_begin(NULL) {
            size_type max_capacity = max_size_base();
            while (first != last && _capacity < max_capacity) {
                ++_capacity;
                ++first;
            }
            if (_capacity >= max_capacity) {
                _capacity = 0;
                throw std::length_error("ft::vector");
            }
            if (_capacity != 0) {
                _begin = _alloc.allocate(_capacity);
            } else {
                _begin = NULL;
            }
        }

        ~vector_base() {
            _alloc.deallocate(_begin, _capacity);
            _alloc.deallocate(_old_begin, _old_capacity);
        }

    private:
        size_type max_size_base() const throw() {
            size_type limit1 = _alloc.max_size();
            size_type limit2 = std::numeric_limits<difference_type>::max();
            if (limit1 <= limit2) {
                return limit1;
            } else {
                return limit2;
            }
        }
    };
}

#endif //VECTOR_BASE_HPP
