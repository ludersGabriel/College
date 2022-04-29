module Teste where

-- f o g
-- funções genéricas sobre listas:
-- mapeamento
-- filtragem
-- redução

-- Mapeamento
mult2 :: [Int] -> [Int]
mult2 [] = []
mult2 (a:x) = 2*a:(mult2 x)

mapear :: (Int -> Int) -> [Int] -> [Int]
mapear f [] = []
mapear f (a:x) = (f a):(mapear f x)

mapearS :: (Char -> Char) -> String -> String
mapearS f [] = []
mapearS f (a:x) = (f a):(mapearS f x)

-- Filtragem

so_pares :: [Int] -> [Int]
so_pares [] = []
so_pares (a:x)
  | mod a 2 == 0 = a:(so_pares x)
  | otherwise = so_pares x

filtrar :: (Int -> Bool) -> [Int] -> [Int]
filtrar f [] = []
filtrar f (a:x)
  | f a = a:(filtrar f x)
  | otherwise = filtrar f x

eh_par :: Int -> Bool
eh_par a = mod a 2 == 0

-- redução

somaR :: [Int] -> Int
somaR [] = 0
somaR (a:x) = a + (somaR x)

multR :: [Int] -> Int
multR [] = 1
multR (a:x) = a * (multR x)

concR :: [String] -> String
concR [] = ""
concR (a:x) = a ++ (concR x)

reduzir :: (a -> a -> a) -> [a] -> a
reduzir f [a] = a
reduzir f (a:x) = f a (reduzir f x)

somar :: Int -> Int -> Int
somar a b = a + b

-- Expressao condicional
sinal x = 
    if x < 0
      then -1
      else
        if x > 0
          then 1
          else 0

f x = 
  case x of
    0 -> 1
    1 -> 5
    2 -> 2
    _ -> -1

-- Blocos
menu :: IO ()
menu = do 
  putStr "Incluir\n"
  putStr "Excluir\n"
  putStr "Sair\n"

menu2 :: IO ()
menu2 = do {
  putStr "Incluir\n"; putStr "Diz a lenda\n";
}

concatena :: IO()
concatena = do 
  str1 <- getLine
  str2 <- getLine
  putStr (str1 ++ str2 ++ "\n")

-- E/S
-- escrita:
-- putChar :: Char -> IO ()
-- putStr :: String -> IO ()
-- putStrLn :: String -> IO ()
-- print :: Show a => a -> IO ()

-- Leitura
-- getChar :: IO Char
-- getLine :: IO String
-- read :: Read a => String -> a

leInt :: IO Int
leInt = do
  linha <- getLine
  return (read linha :: Int)

somaInt = do 
  l1 <- leInt
  l2 <- leInt
  return (l1 + l2)


-- Não funcionais
-- compilação
-- no arquivo.hs:
-- main = do 

main = do 
  putStrLn "ola mundo"

