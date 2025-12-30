for n in 1000  10000 100000 1000000 8000000
do
    g++  all04.cpp  -DARRAYSIZE=$n -o all04 -lm  -fopenmp
    ./all04
done