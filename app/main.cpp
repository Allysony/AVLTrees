#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

#include "proj3.hpp"
#include "MyAVLTree.hpp"


// If you prefer to develop here, this is one way to do it.

void test1()
{
	MyAVLTree<std::string, unsigned> tree; 
	std::fstream fs;
	fs.open("gtest/hamletact1.txt");
	countWords(fs, tree);
	// do things here if you want.
}

void test2()
{
	MyAVLTree<int, std::string> tree;
	tree.insert(5, "Mike");
	bool b1 = tree.contains(5) && tree.find(5) == "Mike";
	if( b1 )
	{
		std::cout << "test2() passes." << std::endl;
	}
	else
	{
		std::cout << "test2() fails." << std::endl;
	}
}
void test3()
{
    MyAVLTree<int, std::string> tree;
    tree.insert(5, "foo");
    tree.insert(3, "sna");
    tree.insert(10, "bar");
    tree.insert(12, "twelve");
    if(tree.contains(12)){
        std::cout << "lsdjf" << std::endl;
    }
}
void test4()
{
    MyAVLTree<int, std::string> tree;
    tree.insert(5, "foo");
    tree.insert(3, "sna");
    tree.insert(10, "bar");
    tree.insert(12, "twelve");
    tree.insert(15, "fifteen");
    if(tree.size() == 5){
        std::cout << "yes" << std::endl;
    }
}

void LEFTLEFTTEEEEEST()
{
    MyAVLTree<int, std::string> tree;
    tree.insert(11, "a");
    tree.insert(6, "a");
    tree.insert(4, "a");
    tree.insert(2, "a");
    tree.insert(1, "a");

}
int main()
{

	int choice;
	std::cout << "Allyson. will you pick the red pill or the blue one?\n";
	std::cin >> choice;
	switch(choice)
	{
		case 1: test1(); break;
		case 2: test2(); break;
		case 3: test3(); break;
		case 4: test4(); break;
		case 5: LEFTLEFTTEEEEEST(); break;
		default: std::cout << "Not a choice.\n" << std::endl; break;
	}
    return 0;
}

