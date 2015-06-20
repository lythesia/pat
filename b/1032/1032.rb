#!/usr/bin/env ruby

n = gets.chomp.to_i
a = Array.new(n + 1, 0)
n.times do
  i, g = gets.split.map &:to_i
  a[i] += g
end
ans = a.each_with_index.max_by { |x, i| x }
puts "#{ans[1]} #{ans[0]}"
