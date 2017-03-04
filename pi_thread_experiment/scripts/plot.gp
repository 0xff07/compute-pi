set xlabel 'thead_num'
set ylabel 'time'
set datafile separator ","
set term png enhanced 1 font "Verdana,12"
set output "pi.png"
plot [0:1024][0.05:0.5] \
     'data.txt' u 1:2 with lines title 'original', \
     'data.txt' u 1:3 with lines title 'openMP Naive', \
     'data.txt' u 1:4 with lines title 'openMP Sync',\
     'data.txt' u 1:5 with lines title 'openMP Parallel For'

