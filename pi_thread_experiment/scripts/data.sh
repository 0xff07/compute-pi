#! /bin/bash

echo "thread_num,original_time,naivemp_time,syncmp_time,simplemp_time" > "./data.txt";
for i in $(seq 1 10 1024)
do
    echo -n "$i," >> "./data.txt";
    ./test_all $i >> "./data.txt";
    echo "" >> "./data.txt";
done
