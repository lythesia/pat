#!/usr/bin/env ruby

s = gets.chomp
v = (s.length + 2) / 3
h = s.length + 2 - v * 2
0.upto(v-2) { |i| puts "#{s[i]}#{' ' * (h - 2)}#{s[s.length - 1 - i]}" }
puts s[v-1, h]
