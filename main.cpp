#include<bits/stdc++.h>

using namespace std;


#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define F first
#define S second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}



class binaryTree
{
public:
	int data;
	binaryTree* left;
	binaryTree* right;
	binaryTree(int data){
		this->data = data;
		left = NULL;
		right = NULL;
	}
	~binaryTree(){
		delete left;
		delete right;
	}
	
};

void preorderTraversal(binaryTree* root){

	if(!root) return;

	cout<<root->data<<" ";
	preorderTraversal(root->left);
	preorderTraversal(root->right);
}

int getIndex( string& s, int si, int ei){
	if( si > ei) return -1;
	stack<char> br;

	for(int i = si; i <= ei ; i++){
		if( s[i] == '('){
			br.push(s[i]);
		}
		else if( s[i] == ')'){
			if(br.top() == '('){
				br.pop();
				if( br.size() == 0){
					return i;
				}
			}

		}
	}

	return -1;
}

binaryTree* builtTreefromString(string& s, int si,int ei){

	if( si > ei) return NULL;

	binaryTree* root = new binaryTree(s[si] -'0');

	int index = -1;

	if( si + 1 <= ei && s[si+1] == '('){
		index = getIndex(s,si+1,ei);
	}

	if( index != -1){

		root->left = builtTreefromString(s,si+2,index-1);

		root->right = builtTreefromString(s, index+2, ei -1 );
	}

	return root;
}



int findIndex(string str, int si, int ei)
{
    if (si > ei)
        return -1;
 
    stack<char> s;
 
    for (int i = si; i <= ei; i++) {
 
        if (str[i] == '(')
            s.push(str[i]);
 
        else if (str[i] == ')') {
            if (s.top() == '(') {
                s.pop();
 
                if (s.empty())
                    return i;
            }
        }
    }
    return -1;
}
 

binaryTree* treeFromString(string str, int si, int ei)
{
    if (si > ei)
        return NULL;
 
    binaryTree* root = new binaryTree(str[si] - '0');
    int index = -1;
 
    if (si + 1 <= ei && str[si + 1] == '(')
        index = findIndex(str, si + 1, ei);
 

    if (index != -1) {
 
        root->left = treeFromString(str, si + 2, index - 1);
 
        root->right
            = treeFromString(str, index + 2, ei - 1);
    }
    return root;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("Error.txt", "w", stderr);
#endif
 
 string s;
 cin>>s;

 binaryTree* root = builtTreefromString(s,0,s.size()-1);

 cout<<"\nPreorder Traversal : ";
 preorderTraversal(root);


return 0;

}

/*

Input : 4(2(3)(1))(6(5))

Output : Preorder Traversal : 4 2 3 1 6 5 
*/
