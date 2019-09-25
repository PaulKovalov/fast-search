# fast-search
Utility to search phrases through the set of text files
This utility uses trie to build indexes on the given files

Query time complexity (assuming query is of size m)
<img src="https://latex.codecogs.com/gif.latex?O(m)" /> 

# fast-search explanation
Fast-search provides an interface to search a phrase (set of words) in the given texts in a <img src="https://latex.codecogs.com/gif.latex?O(m)" />, where <img src="https://latex.codecogs.com/gif.latex?m" /> is a length of the query

# How does it work
It uses prefix tree data structure (trie) to store the texts. However, it stores them permanently and keeps time complexity of the RAM-stored trie. This is achieved by the following idea: to store the word "aba", let's create a filesystem path "a/b/a"
and store there a file with the list of documents, where word "aba" occurs. The idea is illustrated in the picture below
<img src="https://cdn1.imggmi.com/uploads/2019/9/25/9f3d2c5f3bd31cc6bde9677e47f96af4-full.png" />
docs.txt is makes us know that the folder is the end of the word
