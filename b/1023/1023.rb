#!/usr/bin/env ruby

d = gets.split.map &:to_i
if d[0] > 0
  p = d[1..9].index { |x| x > 0 } + 1
  print p
  d[p] -= 1
end
d.each_with_index { |x, i| print i.to_s * x }
puts
