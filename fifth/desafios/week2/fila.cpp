#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using il = long;

int isFifo(queue<int>& mq, int age){
  if(mq.front() == age){
    mq.pop();
    return 1;
  }

  return 0;
}

int isLifo(stack<int>& ms, int age) {
  if(ms.top() == age){
    ms.pop();
    return 1;
  }

  return 0;
}

int isPrio(priority_queue<int, vector<int>, less<int>>& pq, int age){
  if(pq.top() == age){
    pq.pop();
    return 1;
  }

  return 0;
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  int fifo, lifo, prio;
  lifo = fifo = prio = 1;

  queue<int> mq;
  stack<int> ms;
  priority_queue<int, vector<int>, less<int>> pq;

  int n, op, age;
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> op >> age;

    if(op == 0){
      mq.push(age);
      ms.push(age);
      pq.push(age);
    }
    else if(op == 1){
      if(fifo) fifo = isFifo(mq, age);
      if(lifo) lifo = isLifo(ms, age);
      if(prio) prio = isPrio(pq, age);
    }
  }  

  if(lifo && fifo || lifo && prio || fifo && prio){
    cout << "ambiguous";
  }
  else if(lifo){
    cout << "lifo";
  }
  else if(fifo){
    cout << "fifo";
  }
  else if(prio){
    cout << "priority";
  }
  else{
    cout << "unknown";
  }

}