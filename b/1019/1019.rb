#!/usr/bin/env ruby

n = gets.chomp.to_i
loop do
  s = ("%04d" % n).chars.sort.join
  a, b = s.reverse.to_i, s.to_i
  n = a - b
  printf "%04d - %04d = %04d\n" % [a, b, n]
  break if n == 0 or n == 6174
end
