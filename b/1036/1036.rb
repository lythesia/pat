#!/usr/bin/env ruby

n, c = gets.chomp.split
n = n.to_i
puts c * n
((n / 2.0).round - 2).times { puts c + ' ' * (n-2) + c }
puts c * n
