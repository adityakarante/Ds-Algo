/*
1) A trie is a tree and each node in it contains the number of pointers equal to the number of
characters of the alphabet. we consider only a to z
*/
#include<iostream>
#define ll long long
using namespace std;

struct trienode
{
    char data;
    int is_End;
    struct trienode* child[26];//pointer another 26 trie
};



int main(){


}
