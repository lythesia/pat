#!/usr/bin/env ruby

n = gets.chomp.to_i
ns = gets.chomp.split
h = {}
ns.each_index { |i| 
  x = ns[i].to_i
  if not h[x]
    h[x] ||= false  # insert
    while x != 1
      x = x.even? ? x/2 : (x*3+1)/2
      h[x] = true   # true if filter out
    end
  end
}
ans = h.select { |_,v| not v }.keys.sort.reverse
puts ans * ' '
