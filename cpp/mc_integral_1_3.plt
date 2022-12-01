set terminal png
set terminal png size 600,600
set output "mc_integral_1_3.png"
set xrange [0.0:1.0]
set yrange [0.0:1.0]
set zrange [0.0:1.0]
set xlabel "X"
set ylabel "Y"
set zlabel "Z"
splot 1-x-y lc rgb "red", "mc_integral_1_3.txt" with points pt 0 lc rgb "orange"