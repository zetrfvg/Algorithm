/*
恶心模拟设计题，抄了一份代码
*/
struct Node{
    string str;
    int count;
    unordered_map<char,Node*> words;
};

class Trie{
public:
    Node* root;
    
    Trie(){
        root = new Node();
    }
    
    void insert(string& input, int time){
        Node* curr = root;
        for(char ch: input){
            if(curr->words.find(ch) == curr->words.end()){
                curr->words[ch] = new Node();
            }
            curr = curr->words[ch];
        }
        curr->count += time;
        curr->str = input;
    }
    
    void search(Node* curr, vector<pair<int,string>> &results){
        if(!curr) return;
        if(curr->count > 0){
            results.push_back(make_pair(-curr->count, curr->str));
        }
        for(auto& p: curr->words){
            search(p.second, results);
        }
    }
};

class AutocompleteSystem {
public:
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        trie = new Trie();
        currInput.clear();
        for(int i = 0; i < sentences.size(); ++i){
            trie->insert(sentences[i], times[i]);
        }
        node = trie->root;
    }
    
    vector<string> input(char c) {
        vector<string> res;
        if(c == '#'){
            trie->insert(currInput, 1);
            currInput.clear();
            node = trie->root;
            return {};
        }
        else{
            currInput += c;
            if(node->words.find(c) == node->words.end()){
                node->words[c] = new Node();
            }
            node = node->words[c];
            vector<pair<int,string>> results;
            trie->search(node, results);
            sort(results.begin(), results.end());
            for(int i = 0; i < min((int)results.size(),3); ++i){
                res.push_back(results[i].second);
            }
            return res;
        }
    }
    
private:
    Node* node;
    Trie* trie;
    string currInput;
};
