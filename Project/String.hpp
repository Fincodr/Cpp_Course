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
#ifndef STRING_HPP
#define STRING_HPP

#include <stdlib.h>             // for malloc, memcpy

namespace nonstd
{
	const size_t kMAX_STRING_LEN = 1024;

    /**
     *
     *  Note: Basic string container, not for production use!
     *
     */
    template<typename T>
    class Basic_String
    {
        public:

            // ctor
            Basic_String() : m_chars(nullptr)
            {
            }

            Basic_String( const T* other ) : m_chars(nullptr)
            {
				m_chars = nullptr;
                SetChars( other );
            }

            Basic_String& Set( const T* other )
            {
                SetChars( other );
                return *this;
            }

            Basic_String& operator=(const Basic_String&); // delete assignment operator
            Basic_String(const Basic_String&); // delete copy operator

			size_t length() const
			{
				return m_length;
			}

            char* c_str() const
            {
                return m_chars;
            }

            T* operator()() const
            {
                return m_chars;
            }

            operator char*()
            {
                return m_chars;
            }

            void Clear()
            {
               UnSetChars();
            }

			// Compare
			bool operator<( Basic_String& other )
			{
				return strcmp( m_chars, other.m_chars ) < 0;
			}
			bool operator>( Basic_String& other )
			{
				return strcmp( m_chars, other.m_chars ) > 0;
			}

            // dtor
            ~Basic_String()
            {
                UnSetChars();
            }

        protected:
            void UnSetChars()
            {
                if ( m_chars != nullptr )
                    delete[] m_chars;
                m_chars = nullptr;
				m_length = 0;
            }

            void SetChars( const T* other )
            {
                // Scan string len, keep maximum
                size_t len = 0;
                for ( len=0; len!=kMAX_STRING_LEN; ++len )
                {
                    T _char = other[len];
                    if ( _char == 0 )
                        break;
                }

                UnSetChars();
				
				m_length = len;

                // allocate memory (reserve one for termination char)
                m_chars = new T[len*sizeof(T)+sizeof(T)];

                // copy string contents
                memcpy( m_chars, other, len*sizeof(T) );

                // write termination char
                m_chars[len] = 0;
            }
            T* m_chars;
			size_t m_length;

        private:

    };

    // Define it just like in the std::string :)
    typedef Basic_String<char> String;
    typedef Basic_String<wchar_t> WString;
}

#endif // STRING_HPP
