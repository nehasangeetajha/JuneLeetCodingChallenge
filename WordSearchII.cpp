//https://leetcode.com/explore/featured/card/june-leetcoding-challenge/543/week-5-june-29th-june-30th/3376/
/*
Given a 2D board and a list of words from the dictionary, find all words in the board.

Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

 

Example:

Input: 
board = [
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]
words = ["oath","pea","eat","rain"]

Output: ["eat","oath"]
 

Note:

All inputs are consist of lowercase letters a-z.
The values of words are distinct.
*/


struct TrieNode
{
    char data;
    bool isEndOfWord;
    unordered_map<char,TrieNode*>neighbours;
    
    TrieNode(char ch, bool end = false)
    {
        this->data = ch;
        this->isEndOfWord = end;
    }
};

struct Trie
{
    TrieNode*root;
    
    Trie()
    {
        root= new TrieNode('*');
    }
    
    void addWord(string word)
    {
        TrieNode*temp = root;
        for(char ch:word)
        {
            TrieNode*node = new TrieNode(ch);
            
            bool isCharPresent = temp->neighbours.count(ch);
            if(isCharPresent)
                temp = temp->neighbours[ch];
            else
            {
                temp->neighbours.insert({ch,node});
                temp = node;
            }
        }
        temp->isEndOfWord = true;
    }
};

Trie buildTrie(vector<string>&words)
{
    Trie trie;
    for(string &word:words)
        trie.addWord(word);
    return trie;
}

bool isValidCell(vector<vector<char>>& board, int row, int col) {
    const int board_rows = (int)board.size();
    const int board_cols = (int)board[0].size();

    return row >= 0 && col >= 0 && row < board_rows && col < board_cols;
}

void searchWord(vector<vector<char>>&board,int row,int col,string &word, TrieNode*trieRoot,unordered_set<string>&foundWords)
{
    if(!isValidCell(board,row,col) || board[row][col] == ' ')
        return;
    const char currChar = board[row][col];
    bool nbr = trieRoot->neighbours.count(currChar);
    
    if (!nbr) return;
    
    word.push_back(currChar);
    board[row][col] = ' ';
    
    trieRoot = trieRoot -> neighbours[currChar];
    if(trieRoot->isEndOfWord)
        foundWords.insert(word);
    
    vector<vector<int>> directions = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    for (auto dir : directions) {
        int newRow = row + dir[0];
        int newCol = col + dir[1];

        searchWord(board, newRow, newCol, word, trieRoot, foundWords);
    }

    board[row][col] = currChar;
    word.pop_back();
}

class Solution {
public:
    // Time complexity => O(W * C + rows^2 * cols^2); where W = words.size() and C = max char len of a word in words
// Space complexity => O(total_chars_in_words_vector)
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string>foundWords;
        unordered_set<string>result;
        Trie trie = buildTrie(words);
        
        for(int row = 0;row<(int)board.size();row++)
        {
            for(int col = 0;col<board[row].size();col++)
            {
                string word = "";
                TrieNode*trieRoot = trie.root;
                searchWord(board,row,col,word,trieRoot,result);
            }
        }
        
        for(auto word:result)
            foundWords.push_back(word);
        
        return foundWords;
    }
};
