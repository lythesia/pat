#!/usr/bin/env ruby

MOD = 1000000007
t, at, pat = 0, 0, 0
gets.chomp.reverse.each_char do |c|
  if c == 'T'
    t += 1
  elsif c == 'A'
    at = (at + t) % MOD
  else
    pat = (pat + at) % MOD
  end
end
puts pat
