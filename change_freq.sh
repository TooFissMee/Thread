#!/bin/bash

# Mảng chứa các giá trị chu kỳ X
X_values=(1000000 100000 10000 1000 100)

# Vòng lặp để thay đổi giá trị X
for X in "${X_values[@]}"
do
    echo $X > freq.txt
    sleep 60
done

