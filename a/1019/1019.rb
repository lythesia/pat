#!/usr/bin/env ruby

n, b = gets.split.map &:to_i
ans = []
while n != 0
  ans << n % b
  n /= b
end
ans << 0 if ans.empty?
puts ans.reverse == ans ? "Yes" : "No"
puts ans.reverse * ' '
