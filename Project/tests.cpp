
/*
    std::cout << "** Without sorting **" << std::endl;
    // Print contents using C++11 for_each syntax
    for( auto item : dictionary )
    {
        std::cout << item->getFirstType() << " = " << item->getSecondType() << std::endl;
    }
    std::cout << endl;

    dictionary.sort();

    std::cout << "** After sorting **" << std::endl;
    // Print contents using C++11 for_each syntax
    for( auto item : dictionary )
    {
        std::cout << item->getFirstType() << " = " << item->getSecondType() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "** Popping items out **" << std::endl;
    // Get items out
    while ( WordPair* word = dictionary.front() ) {
        std::cout << word->getFirstType() << " = " << word->getSecondType() << std::endl;
        dictionary.pop_front();
    }

    // dictionary.debug_print();

    // dictionary.sort(WordComparer);

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

    std::cout << "** After sorting **" << std::endl;
    // Read one line from console (must be ended by return char)
    auto text1 = nonstd::Console::GetLine();
    // Read one char from console
    std::cout << text1 << std::endl;
    std::cout << ch << std::endl;
    // Print contents using C++11 for_each syntax
    for( auto item : dictionary )
    {
        std::cout << item->getFirstType() << " = " << item->getSecondType() << std::endl;
    }
    std::cout << std::endl;
    while ( true )
    {


        if ( wordpair ) {
            std::cout << std::endl << "First match:" << std::endl;
            std::cout << wordpair->getSecondType() << " = " << wordpair->getFirstType() << std::endl;
        }
        else
            std::cout << "Error: No match!" << std::endl;

    }
*/
