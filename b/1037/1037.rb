#!/usr/bin/env ruby

p, a = gets.chomp.split.map { |s| s.split('.').map &:to_i }
d = ((a[0] - p[0]) * 17 + a[1] - p[1]) * 29 + a[2] - p[2]
if d < 0
  print '-'
  d = -d
end
s = d / 29
puts [s / 17, s - (s / 17 * 17), d % 29] * '.'
