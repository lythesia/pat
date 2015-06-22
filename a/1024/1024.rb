#!/usr/bin/env ruby

n, k = gets.split.map &:to_i
step, rn = 0, n.to_s.reverse
while n.to_s != rn && step != k
  n = n + rn.to_i
  rn = n.to_s.reverse
  step += 1
end
puts n, step
