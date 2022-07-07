NAME=$1;
g++ -fsanitize=undefined -static $NAME
./a.out < input.txt > output.txt
diff output.txt esperado.txt