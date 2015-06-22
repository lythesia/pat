#!/usr/bin/env ruby

s = gets.chomp
n = (s.to_i * 2).to_s
s.length == n.length && s.chars.sort == n.chars.sort ? puts("Yes") : puts("No")
puts n
