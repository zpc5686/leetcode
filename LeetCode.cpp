// LeetCode.cpp : 定义控制台应用程序的入口点。

#include "stdafx.h"
using namespace std;


//min stack 


void push(int x) {
    
}

void pop() {
    
}

int top() {
    return 0;
}

int getMin() {
    return 0;
}

// pascal's triangle

vector<vector<int> > generate(int numRows) {
	if(numRows==0)
	{
		vector<vector<int> > ret ;
		ret.clear();
		return ret;
	}
    else if (numRows ==1)
	{
		vector<vector<int>> vec_ret;
		vector<int> p;
		p.push_back(1);
		vec_ret.push_back(p);
		return vec_ret;
	}
	else if(numRows==2)
	{
		vector<vector<int>> vec_ret;
		vector<int> p;
		p.push_back(1);
		vec_ret.push_back(p);
		p.push_back(1);
		vec_ret.push_back(p);
		return vec_ret;
	}
	else 
	{
		vector<vector<int>> vec_ret = generate(numRows-1);
		vector<int> vec_last = vec_ret.back();
		vector<int> new_add;
		int i=0;
		int last_size = vec_last.size();
		for(i=0;i<last_size;i++)
		{
			if(i==0)
			{
				new_add.push_back(vec_last[i]);
			}
			else
			{
				new_add.push_back(vec_last[i]+vec_last[i-1]); 
			}
		}
		new_add.push_back(1);
		vec_ret.push_back(new_add);
		return vec_ret;
	}
}
// pascal's triangle 2
vector<int> getRow(int rowIndex) {
    vector<vector<int>> ret = generate(rowIndex);
	return ret.back();
}

//ZigZag Conversion
//string convert(string s, int nRows) {
//	int columns ; s.length/(nRows+1)
//	if(s.length%(nRows+1)==0)
//	{
//		columns = s.length/(nRows+1);
//	}
//	else
//	{
//		columns = s.length/(nRows+1)+1;
//	}
//	char middlearray[nRows][columns];
//	int i = 0;
//	for(i=0;i<nRows;i++)
//	{
//		
//	}
//}

// reverse integer
 int reverse(int x) {
    char s [256];
    sprintf(s,"%d",x);
    string str = s;
	string ret =str;
	int i =0;
	int len = str.length();
	if(str[0]=='-')
	{
		ret[0]='-';
		for(i=1;i<len;i++)
		{
			ret[len-i]= str[i];
		}
	}

	else
	{
		for(i=0;i<len;i++)
		{
			if(i==0)
			{
				ret[len-1]= str[i];
			}
			else
			{
				ret[len-i-1]=str[i];
			}
		}
	}
	int m = atoi (ret.c_str());
	return m;
 }


// two sum
    vector<int> twoSum(vector<int> &numbers, int target) 
	{
		int index1=0,index2=0;
		int size = numbers.size();
		vector<int> result;
		map<int,int> mymap;
			
		for (int i =0;i<size;i++)
		{
			mymap[numbers[i]]=i+1;
	
		}
		for(int i=0;i<size;i++)
		{
			map<int,int>::iterator key_iter = mymap.begin();
			int com = target - mymap[i];
			key_iter=mymap.find(com);

			if(key_iter!=mymap.end())
			{
				index1 = i+1;
				index2 = key_iter->second;

				if(index1>index2)
				{
					result.push_back(index2);
					result.push_back(index1);
				}
				else
				{
					result.push_back(index1);
					result.push_back(index2);
				}
			}
			else
			{
				if(key_iter->first+numbers[i]==target)
				{
					index1=i+1;
					index2=key_iter->second;
					result.push_back(index1);
					result.push_back(index2);
				}
			}
		}

	return result;
}

// atoi
#define INT_MIN -2147483648
#define INT_MAX 2147483647
long long int pow(int num,int buttom,int m)
{
	if(m==0)
    {
        return num;        
    }
	long long int ret = 1;
	for(int i =0;i<m;i++)
	{
		ret = ret*buttom;
	}
	ret = ret * num;
	return ret;
}



void normalize(const char *str,vector<char> &vec)
{
	bool label = false;
	bool end = false;
	bool space_end = false;
	for(int i =0;i<strlen(str);i++)
	{
		if(str[i] == 32&&!space_end )
		{
			continue;
		}
		else
		{	space_end=true;
			if((str[i]>=48&&str[i]<=57)||str[i]=='-'||str[i]=='+')
			{
				if(str[i]=='-'||str[i]=='+')
				{
					if(!label)
					{
						vec.push_back(str[i]);
						label = true;
					}
					else
					{	
						vec.clear();
						return;
					}
				}
				else
					vec.push_back(str[i]);
			}
			else
				return;
		}
	}
}

long long int get_int(vector<char> &vec,bool &isPositive)
{
	long long int  ret = 0;
	int size = vec.size();
	if (size ==0)
		return ret;

	if(size==1&&(vec[0]=='-'||vec[0]=='+'))
		return ret;
	if(vec[0]=='-')
	{
		isPositive = false;
		for(int i = 1;i<size;i++)
		{	
			int tmp = (int)vec[i]-48;
			ret += pow(tmp,10,size-i-1);
		}
	}
	else if (vec[0]=='+')
	{
		isPositive = true;
		for(int i = 1;i<size;i++)
		{	
			int tmp = (int)vec[i]-48;
			ret += pow(tmp,10,size-i-1);
		}
	}
	else
	{
		isPositive = true;
		for(int i = 0;i<size;i++)
		{	
			int tmp = (int)vec[i]-48;
			ret += pow(tmp,10,size-i-1);
		}
	}
	return ret;
}

int atoi(const char *str) 
{
	vector<char> vec;
	bool isPositive=false;
	normalize(str,vec);
	long long int ret = get_int(vec,isPositive);
	if(isPositive)
	{
		
		if (ret>INT_MAX)
		{
			return INT_MAX;
		}
		else
		{
			return ret;
		}
	}
	else
	{	
		if(ret>(-INT_MIN))
		{	cout<<-INT_MIN<<endl;
			return INT_MIN;
		}
		else
			return -ret;
	}
}

// plus one 
 vector<int> plusOne(vector<int> &digits) {
	int length = digits.size();
	int nine_counts = 0;
	bool up = false;
	vector<int>::iterator i = digits.end()-1;
	if((*i)!=9)
	{
		++(*i);
		return digits;
	}

	for(;i!=digits.begin()-1;i--)
	{
		if((*i)==9)
		{
			(*i) =0;
			nine_counts++;
			up = true;
		}
		else
		{
			if(up)
			{
				++(*i);
				break;
			}
		}
	}
	if(nine_counts==length)
	{
		digits.insert(digits.begin(),1);
		return digits;
	}
	else
		return digits;
}
//Valid Sudoku
bool isValidSudoku(vector<vector<char> > &board) {  

	int column_used[9][9]={0};
	int row_used[9][9]={0};
	int box_used[9][9]={0};
	for(int i =0;i<board.size();i++)
	{
		for (int j = 0;j<board[i].size();j++)
		{
			if(board[i][j]!='.')
			{
				int num = (int)(board[i][j]-'0')-1;
				int k = i/3*3+j/3;
				if(row_used[i][num] || column_used[j][num] || box_used[k][num])
					return false;
				row_used[i][num] = column_used[j][num] = box_used[k][num] = 1;
			}
		}

	}
	return true;
}

// valid parentheses
bool isValid(string s) {
	if(s.size()<2)
		return false;
	std::stack<char> parentheses;
	bool ret = false;
	for (int i =0;i<s.size();i++)
	{
		char t = s[i];
		switch(t)
		{
			case ')':
				if(!parentheses.empty() && parentheses.top()=='(')
					parentheses.pop();
				else
					return false;
				continue;
			case ']':
				if(!parentheses.empty() && parentheses.top()=='[')
					parentheses.pop();
				else
					return false;
				continue;
			case '}':
				if(!parentheses.empty() && parentheses.top()=='{')
					parentheses.pop();
				else
					return false;
				continue;
			default:
				parentheses.push(t);
		}
	}
	return parentheses.empty() ? true : false;
}




//sort a list
typedef struct listnode
{
	int val;
	struct listnode* next;

}ListNode;


ListNode *sortList(ListNode *head) {

	return head;
}

// Search in Rotated Sorted Array

int search(int A[], int n, int target)
{
    int i = 0;
    bool isFind=false;
    int ret =0;
	
    for(i=0;i<n;i++)
    {
       if(A[i]==target)
       {
          ret = i;
          isFind=true;
		  break;
       }
    }
    if(isFind)
	{
        return ret;
	}
    else
        return -1;
}

/// binary tree postorder

typedef struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
}TreeNode;


void PreOrder(TreeNode* root, vector<int>& vec)
{
	if(root!=NULL)
	{
		vec.push_back(root->val);
		PreOrder(root->left,vec);
		PreOrder(root->right,vec);
	}
}

void PostOrder(TreeNode* root, vector<int>& vec)
{

	//if(root!=NULL)
	//{
	//	PostOrder(root->left,vec);
	//	PostOrder(root->right,vec);
	//	vec.push_back(root->val);
	//}
	if(root!=NULL)
	{
	while(root->left!=NULL)
	{
		PostOrder(root->left,vec);
		root->left=NULL;
	}
	while(root->right!=NULL)
	{
		PostOrder(root->right,vec);
		root->right=NULL;
	}
	vec.push_back(root->val);
	}
}

vector<int> postorderTraversal(TreeNode *root) {
   vector<int> ret;
   PostOrder(root, ret);
   return ret;
}
// Gray Code

vector<int>* GenerateGrayCode(int n)
{
	if(n<1)
	{
		vector<int>* ret = new vector<int>();
		ret->push_back(0);
		return ret;
	}
	if(n==1)
	{
		vector<int>* ret = new vector<int>();
		ret->push_back(0);
		ret->push_back(1);
		return ret;
	}
	vector<int>* ret = GenerateGrayCode(n-1);
	for(int i =ret->size()-1;i>=0;i--)
	{
		ret->push_back(ret->at(i)+(1<<n-1));
	}

	return ret;
}

vector<int> GrayCode(int n) 
{
	vector<int> s;
	vector<int>* ret = GenerateGrayCode(n);

	vector<int>::iterator i  = ret->begin();
	while(i!=ret->end())
	{
		s.push_back((*i));
		++i;
	}
	

    return s;
}


//Maximum Depth of Binary Tree 

int maxDepth(TreeNode *root) {
    
	if(root)
	{
		int ld = maxDepth(root->left);
		int rd = maxDepth(root->right);
		
		return ld > rd ? ld+1 : rd+1;
	}
	return 0;
}

// Minimum Depth of Binary Tree
int minDepth(TreeNode *root) {
    if(root)
	{
		int ld = minDepth(root->left);
		int rd = minDepth(root->right);
		return ld<=rd? ld+1:rd+1;
	}
	return 0;
}
// number of 1 bits;
int hammingWeight(unsigned int n) {
	int ret = 0;
	while(n)
	{
		if(n&1)
			ret++;
		n=n>>1;
	}
    return ret;
}

// single number;
//int singleNumber(int A[], int n) {
//	int i=0;
//	int ret =0;
//	for(i=0;i<n;i++)
//	{
//		ret^=A[i];
//	}
//	return ret;
//}

// single number 2
int singleNumber(int A[], int n) {
	
	return 0;
}

//peak element
int findPeakElement(const vector<int> &num) {
	return 0;    
}



// word search
bool exist(vector<vector<char>>& board, string word) {
    int i =0;

}
void test(map<int,int>& m)
{
	m[1]=3;
	m[2]=4;
}
int _tmain(int argc, _TCHAR* argv[])
{
	printf("bool is %d \n",hammingWeight(256));
	return 0;
}

