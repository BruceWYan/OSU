#!/bin/bash
#SBATCH -J Project7
#SBATCH -A cs475-575
#SBATCH -p classmpifinal
#SBATCH -N 8
#SBATCH -n 8
#SBATCH --constraint=ib
#SBATCH -o proj07.out
#SBATCH -e proj07.err
#SBATCH --mail-type=BEGIN,END,FAIL
#SBATCH --mail-user=yanbr@oregonstate.edu


for p in 1 2 4 8
do 
    mpic++ -o proj07 proj07.cpp -lm
    mpiexec -np $p ./proj07
done