-- tipos estruturados

-- enum
data Cor = Verde | Azul | Amarelo deriving (Eq, Show)

cor_basica :: Cor -> Bool
cor_basica c = (c == Verde || c == Azul || c == Amarelo)

-- binary search tree
data ArvoreBin = NodoNull | NodoInt Int ArvoreBin ArvoreBin deriving (Show)
arvore = NodoInt 4 (NodoInt 2 NodoNull NodoNull) (NodoInt 10 (NodoInt 5 NodoNull NodoNull) (NodoInt 15 NodoNull NodoNull))

-- pre order
passeio :: ArvoreBin -> [Int]
passeio (NodoNull) = []
passeio (NodoInt a NodoNull NodoNull) = [a]
passeio (NodoInt a esq dir) = [a] ++ passeio esq ++ passeio dir

-- insert
insere :: ArvoreBin -> Int -> ArvoreBin
insere (NodoNull) b = NodoInt b NodoNull NodoNull
insere (NodoInt a esq dir) b 
  | b < a  = (NodoInt a (insere esq b) dir)
  | b >= a  = (NodoInt a esq (insere dir b))

-- binary search
bs :: ArvoreBin -> Int -> ArvoreBin
bs (NodoNull) b = NodoNull
bs (NodoInt a esq dir) b 
  | b == a = (NodoInt a esq dir)
  | b < a = bs esq b
  | b > a = bs dir b