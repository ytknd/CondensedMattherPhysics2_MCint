set terminal png
set terminal png size 600,600
set output "mc_integral_1_1.png"
set xrange [0.0:1.0]
set yrange [0.0:1.0]
set xlabel "X"
set ylabel "Y"
plot x * x lc rgb "red", x * x * x lc rgb "red", "mc_integral_1_2.txt" with points pt 0 lc rgb "orange"