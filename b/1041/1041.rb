#!/usr/bin/env ruby

seat = {}
n = gets.chomp.to_i
n.times do
  id, try, test = gets.chomp.split
  seat[try.to_i] = [id, test]
end
gets
gets.split.map(&:to_i).each do |query|
  puts seat[query] * ' '
end
