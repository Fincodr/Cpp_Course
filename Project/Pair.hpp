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
#ifndef PAIR_HPP
#define PAIR_HPP

namespace nonstd
{
	template<typename T1, typename T2>
	class Pair
	{
		public:
			T1 firstType;
			T2 secondType;

			// Empty constructor
			Pair() : firstType(), secondType() {};

			// Constructor with parameters from chars
			Pair( char* first, char* second ) : firstType(), secondType()
			{
				firstType.Set( first );
				secondType.Set( second );
			}

			// Getters
			char* getFirstType()
			{
				return ( firstType() );
			}
			char* getSecondType()
			{
				return ( secondType() );
			}

			// Setters
			Pair& setFirstType( const T1* other )
			{
				firstType.Set( other );
				return *this;
			}
			Pair& setSecondType( const T2* other )
			{
				secondType.Set( other );
				return *this;
			}

			// Compare
			bool operator<( Pair& other )
			{
				return ( firstType < other.firstType );
			}
			bool operator>( Pair& other )
			{
				return ( firstType > other.firstType );
			}

			// Clear
			Pair& clearFirstType()
			{
				firstType.Clear();
				return *this;
			}

			Pair& clearSecondType()
			{
				secondType.Clear();
				return *this;
			}

			// Copy constructor
			Pair(const Pair& other) : firstType(), secondType()
			{
				firstType.Set( other.firstType() );
				secondType.Set( other.secondType() );
			}

			// Assignment operator
			Pair& operator=(const Pair& other)
			{
				setFirstType( other.firstType );
				setSecondType( other.secondType );
				return *this;
			}

			// dtor
			~Pair()
			{
				clearFirstType();
				clearSecondType();
			}
		protected:
		private:
	};

}

#endif // PAIR_HPP
