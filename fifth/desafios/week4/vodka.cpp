#include <bits/stdc++.h>
#define BIGINT 1e9

using namespace std;
using ll = long long;


int f(
  int corrente, 
  int periodo,
  int idade,
  int idadeMaxima,
  int precoNovo,
  vector<int>& c, 
  vector<int>& v 
){
  if(corrente > periodo) return 0;

  int custoMan = BIGINT;
  if(idade < idadeMaxima){
    custoMan = c[idade];
    custoMan += f(corrente + 1, periodo, idade + 1, idadeMaxima, precoNovo, c, v);
  }

  int custoVenda = idade < idadeMaxima 
    ? precoNovo + c[idade] - v[idade]
    : precoNovo - v[idade];
  custoVenda += f(corrente + 1, periodo, 0, idadeMaxima, precoNovo, c, v);

  return custoMan < custoVenda ? custoMan : custoVenda;

}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  int n, i, m, p;

  cin >> n >> i >> m >> p;

  vector<int> c (m);
  vector<int> v(m + 1, 0);

  for(auto& el : c){
    cin >> el;
  }

  int tmp;
  for(int i = 1; i < v.size(); i++){
    cin >> tmp;
    v[i] = tmp;
  }
  
  int custo = f(1, n, i, m, p, c, v);
  
  cout << custo;

}