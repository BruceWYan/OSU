#!/bin/bash
#SBATCH -J Project05
#SBATCH -A cs475-575
#SBATCH -p classgpufinal
#SBATCH --constraint=v100
#SBATCH --gres=gpu:1
#SBATCH -o proj05.out
#SBATCH -e proj05.err
#SBATCH --mail-type=BEGIN,END,FAIL
#SBATCH --mail-user=yanbr@oregonstate.edu