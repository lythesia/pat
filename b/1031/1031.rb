#!/usr/bin/env ruby

w = [7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2]
m = (('0'..'9').to_a.reverse << 'X').rotate -3
ans = []
n = gets.chomp.to_i
n.times do
  s = gets.chomp
  z = (0..16).reduce(0) { |acc, i| acc + (s[i].ord - '0'.ord) * w[i] } % 11
  ans << s if s[17] != m[z]
end
ans.empty? ? puts("All passed") : puts(ans * "\n")
