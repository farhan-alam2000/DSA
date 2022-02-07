struct Node
{
	Node* link[26];
    bool containsKey(char ch)
    {
        return (link[ch - 'a'] !=  NULL);
    }
    
    void put(char ch, Node* node)
    {
        link[ch - 'a'] = node;
    }
    
    Node* get(char ch)
    {
        return link[ch - 'a'];
    }
};

class Trie{
  private: Node* root;
    	int ans;	
   public:
    	
    	Trie()
        {
            ans = 0;
            root = new Node();
        }
    
    	void insert(string word)
        {
            Node* node = root;
            for(auto ch: word)
            {
                if(!node->containsKey(ch)){
                    node->put(ch, new Node());
                    ans++;
                }
                node = node->get(ch);
            }
        }
    
    	int countSubstring(){
            return ans;
        }
};

int countDistinctSubstrings(string &s)
{
    Trie *tr = new Trie();
    int n = s.size();
    for(int i = 0; i<n; i++)
    {
        for(int j = i; j < n; j++)
        {
            tr->insert(s.substr(j, n-j));
        }
    }
//     cout << tr->countSubstring() << endl;
    return tr->countSubstring() + 1; // add empty string
    
}