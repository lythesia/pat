#!/usr/bin/env ruby

n, ans = gets.chomp.to_i, 0
while n != 1
  n = n.even? ? n/2 : (3*n+1)/2
  ans += 1
end
puts ans
