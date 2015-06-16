#!/usr/bin/env ruby

n = gets.chomp
ans = Array.new(10, 0)
n.chars.map { |c| c.ord - '0'.ord }.each { |x| ans[x] += 1 }
ans.each_with_index do |x, i|
  puts "#{i}:#{x}" if x > 0
end
