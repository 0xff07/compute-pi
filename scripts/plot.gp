set xlabel 'N'
set ylabel 'time(sec)'
set datafile separator ","
set logscale x 10
set term png enhanced
set output "pi.png"
plot [10000:1000000][0.00:0.3] \
     'time_data.txt' u 1:2 with lines title 'bassline', \
     'time_data.txt' u 1:3 with lines title 'openMP 2 Threads', \
     'time_data.txt' u 1:4 with lines title 'openMP 4 Threads', \
     'time_data.txt' u 1:5 with lines title 'AVX', \
     'time_data.txt' u 1:6 with lines title 'AVX + Unrolling' \
