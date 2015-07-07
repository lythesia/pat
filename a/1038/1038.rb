#!/usr/bin/env ruby

_, *s = gets.chomp.split
s.sort! { |x, y| x + y <=> y + x }
ss = s.index { |x| x.to_i > 0 }
if ss.nil?
  puts 0
else
  print s[ss].to_i
  s[(ss + 1)..-1].each { |x| print x }
  puts
end
