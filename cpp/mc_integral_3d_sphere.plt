set terminal png
set terminal png size 600,600
set output "mc_integral_3d_sphere.png"
set parametric
set hidden3d
set view 45
set xrange [0.0:1.0]
set yrange [0.0:1.0]
set zrange [0.0:1.0]
set xlabel "X"
set ylabel "Y"
set zlabel "Z"
splot [0:0.5*pi] cos(u)*cos(v),sin(u)*cos(v),sin(v) lc rgb "red", "mc_integral_3d_sphere.txt" with points pt 0 lc rgb "orange"