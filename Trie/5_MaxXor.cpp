struct Node
{
  	Node* link[2];
    
    bool containsKey(int x)
    {
        return (link[x] !=  NULL);
    }
    
    void put(int x, Node* node)
    {
        link[x] = node;
    }
    
    Node* get(int x)
    {
        return link[x];
    }
};

class Trie{

private: Node* root;
public:
    	Trie(){
            root = new Node();
        }
    
    	void insert(int x)
        {
            Node* node = root;
            for(int i = 31; i>= 0 ; i--)
            {
                int bit = (x >> i) & 1;
                if(!node->containsKey(bit))
                    node->put(bit, new Node());
                node = node->get(bit);
            }
        }
    
    	int Max(int x)
        {
            Node* node = root;
            int ans = 0;
            for(int i = 31; i>-1; i--)
            {
                int bit = (x >> i) & 1;
                if(node->containsKey(!bit))
                {
                    ans = (ans|(1 << i));
                    node = node->get(!bit);
                }
                else node = node->get(bit);
            }
            return ans;
        }
    
};

int maxXOR(int n, int m, vector<int> &arr1, vector<int> &arr2) 
{
    Trie* node = new Trie();
    for(int i = 0; i<n; i++){
        node->insert(arr1[i]);
    }
    
    int mx = 0;
    for(int i = 0; i<m; i++)
    {
        int temp = node->Max(arr2[i]);
//         cout << temp << endl;
        mx = max(mx, temp);
    }
    return mx;
}