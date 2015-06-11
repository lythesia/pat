#!/usr/bin/env ruby

n, *a = gets.split.map(&:to_i)
ans, cur = 0, 0
a.each do |x|
  ans, cur = ans + (x > cur ? 6*(x - cur) : 4*(cur - x)) + 5, x
end
puts ans
