NAME=$1;
g++ -g -std=c++17 -fsanitize=undefined -static $NAME
./a.out < input.txt > output.txt
diff output.txt esperado.txt