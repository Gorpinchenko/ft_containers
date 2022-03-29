#ifndef MAP_HPP
#define MAP_HPP

#include "tree.hpp"
#include "utils.hpp"

namespace ft {
    template<class Key, class T, class Compare, class Allocator>
    class map_traits {
    protected:
        typedef Key                                                    key_type;
        typedef pair<const Key, T>                                     value_type;
        typedef Compare                                                key_compare;
        typedef typename Allocator::template rebind<value_type>::other allocator_type;

        map_traits() : comp() {};

        map_traits(Compare Comp) : comp(Comp) {};

        class value_compare {
        public:
            bool operator()(value_type const &lhs, value_type
            const &rhs) const {
                return comp(lhs.first, rhs.first);
            }

            value_compare(key_compare Comp) : comp(Comp) {}

        protected:
            key_compare comp;
        };

        struct Kfn {
            Key const &operator()(value_type const &X) const {
                return (X.first);
            }
        };

        Compare comp;
    };

    template<class Key, class T, class Compare = less<Key>, class Allocator = std::allocator<pair<const Key, T> > >
    class map : public tree<map_traits<Key, T, Compare, Allocator> > {
    private:
        typedef tree<map_traits<Key, T, Compare, Allocator> > _base;

    public:
        typedef Key                                    key_type;
        typedef T                                      mapped_type;
        typedef typename _base::value_type             value_type;
        typedef Compare                                key_compare;
        typedef typename _base::allocator_type         allocator_type;
        typedef typename _base::reference              reference;
        typedef typename _base::const_reference        const_reference;
        typedef typename _base::pointer                pointer;
        typedef typename _base::const_pointer          const_pointer;
        typedef typename _base::iterator               iterator;
        typedef typename _base::const_iterator         const_iterator;
        typedef typename _base::reverse_iterator       reverse_iterator;
        typedef typename _base::const_reverse_iterator const_reverse_iterator;
        typedef typename _base::difference_type        difference_type;
        typedef typename _base::size_type              size_type;

    public:
        map() : _base(key_compare(), allocator_type()) {};

        explicit map(key_compare const &comp) : _base(comp, allocator_type()) {};

        map(key_compare const &comp, allocator_type const &alloc) : _base(comp, alloc) {};

        template<class InputIterator>
        map(InputIterator first, InputIterator last) :_base(key_compare(), allocator_type()) {
            for (; first != last; ++first) {
                _base::insert(*first);
            }
        };

        template<class InputIterator>
        map(InputIterator first, InputIterator last, Compare const &comp):_base(comp, allocator_type()) {
            for (; first != last; ++first) {
                _base::insert(*first);
            }
        };

        template<class InputIterator>
        map(InputIterator first, InputIterator last, Compare const &comp, Allocator const &al):_base(comp, al) {
            for (; first != last; ++first) {
                _base::insert(*first);
            }
        };

        map(map const &rhs) : _base(rhs) {};

        mapped_type &operator[](key_type const &Kv) {
            iterator P = _base::insert(value_type(Kv, mapped_type())).first;
            return (*P).second;
        }
    };
}

#endif //MAP_HPP
