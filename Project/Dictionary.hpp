#ifndef DICTIONARY_HPP
#define DICTIONARY_HPP

#include "List.hpp"
#include "Pair.hpp"
#include "String.hpp"

#include <iostream>		// for debug only!

using nonstd::List;
using nonstd::String;
using nonstd::Pair;

typedef Pair<String, String> WordPair;

class Dictionary : public List<WordPair>
{
	public:
		virtual ~Dictionary() {};
		virtual void load(char*);
		virtual void save(char*);
	private:
	protected:
};

void Dictionary::load(char* filename)
{
	std::cout << "Dictionary::Loading from file " << filename << std::endl;
}

void Dictionary::save(char* filename) {
	std::cout << "Dictionary::Saving to file " << filename << std::endl;
}

#endif // DICTIONARY_HPP

/*
	// Constructor
	WordPair word01( (char*)"a school", (char*)"koulu" );
	WordPair word02( (char*)"a class", (char*)"luokka" );
	WordPair word03( (char*)"is playing", (char*)"pelaa" );
	WordPair word04( (char*)"a game", (char*)"peli" );
	WordPair word05( (char*)"a laptop", (char*)"kannettava tietokone" );
	WordPair word06( (char*)"cold", (char*)"kylma" );
	WordPair word07( (char*)"warm", (char*)"lammin" );
	WordPair word08( (char*)"hot", (char*)"kuuma" );
	WordPair word09( (char*)"well done", (char*)"hienoa" );
	WordPair word10( (char*)"thank you", (char*)"kiitos" );
	WordPair word11( (char*)"a professor", (char*)"professori" );
	WordPair word12( (char*)"we have", (char*)"meilla on" );
	WordPair word13( (char*)"a pupil", (char*)"oppilas" );
	WordPair word14( (char*)"count", (char*)"laskea" );
	WordPair word15( (char*)"amazing", (char*)"hammastyttava" );
	WordPair word16( (char*)"like", (char*)"pitaa jostakin" );
	WordPair word17( (char*)"know", (char*)"tietaa" );
	WordPair word18( (char*)"a fruit", (char*)"hedelma" );
	WordPair word19( (char*)"eat", (char*)"syota" );
	WordPair word20( (char*)"food", (char*)"ruoka" );
	WordPair word21( (char*)"drink", (char*)"juoda" );
	WordPair word22( (char*)"but", (char*)"mutta" );
	WordPair word23( (char*)"need", (char*)"tarvita" );
	WordPair word24( (char*)"energy", (char*)"energia" );
	WordPair word25( (char*)"the sun", (char*)"aurinko" );
	WordPair word26( (char*)"a wind", (char*)"tuuli" );
	WordPair word27( (char*)"a sea", (char*)"meri" );
	WordPair word28( (char*)"at night", (char*)"yolla" );
	WordPair word29( (char*)"a night", (char*)"yo" );
	WordPair word30( (char*)"off the wall", (char*)"seinasta" );
	WordPair word31( (char*)"a wall", (char*)"seina" );
	WordPair word32( (char*)"play", (char*)"pelata" );
	WordPair word33( (char*)"love", (char*)"rakastaa" );
	WordPair word34( (char*)"why", (char*)"miksi" );
	WordPair word35( (char*)"ice cream", (char*)"jaatelo" );
	WordPair word36( (char*)"a toy", (char*)"lelu" );
	WordPair word37( (char*)"a factory", (char*)"tehdas" );
	WordPair word38( (char*)"look", (char*)"katsoa" );
	WordPair word39( (char*)"a suprise", (char*)"yllatys" );
	WordPair word40( (char*)"fantastic", (char*)"upea" );
	WordPair word41( (char*)"many", (char*)"monta" );
	WordPair word42( (char*)"here", (char*)"taalla" );
	WordPair word43( (char*)"any", (char*)"yhtaan" );
	WordPair word44( (char*)"a pet", (char*)"lemmikki" );
	WordPair word45( (char*)"a rat", (char*)"rotta" );
	WordPair word46( (char*)"a snail", (char*)"etana" );
	WordPair word47( (char*)"a whale", (char*)"valas" );
	WordPair word48( (char*)"very", (char*)"erittain" );
	WordPair word49( (char*)"also", (char*)"myos" );
	WordPair word50( (char*)"this", (char*)"tama" );
	WordPair word51( (char*)"a brain", (char*)"aivot" );
	WordPair word52( (char*)"a computer", (char*)"tietokone" );
	WordPair word53( (char*)"a heart", (char*)"sydan" );
	WordPair word54( (char*)"ten", (char*)"kymmenen" );
	WordPair word55( (char*)"eleven", (char*)"yksitoista" );
	WordPair word56( (char*)"twelve", (char*)"kaksitoista" );
	WordPair word57( (char*)"thirteen", (char*)"kolmetoista" );
	WordPair word58( (char*)"fourteen", (char*)"neljatoista" );
	WordPair word59( (char*)"fifteen", (char*)"viisitoista" );
	WordPair word60( (char*)"sixteen", (char*)"kuusitoista" );
	WordPair word61( (char*)"eighteen", (char*)"kahdeksantoista" );
	WordPair word62( (char*)"nineteen", (char*)"yhdeksantoista" );
	WordPair word63( (char*)"twenty", (char*)"kaksikymmenta" );
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
*/
