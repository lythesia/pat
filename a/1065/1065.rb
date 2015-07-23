#!/usr/bin/env ruby
t = gets.chomp.to_i
1.upto(t) do |i|
  a, b, c = gets.split.map &:to_i
  puts "Case ##{i}: #{a + b > c}"
end
