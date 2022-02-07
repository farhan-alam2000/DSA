class Node
{	
	Node* link[26];
	int count_words = 0;
	int count_prefix = 0; 
public:

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

	void increaseWords(){
		count_words++;
	}

	void increasePrefix(){
		count_prefix++;
	}

	int countWords(){
		return count_words;
	}

	int countPrefix()
	{
		return count_prefix;
	}

	void deleteEnd(){
		count_words--;
	}
	void deletePrefix(){
		count_prefix--;
	}
};

class Trie{

private:
	Node* root;
public:

	Trie(){
		root = new Node();
	}

	void insert(string word){
		int n = word.length();
		Node* node = root;

		for(int i = 0; i<n ;i++)
		{
			if(!node->containKey(word[i])){
				node->put(word[i],new Node());
			}
			node = node->get(word[i]);
			node->increasePrefix();
		}
		node->increaseWords();
	}

	int countwordEnds(string word)
	{
		int n = word.length();
		Node* node = root;

		for(int i  = 0; i < n; i++)
		{
			if(!node->containKey(word[i])) return 0;
			node = node->get(word[i]);
		}
		return node->countWords();
	}

	int countprefixEnds(string pre)
	{
		int n = pre.size();
		Node* node = root;

		for(int i = 0; i<n; i++)
		{
			if(!node->containKey(word[i])) return 0;
			node = node->get(word[i]);
		}

		return node->countPrefix();
	}

	void erase(string word)
	{
		if(countwordEnds(word) == 0) return;

		Node* node = root;
		int n = word.length();

		for(int i = 0; i<n; i++)
		{
			node = node->get(word[i]);
			node->deletePrefix();
		}
		node->deleteEnd();
	}

};