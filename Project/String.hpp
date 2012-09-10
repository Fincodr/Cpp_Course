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

#include <string.h>             // for strlen
#include <stdlib.h>             // for malloc, memcpy

namespace nonstd
{
	const size_t kMAX_STRING_LEN = 1024;

    /**
     *
     *  Note: Basic string container, not for production use!
     *
     *  Warning: Is vulnerable for buffer overflow because input string length is checked with strlen
     *
     */
    template<typename T>
    class Basic_String
    {
        public:

            // ctor
            Basic_String() : chars(nullptr)
            {
            }

            Basic_String( const T* other ) : chars(nullptr)
            {
				chars = nullptr;
                SetChars( other );
            }

            Basic_String& Set( const T* other )
            {
                SetChars( other );
                return *this;
            }

            Basic_String& operator=(const Basic_String&); // delete assignment operator
            Basic_String(const Basic_String&); // delete copy operator


            char* c_str() const
            {
                return chars;
            }

            T* operator()() const
            {
                return chars;
            }

            operator char*()
            {
                return chars;
            }

            void Clear()
            {
               UnSetChars();
            }

			// Compare
			bool operator<( Basic_String& other )
			{
				return strcmp( chars, other.chars ) < 0;
			}
			bool operator>( Basic_String& other )
			{
				return strcmp( chars, other.chars ) > 0;
			}

            // dtor
            ~Basic_String()
            {
                UnSetChars();
            }

        protected:
            void UnSetChars()
            {
                if ( chars != nullptr )
                    delete[] chars;
                chars = nullptr;
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

                if ( len == 0 ) return;

                UnSetChars();

                // allocate memory (reserve one for termination char)
                chars = new T[len*sizeof(T)+sizeof(T)];

                // copy string contents
                memcpy( chars, other, len*sizeof(T) );

                // write termination char
                chars[len] = 0;
            }
            T* chars;

        private:

    };

    // Define it just like in the std::string :)
    typedef Basic_String<char> String;
    typedef Basic_String<wchar_t> WString;
}

#endif // STRING_HPP
