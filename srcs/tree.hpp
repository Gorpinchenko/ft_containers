#ifndef TREE_HPP
#define TREE_HPP

#include <limits>
#include "utils.hpp"

namespace ft {
    template<class Tr>
    class tree_node : public Tr {

    protected:
        typedef typename Tr::value_type                                        value_type;
        typedef typename Tr::key_compare                                       key_compare;
        typedef typename Tr::allocator_type                                    allocator_type;
        typedef typename allocator_type::template rebind<void>::other::pointer Genptr;

        struct Node {
            Genptr     _parent;
            Genptr     _left;
            Genptr     _right;
            value_type _value;
            char       _color;
            char       _isnil;
        };

        tree_node(key_compare const &comp, allocator_type const &alloc) : Tr(comp), Alnod(alloc) {};

        typename allocator_type::template rebind<Node>::other Alnod;
    };

    template<class Tr>
    class tree_ptr : public tree_node<Tr> {

    protected:
        typedef typename Tr::key_compare    key_compare;
        typedef typename Tr::allocator_type allocator_type;

        typedef typename tree_node<Tr>::Node                                   Node;
        typedef typename allocator_type::template rebind<Node>::other::pointer Nodeptr;

        tree_ptr(key_compare const &comp, allocator_type const &alloc) : tree_node<Tr>(comp, alloc), Alptr(alloc) {};

        typename allocator_type::template rebind<Nodeptr>::other Alptr;
    };

    template<class Tr>
    class tree_val : public tree_ptr<Tr> {

    protected:

        typedef typename Tr::key_compare    key_compare;
        typedef typename Tr::allocator_type allocator_type;

        tree_val(key_compare const &comp, allocator_type const &alloc) : tree_ptr<Tr>(comp, alloc), Alval(alloc) {};

        allocator_type Alval;
    };

    template<class Tr>
    class tree : public tree_val<Tr> {
    public:
        typedef tree<Tr>     Myt;
        typedef tree_val<Tr> Mybase;

        typedef typename Tr::allocator_type allocator_type;
        typedef typename Tr::value_type     value_type;
        typedef typename Tr::key_type       key_type;
        typedef typename Tr::key_compare    key_compare;
        typedef typename Tr::value_compare  value_compare;

    protected:
        enum RedBlack {
            Red,
            Black,
            ToLeft,
            ToRight
        };

        typedef typename tree_node<Tr>::Genptr                                             Genptr;
        typedef typename tree_node<Tr>::Node                                               Node;
        typedef typename allocator_type::template rebind<Node>::other::pointer             Nodeptr;
        typedef typename allocator_type::template rebind<Nodeptr>::other::reference        Noderef;
        typedef typename allocator_type::template rebind<key_type>::other::const_reference Keyref;
        typedef typename allocator_type::template rebind<char>::other::reference           Charref;
        typedef typename allocator_type::template rebind<value_type>::other::reference     Vref;
        typedef typename Tr::Kfn                                                           Kfn;

        static Charref Color(Nodeptr P) {
            return ((Charref) (*P)._color);
        }

        static Charref Isnil(Nodeptr P) {
            return ((Charref) (*P)._isnil);
        }

        static Keyref Key(Nodeptr P) {
            return (Kfn()(Value(P)));
        }

        static Noderef Left(Nodeptr P) {
            return ((Noderef) (*P)._left);
        }

        static Noderef Right(Nodeptr P) {
            return ((Noderef) (*P)._right);
        }

        static Noderef Parent(Nodeptr P) {
            return ((Noderef) (*P)._parent);
        }

        static Vref Value(Nodeptr P) {
            return ((Vref) (*P)._value);
        }

        static void Inc(Nodeptr &node) {

            Nodeptr temp = node;
            if (Isnil(node)) {
                return;
            }
            if (!Isnil(Right(temp))) {
                temp = Right(temp);
                while (!Isnil(Left(temp))) {
                    temp = Left(temp);
                }
                node = temp;
                return;
            }
            while (!Isnil(Parent(temp)) && Right(Parent(temp)) == temp) {
                temp = Parent(temp);
            }
            if (!Isnil(Parent(temp)) && Left(Parent(temp)) == temp) {
                node = Parent(temp);
                return;
            } else {
                node = Right(node);
                return;
            }
        }

        static void Dec(Nodeptr &node) {

            Nodeptr temp = node;
            if (Isnil(node)) {
                return;
            }
            if (!Isnil(Left(temp))) {
                temp = Left(temp);
                while (!Isnil(Right(temp))) {
                    temp = Right(temp);
                }
                node = temp;
                return;
            }
            while (!Isnil(Parent(temp)) && Left(Parent(temp)) == temp) {
                temp = Parent(temp);
            }
            if (!Isnil(Parent(temp)) && Right(Parent(temp)) == temp) {
                node = Parent(temp);
                return;
            } else {
                node = Left(node);
                return;
            }
        }

    public:
        typedef size_t                                                                       size_type;
        typedef std::ptrdiff_t                                                               difference_type;
        typedef typename allocator_type::template rebind<value_type>::other::pointer         ValPtr;
        typedef typename allocator_type::template rebind<value_type>::other::const_pointer   CValPtr;
        typedef typename allocator_type::template rebind<value_type>::other::reference       ValRef;
        typedef ValPtr                                                                       pointer;
        typedef CValPtr                                                                      const_pointer;
        typedef ValRef                                                                       reference;
        typedef typename allocator_type::template rebind<value_type>::other::const_reference const_reference;

        class const_iterator;

        struct bidirectional_iterator_tag;

        class iterator {
        public:
            typedef bidirectional_iterator_tag iterator_category;

            iterator() {};

            iterator(Nodeptr ptr) : _ptr(ptr) {};

            iterator(iterator const &src) {
                _ptr = src._ptr;
            }

            iterator(const_iterator const &src) {
                *this = src;
            }

            iterator &operator=(iterator const &rhs) {
                if (this == &rhs) {
                    return *this;
                }
                _ptr = rhs._ptr;
                return *this;
            }

            iterator &operator=(const_iterator const &rhs) {
                temp_const_iterator temp_i(rhs);
                _ptr = temp_i.Mynode();
                return *this;
            }

            ~iterator() {};

            reference operator*() const {
                return Value(_ptr);
            }

            pointer operator->() const {
                return &**this;
            }

            iterator &operator++() throw() {
                Inc(_ptr);
                return *this;
            }

            iterator &operator--() throw() {
                Dec(_ptr);
                return *this;
            }

            iterator operator++(int) throw() {
                iterator old(*this);
                ++*this;
                return old;
            }

            iterator operator--(int) throw() {
                iterator old(*this);
                --*this;
                return old;
            }

            friend bool operator==(iterator const &lhs,
                                   iterator const &rhs) throw() {
                return (lhs._ptr == rhs._ptr);
            }

            friend bool operator==(iterator const &lhs,
                                   const_iterator const &rhs) throw() {
                temp_const_iterator temp_i(rhs);
                return (lhs._ptr == temp_i.Mynode());
            }

            friend bool operator!=(iterator const &lhs,
                                   iterator const &rhs) throw() {
                return (lhs._ptr != rhs._ptr);
            }

            friend bool operator!=(iterator const &lhs,
                                   const_iterator const &rhs) throw() {
                temp_const_iterator temp_i(rhs);
                return (lhs._ptr != temp_i.Mynode());
            }

        protected:
            Nodeptr _ptr;

            class temp_const_iterator : public const_iterator {
            public:
                temp_const_iterator(const_iterator const &It) :
                        const_iterator(It) {};

                Nodeptr Mynode() {
                    return const_iterator::_ptr;
                }
            };
        };

        class const_iterator {
        public:
            typedef bidirectional_iterator_tag iterator_category;

            const_iterator() {};

            const_iterator(Nodeptr ptr) : _ptr(ptr) {};

            const_iterator(const_iterator const &src) {
                _ptr = src._ptr;
            }

            const_iterator(iterator const &src) {
                *this = src;
            }

            const_iterator &operator=(const_iterator const &rhs) {
                if (this == &rhs) {
                    return *this;
                }
                _ptr = rhs._ptr;
                return *this;
            }

            const_iterator &operator=(iterator const &rhs) {
                temp_iterator temp_i(rhs);
                _ptr = temp_i.Mynode();
                return *this;
            }

            ~const_iterator() {}

            const_reference operator*() const {
                return Value(_ptr);
            }

            const_pointer operator->() const {
                return &**this;
            }

            const_iterator &operator++() throw() {
                Inc(_ptr);
                return *this;
            }

            const_iterator &operator--() throw() {
                Dec(_ptr);
                return *this;
            }

            const_iterator operator++(int) throw() {
                const_iterator old(*this);
                ++*this;
                return old;
            }

            const_iterator operator--(int) throw() {
                const_iterator old(*this);
                --*this;
                return old;
            }

            friend bool operator==(const_iterator const &lhs,
                                   const_iterator const &rhs) throw() {
                return (lhs._ptr == rhs._ptr);
            }

            friend bool operator!=(const_iterator const &lhs,
                                   const_iterator const &rhs) throw() {
                return (lhs._ptr != rhs._ptr);
            }

        protected:

            Nodeptr _ptr;

            class temp_iterator : public iterator {
            public:
                temp_iterator(iterator const &It) : iterator(It) {};

                Nodeptr Mynode() {
                    return iterator::_ptr;
                }
            };
        };

        class const_reverse_iterator;

        class reverse_iterator {
        public:
            typedef bidirectional_iterator_tag iterator_category;

            reverse_iterator() {};

            reverse_iterator(Nodeptr ptr) : _ptr(ptr) {};

            reverse_iterator(reverse_iterator const &src) {
                _ptr = src._ptr;
            }

            reverse_iterator(const_reverse_iterator const &src) {
                *this = src;
            }

            reverse_iterator &operator=(reverse_iterator const &rhs) {
                if (this == &rhs) {
                    return *this;
                }
                _ptr = rhs._ptr;
                return *this;
            }

            reverse_iterator &operator=(const_reverse_iterator const &rhs) {
                temp_const_iterator temp_i(rhs);
                _ptr = temp_i.Mynode();
                return *this;
            }

            ~reverse_iterator() {}

            reference operator*() const {
                return Value(_ptr);
            }

            pointer operator->() const {
                return &**this;
            }

            reverse_iterator &operator++() throw() {
                Dec(_ptr);
                return *this;
            }

            reverse_iterator &operator--() throw() {
                Inc(_ptr);
                return *this;
            }

            reverse_iterator operator++(int) throw() {
                reverse_iterator old(*this);
                ++*this;
                return old;
            }

            reverse_iterator operator--(int) throw() {
                reverse_iterator old(*this);
                --*this;
                return old;
            }

            friend bool operator==(reverse_iterator const &lhs,
                                   reverse_iterator const &rhs) throw() {
                return (lhs._ptr == rhs._ptr);
            }

            friend bool operator==(reverse_iterator const &lhs,
                                   const_reverse_iterator const &rhs) throw() {
                temp_const_iterator temp_i(rhs);
                return (lhs._ptr == temp_i.Mynode());
            }

            friend bool operator!=(reverse_iterator const &lhs,
                                   reverse_iterator const &rhs) throw() {
                return (lhs._ptr != rhs._ptr);
            }

            friend bool operator!=(reverse_iterator const &lhs,
                                   const_reverse_iterator const &rhs) throw() {
                temp_const_iterator temp_i(rhs);
                return (lhs._ptr != temp_i.Mynode());
            }

        protected:
            Nodeptr _ptr;

            class temp_const_iterator : public const_reverse_iterator {
            public:
                temp_const_iterator(const_reverse_iterator const &It) :
                        const_reverse_iterator(It) {};

                Nodeptr Mynode() {
                    return const_reverse_iterator::_ptr;
                }
            };
        };

        class const_reverse_iterator {
        public:
            typedef bidirectional_iterator_tag iterator_category;

            const_reverse_iterator() {};

            const_reverse_iterator(Nodeptr ptr) : _ptr(ptr) {};

            const_reverse_iterator(const_reverse_iterator const &src) {
                _ptr = src._ptr;
            }

            const_reverse_iterator(reverse_iterator const &src) {
                *this = src;
            }

            const_reverse_iterator &operator=(const_reverse_iterator
                                              const &rhs) {
                if (this == &rhs) {
                    return *this;
                }
                _ptr = rhs._ptr;
                return *this;
            }

            const_reverse_iterator &operator=(reverse_iterator const &rhs) {
                temp_iterator temp_i(rhs);
                _ptr = temp_i.Mynode();
                return *this;
            }

            ~const_reverse_iterator() {}

            const_reference operator*() const {
                return Value(_ptr);
            }

            const_pointer operator->() const {
                return &**this;
            }

            const_reverse_iterator &operator++() throw() {
                _ptr = Dec(_ptr);
                return *this;
            }

            const_reverse_iterator &operator--() throw() {
                Inc(_ptr);
                return *this;
            }

            const_reverse_iterator operator++(int) throw() {
                const_reverse_iterator old(*this);
                ++*this;
                return old;
            }

            const_reverse_iterator operator--(int) throw() {
                const_reverse_iterator old(*this);
                --*this;
                return old;
            }

            friend bool operator==(const_reverse_iterator const &lhs,
                                   const_reverse_iterator const &rhs) throw() {
                return (lhs._ptr == rhs._ptr);
            }

            friend bool operator!=(const_reverse_iterator const &lhs,
                                   const_reverse_iterator const &rhs) throw() {
                return (lhs._ptr != rhs._ptr);
            }

        protected:
            Nodeptr _ptr;

            class temp_iterator : public reverse_iterator {
            public:
                temp_iterator(reverse_iterator const &It) : reverse_iterator(It) {};

                Nodeptr Mynode() {
                    return reverse_iterator::_ptr;
                }
            };
        };

        class tree_iterator : public iterator {
        public:
            tree_iterator(iterator const &It) : iterator(It) {};

            Nodeptr Mynode() {
                return iterator::_ptr;
            }
        };

        class tree_reverse_iterator : public reverse_iterator {
        public:
            tree_reverse_iterator(reverse_iterator const &It) : reverse_iterator(It) {};

            Nodeptr Mynode() {
                return reverse_iterator::_ptr;
            }
        };

        explicit tree(key_compare const &comp, allocator_type const &alloc) : Mybase(comp, alloc) {
            init();
        }

        tree(value_type const *first, value_type const *last, key_compare const &comp, allocator_type const &alloc)
                : Mybase(comp, alloc) {
            init();
            insert(first, last);
        }

        tree(Myt const &rhs) : Mybase(rhs.key_comp(), rhs.get_allocator()) {
            init();
            insert(rhs.begin(), rhs.end());
        }

        Myt &operator=(const Myt &rhs) {
            if (this == &rhs) {
                return *this;
            }
            clear();
            this->comp = rhs.comp;
            insert(rhs.begin(), rhs.end());
            return *this;
        }

        ~tree() {
            delete_tree(Root());
            destruct_val_in_node(_head);
            free_node_alloc(_head);
        }

        iterator begin() {
            return iterator(HeadLeft_first());
        }

        const_iterator begin() const {
            return const_iterator(HeadLeft_first());
        }

        iterator end() {
            return iterator(_head);
        }

        const_iterator end() const {
            return const_iterator(_head);
        }

        reverse_iterator rbegin() {
            return reverse_iterator(HeadRight_last());
        }

        const_reverse_iterator rbegin() const {
            return const_reverse_iterator(HeadRight_last());
        }

        reverse_iterator rend() {
            return reverse_iterator(_head);
        }

        const_reverse_iterator rend() const {
            return const_reverse_iterator(_head);
        }

        size_type size() const {
            return _size;
        }

        size_type max_size() {
            return Mybase::Alnod.max_size();
        }

        bool empty() const {
            return (_size == 0);
        }

        allocator_type get_allocator() const {
            return Mybase::Alval;
        }

        key_compare key_comp() const {
            return Mybase::comp;
        }

        value_compare value_comp() const {
            return value_compare(key_comp());
        }

        void clear() {
            delete_tree(Root());
            _size = 0;
            Root()           = _head;
            HeadLeft_first() = _head;
            HeadRight_last() = _head;
        }

        iterator find(const key_type &key) {
            return iterator(find_node(key));
        }

        const_iterator find(const key_type &key) const {
            return const_iterator(find_node(key));
        }

        pair<iterator, bool> insert(value_type const &new_value) {
            Nodeptr temp;
            if (_size == 0) {
                temp = insert_new(ToLeft, _head, new_value, Black);
                return pair<iterator, bool>(iterator(temp), true);
            } else {
                temp            = Root();
                Nodeptr newNode = temp;
                while (!Isnil(temp)) {
                    if (Key(temp) == Kfn()(new_value)) {
                        return pair<iterator, bool>(iterator(temp), false);
                    } else if (Mybase::comp(Kfn()(new_value), Key(temp))) {
                        if (!Isnil(Left(temp))) {
                            temp = Left(temp);
                        } else {
                            newNode = insert_new(ToLeft, temp, new_value, Red);
                            temp    = _head;
                        }
                    } else {
                        if (!Isnil(Right(temp))) {
                            temp = Right(temp);
                        } else {
                            newNode = insert_new(ToRight, temp, new_value, Red);
                            temp    = _head;
                        }
                    }
                }
                return pair<iterator, bool>(iterator(newNode), true);
            }
        }

        template<class InputIterator>
        void insert(InputIterator first, InputIterator last) {
            for (; first != last; ++first) {
                insert(*first);
            }
        }

        iterator insert(iterator position, const value_type &val) {
            if (_size == 0) {
                return iterator(insert_new(ToLeft, _head, val, Black));
            } else if (position == begin()) {
                if (Mybase::comp(Kfn()(val), Key(HeadLeft_first()))) {
                    return iterator(insert_new(ToLeft, HeadLeft_first(), val,
                                               Red));
                }
            } else if (position == end()) {
                if (Mybase::comp(Key(HeadRight_last()), Kfn()(val))) {
                    return iterator(insert_new(ToRight, HeadRight_last(), val,
                                               Red));
                }
            } else {
                tree_iterator P(position);
                tree_iterator Pb = P;
                if (Mybase::comp(Kfn()(*(--Pb)), Kfn()(val))
                    && Mybase::comp(Kfn()(val), Kfn()(*P))) {
                    if (Isnil((Right(Pb.Mynode())))) {
                        return iterator(insert_new(ToRight, Pb.Mynode(), val,
                                                   Red));
                    } else {
                        return iterator(insert_new(ToLeft, P.Mynode(), val,
                                                   Red));
                    }
                }
                ++P;
                Pb = P;
                if (Mybase::comp(Kfn()(*(--Pb)), Kfn()(val))
                    && Mybase::comp(Kfn()(val), Kfn()(*P))) {
                    if (Isnil((Right(Pb.Mynode())))) {
                        return iterator(insert_new(ToRight, Pb.Mynode(), val,
                                                   Red));
                    } else {
                        return iterator(insert_new(ToLeft, P.Mynode(), val,
                                                   Red));
                    }
                }
            }
            return insert(val).first;
        }

        iterator insert(const_iterator position, const value_type &val) {
            return (insert(iterator(position), val));
        }

        void erase(iterator position) {
            tree_iterator temp_i(position);
            Nodeptr       node  = temp_i.Mynode();
            Nodeptr       temp1 = node;
            Nodeptr       temp2 = node;
            if (Isnil(node)) {
                throw std::out_of_range("map/set<T> iterator");
            }
            if (_size == 1 && position == begin()) {
                clear();
                return;
            }
            renew_first_last_erase_start(node);
            if (!Isnil(Left(node)) && !Isnil(Right(node))) {
                temp1 = Left(node);
                while (!Isnil(Right(temp1))) {
                    temp1 = Right(temp1);
                }
                temp2 = Right(node);
                while (!Isnil(Left(temp2))) {
                    temp2 = Left(temp2);
                }
                if ((Isnil(Left(temp1)) && Color(temp1) == Red)
                    || ((Isnil(Left(Left(temp1))) && Isnil(Right(Left(temp1))))
                        && ((Color(temp1) == Red && Color(Left(temp1)) == Black)
                            || (Color(temp1) == Black && Color(Left(temp1)) == Red))
                    )) {
                    value_type temp_val(Value(node));
                    destruct_val_in_node(node);
                    construct_val_in_node(node, Value(temp1));
                    destruct_val_in_node(temp1);
                    construct_val_in_node(temp1, temp_val);
                    renew_first_last_erase_swap(node, temp1);
                    node = temp1;
                } else {
                    value_type temp_val(Value(node));
                    destruct_val_in_node(node);
                    construct_val_in_node(node, Value(temp2));
                    destruct_val_in_node(temp2);
                    construct_val_in_node(temp2, temp_val);
                    renew_first_last_erase_swap(node, temp2);
                    node = temp2;
                }
            }
            if (!Isnil(Left(node))) {
                destruct_val_in_node(node);
                construct_val_in_node(node, Value(Left(node)));
                Color(node) = Black;
                renew_first_last_erase_swap(node, Left(node));
                del_node(Left(node));
                Left(node) = _head;
                return;
            } else if (!Isnil(Right(node))) {
                destruct_val_in_node(node);
                construct_val_in_node(node, Value(Right(node)));
                Color(node) = Black;
                renew_first_last_erase_swap(node, Right(node));
                del_node(Right(node));
                Right(node) = _head;
                return;
            }
            if (Color(node) == Red && Isnil(Left(node)) && Isnil(Right(node))) {
                if (Left(Parent(node)) == node) {
                    Left(Parent(node)) = _head;
                } else {
                    Right(Parent(node)) = _head;
                }
                del_node(node);
                return;
            }
            if (Color(node) == Black && Isnil(Left(node)) && Isnil(Right(node))) {
                rebalanse_erase(node);
                if (Left(Parent(node)) == node) {
                    Left(Parent(node)) = _head;
                } else {
                    Right(Parent(node)) = _head;
                }
                del_node(node);
                return;
            }
        }

        size_type erase(const key_type &key) {
            Nodeptr node = find_node(key);
            if (Isnil(node)) {
                return 0;
            }
            erase(iterator(node));
            return 1;
        }

        void erase(iterator first, iterator last) {
            iterator temp;
            while (first != last) {
                temp = first;
                ++temp;
                erase(first);
                first = temp;
            }
        }

        iterator lower_bound(key_type const &Kv) {
            return iterator(lbound(Kv));
        }

        const_iterator lower_bound(key_type const &Kv) const {
            return const_iterator(lbound(Kv));
        }

        iterator upper_bound(key_type const &Kv) {
            return iterator(ubound(Kv));
        }

        const_iterator upper_bound(key_type const &Kv) const {
            return const_iterator(ubound(Kv));
        }

        pair<iterator, iterator> equal_range(key_type const &Kv) {
            return pair<iterator, iterator>
                    (iterator(lbound(Kv)), iterator(ubound(Kv)));
        }

        pair<const_iterator, const_iterator> equal_range(key_type const &Kv)
        const {
            return pair<const_iterator, const_iterator>
                    (const_iterator(lbound(Kv)), const_iterator(ubound(Kv)));
        }

        size_type count(key_type const &Kv) const {
            if (find(Kv) == _head) {
                return 0;
            } else {
                return 1;
            }
        }

        void swap(Myt &rhs) {
            if (this->Alval == rhs.Alval) {
                Nodeptr     temp_h = this->_head;
                size_type   temp_s = this->_size;
                key_compare temp_c = this->comp;
                this->_head = rhs._head;
                this->_size = rhs._size;
                this->comp  = rhs.comp;
                rhs._head   = temp_h;
                rhs._size   = temp_s;
                rhs.comp    = temp_c;
            } else {
                Myt temp_tree = *this;
                *this = rhs;
                rhs = temp_tree;
            }
        }

    protected:
        Nodeptr   _head;
        size_type _size;

        void init() {
            _head = new_node(NULL, value_type(), Black);
            Isnil(_head)     = true;
            Root()           = _head;
            HeadLeft_first() = _head;
            HeadRight_last() = _head;
            _size = 0;
        }

        void del_node(Nodeptr &node) {
            if (node == _head) {
                return;
            }
            destruct_val_in_node(node);
            free_node_alloc(node);
            --_size;
        }

        void del_nodes(Nodeptr &node) {
            if (node == _head) {
                return;
            }
            del_nodes(Left(node));
            del_nodes(Right(node));
            del_node(node);
        }

        void delete_tree(Nodeptr &node) {
            if (node == _head) {
                return;
            }
            del_nodes(Left(node));
            del_nodes(Right(node));
            destruct_val_in_node(node);
            free_node_alloc(node);
        }

        void construct_val_in_node(Nodeptr &node, value_type const &val) {
            Mybase::Alval.construct(&Value(node), val);
        }

        void destruct_val_in_node(Nodeptr &node) {
            Mybase::Alval.destroy(&Value(node));
        }

        void free_node_alloc(Nodeptr &node) {
            Mybase::Alnod.deallocate(node, 1);
        }

        Nodeptr new_node(Nodeptr parent_node, value_type const &new_value,
                         char color) {
            Nodeptr temp = Mybase::Alnod.allocate(1);
            Mybase::Alptr.construct(&Left(temp), _head);
            Mybase::Alptr.construct(&Right(temp), _head);
            Mybase::Alptr.construct(&Parent(temp), parent_node);
            try {
                construct_val_in_node(temp, new_value);
            }
            catch (...) {
                free_node_alloc(temp);
                throw;
            };
            Color(temp) = color;
            Isnil(temp) = false;
            return temp;
        }

        Nodeptr insert_new(char left_right, Nodeptr node,
                           value_type const &new_value, char color) {
            if (_size + 1 >= max_size()) {
                throw std::length_error("ft::set/map too long");
            }
            Nodeptr temp;
            if (_size == 0) {
                temp = new_node(node, new_value, color);
                Root()           = temp;
                HeadLeft_first() = temp;
                HeadRight_last() = temp;
                ++_size;
                return temp;
            } else {
                temp = new_node(node, new_value, color);
                if (left_right == ToLeft) {
                    Left(node) = temp;
                } else {
                    Right(node) = temp;
                }
                renew_first_last_insert(temp);
                ++_size;
                rebalanse_insert(temp);
                return temp;
            }
        }

        void renew_first_last_insert(Nodeptr &newNode) {
            if (Mybase::comp(Key(newNode), Key(HeadLeft_first()))) {
                HeadLeft_first() = newNode;
            }
            if (Mybase::comp(Key(HeadRight_last()), Key(newNode))) {
                HeadRight_last() = newNode;
            }
        }

        void renew_first_last_erase_start(Nodeptr &node) {
            if (node == HeadLeft_first()) {
                tree_iterator it(++begin());
                HeadLeft_first() = it.Mynode();
            }
            if (node == HeadRight_last()) {
                tree_reverse_iterator rit(++rbegin());
                HeadRight_last() = rit.Mynode();
            }
        }

        void renew_first_last_erase_swap(Nodeptr &node1, Nodeptr &node2) {
            if (HeadLeft_first() == node1) {
                HeadLeft_first() = node2;
            } else if (HeadLeft_first() == node2) {
                HeadLeft_first() = node1;
            }
            if (HeadRight_last() == node1) {
                HeadRight_last() = node2;
            } else if (HeadRight_last() == node2) {
                HeadRight_last() = node1;
            }
        }

        Nodeptr find_node(const key_type &key) const {
            Nodeptr temp;
            if (_size == 0) {
                return _head;
            } else {
                temp = Root();
                while (!Isnil(temp)) {
                    if (Key(temp) == key) {
                        return temp;
                    } else if (Mybase::comp(key, Key(temp))) {
                        if (!Isnil(Left(temp))) {
                            temp = Left(temp);
                        } else {
                            return _head;
                        }
                    } else {
                        if (!Isnil(Right(temp))) {
                            temp = Right(temp);
                        } else {
                            return _head;
                        }
                    }
                }
                return _head;
            }
        }

        void rebalanse_insert(Nodeptr &node) {
            Nodeptr father = Parent(node);
            if (Color(node) == Black) {
                return;
            }
            if (Isnil(father)) {
                Color(node) = Black;
                return;
            }
            if (Color(father) == Black) {
                return;
            }
            Nodeptr grand = Parent(father);
            if (Isnil(grand)) {
                Color(father) = Black;
                return;
            }
            Nodeptr uncle;
            if (Left(grand) == father) {
                uncle = Right(grand);
            } else {
                uncle = Left(grand);
            }
            if (!Isnil(uncle) && Color(uncle) == Red) {
                Color(father) = Black;
                Color(uncle)  = Black;
                Color(grand)  = Red;
                rebalanse_insert(grand);
                return;
            }
            if (Left(father) == node && Left(grand) == father) {
                rotate_R(father);
            } else if (Right(father) == node && Right(grand) == father) {
                rotate_L(father);
            } else if (Right(father) == node && Left(grand) == father) {
                rotate_LR(father);
            } else if (Left(father) == node && Right(grand) == father) {
                rotate_RL(father);
            }

        }

        void rebalanse_erase(Nodeptr &node) {
            Nodeptr sibling_node;
            Nodeptr parent_node = Parent(node);
            if (Isnil(parent_node)) {
                return;
            }
            if (Left(parent_node) == node) {
                sibling_node = Right(parent_node);
                if (!Isnil(sibling_node)
                    && Color(sibling_node) == Black
                    && Color(Right(sibling_node)) == Red) {
                    rotate_L(sibling_node);
                } else if (!Isnil(sibling_node)
                           && Color(sibling_node) == Black
                           && Color(Right(sibling_node)) == Black
                           && Color(Left(sibling_node)) == Red) {
                    rotate_RL(sibling_node);
                } else if (!Isnil(sibling_node)
                           && Color(sibling_node) == Black
                           && Color(parent_node) == Red) {
                    Color(sibling_node) = Red;
                    Color(parent_node)  = Black;
                    return;
                } else if (Color(sibling_node) == Black
                           && Color(parent_node) == Black) {
                    Color(sibling_node) = Red;
                    rebalanse_erase(parent_node);
                    return;
                } else if (Color(sibling_node) == Red) {
                    Nodeptr local_root = Parent(parent_node);
                    Nodeptr far_child  = Right(sibling_node);
                    rotate_L(sibling_node);
                    Color(far_child)     = Black;
                    if (!Isnil(local_root)) {
                        if (Left(local_root) == parent_node) {
                            Left(local_root) = sibling_node;
                        } else {
                            Right(local_root) = sibling_node;
                        }
                    } else {
                        Parent(local_root) = sibling_node;
                    }
                    Parent(sibling_node) = local_root;
                    rebalanse_erase(node);
                    return;
                }
            } else {
                sibling_node = Left(parent_node);
                if (!Isnil(sibling_node)
                    && Color(sibling_node) == Black
                    && Color(Left(sibling_node)) == Red) {
                    rotate_R(sibling_node);
                } else if (!Isnil(sibling_node)
                           && Color(sibling_node) == Black
                           && Color(Left(sibling_node)) == Black
                           && Color(Right(sibling_node)) == Red) {
                    rotate_LR(sibling_node);
                } else if (!Isnil(sibling_node)
                           && Color(sibling_node) == Black
                           && Color(parent_node) == Red) {
                    Color(sibling_node) = Red;
                    Color(parent_node)  = Black;
                    return;
                } else if (Color(sibling_node) == Black
                           && Color(parent_node) == Black) {
                    Color(sibling_node) = Red;
                    rebalanse_erase(parent_node);
                    return;
                } else if (Color(sibling_node) == Red) {
                    Nodeptr local_root = Parent(parent_node);
                    Nodeptr far_child  = Left(sibling_node);
                    rotate_R(sibling_node);
                    Color(far_child)     = Black;
                    if (!Isnil(local_root)) {
                        if (Left(local_root) == parent_node) {
                            Left(local_root) = sibling_node;
                        } else {
                            Right(local_root) = sibling_node;
                        }
                    } else {
                        Parent(local_root) = sibling_node;
                    }
                    Parent(sibling_node) = local_root;
                    rebalanse_erase(node);
                    return;
                }
            }
        }

        void rotate_R(Nodeptr &father) {
            Nodeptr child      = Left(father);
            Nodeptr grand      = Parent(father);
            Nodeptr local_root = Parent(grand);
            Left(grand)   = Right(father);
            if (!Isnil(Left(grand))) {
                Parent(Left(grand)) = grand;
            }
            Right(father) = grand;
            if (!Isnil(Right(father))) {
                Parent(Right(father)) = father;
            }
            if (!Isnil(child)) {
                Color(child) = Color(father);
            }
            char temp_color_father = Color(father);
            Color(father)  = Color(grand);
            Color(grand)   = temp_color_father;
            if (!Isnil(local_root)) {
                if (Left(local_root) == grand) {
                    Left(local_root) = father;
                } else {
                    Right(local_root) = father;
                }
            } else {
                Parent(local_root) = father;
            }
            Parent(father) = local_root;

        }

        void rotate_L(Nodeptr &father) {
            Nodeptr child      = Right(father);
            Nodeptr grand      = Parent(father);
            Nodeptr local_root = Parent(grand);
            Right(grand) = Left(father);
            if (!Isnil(Right(grand))) {
                Parent(Right(grand)) = grand;
            }
            Left(father) = grand;
            if (!Isnil(Left(father))) {
                Parent(Left(father)) = father;
            }
            if (!Isnil(child)) {
                Color(child) = Color(father);
            }
            char temp_color_father = Color(father);
            Color(father)  = Color(grand);
            Color(grand)   = temp_color_father;
            if (!Isnil(local_root)) {
                if (Left(local_root) == grand) {
                    Left(local_root) = father;
                } else {
                    Right(local_root) = father;
                }
            } else {
                Parent(local_root) = father;
            }
            Parent(father) = local_root;
        }

        void rotate_LR(Nodeptr &father) {
            Nodeptr child = Right(father);
            if (Isnil(child)) {
                return;
            }
            Nodeptr grand      = Parent(father);
            Nodeptr local_root = Parent(grand);
            Left(grand)   = Right(child);
            if (!Isnil(Left(grand))) {
                Parent(Left(grand)) = grand;
            }
            Right(father) = Left(child);
            if (!Isnil(Right(father))) {
                Parent(Right(father)) = father;
            }
            Left(child)   = father;
            if (!Isnil(Left(child))) {
                Parent(Left(child)) = child;
            }
            Right(child)  = grand;
            if (!Isnil(Right(child))) {
                Parent(Right(child)) = child;
            }
            Color(child)  = Color(grand);
            Color(grand)  = Color(father);
            if (!Isnil(local_root)) {
                if (Left(local_root) == grand) {
                    Left(local_root) = child;
                } else {
                    Right(local_root) = child;
                }
            } else {
                Parent(local_root) = child;
            }
            Parent(child) = local_root;
        }

        void rotate_RL(Nodeptr &father) {
            Nodeptr child = Left(father);
            if (Isnil(child)) {
                return;
            }
            Nodeptr grand      = Parent(father);
            Nodeptr local_root = Parent(grand);
            Right(grand)  = Left(child);
            if (!Isnil(Right(grand))) {
                Parent(Right(grand)) = grand;
            }
            Left(father)  = Right(child);
            if (!Isnil(Left(father))) {
                Parent(Left(father)) = father;
            }
            Right(child)  = father;
            if (!Isnil(Right(child))) {
                Parent(Right(child)) = child;
            }
            Left(child)   = grand;
            if (!Isnil(Left(child))) {
                Parent(Left(child)) = child;
            }
            Color(child)  = Color(grand);
            Color(grand)  = Color(father);
            if (!Isnil(local_root)) {
                if (Left(local_root) == grand) {
                    Left(local_root) = child;
                } else {
                    Right(local_root) = child;
                }
            } else {
                Parent(local_root) = child;
            }
            Parent(child) = local_root;
        }

        Nodeptr lbound(const key_type &Kv) const {
            Nodeptr X = Root();
            Nodeptr Y = _head;
            while (!(Isnil(X))) {
                if (Mybase::comp(Key(X), Kv)) {
                    X = Right(X);
                } else {
                    Y = X;
                    X = Left(X);
                }
            }
            return Y;
        }

        Nodeptr ubound(const key_type &Kv) const {
            Nodeptr X = Root();
            Nodeptr Y = _head;
            while (!(Isnil(X))) {
                if (Mybase::comp(Kv, Key(X))) {
                    Y = X;
                    X = Left(X);
                } else {
                    X = Right(X);
                }
            }
            return Y;
        }

        Nodeptr &Root() {
            return Parent(_head);
        }

        Nodeptr &Root() const {
            return Parent(_head);
        }

        Nodeptr &HeadLeft_first() {
            return Left(_head);
        }

        Nodeptr &HeadLeft_first() const {
            return Left(_head);
        }

        Nodeptr &HeadRight_last() {
            return Right(_head);
        }

        Nodeptr &HeadRight_last() const {
            return Right(_head);
        }

//    private:
//        void print_tree_set() {
//            std::cout << "\033[0;34m" << "printing set tree:" << "\033[0m" << std::endl;
//            std::cout << "_head color=" << (int) Color(_head) << std::endl;
//            print_tree_set_p(Root());
//        }
//
//        void print_tree_map() {
//            std::cout << "\033[0;34m" << "printing map tree:" << "\033[0m" << std::endl;
//            std::cout << "_head color=" << (int) Color(_head) << std::endl;
//            print_tree_map_p(Root());
//        }
//
//        void print_tree_set_p(Nodeptr node) {
//            std::cout << "isnil(node) = " << (Isnil(node) ? "nill" : "real") << std::endl;
//            if (Isnil(node)) {
//                return;
//            }
//            std::cout << "value = " << Value(node) << ", color = "
//                      << ((Color(node) == Black) ? "\033[0;40m""Black" : "")
//                      << ((Color(node) == Red) ? "\033[0;41m""Red" : "")
//                      << "\033[0m" << std::endl;
//            std::cout << "isnil(left) = " << (Isnil(Left(node)) ? "nill" : "real") << std::endl;
//            if (!Isnil(Left(node))) {
//                std::cout << "value of left= " << Value(Left(node)) << std::endl;
//            }
//            std::cout << "isnil(right) = " << (Isnil(Right(node)) ? "nill" : "real") << std::endl;
//            if (!Isnil(Right(node))) {
//                std::cout << "value of right= " << Value(Right(node)) << std::endl;
//            }
//            if (!Isnil(Left(node))) {
//                std::cout << "go to left" << std::endl;
//                print_tree_set_p(Left(node));
//            }
//            if (!Isnil(Right(node))) {
//                std::cout << "go to right" << std::endl;
//                print_tree_set_p(Right(node));
//            }
//        }
//
//        void print_tree_map_p(Nodeptr node) {
//            std::cout << "isnil(node) = " << (Isnil(node) ? "nill" : "real") << std::endl;
//            if (Isnil(node)) {
//                return;
//            }
//            std::cout << "color = " << (int) Color(node) << std::endl;
//
//            std::cout << "key = " << Value(node).first << ", value = "
//                      << Value(node).second << ", color = "
//                      << ((Color(node) == Black) ? "\033[0;46m""Black" : "")
//                      << ((Color(node) == Red) ? "\033[0;41m""Red" : "")
//                      << "\033[0m" << std::endl;
//            std::cout << "isnil(left) = " << (Isnil(Left(node)) ? "nill" : "real") << std::endl;
//            if (!Isnil(Left(node))) {
//                std::cout << "key of left = " << Value(Left(node)).first << ", value of left= "
//                          << Value(Left(node)).second << std::endl;
//            }
//            std::cout << "isnil(right) = " << (Isnil(Right(node)) ? "nill" :
//                                               "real") << std::endl;
//            if (!Isnil(Right(node))) {
//                std::cout << "key of right = " << Value(Right(node)).first
//                          << ", value of right= " << Value(Right(node)).second << std::endl;
//            }
//            if (!Isnil(Left(node))) {
//                std::cout << "go to left" << std::endl;
//                print_tree_map_p(Left(node));
//            }
//            if (!Isnil(Right(node))) {
//                std::cout << "go to right" << std::endl;
//                print_tree_map_p(Right(node));
//            }
//        }
    };

    template<class Tr>
    void swap(tree<Tr> &lhs, tree<Tr> &rhs) {
        return lhs.swap(rhs);
    }

    template<class Tr>
    bool operator==(tree<Tr> const &lhs, tree<Tr> const &rhs) throw() {
        if (&lhs == &rhs) {
            return true;
        }
        if (lhs.size() != rhs.size()) {
            return false;
        }
        return equal(lhs.begin(), lhs.end(), rhs.begin());
    }

    template<class Tr>
    bool operator!=(tree<Tr> const &lhs, tree<Tr> const &rhs) throw() {
        return !(lhs == rhs);
    }

    template<class Tr>
    bool operator<(tree<Tr> const &lhs, tree<Tr> const &rhs) throw() {
        return lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end(), lhs.value_comp());
    }

    template<class Tr>
    bool operator>(tree<Tr> const &lhs, tree<Tr> const &rhs) throw() {
        return (rhs < lhs);
    }

    template<class Tr>
    bool operator<=(tree<Tr> const &lhs, tree<Tr> const &rhs) throw() {
        return !(rhs < lhs);
    }

    template<class Tr>
    bool operator>=(tree<Tr> const &lhs, tree<Tr> const &rhs) throw() {
        return !(lhs < rhs);
    }
}

#endif //TREE_HPP
