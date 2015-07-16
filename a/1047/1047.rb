#!/usr/bin/env ruby

# case 3 TLE
n, k = gets.split.map &:to_i
cs = Array.new(k) { Array.new }
n.times do
  s, _, *cc = gets.chomp.split
  cc.each do |c|
    c = c.to_i - 1
    cs[c] << s
  end
end
k.times do |i|
  puts "#{i + 1} #{cs[i].length}"
  cs[i].sort!
  puts cs[i]
end
