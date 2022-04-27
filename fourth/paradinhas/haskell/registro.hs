type Nome = String
type Endereco = String
type Telefone = String
type Email = String
type GRR = String
type CPF = String
type Idade = Integer

type Aluno = (Nome, Idade)

pessoa rg
  | rg == 1 = ("duud", 10)
  | rg == 2 = ("duud2", 20)
  | rg == 3 = ("duud3", 5)
  | rg == 4 = ("duud4", 40)

getNome :: Aluno -> Nome
getNome (a, g) = a

getIdade :: Aluno -> Integer
getIdade (a, g) = g

setNome :: Aluno -> Nome -> Aluno
setNome (a,g) name = (name,g)

menor :: Aluno -> Aluno -> Aluno
menor p1 p2 = if getIdade p1 <= getIdade p2 then p1 else p2

menorIdade rg
  | rg == 1 = pessoa 1
  | otherwise = menor (pessoa rg) (menorIdade (rg - 1))

