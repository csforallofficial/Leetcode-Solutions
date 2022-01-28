class node
{
public:
    node *left;
    node *right;
};

class trie
{
    node *root;

public:
    trie()
    {
        root = new node();
    }

    void insert(int n)
    {
        node *temp = root;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (n >> i) & 1;
            if (bit == 0)
            {
                if (temp->left == NULL)
                {
                    temp->left = new node();
                }
                temp = temp->left;
            }
            else
            {
                if (temp->right == NULL)
                {
                    temp->right = new node();
                }
                temp = temp->right;
            }
        }
    }

    int max_xor_helper(int value)
    {
        node *temp = root;
        int current_ans = 0;
        for (int j = 31; j >= 0; j--)
        {
            int bit = (value >> j) & 1;
            if (bit == 0)
            {
                if (temp->right != NULL)
                {
                    temp = temp->right;
                    current_ans += (1 << j);
                }
                else
                {
                    temp = temp->left;
                }
            }
            else
            {
                if (temp->left != NULL)
                {
                    temp = temp->left;
                    current_ans += (1 << j);
                }
                else
                {
                    temp = temp->right;
                }
            }
        }

        return current_ans;
    }

    int maxXor(vector<int> &input, int n)
    {
        int max_xor = 0;
        for (int i = 0; i < n; i++)
        {
            int val = input[i];
            insert(val);
            int current_xor = max_xor_helper(val);
            max_xor = max(current_xor, max_xor);
        }

        return max_xor;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        trie t;
        return t.maxXor(nums,nums.size());
    }
};