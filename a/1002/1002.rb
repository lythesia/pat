#!/usr/bin/env ruby

a = Array.new 1001, 0.0
2.times do
  k, *an = gets.chomp.split
  0.upto(k.to_i - 1) { |i| a[an[2*i].to_i] += an[2*i+1].to_f }
end
ans = a.map { |x| x.round(1) }.each_with_index.select { |x, i| x != 0.0 }
puts "#{(ans << ans.length).flatten.reverse * ' '}"
