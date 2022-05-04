-- PROVA 2-1

-- questão 1
coprimos :: Int -> Int -> Bool
coprimos a b
  | b == 0 = if a == 1 then True else False
  | otherwise = coprimos b (mod a b)

-- questão 2
limpa :: String -> String
limpa [] = []
limpa (a:c) 
  | a /= 'c' = a:(limpa c)
  | otherwise = limpa c

-- questão 3
rotaciona :: String -> Int -> String
rotaciona [] i = []
rotaciona (a:c) i 
  | i > 0 = rotaciona (c ++ [a]) (i-1)
  | otherwise = (a:c)

-- questão 4
data ArvoreBin = NodoNull | NodoInt Int [Int] [ArvoreBin]

-- questão 5
type Nome = String
type Idade = Int
type Pessoa = (Nome, Idade)

f :: Pessoa -> Bool
f (nome, idade) = idade >= 21

filtragem :: (Pessoa -> Bool) -> [Pessoa] -> [Pessoa] 
filtragem f [] = []
filtragem f (a:c) 
  | f a = a:(filtragem f c)
  | otherwise = filtragem f c

-- PROVA 2-2

-- questão 1
-- indice de 1 a n, sendo n o tamanho da lista
removek :: [Int] -> Int -> [Int]
removek [] i = []
removek (a:c) i
  | i == 1 = c
  | otherwise = a:(removek c (i - 1))

-- questão 2
-- indice de 1 até n, sendo n o tamanho da lista
fatia :: String -> Int -> Int -> String
fatia [] i j = []
fatia (a:c) i j
  | i > 1 = fatia c (i - 1) (j - 1)
  | j > 0 = a:(fatia c i (j - 1))
  | otherwise = [a] 

-- questão 3
intercala :: [Int] -> [Int] -> [Int]
intercala [] [] = []
intercala [] a = a
intercala a [] = a
intercala (a:b) (c:d) 
  | a <= c = [a] ++ intercala b (c:d) 
  | otherwise =  [c] ++ intercala (a:b) d

-- questao 4
type Nome2 = String
type Endereco2 = String
type Email2 = String
type Pessoa2 = (Nome2, Endereco2, Email2)

data AVL = NodoNull2 | NodoPessoa AVL Pessoa Int AVL

-- questão 5
f2 :: Int -> Int -> Bool
f2 a x = a >= x &&  a <= (x*x)

filtragem2 :: (Int -> Int -> Bool) -> [Int] -> Int -> [Int]
filtragem2 f2 [] x = []
filtragem2 f2 (a:c) x 
  | (f2 a x) = [a] ++ filtragem2 f2 c x
  | otherwise = filtragem2 f2 c x 

