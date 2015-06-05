#!/usr/bin/env ruby

r, s = "WTL", ""
ans = 1.0
3.times do
  odd = gets.split.map(&:to_f)
  mmax = odd.each_with_index.max
  ans *= mmax[0]
  s << "#{r[mmax[1]]} "
end
s << "#{((ans*0.65 - 1)*2).round(2)}"
puts s
