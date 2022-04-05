#include<bits/stdc++.h>
#include<iostream>
//Indexing used
//0->a
//1->b
//.
//.
//25->z
// if you want to make track of duplicate word than use counter for that also
using namespace std;
/* this trie is made in such a way
-> it will store duplicate word, and gives true on searching of that word till
all duplicate is deleted
 */
struct node {
	bool flag = false;
	int end_with = 0;
	int pre_count = 0;
	node* link[26];

	bool check(char ch)
	{
		return link[ch - 'a'] != NULL;
	}
	void put_char(char ch, node* curr)
	{
		link[ch - 'a'] = curr;
	}
	node* get_node(char ch)
	{
		return link[ch - 'a'];
	}

	void mark_end()
	{
		flag = true;
	}

	bool is_end()
	{
		return flag;
	}
	void addPre()
	{
		pre_count++;
	}
	void addWord()
	{
		end_with++;
	}

	int get_word_count()
	{
		return end_with;
	}
	int get_prefix_count()
	{
		return pre_count;
	}
	void dec_pre()
	{
		pre_count--;
	}
	void dec_word()
	{
		end_with--;
		if (end_with == 0) flag = false;
	}

};

class trie {
private: node* root;

public:

	trie()
	{
		root = new node();
	}

	void insert_word(string str)
	{
		node* curr = root;
		for (auto ch : str)
		{
			if (!curr->check(ch))
			{
				curr->put_char(ch, new node());
			}

			curr = curr->get_node(ch);
			curr->addPre();

		}
		curr->mark_end();
		curr->addWord();

	}


	bool search_word(string str)
	{
		node* curr = root;

		for (auto ch : str)
		{
			if (!curr->check(ch)) return false;

			curr = curr->get_node(ch);
		}

		return curr->is_end();
	}

	bool is_prefix(string pre)
	{
		node* curr = root;

		for (auto ch : pre)
		{
			if (!curr->check(ch)) return false;

			curr = curr->get_node(ch);
		}

		return true;
	}

	int count_word(string str)
	{
		node* curr = root;

		for (auto ch : str)
		{
			if (!curr->check(ch)) return 0;

			curr = curr->get_node(ch);
		}

		return curr->get_word_count();
	}

	int count_prefix(string str)
	{
		node* curr = root;

		for (auto ch : str)
		{
			if (!curr->check(ch)) return 0;

			curr = curr->get_node(ch);
		}

		return curr->get_prefix_count();
	}

	void remove_word(string str)
	{
		if (!search_word(str)) return;

		node* curr = root;

		for (auto ch : str)
		{
			curr = curr->get_node(ch);
			curr->dec_pre();

		}

		curr->dec_word();


	}

};


int main()
{
#ifndef ONLINE_JUDGE
	freopen("C:\\Users\\nites\\Desktop\\c++\\all_input.txt", "r", stdin);
	freopen("C:\\Users\\nites\\Desktop\\c++\\all_output.txt", "w", stdout);
#endif
	trie* trie_ds = new trie();

	trie_ds->insert_word("apple");
	trie_ds->insert_word("applut");
	trie_ds->insert_word("ayple");
	trie_ds->insert_word("bpple");
	trie_ds->insert_word("postrle");
	trie_ds->insert_word("apple");
	trie_ds->insert_word("khan");
	trie_ds->insert_word("choubey");
	trie_ds->insert_word("nitesh");
	trie_ds->insert_word("nitesh");
	trie_ds->insert_word("rani");
	trie_ds->insert_word("abhishek");
	trie_ds->insert_word("nitesh");
	trie_ds->insert_word("nitesh");
	trie_ds->insert_word("niteabba");
	trie_ds->insert_word("abbacc");

	cout << trie_ds->search_word("choubey") << endl;
	cout << trie_ds->search_word("applee") << endl;
	cout << trie_ds->search_word("applle") << endl;
	cout << trie_ds->search_word("postrle") << endl;
	cout << trie_ds->search_word("apple") << endl;
	//Line break
	cout << endl;
	cout << trie_ds->is_prefix("app") << endl;
	cout << trie_ds->is_prefix("a") << endl;
	cout << trie_ds->is_prefix("kl") << endl;
	cout << trie_ds->is_prefix("pose") << endl;
	cout << trie_ds->is_prefix("appl") << endl;
	//Line break
	cout << endl;
	cout << trie_ds->count_prefix("appl") << endl;
	cout << trie_ds->count_prefix("cho") << endl;
	cout << trie_ds->count_word("apple") << endl;
	cout << trie_ds->count_word("khan") << endl;
	//Line break
	cout << endl;
	cout << trie_ds->count_word("nitesh") << endl;
	cout << trie_ds->count_prefix("nite") << endl;

	trie_ds->remove_word("nitesh");
	cout << trie_ds->count_word("nitesh") << endl;
	cout << trie_ds->count_prefix("nite") << endl;
	trie_ds->remove_word("nitesh");
	cout << trie_ds->count_word("nitesh") << endl;
	cout << trie_ds->count_prefix("nite") << endl;





	return 0;
}