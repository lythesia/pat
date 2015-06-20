#!/usr/bin/env ruby

broke = Array.new(96, false)
s = gets.chomp.downcase
s.each_char { |c| broke[c.ord] = true }

s = gets.chomp
s.each_char do |c|
  next if broke[c.downcase.ord] or (c[/[A-Z]/] and broke['+'.ord])
  print c
end
puts
