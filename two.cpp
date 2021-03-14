bool find_path(Node* root,int value,vector<int> &v)
{
	if(root==NULL)
	return false;
	v.push_back(root->data);

	if(root->data==value)
	return true;
	if(find_path(root->left,value,v) || find_path(root->right,value,v))
	return true;

	v.pop_back();
	return false;
}

int kthAncestor(Node *root, int k, int a)
{
    
   vector<int> v1;
  	if(find_path(root,a,v1)==false)
	return 0;
	int flag=0;
	if(k==0)
	return v1[0];
	
	if(v1.size()==1)
	return -1;
	int i;

	for( i=v1.size()-1;i>=0 && k>=0;i--)
	{
		if(k==0)
		{
		flag=1;
		break;
		}
		else
		k--;
	}
	

	if(flag==0)
	return -1;
	
	return v1[i];
}