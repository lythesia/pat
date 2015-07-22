#!/usr/bin/env ruby

BASE = [29, 17, 0x3f3f3f3f]
a, b = gets.chomp.split.map { |x| x.split('.').map(&:to_i).reverse }
ans, c = [], 0
a.zip(b).each_with_index do |(aa, bb), i|
  sum = aa + bb + c
  ans << sum % BASE[i]
  c = sum / BASE[i]
end
puts ans.reverse * '.'
