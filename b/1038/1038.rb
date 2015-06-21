#!/usr/bin/env ruby

a = Array.new(101, 0)
_ = gets
gets.chomp.split.each { |x| a[x.to_i] += 1 } 
_, *q = gets.chomp.split
ans = q.map { |x| a[x.to_i] }
puts ans * ' '
