#!/usr/bin/env ruby

n = gets.chomp.to_i
puts 'B'*(n/100) + 'S'*(n%100/10) + (1..n%10).to_a*''
