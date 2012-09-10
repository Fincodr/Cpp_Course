/*
 *     _/_/_/_/  _/                                      _/
 *    _/            _/_/_/      _/_/_/    _/_/      _/_/_/  _/  _/_/
 *   _/_/_/    _/  _/    _/  _/        _/    _/  _/    _/  _/_/
 *  _/        _/  _/    _/  _/        _/    _/  _/    _/  _/
 * _/        _/  _/    _/    _/_/_/    _/_/      _/_/_/  _/
 *
 * Copyright (c) 2012 Mika Luoma-aho <fincodr@mxl.fi>
 *
 * This source code and software is provided 'as-is', without any express or implied warranty.
 * In no event will the authors be held liable for any damages arising from the use of this source code or software.
 *
 * Permission is granted to anyone to use this software (and the source code when its released from the author)
 * as a learning point to create games, including commercial applications.
 *
 * You are however subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not claim that you wrote the original software.
 *    If you use this software's source code in a product,
 *    an acknowledgment in the product documentation would be appreciated but is not required.
 * 2. Altered versions must be plainly marked as such, and must not be misrepresented as being the original software.
 * 3. This notice may not be removed or altered from any distribution.
 *
 */
#ifndef LIST_HPP
#define LIST_HPP

#include <iterator>

namespace nonstd
{

	/**
	 *  Simple std::list type list created from scratch by Mika Luoma-aho (see banner for usage terms)
	 *
	 *  A list (an instance of the container cass List<>) manages its elements as a doubly linked list.
	 *
	 *  Operations:
	 *  c.front() - Returns the first element (or nullptr if no elements exists)
	 *  c.back() - Returns the last element (or nullptr if no element exists)
	 *  c.push_back(elem) - Appends a copy of elem at the end
	 *  c.pop_back() - Removes the last element (does not return it!)
	 *  c.push_front(eleme) - Appends a copy of elem at the end
	 *  c.pop_front() - Removes the first element (does not return it!)
	 *  c.clear() - Clears the list
	 *  c.sort() - Sorts the list (by function elem > elem)
	 *  c.find(op) - Finds and returns an element from the list using op function (can be a lambda for example)
	 *  c.contains(op) - Returns true if an element is found in the list using op function
	 *  c.count() - Returns the count of the items in the dictionary
	 *
	 *  Element insertion happends at constant time
	 *  Element sorting happends at O(^2) time (exponential to the count of elements)
	 *
	 *  Iterator functions:
	 *  - To access all elements of a list, you must use iterators.
	 *
	 */

    template<typename T>
    class List
    {
        public:
            struct Node
            {
                T* item;
                Node* prev;
                Node* next;
            };

            // List start (head) and end (tail)
            Node* head;
            Node* tail;

            List() : head(nullptr), tail(nullptr), m_count(0) {}

            virtual ~List() {
				clear();
			}

            class iterator
            {
                friend class List;
                public:
                    iterator(Node& node) : ptr(&node) {}
                    iterator(Node* p = nullptr) : ptr(p) {}
                    iterator& operator++() { ptr=ptr->next; return *this; }
                    iterator& operator--() { ptr=ptr->prev; return *this; }
                    T* operator*() { return (T*)ptr->item; }
                    T* GetItem() { return (T*)ptr->item; }
                    bool operator==(const iterator& rhs) const { return ptr == rhs.ptr; }
                    bool operator!=(const iterator& rhs) const { return ptr!=rhs.ptr; }
				protected:
                private:
                    Node* ptr;
            };

            iterator begin() const { return ( head ? iterator(head) : nullptr ); }
            iterator end() const { return ( tail ? iterator(tail->next) : nullptr ); }
            iterator last() const { return ( tail ? iterator(tail) : nullptr ); }

            /** Copy constructor
             *  \param other Object to copy from
             */
            List(const List& other) {}

            /** Assignment operator
             *  \param other Object to assign from
             *  \return A reference to this
             */
            List& operator=(const List& other) { return *this; }

			List& push_back( const T& other )
            {
                // Take a internal copy of referenced item
                Node* node = new Node();

                node->item = new T(other);
                node->prev = tail;
                node->next = nullptr;

                // Add node to the end of the list
                if ( tail == nullptr )
                {
                    // The list must be empty, just set it as last and first item then
                    head = tail = node;
                }
                else
                {
                    // Add to last item
                    tail->next = node;
                    tail = node;
                }
                ++m_count;

                // Always return reference back to us
                return *this;
            }

            List& push_front( const T& other )
            {
                // Take a internal copy of referenced item
                Node* node = new Node();

                node->item = new T(other);
                node->prev = nullptr;
                node->next = head;

                // Add node to the start of the list
                if ( head == nullptr )
                {
                    // The list must be empty, just set it as last and first item then
                    head = tail = node;
                }
                else
                {
                    // Add to last item
                    head = head->prev = node;
                }
                ++m_count;

                // Always return reference back to us
                return *this;
            }

            // Implement find ?

			T* front()
			{
				if ( head )
					return head->item;
				return nullptr;
			}

            List& pop_front()
            {
                // Get the front item out of list
                if ( head )
                {
                    // Get the first item
                    Node* node = head;
                    // Set the current head to next item (that can be nullptr)
                    head = node->next;
                    if ( head != nullptr ) {
                        // Set the current head prev pointer to nullptr
                        head->prev = nullptr;
                    }
					delete( node->item );
					delete( node );
					--m_count;
                }

				// Always return reference back to us
                return *this;
            }

            T* back()
            {
                if ( tail )
					return tail->item;
				return nullptr;
            }

			List& pop_back()
			{
                // Get the back item out of list
                if ( tail )
                {
                    // Get the last item
                    Node* node = tail;
                    // Set the current tail to prev item (that can be nullptr)
                    tail = node->prev;
                    if ( tail != nullptr ) {
                        // Set the current head next pointer to nullptr
                        tail->next = nullptr;
                    }
					delete( node->item );
					delete( node );
					--m_count;
                }

				// Always return reference back to us
				return *this;
			}

            List& erase( Node* node )
            {
                if ( node )
                {
                    // if we are the head
                    if ( node == head )
                        pop_front();
                    else if ( node == tail )
                        pop_back();
                    else
                    {
                        Node* prev = node->prev;
                        Node* next = node->next;
                        prev->next = next;
                        next->prev = prev;
                        delete( node->item );
                        delete( node );
                        --m_count;
                    }

                }

                // Always return reference back to us
                return *this;
            }

            void sort()
            {

                Node* list_end = nullptr;
				Node* swap1 = nullptr;

                while ( list_end != head )
                {
                    swap1 = head;
                    while ( swap1->next != list_end )
                    {
                        Node* swap2 = swap1->next;
                        T& item1 = *swap1->item;
                        T& item2 = *swap2->item;
                        if ( item1 > item2 )
                        {
							// Swap item1 and item2 places by swapping the item references only
							T* i1 = swap1->item;
							T* i2 = swap2->item;
							swap1->item = i2;
							swap2->item = i1;
                        }
                        swap1 = swap1->next;
                    }
					list_end = swap1;
                }
            }

			template<class CompareFunction>
			Node* find( CompareFunction c )
			{
                if ( head )
                {
                    Node* node = head;
                    while ( node )
                    {
                        if ( c(node->item) )
                            return( node );
                        node = node->next;
                    }
                }
				return ( nullptr );
			}

			void clear()
			{
				// Delete items in the list
				if ( head )
				{
					while ( front() ) {
						pop_front();
					}
				}
				head = nullptr;
				tail = nullptr;
				m_count = 0;
			}

			int count()
			{
			    return ( m_count );
			}

        protected:
        private:
            int m_count;
    };

}

#endif // LIST_HPP
