set terminal pngcairo enhanced font "arial,10" fontscale 1.0 size 800, 600

set datafile separator "\t"
set key autotitle columnhead
set ylabel "Время выполнения (мс)"
set xlabel "n (Число Фибоначчи)"
set title "Зависимость времени выполнения от числа Фибоначчи"

set grid
set output "fibonacci_timings.png"
plot "fibonacci_timings.txt" using 1:2 with linespoints lw 2 lc rgb "blue" pt 7,\
     '' using 1:3 with linespoints lw 2 lc rgb "red" pt 7
