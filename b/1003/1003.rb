#!/usr/bin/env ruby

n = gets.chomp.to_i
n.times do
  s = gets.chomp
  /^(?<a>A*)P(?<b>A+)T(?<c>A*)$/ =~ s
  puts !!(a and b and c and a.length * b.length == c.length) ? "YES" : "NO"
end
