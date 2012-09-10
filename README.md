# C++ programming course
## Helsinki Metropolia University of Applied Sciences
Course goals: After completing the course the student is capable to learn to use different kind of class libraries and application frameworks.

###Project task:
* Create dictionary app for storing and searching english and finnish words. Database must be simple text file. No C++ libraries or STL (for example std::string or std::list) is allowed.

###My solution for the task:

*Contains:*
* Console class (input from and output to console)
* String class (stores chars as array)
* Pair class (stores any two classes together)
* List class (stores any objects as double-linked-list)
* Dictionary class (extends List class for loading from and writing to files)

*How it all works:*
* String class is used to store single words
* Pair class is used to store two Strings together as WordPair objects (English and Finnish words)
* List is created for WordPair objects
* Dictionary class is used to load and save word lists
* Search, Insert and Delete functionality is proveded directly by the List class (find, push_back, back, pop_back)
