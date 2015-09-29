#!/usr/bin/env ruby

n = gets.chomp.to_i
isp = Array.new(n, true)
a = gets.split.map &:to_i
mmax, mmin = a.first, a.last
ans = []
a.each_with_index do |x, i|
  if x >= mmax
    mmax = x
  else
    isp[i] = false
  end
end
a.reverse.each_with_index do |x, i|
  if x <= mmin
    mmin = x
  else
    isp[n - 1 - i] = false
  end
end
isp.each_with_index do |x, i|
  ans << a[i] if x
end
ans.sort!
puts ans.size
puts ans * ' '
