#!/usr/bin/env ruby

t = gets.chomp.to_i
t.times do |i|
  a, b, c = gets.split.map(&:to_i)
  puts "Case ##{i+1}: #{a+b > c}"
end
