class MyCircularQueue {
public:
  vector<int> v;
  int ptrAhead = 0, ptrBehind = 0;
  MyCircularQueue(int k) {
    v.resize(k, -1);
    ptrAhead = 0;
    ptrBehind = 0;
  }

  bool enQueue(int value) {
    if(v[ptrAhead] == -1 or v[0] == -1) {
      v[ptrAhead] = value;
      ptrAhead++;
      if(ptrAhead == v.size()) ptrAhead=0;
      return true;
    }
    return false;
  }

  bool deQueue() {
    if(v[ptrBehind] == -1) return false;
    v[ptrBehind] = -1;
    ptrBehind++;
    if(ptrBehind == v.size()) ptrBehind=0;
    return true;
  }

  int Front() {
    return v[ptrBehind];
  }

  int Rear() {
    if(ptrAhead == 0) return v[v.size()-1];
    return v[ptrAhead-1];
  }

  bool isEmpty() {
    if(ptrAhead == ptrBehind and v[ptrAhead]==-1) return true;
    return false;
  }

  bool isFull() {
    if(ptrAhead == ptrBehind and v[ptrAhead]!=-1) return true;
    return false;
  }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */