#include<bits/stdc++.h>
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
                else if(node->containsKey(bit)) 
                    node = node->get(bit);
               	else return -1;
            }
            return ans;
        }
};


vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries){

    vector<pair<int, pair<int,int>>> offlineQueries;
    int m = queries.size();
    int n = arr.size();
    
    vector<int> res(m,0);
    sort(arr.begin(), arr.end());
    int index = 0;
    for(auto &it: queries) {
        offlineQueries.push_back({it[1],{it[0], index++}}); 
    }
   
    sort(offlineQueries.begin(), offlineQueries.end()); 
    
    Trie node;
    int i = 0;
    for(auto& it: offlineQueries)
    {
        while(i < n && arr[i] <= it.first)
        {
            node.insert(arr[i]);
            i++;
        }
        if(i != 0) res[it.second.second] = node.Max(it.second.first);
        else res[it.second.second] = -1;
    }
    return res;
}
