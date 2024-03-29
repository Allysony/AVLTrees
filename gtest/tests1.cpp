#include "gtest/gtest.h"
#include "MyAVLTree.hpp"
#include "proj3.hpp"
#include <string>
#include <sstream>
#include <vector>
#include <fstream>

namespace{


// NOTE:  these are not intended as exhaustive tests.
// This should get you started testing.

// The four tests marked "CheckPoint" are going to be run
// on your submission for the checkpoint code.
// This is worth 25% of your grade on the assignment
// and is due at the time marked "checkpoint" (Monday Nov 11, 11:59PM)


// None of the "checkpoint" tests require you to have
// AVL functionality OR the counting of words.
// Implementing your tree as a plain binary search
// tree is more than enough to pass these tests.

// Of course, you are expected to implement AVL functionality
// for the full project.


TEST(CheckPoint, CheckPoint_FindTheRoot)
{
	MyAVLTree<int, std::string> tree;
	tree.insert(5, "foo");

	EXPECT_TRUE( tree.contains(5) );
}

TEST(CheckPoint, CheckPoint_FindOneHop)
{
	MyAVLTree<int, std::string> tree;
	tree.insert(5, "foo");
	tree.insert(10, "bar");

	EXPECT_TRUE( tree.contains(10) );
}

TEST(CheckPoint, CheckPoint_FindTwoHops)
{
	MyAVLTree<int, std::string> tree;
	tree.insert(5, "foo");
	tree.insert(3, "sna");
	tree.insert(10, "bar");
	tree.insert(12, "twelve");

	EXPECT_TRUE( tree.contains(12) );
}



TEST(CheckPoint, CheckPoint_Add5)
{
	MyAVLTree<int, std::string> tree;
	tree.insert(5, "foo");
	tree.insert(3, "sna");
	tree.insert(10, "bar");
	tree.insert(12, "twelve");
	tree.insert(15, "fifteen");

	EXPECT_TRUE( tree.size() == 5 );
}



TEST(PostCheckPoint, InOrderTraversal)
{
	MyAVLTree<int, std::string> tree;
	tree.insert(5, "foo");
	tree.insert(3, "sna");
	tree.insert(10, "bar");
	tree.insert(12, "twelve");
	tree.insert(15, "fifteen");

	std::vector<int> trav = tree.inOrder();
	std::vector<int> expected = {3, 5, 10, 12, 15};
	EXPECT_TRUE( trav == expected );
}



TEST(PostCheckPoint, JackSparrow)
{
	std::string quote = "I'm dishonest, and a dishonest man you can ";
	quote += "always trust to be dishonest. Honestly. It's the honest ";
	quote += "ones you want to watch out for, because you can never ";
	quote += "predict when they're going to do something incredibly... stupid.";

	std::istringstream stream( quote );

	MyAVLTree<std::string, unsigned> tree;

	countWords(stream, tree);
	EXPECT_TRUE(tree.find("dishonest") == 3);
}

TEST(Finaltest, SmallBalance)
{
MyAVLTree<int,int> tree;
tree.insert(5,1);
tree.insert(3,1);
tree.insert(2,1);
std::vector<int> trav = tree.preOrder();
std::vector<int> expected = {3,2,5};
EXPECT_TRUE( trav == expected );
}

TEST(Finaltest, BigBalance)
{
MyAVLTree<int,int> tree;
tree.insert(5,1);
tree.insert(3,1);
tree.insert(2,1);
tree.insert(4,1);
tree.insert(6,1);
tree.insert(7,1);
tree.insert(8,1);
std::vector<int> trav = tree.preOrder();
std::vector<int> expected = {5,3,2,4,7,6,8};
EXPECT_TRUE( trav == expected );
}

TEST(Order, inOrder)
{
MyAVLTree<int, std::string> tree;
for (int i=10;i>4;i--)
{
tree.insert(i,"i=");
}

std::vector keys=tree.inOrder();
std::vector expected={5,6,7,8,9,10};
for (int i=0;i<keys.size();i++)
std::cout<<"at keys["<<i<<"] "<<keys[i]<<std::endl;
EXPECT_TRUE(keys==expected);
}
TEST(Order, postOrder)
{
MyAVLTree<int, std::string> tree;
for (int i=10;i>4;i--)
{
tree.insert(i,"i=");
}

std::vector<int> keys=tree.postOrder();
std::vector<int> expected={5,6,8,10,9,7};

for (int i=0;i<keys.size();i++)
std::cout<<"at keys["<<i<<"]  "<<keys[i]<<std::endl;
EXPECT_TRUE(keys==expected);
}
TEST(Order, preOrder)
{
MyAVLTree<int, std::string> tree;
for (int i=10;i>4;i--)
{
tree.insert(i,"i=");
}

std::vector keys=tree.preOrder();
std::vector expected={7,6,5,9,8,10};
for (int i=0;i<keys.size();i++)
std::cout<<"at keys["<<i<<"] "<<keys[i]<<std::endl;
EXPECT_TRUE(keys==expected);
}

TEST(PostCheckPoint, r1)
{
MyAVLTree<int, std::string> tree;
tree.insert(10, "bar");
tree.insert(12, "twelve");
tree.insert(15, "fifteen");

std::vector<int> trav = tree.inOrder();
std::vector<int> expected = {10, 12, 15};
EXPECT_TRUE( trav == expected );
}

TEST(PostCheckPoint, r2)
{
MyAVLTree<int, std::string> tree;
tree.insert(5, "foo");
tree.insert(3, "sna");
tree.insert(1, "bar");

std::vector<int> trav = tree.inOrder();
std::vector<int> expected = {1, 3, 5};
EXPECT_TRUE( trav == expected );
}

TEST(PostCheckPoint, r3)
{
MyAVLTree<int, std::string> tree;
tree.insert(3, "foo");
tree.insert(11, "sna");
tree.insert(10, "bar");

std::vector<int> trav = tree.inOrder();
std::vector<int> expected = {3, 10, 11};
EXPECT_TRUE( trav == expected );
}

TEST(PostCheckPoint, r4)
{
MyAVLTree<int, std::string> tree;
tree.insert(5, "foo");
tree.insert(3, "sna");
tree.insert(4, "bar");

std::vector<int> trav = tree.inOrder();
std::vector<int> expected = {3, 4, 5};
EXPECT_TRUE( trav == expected );
}

TEST(PostCheckPoint, rr1)
{
MyAVLTree<int, std::string> tree;
tree.insert(-1, "f");
tree.insert(-2, "x");
tree.insert(10, "bar");
tree.insert(12, "twelve");
tree.insert(15, "fifteen");

std::vector<int> trav = tree.inOrder();
std::vector<int> expected = {-2, -1, 10, 12, 15};
EXPECT_TRUE( trav == expected );
}

TEST(PostCheckPoint, rr2)
{
MyAVLTree<int, std::string> tree;
tree.insert(-1, "f");
tree.insert(-2, "x");
tree.insert(5, "foo");
tree.insert(3, "sna");
tree.insert(1, "bar");

std::vector<int> trav = tree.inOrder();
std::vector<int> expected = {-2, -1, 1, 3, 5};
EXPECT_TRUE( trav == expected );
}

TEST(PostCheckPoint, rr3)
{
MyAVLTree<int, std::string> tree;
tree.insert(-1, "f");
tree.insert(-2, "x");
tree.insert(3, "foo");
tree.insert(11, "sna");
tree.insert(10, "bar");

std::vector<int> trav = tree.inOrder();
std::vector<int> expected = {-2, -1, 3, 10, 11};
EXPECT_TRUE( trav == expected );
}

TEST(PostCheckPoint, rr4)
{
MyAVLTree<int, std::string> tree;
tree.insert(-1, "f");
tree.insert(-2, "x");
tree.insert(5, "foo");
tree.insert(3, "sna");
tree.insert(4, "bar");

std::vector<int> trav = tree.inOrder();
std::vector<int> expected = {-2, -1, 3, 4, 5};
EXPECT_TRUE( trav == expected );
}
TEST(Hamlet, HamletOpen)
{

std::ifstream stream;
stream.open("/home/ics46b/projects/proj3/gtest/hamletopen.txt");

MyAVLTree<std::string, unsigned> tree;
countWords(stream, tree);
stream.close();

EXPECT_TRUE(tree.find("marcellus") == 9);
}

TEST(Hamlet, HamletAct1)
{

std::ifstream stream;
stream.open("/home/ics46b/projects/proj3/gtest/hamletact1.txt");
MyAVLTree<std::string, unsigned> tree;

countWords(stream, tree);
stream.close();
EXPECT_TRUE(tree.find("marcellus") == 48);
}



}