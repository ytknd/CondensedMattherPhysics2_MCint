set terminal png
set terminal png size 600,600
set output "mc_integral_2d_disk.png"
set parametric
set xrange [0.0:1.0]
set yrange [0.0:1.0]
set xlabel "X"
set ylabel "Y"
plot [0:0.5*pi] cos(t),sin(t) lc rgb "red", "mc_integral_2d_disk.txt" with points pt 0 lc rgb "orange"