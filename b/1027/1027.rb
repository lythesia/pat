#!/usr/bin/env ruby

n, c = gets.chomp.split
k = Math.sqrt((n.to_i + 1) / 2).to_i
r = n.to_i - 2*k*k + 1
(1-k).upto(k-1).map { |x| x.abs + 1 }.each { |i| puts "#{' ' * (k-i)}#{c * (2*i-1)}"}
puts r
