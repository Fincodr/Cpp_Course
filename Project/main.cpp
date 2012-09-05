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
#ifdef _MSC_VER
	#ifdef _DEBUG
	// We are using Visual Studio so enable memory debugging
	#define _CRTDBG_MAP_ALLOC
	#include <crtdbg.h>
	#endif
#endif

/**
 *
 * Standard C libraries are allowed
 *
 */
#include <string.h>     // for strlen
#include <stdlib.h>     // for malloc
#include <assert.h>		// for assert macro
#include <stdio.h>		// for printf

/**
 *
 * C++ libraries are not allowed, except for exception handling
 *
 */
// TODO: Remove these..
#include <iostream>     // for cout and endl
#include <string>


#include <stdexcept>

#include "List.hpp"             // for Linked-List container
#include "String.hpp"           // for our own String implementation
#include "Pair.hpp"
//#include "IOStream.hpp"         // for our own Input output implementation

using std::cout;
using std::endl;

using namespace nonstd;

typedef Pair<String, String> WordPair;


int main()
{
	// If we are on windows we can set the console output codepage to ansi
	setlocale(LC_ALL, "");

	// Start new scope
	{
		// Constructor
		WordPair word01( "a school", "koulu" );
		WordPair word02( "a class", "luokka" );
		WordPair word03( "is playing", "pelaa" );
		WordPair word04( "a game", "peli" );
		WordPair word05( "a laptop", "kannettava tietokone" );
		WordPair word06( "cold", "kylma" );
		WordPair word07( "warm", "lammin" );
		WordPair word08( "hot", "kuuma" );
		WordPair word09( "well done", "hienoa" );
		WordPair word10( "thank you", "kiitos" );
		WordPair word11( "a professor", "professori" );
		WordPair word12( "we have", "meilla on" );
		WordPair word13( "a pupil", "oppilas" );
		WordPair word14( "count", "laskea" );
		WordPair word15( "amazing", "hammastyttava" );
		WordPair word16( "like", "pitaa jostakin" );
		WordPair word17( "know", "tietaa" );
		WordPair word18( "a fruit", "hedelma" );
		WordPair word19( "eat", "syota" );
		WordPair word20( "food", "ruoka" );
		WordPair word21( "drink", "juoda" );
		WordPair word22( "but", "mutta" );
		WordPair word23( "need", "tarvita" );
		WordPair word24( "energy", "energia" );
		WordPair word25( "the sun", "aurinko" );
		WordPair word26( "a wind", "tuuli" );
		WordPair word27( "a sea", "meri" );
		WordPair word28( "at night", "yolla" );
		WordPair word29( "a night", "yo" );
		WordPair word30( "off the wall", "seinasta" );
		WordPair word31( "a wall", "seina" );
		WordPair word32( "play", "pelata" );
		WordPair word33( "love", "rakastaa" );
		WordPair word34( "why", "miksi" );
		WordPair word35( "ice cream", "jaatelo" );
		WordPair word36( "a toy", "lelu" );
		WordPair word37( "a factory", "tehdas" );
		WordPair word38( "look", "katsoa" );
		WordPair word39( "a suprise", "yllatys" );
		WordPair word40( "fantastic", "upea" );
		WordPair word41( "many", "monta" );
		WordPair word42( "here", "taalla" );
		WordPair word43( "any", "yhtaan" );
		WordPair word44( "a pet", "lemmikki" );
		WordPair word45( "a rat", "rotta" );
		WordPair word46( "a snail", "etana" );
		WordPair word47( "a whale", "valas" );
		WordPair word48( "very", "erittain" );
		WordPair word49( "also", "myos" );
		WordPair word50( "this", "tama" );
		WordPair word51( "a brain", "aivot" );
		WordPair word52( "a computer", "tietokone" );
		WordPair word53( "a heart", "sydan" );
		WordPair word54( "ten", "kymmenen" );
		WordPair word55( "eleven", "yksitoista" );
		WordPair word56( "twelve", "kaksitoista" );
		WordPair word57( "thirteen", "kolmetoista" );
		WordPair word58( "fourteen", "neljatoista" );
		WordPair word59( "fifteen", "viisitoista" );
		WordPair word60( "sixteen", "kuusitoista" );
		WordPair word61( "eighteen", "kahdeksantoista" );
		WordPair word62( "nineteen", "yhdeksantoista" );
		WordPair word63( "twenty", "kaksikymmenta" );

		nonstd::List<WordPair> mylist;

		// Add to my own list
		mylist.push_back(word01);
		mylist.push_back(word02);
		mylist.push_back(word03);
		mylist.push_back(word04);
		mylist.push_back(word05);
		mylist.push_back(word06);
		mylist.push_back(word07);
		mylist.push_back(word08);
		mylist.push_back(word09);
		mylist.push_back(word10);
		mylist.push_back(word11);
		mylist.push_back(word12);
		mylist.push_back(word13);
		mylist.push_back(word14);
		mylist.push_back(word15);
		mylist.push_back(word16);
		mylist.push_back(word17);
		mylist.push_back(word18);
		mylist.push_back(word19);
		mylist.push_back(word20);
		mylist.push_back(word21);
		mylist.push_back(word22);
		mylist.push_back(word23);
		mylist.push_back(word24);
		mylist.push_back(word25);
		mylist.push_back(word26);
		mylist.push_back(word27);
		mylist.push_back(word28);
		mylist.push_back(word29);
		mylist.push_back(word30);
		mylist.push_back(word31);
		mylist.push_back(word32);
		mylist.push_back(word33);
		mylist.push_back(word34);
		mylist.push_back(word35);
		mylist.push_back(word36);
		mylist.push_back(word37);
		mylist.push_back(word38);
		mylist.push_back(word39);
		mylist.push_back(word40);
		mylist.push_back(word41);
		mylist.push_back(word42);
		mylist.push_back(word43);
		mylist.push_back(word44);
		mylist.push_back(word45);
		mylist.push_back(word46);
		mylist.push_back(word47);
		mylist.push_back(word48);
		mylist.push_back(word49);
		mylist.push_back(word50);
		mylist.push_back(word51);
		mylist.push_back(word52);
		mylist.push_back(word53);
		mylist.push_back(word54);
		mylist.push_back(word55);
		mylist.push_back(word56);
		mylist.push_back(word57);
		mylist.push_back(word58);
		mylist.push_back(word59);
		mylist.push_back(word60);
		mylist.push_back(word61);
		mylist.push_back(word62);
		mylist.push_back(word63);

		mylist.sort();

		std::cout << "** After sorting **" << std::endl;
		// Print contents using C++11 for_each syntax
		for( auto item : mylist )
		{
			std::cout << item->getFirstType() << " = " << item->getSecondType() << std::endl;
		}
		std::cout << std::endl;

		while ( true )
		{
			std::cout << ::endl;
			std::string text;
			std::getline(std::cin, text);

			// Find one item from list
			WordPair* wordpair = mylist.find(
				/* lambda function */
				[&]( WordPair* tempwordpair ) {
					if ( strstr( tempwordpair->getFirstType(), text.c_str() ) != nullptr || strstr( tempwordpair->getSecondType(), text.c_str() ) != nullptr )
						return ( true );
					else
						return ( false );
				}
			);

			if ( wordpair ) {
				std::cout << std::endl << "First match:" << std::endl;
				std::cout << wordpair->getSecondType() << " = " << wordpair->getFirstType() << std::endl;
			}
			else
				std::cout << "Error: No match!" << std::endl;

		}


		/*
		std::cout << "** Without sorting **" << std::endl;
		// Print contents using C++11 for_each syntax
		for( auto item : mylist )
		{
			std::cout << item->getFirstType() << " = " << item->getSecondType() << std::endl;
		}
		std::cout << endl;

		mylist.sort();

		std::cout << "** After sorting **" << std::endl;
		// Print contents using C++11 for_each syntax
		for( auto item : mylist )
		{
			std::cout << item->getFirstType() << " = " << item->getSecondType() << std::endl;
		}

		std::cout << std::endl;
		std::cout << "** Popping items out **" << std::endl;
		// Get items out
		while ( WordPair* word = mylist.front() ) {
			std::cout << word->getFirstType() << " = " << word->getSecondType() << std::endl;
			mylist.pop_front();
		}
		*/
	}


    // mylist.debug_print();

    // mylist.sort(WordComparer);

    /*
    cout << "Using for each: " << endl;
    for ( auto& word : stdlist )
    {
        cout << "  Word:" << endl;
        cout << "    Fin: " << word.GetFinnishWord() << endl;
        cout << "    Eng: " << word.GetEnglishWord() << endl;
    }

    cout << endl;

    cout << "Word1: " << endl;
    cout << "  " << word1.GetEnglishWord() << endl;
    cout << "  " << word1.GetFinnishWord() << endl;
    cout << "Word2: " << endl;
    cout << "  " << word2.GetEnglishWord() << endl;
    cout << "  " << word2.GetFinnishWord() << endl;
    */

	#ifdef _CRTDBG_MAP_ALLOC
	_CrtDumpMemoryLeaks();
	#endif

    return 0;
}

