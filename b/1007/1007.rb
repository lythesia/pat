#!/usr/bin/env ruby

n = gets.chomp.to_i
p = Array.new n+1, true
(2..Math.sqrt(n).to_i).each do |i|
  (i*i..n).step(i) { |j| p[j] = false } if p[i]
end
prev, ans = 2, 0
(3..n).each do |i|
  if p[i]
    ans += 1 if i-prev == 2
    prev = i
  end
end
puts ans
