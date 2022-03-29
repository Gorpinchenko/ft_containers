#ifndef SET_HPP
#define SET_HPP

#include "tree.hpp"
#include "utils.hpp"

namespace ft {
    template<class Key, class Compare, class Allocator>
    class set_traits {
    protected:
        typedef Key                                                    key_type;
        typedef Key                                                    value_type;
        typedef Compare                                                key_compare;
        typedef typename Allocator::template rebind<value_type>::other allocator_type;

        set_traits() : comp() {};

        set_traits(Compare Comp) : comp(Comp) {};
        typedef key_compare value_compare;

        struct Kfn {
            Key const &operator()(value_type const &X) const {
                return (X);
            }
        };

        Compare comp;
    };

    template<class Key, class Compare = less <Key>, class Allocator = std::allocator<Key> >
    class set : public tree<set_traits<Key, Compare, Allocator> > {
    private:
        typedef tree <set_traits<Key, Compare, Allocator> > _base;

    public:
        typedef Key                                    key_type;
        typedef Compare                                key_compare;
        typedef typename _base::value_compare          value_compare;
        typedef typename _base::allocator_type         allocator_type;
        typedef typename _base::value_type             value_type;
        typedef typename _base::size_type              size_type;
        typedef typename _base::difference_type        difference_type;
        typedef typename _base::pointer                pointer;
        typedef typename _base::const_pointer          const_pointer;
        typedef typename _base::reference              reference;
        typedef typename _base::const_reference        const_reference;
        typedef typename _base::iterator               iterator;
        typedef typename _base::const_iterator         const_iterator;
        typedef typename _base::reverse_iterator       reverse_iterator;
        typedef typename _base::const_reverse_iterator const_reverse_iterator;

        set() : _base(key_compare(), allocator_type()) {};

        explicit set(key_compare const &comp) : _base(comp, allocator_type()) {};

        set(key_compare const &comp, allocator_type const &alloc) : _base(comp, alloc) {};

        template<class InputIterator>
        set(InputIterator first, InputIterator last) :_base(key_compare(), allocator_type()) {
            for (; first != last; ++first) {
                _base::insert(*first);
            }
        };

        template<class InputIterator>
        set(InputIterator first, InputIterator last, Compare const &comp) :_base(comp, allocator_type()) {
            for (; first != last; ++first) {
                _base::insert(*first);
            }
        };

        template<class InputIterator>
        set(InputIterator first, InputIterator last, Compare const &comp, Allocator const &al) : _base(comp, al) {
            for (; first != last; ++first) {
                _base::insert(*first);
            }
        };

        set(set const &rhs) : _base(rhs) {};
    };
}

#endif //SET_HPP
