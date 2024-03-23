#!/bin/bash

# Biên dịch chương trình C
gcc -o program program.c -lpthread

# Chạy chương trình C và lưu PID của nó
./program &
PROGRAM_PID=$!

# Chạy shell script để thay đổi X
./change_freq.sh &

# Đợi 5 phút
sleep 300

# Dừng chương trình C
kill $PROGRAM_PID

