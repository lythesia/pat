#!/usr/bin/env ruby

n, *a = gets.split.map(&:to_i)
a1 = a.select { |x| x % 10 == 0 }
a2 = a.select { |x| x % 5 == 1 }
a3 = a.select { |x| x % 5 == 2 }
a4 = a.select { |x| x % 5 == 3 }
a5 = a.select { |x| x % 5 == 4 }

ans = []
ans << (a1.empty? ? 'N' : a1.reduce(:+))
ans << (a2.empty? ? 'N' : a2.each_with_index.inject(0) { |acc, (x, i)| acc + x*(i.even? ? 1 : -1) })
ans << (a3.empty? ? 'N' : a3.length)
ans << (a4.empty? ? 'N' : (a4.reduce(:+) * 1.0 / a4.length).round(1))
ans << (a5.empty? ? 'N' : a5.max)
puts ans * ' '
