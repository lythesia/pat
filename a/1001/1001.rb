#!/usr/bin/env ruby

sum = gets.split.map(&:to_i).reduce(:+)
ans = ""
s = sum.abs.to_s.reverse
0.upto(s.length - 1) do |i|
  ans << s[i]
  ans << ',' if (i + 1) % 3 == 0 and i != s.length - 1
end
ans << '-' if sum < 0
puts "#{ans.reverse}"
