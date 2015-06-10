#!/usr/bin/env ruby

k = gets.chomp.to_i
a = gets.split.map(&:to_i)
ans, as, ae, sum, s = -1, 0, k-1, 0, 0
a.each_with_index do |x, i|
  sum += x
  ans, as, ae = sum, s, i if sum > ans
  sum, s = 0, i+1 if sum < 0
end
puts "%d %d %d" % [ans==-1 ? 0 : ans, a[as], a[ae]]
