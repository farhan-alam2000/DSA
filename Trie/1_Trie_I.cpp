struct Node{
	Node* links[26];
	bool flag = false;

	bool containKey(char ch)
	{
		return (links[ch - 'a'] != NULL);
	}

	void put(char ch, Node* node)
	{
		links[ch - 'a'] = node;
	}

	Node* get(char ch)
	{
		return links[ch - 'a'];
	}

	void setEnd()
	{
		flag = true;
	}

	bool isEnd()
	{
		return flag;
	}
};

class Trie
{
private: Node* root; 
			
public:
		Trie()
		{
			root = new Node();
		}
		
		//time - O(len)
		void insert(string word)
		{
			Node* node = root;
			for(int i = 0; i<word.length(); i++)
			{
				if(!node->containKey(word[i])){
					node->put(word[i], new Node());
				}
				//moves to the reference trie
				node->get(word[i]);
			}

			node->setEnd();
		}

		//time - O(len)
		bool search(string word)
		{
			Node* node = root;
			for(int i = 0; i < word.length(); i++)
			{
				if(node->containKey(word[i])){
					node = node->get(word[i]);
				}
				else return false;
			}
			return isEnd();
		}

		//time - O(len)
		bool startWith(string word)
		{
			Node* node = root;
			for(int i = 0; i<word.length(); i++)
			{
				if(node->containKey(word[i]))
					node = node->get(word[i]);
				else return false;
			}
			return true;
		}
};