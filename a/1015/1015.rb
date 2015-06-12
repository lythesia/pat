#!/usr/bin/env ruby

def is_prime(x)
  return false if x < 2
  2.upto(Math.sqrt(x).to_i) do |i|
    return false if x % i == 0
  end
  true
end

def revr(x, r)
  ans = 0
  while x != 0
    ans, x = ans * r + x % r, x / r
  end
  ans
end

while true
  n, d = gets.split.map(&:to_i)
  break if n < 0
  puts (is_prime(n) and is_prime(revr(n, d))) ? "Yes" : "No"
end
