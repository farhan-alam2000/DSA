struct Node
{
    	Node* link[26];
    	bool flag = false;
    
    	bool containsKey(char ch)
        {
            return (link[ch - 'a'] != NULL);
        }
    
    	Node* get(char ch)
        {
            return link[ch - 'a'];
        }
    
    	void put(char ch, Node* node)
        {
            link[ch - 'a'] = node;
        }
    
    	void setEnd(){
            flag = true;
        }
    
    	bool isEnd(){
            return flag;
        }
};


class Trie{
    private:
    		Node* root;
    public:
    		Trie(){
                root = new Node();
            }
    
    		void insert(string word)
            {
                int n = word.size();
                Node* node = root;
                for(int i = 0; i<n; i++)
                {
                    if(!node->containsKey(word[i])){
                        node->put(word[i],new Node());
                    }
                    node = node->get(word[i]);
                }
                node->setEnd();
            }
    
    		bool checkAllPrefix(string word)
            {
                bool f = true;
                Node* node = root;
                for(int i = 0; i<word.size(); i++)
                {
                    if(!node->containsKey(word[i])){
                        return false;
                    }
                    node = node->get(word[i]);
                    f = (f & node->isEnd());
                }
               	return f;
            }
};

string completeString(int n, vector<string> &a){
    // Write your code here.
    Trie *tr = new Trie();
    for(int i = 0; i<n; i++){
        tr->insert(a[i]);
    }
    string longest = "";
    
    for(auto word : a)
    {
        if(tr->checkAllPrefix(word)){
            if(word.size() > longest.size())
                longest = word;
            else if(word.size() == longest.size() && word < longest)
                longest = word;
        }
    }
    if(longest == "") return "None";
    return longest;
}
