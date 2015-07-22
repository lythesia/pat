#!/usr/bin/env ruby

require "prime"
n = gets.chomp.to_i
f = Prime.prime_division(n)
ans = f.map { |p, c| c > 1 ? "#{p}^#{c}" : "#{p}" }
ans << '1' if ans.empty?
print n, '='
puts ans * '*'
