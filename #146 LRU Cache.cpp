class LRUCache {
    class Node{
        public:
        int key,val;
        Node*next;
        Node*prev;
        public:
        Node(int _key,int _val){
            key=_key;
            val=_val;
        }
    };
public:
    int cap;
    unordered_map<int,Node*>mpp;
Node * head = new Node(-1, -1);
Node * tail = new Node(-1, -1);

void addnode(Node*newnode){
    Node*temp=head->next;
    newnode->next=temp;
    newnode -> prev = head;
    head -> next = newnode;
    temp -> prev = newnode;
}
  void deletenode(Node * delnode) {
    Node * delprev = delnode -> prev;
    Node * delnext = delnode -> next;
    delprev -> next = delnext;
    delnext -> prev = delprev;
  }
    LRUCache(int capacity) {
        cap=capacity;
        head -> next = tail;
        tail -> prev = head;
    }
    
    int get(int key) {
        if(mpp.find(key)!=mpp.end()){
            Node*temp=mpp[key];
            int ans=temp->val;
            mpp.erase(key);
            deletenode(temp);
            addnode(temp);
            mpp[key]=head->next;
            return ans;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (mpp.find(key) != mpp.end()) {
      Node * existingnode = mpp[key];
      mpp.erase(key);
      deletenode(existingnode);
    }
    if (mpp.size() == cap) {
      mpp.erase(tail -> prev -> key);
      deletenode(tail -> prev);
    }
    Node*newnode=new Node(key,value);
    addnode(newnode);
    mpp[key]=newnode;
    }
};

//T.C.=O(N)  S.C.=O(1)
